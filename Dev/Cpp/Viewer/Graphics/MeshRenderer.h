
#pragma once

#include <Effekseer.h>

namespace Effekseer
{
namespace Tool
{

struct RendererParameter
{
	Effekseer::Matrix44 CameraMatrix;
	Effekseer::Matrix44 ProjectionMatrix;
};

struct StaticMeshVertex
{
	std::array<float, 3> Pos;
	std::array<float, 2> UV;
	Effekseer::Color VColor;
};

class StaticMesh
{
private:
	std::shared_ptr<Backend::VertexBuffer> vb_;
	std::shared_ptr<Backend::IndexBuffer> ib_;
public:

};

class StaticMeshRenderer
{
private:
	std::shared_ptr<Backend::GraphicsDevice> graphicsDevice_;
	std::shared_ptr<Backend::UniformBuffer> uniformBufferVS_;
	std::shared_ptr<Backend::UniformBuffer> uniformBufferPS_;
	std::shared_ptr<Backend::Shader> shader_;
	std::shared_ptr<Backend::PipelineState> pip_;
	std::shared_ptr<Backend::UniformLayout> uniformLayout_;
	std::shared_ptr<Backend::VertexLayout> vertexLayout_;

	std::shared_ptr<StaticMesh> staticMesh_;

public:
	StaticMeshRenderer(std::shared_ptr<Backend::GraphicsDevice> graphicsDevice);
	void Render(const RendererParameter& rendererParameter);
};

}
} // namespace Effekseer