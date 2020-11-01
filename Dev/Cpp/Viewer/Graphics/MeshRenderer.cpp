#include "MeshRenderer.h"


namespace Effekseer
{
namespace Tool
{

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

	auto shader = Effekseer::CreateReference(GenerateShader(graphicsDevice.get(), uniformLayout.get(), window.get()));

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
	vertexLayoutElements[4].Format = Effekseer::Backend::VertexLayoutFormat::R32G32B32_FLOAT;
	vertexLayoutElements[4].Name = "in_normal";
	vertexLayoutElements[4].SemanticIndex = 1;
	vertexLayoutElements[4].SemanticName = "NORMAL";

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
}

}
} // namespace Effekseer

