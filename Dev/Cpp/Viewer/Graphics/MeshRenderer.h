
#pragma once

#include <Effekseer.h>

namespace Effekseer
{
namespace Tool
{

struct RendererParameter
{
	Effekseer::Matrix44 ProjectionMatrix;
	Effekseer::Matrix44 CameraMatrix;
	std::array<float, 4> DirectionalLightDirection;
	std::array<float, 4> DirectionalLightColor;
	std::array<float, 4> AmbientLightColor;
};

struct StaticMeshVertex
{
	std::array<float, 3> Pos;
	std::array<float, 2> UV;
	Effekseer::Color VColor;
	std::array<float, 3> Normal;
};

class StaticMesh
{
private:
	int32_t vertexCount_;
	int32_t indexCount_;
	std::shared_ptr<Backend::VertexBuffer> vb_;
	std::shared_ptr<Backend::IndexBuffer> ib_;

public:
};

class StaticMeshRenderer
{
private:
	struct UniformBufferVS
	{
		Effekseer::Matrix44 projectionMatrix;
		Effekseer::Matrix44 cameraMatrix;
	};

	struct UniformBufferPS
	{
		std::array<float, 4> directionalLightDirection;
		std::array<float, 4> directionalLightColor;
		std::array<float, 4> ambientLightColor;
	};

	std::shared_ptr<Backend::GraphicsDevice> graphicsDevice_;
	std::shared_ptr<Backend::UniformBuffer> uniformBufferVS_;
	std::shared_ptr<Backend::UniformBuffer> uniformBufferPS_;
	std::shared_ptr<Backend::UniformLayout> uniformLayout_;
	std::shared_ptr<Backend::Shader> shader_;
	std::shared_ptr<Backend::PipelineState> pip_;
	std::shared_ptr<Backend::VertexLayout> vertexLayout_;

	std::shared_ptr<StaticMesh> staticMesh_;

	StaticMeshRenderer();

public:
	static std::shared_ptr<StaticMeshRenderer> Create(std::shared_ptr<Backend::GraphicsDevice> graphicsDevice);
	void Render(const RendererParameter& rendererParameter);
};

} // namespace Tool
} // namespace Effekseer