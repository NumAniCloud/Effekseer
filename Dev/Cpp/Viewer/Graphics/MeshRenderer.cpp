#include "MeshRenderer.h"

static const char* vs_code = R"(

cbuffer VS_ConstantBuffer : register(b0)
{
	float4x4 cameraMatrix;
	float4x4 projectionMatrix;
}

struct VS_Input
{
	float3 Pos : POSITION0;
	float2 UV : TEXCOORD0;
	float4 Color : NORMAL0;
	float3 Normal : NORMAL1;
};

struct VS_Output
{
	float4 Pos : SV_POSITION;
	float2 UV : TEXCOORD0;
	float4 Color : NORMAL0;
	float3 Normal : NORMAL1;
};

VS_Output main(const VS_Input input)
{
	VS_Output output;
	float4 localPos = float4(input.Pos, 1.0f);
	float4 cameraPos = mul(cameraMatrix, localPos);
	output.Pos = mul(projectionMatrix, cameraPos);
	output.UV = input.UV;
	output.Color = input.Color;
	output.Normal = input.Normal;
	return output;
}

)";

static const char* ps_code = R"(

cbuffer VS_ConstantBuffer : register(b0)
{
	float4 directionalLightDirection;
	float4 directionalLightColor;
	float4 ambientLightColor;
}

struct PS_Input
{
	float4 Pos : SV_POSITION;
	float2 UV : TEXCOORD0;
	float4 Color : NORMAL0;
	float3 Normal : NORMAL1;
};

float4 main(const PS_Input input)
	: SV_Target
{
	return float4(1.0, 1.0, 1.0, 1.0);

	float4 output = input.Color;
	float diffuse = max(dot(directionalLightDirection.xyz, input.Normal.xyz), 0.0);
	output.xyz = output.xyz * (directionalLightColor.xyz * diffuse + ambientLightColor.xyz);

	if (output.a == 0.0)
		discard;

	return output;
}
)";

