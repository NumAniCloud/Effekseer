
#include "efk.ImageResource.h"
#include <IO/IO.h>

namespace efk
{

ImageResource::ImageResource(DeviceType deviceType, std::shared_ptr<Effekseer::TextureLoader> loader)
	: deviceType_(deviceType)
	, loader_(loader)
{
}

ImageResource::~ImageResource()
{
	if (textureData != nullptr)
	{
		loader_->Unload(textureData);
	}
}

bool ImageResource::Validate()
{
	auto staticFile = Effekseer::IO::GetInstance()->LoadFile(path.c_str());
	if (staticFile == nullptr)
		return false;

	auto loaded = loader_->Load(staticFile->GetData(), staticFile->GetSize(), Effekseer::TextureType::Color, true);

	if (loaded == nullptr)
		return false;

	if (textureData != nullptr)
	{
		loader_->Unload(textureData);
	}

	textureData = loaded;

	return true;
}

void ImageResource::Invalidate()
{

	if (textureData != nullptr)
	{
		loader_->Unload(textureData);
	}

	textureData = nullptr;
}

} // namespace efk