namespace Effekseer
{
namespace Tool
{

std::shared_ptr<StaticMesh> StaticMesh::Create(std::shared_ptr<Backend::GraphicsDevice> graphicsDevice, Effekseer::CustomVector<StaticMeshVertex> vertexes, Effekseer::CustomVector<int32_t> indexes)
{
	auto vb = Effekseer::CreateReference(graphicsDevice->CreateVertexBuffer(static_cast<int32_t>(sizeof(StaticMeshVertex) * vertexes.size()), vertexes.data(), false));
	auto ib = Effekseer::CreateReference(graphicsDevice->CreateIndexBuffer(static_cast<int32_t>(indexes.size()), indexes.data(), Effekseer::Backend::IndexBufferStrideType::Stride4));

	if (vb == nullptr || ib == nullptr)
	{
		return nullptr;
	}

	auto ret = std::make_shared<StaticMesh>();
	ret->vb_ = vb;
	ret->ib_ = ib;
	ret->indexCount_ = ib->GetElementCount();
	return ret;
}

StaticMeshRenderer::StaticMeshRenderer()
{
}

std::shared_ptr<StaticMeshRenderer> StaticMeshRenderer::Create(std::shared_ptr<Backend::GraphicsDevice> graphicsDevice)
{
	// shader
	Effekseer::CustomVector<Effekseer::Backend::UniformLayoutElement> uniformLayoutElements;
	uniformLayoutElements.resize(5);
	uniformLayoutElements[0].Name = "projectionMatrix";
	uniformLayoutElements[0].Offset = 0;
	uniformLayoutElements[0].Stage = Effekseer::Backend::ShaderStageType::Vertex;
	uniformLayoutElements[0].Type = Effekseer::Backend::UniformBufferLayoutElementType::Matrix44;
	uniformLayoutElements[1].Name = "cameraMatrix";
	uniformLayoutElements[1].Offset = sizeof(float) * 16;
	uniformLayoutElements[1].Stage = Effekseer::Backend::ShaderStageType::Vertex;
	uniformLayoutElements[1].Type = Effekseer::Backend::UniformBufferLayoutElementType::Matrix44;

	uniformLayoutElements[2].Name = "directionalLightDirection";
	uniformLayoutElements[2].Offset = 0;
	uniformLayoutElements[2].Stage = Effekseer::Backend::ShaderStageType::Pixel;
	uniformLayoutElements[2].Type = Effekseer::Backend::UniformBufferLayoutElementType::Vector4;
	uniformLayoutElements[3].Name = "directionalLightColor";
	uniformLayoutElements[3].Offset = 0;
	uniformLayoutElements[3].Stage = Effekseer::Backend::ShaderStageType::Pixel;
	uniformLayoutElements[3].Type = Effekseer::Backend::UniformBufferLayoutElementType::Vector4;
	uniformLayoutElements[4].Name = "ambientLightColor";
	uniformLayoutElements[4].Offset = 0;
	uniformLayoutElements[4].Stage = Effekseer::Backend::ShaderStageType::Pixel;
	uniformLayoutElements[4].Type = Effekseer::Backend::UniformBufferLayoutElementType::Vector4;

	// constant buffer
	auto vcb = Effekseer::CreateReference(graphicsDevice->CreateUniformBuffer(sizeof(UniformBufferVS), nullptr));
	auto pcb = Effekseer::CreateReference(graphicsDevice->CreateUniformBuffer(sizeof(UniformBufferPS), nullptr));
	auto uniformLayout = Effekseer::CreateReference(new Effekseer::Backend::UniformLayout({}, std::move(uniformLayoutElements)));

	auto shader = Effekseer::CreateReference(graphicsDevice->CreateShaderFromCodes(vs_code, ps_code, uniformLayout.get()));

	std::vector<Effekseer::Backend::VertexLayoutElement> vertexLayoutElements;
	vertexLayoutElements.resize(4);
	vertexLayoutElements[0].Format = Effekseer::Backend::VertexLayoutFormat::R32G32B32_FLOAT;
	vertexLayoutElements[0].Name = "in_position";
	vertexLayoutElements[0].SemanticIndex = 0;
	vertexLayoutElements[0].SemanticName = "POSITION";
	vertexLayoutElements[1].Format = Effekseer::Backend::VertexLayoutFormat::R32G32_FLOAT;
	vertexLayoutElements[1].Name = "in_uv";
	vertexLayoutElements[1].SemanticIndex = 0;
	vertexLayoutElements[1].SemanticName = "TEXCOORD";
	vertexLayoutElements[2].Format = Effekseer::Backend::VertexLayoutFormat::R8G8B8A8_UNORM;
	vertexLayoutElements[2].Name = "in_color";
	vertexLayoutElements[2].SemanticIndex = 0;
	vertexLayoutElements[2].SemanticName = "NORMAL";
	vertexLayoutElements[3].Format = Effekseer::Backend::VertexLayoutFormat::R32G32B32_FLOAT;
	vertexLayoutElements[3].Name = "in_normal";
	vertexLayoutElements[3].SemanticIndex = 1;
	vertexLayoutElements[3].SemanticName = "NORMAL";

	auto vertexLayout = Effekseer::CreateReference(graphicsDevice->CreateVertexLayout(vertexLayoutElements.data(), static_cast<int32_t>(vertexLayoutElements.size())));

	Effekseer::Backend::PipelineStateParameter pipParam;

	// OpenGL doesn't require it
	pipParam.FrameBufferPtr = nullptr;
	pipParam.VertexLayoutPtr = vertexLayout.get();
	pipParam.ShaderPtr = shader.get();
	pipParam.IsDepthTestEnabled = false;
	pipParam.IsBlendEnabled = false;

	auto pip = Effekseer::CreateReference(graphicsDevice->CreatePipelineState(pipParam));

	auto ret = std::make_shared<StaticMeshRenderer>();

	ret->graphicsDevice_ = graphicsDevice;
	ret->pip_ = pip;
	ret->shader_ = shader;
	ret->uniformBufferVS_ = vcb;
	ret->uniformBufferPS_ = pcb;
	ret->vertexLayout_ = vertexLayout;

	return ret;
}

void StaticMeshRenderer::Render(const RendererParameter& rendererParameter)
{
	if (staticMesh_ == nullptr)
	{
		return;
	}

	UniformBufferVS uvs{};
	UniformBufferPS ups{};

	graphicsDevice_->UpdateUniformBuffer(uniformBufferVS_.get(), sizeof(UniformBufferVS), 0, &uvs);
	graphicsDevice_->UpdateUniformBuffer(uniformBufferPS_.get(), sizeof(UniformBufferPS), 0, &ups);

	Effekseer::Backend::DrawParameter drawParam;
	drawParam.VertexBufferPtr = staticMesh_->GetVertexBuffer().get();
	drawParam.IndexBufferPtr = staticMesh_->GetIndexBuffer().get();
	drawParam.PipelineStatePtr = pip_.get();
	drawParam.VertexUniformBufferPtr = uniformBufferVS_.get();
	drawParam.PixelUniformBufferPtr = uniformBufferPS_.get();
	drawParam.PrimitiveCount = staticMesh_->GetIndexCount() / 3;
	drawParam.InstanceCount = 1;
	graphicsDevice_->Draw(drawParam);
}

void StaticMeshRenderer::SetStaticMesh(const std::shared_ptr<StaticMesh>& mesh)
{
	staticMesh_ = mesh;
}

} // namespace Tool
} // namespace Effekseer
