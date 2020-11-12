﻿using System;
using System.Collections.Generic;
using Effekseer.Binary.RenderData;
using Effekseer.Utl;

namespace Effekseer.Binary
{
	class RendererCommonValues
	{
		private static readonly MaterialSerializer MaterialSerializerInstance = new MaterialSerializer();

		public static byte[] GetBytes(Data.RendererCommonValues value,
			Data.AdvancedRenderCommonValues advanceValue,
			Data.AdvancedRenderCommonValues2 advanceValue2,
			Dictionary<string, int> texture_and_index,
			Dictionary<string, int> normalTexture_and_index,
			Dictionary<string, int> distortionTexture_and_index,
			Dictionary<string, int> material_and_index,
			ExporterVersion version)
		{
			List<byte[]> data = new List<byte[]>();

			var texInfo = new TextureInformation();

			var alphaTexInfo = new TextureInformation();

			var uvDistortionTexInfo = new TextureInformation();

			var blendTexInfo = new TextureInformation();

			var blendAlphaTexInfo = new TextureInformation();

			var blendUVDistortionTexInfo = new TextureInformation();

			data.Add(((int)value.Material.Value).GetBytes());

			if (version >= ExporterVersion.Ver16Alpha1)
			{
				if (value.Material.Value == Data.RendererCommonValues.MaterialType.Default ||
				value.Material.Value == Data.RendererCommonValues.MaterialType.Lighting)
				{
					data.Add(BitConverter.GetBytes(value.EmissiveScaling));
				}
			}

			{
				var aggregator = new TextureValuesAggregator(value, advanceValue, advanceValue2,
					texInfo, alphaTexInfo, uvDistortionTexInfo, blendTexInfo, blendAlphaTexInfo, blendUVDistortionTexInfo);
				MaterialSerializerInstance.AddMaterialData(version, value, aggregator,
					texture_and_index, distortionTexture_and_index, normalTexture_and_index, material_and_index);
				data.AddRange(aggregator.CurrentData);
			}

			data.Add(value.AlphaBlend);
			data.Add(value.Filter);
			data.Add(value.Wrap);

			data.Add(value.Filter2);
			data.Add(value.Wrap2);

			if (version >= ExporterVersion.Ver16Alpha1)
			{
				data.Add(advanceValue.AlphaTextureParam.Filter);
				data.Add(advanceValue.AlphaTextureParam.Wrap);

				data.Add(advanceValue.UVDistortionTextureParam.Filter);
				data.Add(advanceValue.UVDistortionTextureParam.Wrap);

				data.Add(advanceValue2.BlendTextureParams.BlendTextureParam.Filter);
				data.Add(advanceValue2.BlendTextureParams.BlendTextureParam.Wrap);

				data.Add(advanceValue2.BlendTextureParams.BlendAlphaTextureParam.Filter);
				data.Add(advanceValue2.BlendTextureParams.BlendAlphaTextureParam.Wrap);

				data.Add(advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.Filter);
				data.Add(advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.Wrap);
			}

			data.Add(value.ZTest.GetValue() ? 1.GetBytes() : 0.GetBytes());
			data.Add(value.ZWrite.GetValue() ? 1.GetBytes() : 0.GetBytes());

			data.Add(value.FadeInType);
			if (value.FadeInType.Value == Data.RendererCommonValues.FadeType.Use)
			{
				data.Add(value.FadeIn.Frame.GetBytes());

				var easing = Utl.MathUtl.Easing((float)value.FadeIn.StartSpeed.Value, (float)value.FadeIn.EndSpeed.Value);
				data.Add(BitConverter.GetBytes(easing[0]));
				data.Add(BitConverter.GetBytes(easing[1]));
				data.Add(BitConverter.GetBytes(easing[2]));
			}

			data.Add(value.FadeOutType);
			if (value.FadeOutType.Value == Data.RendererCommonValues.FadeType.Use)
			{
				data.Add(value.FadeOut.Frame.GetBytes());

				var easing = Utl.MathUtl.Easing((float)value.FadeOut.StartSpeed.Value, (float)value.FadeOut.EndSpeed.Value);
				data.Add(BitConverter.GetBytes(easing[0]));
				data.Add(BitConverter.GetBytes(easing[1]));
				data.Add(BitConverter.GetBytes(easing[2]));
			}

			data.Add(new BasicUvSerializer(value).SerializeUv(texInfo));


			if (version >= ExporterVersion.Ver16Alpha1)
			{
				// alpha texture
				data.Add(GetUVBytes
				(
				alphaTexInfo,
				advanceValue.AlphaTextureParam.UV,
				advanceValue.AlphaTextureParam.UVFixed,
				advanceValue.AlphaTextureParam.UVAnimation,
				advanceValue.AlphaTextureParam.UVScroll,
				advanceValue.AlphaTextureParam.UVFCurve
				));

				// uv distortion texture
				data.Add(GetUVBytes
				(
				uvDistortionTexInfo,
				advanceValue.UVDistortionTextureParam.UV,
				advanceValue.UVDistortionTextureParam.UVFixed,
				advanceValue.UVDistortionTextureParam.UVAnimation,
				advanceValue.UVDistortionTextureParam.UVScroll,
				advanceValue.UVDistortionTextureParam.UVFCurve
				));

				// uv distortion intensity
				data.Add(advanceValue.UVDistortionTextureParam.UVDistortionIntensity.GetBytes());

				// blend texture
				data.Add(GetUVBytes
				(
				blendTexInfo,
				advanceValue2.BlendTextureParams.BlendTextureParam.UV,
				advanceValue2.BlendTextureParams.BlendTextureParam.UVFixed,
				advanceValue2.BlendTextureParams.BlendTextureParam.UVAnimation,
				advanceValue2.BlendTextureParams.BlendTextureParam.UVScroll,
				advanceValue2.BlendTextureParams.BlendTextureParam.UVFCurve
				));

				// blend texture blend type
				if (advanceValue2.EnableBlendTexture && advanceValue2.BlendTextureParams.BlendTextureParam.Texture.RelativePath != string.Empty)
				{
					data.Add(advanceValue2.BlendTextureParams.BlendTextureParam.BlendType);
				}
				else
				{
					data.Add((-1).GetBytes());
				}

				// blend alpha texture
				data.Add(GetUVBytes
				(
					blendAlphaTexInfo,
					advanceValue2.BlendTextureParams.BlendAlphaTextureParam.UV,
					advanceValue2.BlendTextureParams.BlendAlphaTextureParam.UVFixed,
					advanceValue2.BlendTextureParams.BlendAlphaTextureParam.UVAnimation,
					advanceValue2.BlendTextureParams.BlendAlphaTextureParam.UVScroll,
					advanceValue2.BlendTextureParams.BlendAlphaTextureParam.UVFCurve
				));

				// blend uv distoriton texture
				data.Add(GetUVBytes
				(
					blendUVDistortionTexInfo,
					advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.UV,
					advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.UVFixed,
					advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.UVAnimation,
					advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.UVScroll,
					advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.UVFCurve
				));

				// blend uv distoriton intensity
				data.Add(advanceValue2.BlendTextureParams.BlendUVDistortionTextureParam.UVDistortionIntensity.GetBytes());
			}


			// Inheritance
			data.Add(value.ColorInheritType.GetValueAsInt().GetBytes());

			// Distortion
			data.Add(value.DistortionIntensity.GetBytes());

			// Custom data1 from 1.5
			data.Add(value.CustomData1.CustomData);
			if (value.CustomData1.CustomData.Value == Data.CustomDataType.Fixed2D)
			{
				data.Add(BitConverter.GetBytes(value.CustomData1.Fixed.X.Value));
				data.Add(BitConverter.GetBytes(value.CustomData1.Fixed.Y.Value));
			}
			else if (value.CustomData1.CustomData.Value == Data.CustomDataType.Random2D)
			{
				var value_ = value.CustomData1.Random;
				var bytes1 = value_.GetBytes(1.0f);
				data.Add(bytes1);
			}
			else if (value.CustomData1.CustomData.Value == Data.CustomDataType.Easing2D)
			{
				var easing = Utl.MathUtl.Easing((float)value.CustomData1.Easing.StartSpeed.Value, (float)value.CustomData1.Easing.EndSpeed.Value);

				List<byte[]> _data = new List<byte[]>();
				_data.Add(value.CustomData1.Easing.Start.GetBytes(1.0f));
				_data.Add(value.CustomData1.Easing.End.GetBytes(1.0f));
				_data.Add(BitConverter.GetBytes(easing[0]));
				_data.Add(BitConverter.GetBytes(easing[1]));
				_data.Add(BitConverter.GetBytes(easing[2]));
				var __data = _data.ToArray().ToArray();
				data.Add(__data);
			}
			else if (value.CustomData1.CustomData.Value == Data.CustomDataType.FCurve2D)
			{
				var value_ = value.CustomData1.FCurve;
				var bytes1 = value_.GetBytes();
				data.Add(bytes1);
			}
			else if (value.CustomData1.CustomData.Value == Data.CustomDataType.Fixed4D)
			{
				data.Add(BitConverter.GetBytes(value.CustomData1.Fixed4.X.Value));
				data.Add(BitConverter.GetBytes(value.CustomData1.Fixed4.Y.Value));
				data.Add(BitConverter.GetBytes(value.CustomData1.Fixed4.Z.Value));
				data.Add(BitConverter.GetBytes(value.CustomData1.Fixed4.W.Value));
			}
			else if (value.CustomData1.CustomData.Value == Data.CustomDataType.FCurveColor)
			{
				var bytes = value.CustomData1.FCurveColor.GetBytes();
				data.Add(bytes);
			}

			// Custom data2 from 1.5
			data.Add(value.CustomData2.CustomData);
			if (value.CustomData2.CustomData.Value == Data.CustomDataType.Fixed2D)
			{
				data.Add(BitConverter.GetBytes(value.CustomData2.Fixed.X.Value));
				data.Add(BitConverter.GetBytes(value.CustomData2.Fixed.Y.Value));
			}
			else if (value.CustomData2.CustomData.Value == Data.CustomDataType.Random2D)
			{
				var value_ = value.CustomData2.Random;
				var bytes1 = value_.GetBytes(1.0f);
				data.Add(bytes1);
			}
			else if (value.CustomData2.CustomData.Value == Data.CustomDataType.Easing2D)
			{
				var easing = Utl.MathUtl.Easing((float)value.CustomData2.Easing.StartSpeed.Value, (float)value.CustomData2.Easing.EndSpeed.Value);

				List<byte[]> _data = new List<byte[]>();
				_data.Add(value.CustomData2.Easing.Start.GetBytes(1.0f));
				_data.Add(value.CustomData2.Easing.End.GetBytes(1.0f));
				_data.Add(BitConverter.GetBytes(easing[0]));
				_data.Add(BitConverter.GetBytes(easing[1]));
				_data.Add(BitConverter.GetBytes(easing[2]));
				var __data = _data.ToArray().ToArray();
				data.Add(__data);
			}
			else if (value.CustomData2.CustomData.Value == Data.CustomDataType.FCurve2D)
			{
				var value_ = value.CustomData2.FCurve;
				var bytes1 = value_.GetBytes();
				data.Add(bytes1);
			}
			else if (value.CustomData2.CustomData.Value == Data.CustomDataType.Fixed4D)
			{
				data.Add(BitConverter.GetBytes(value.CustomData2.Fixed4.X.Value));
				data.Add(BitConverter.GetBytes(value.CustomData2.Fixed4.Y.Value));
				data.Add(BitConverter.GetBytes(value.CustomData2.Fixed4.Z.Value));
				data.Add(BitConverter.GetBytes(value.CustomData2.Fixed4.W.Value));
			}
			else if (value.CustomData2.CustomData.Value == Data.CustomDataType.FCurveColor)
			{
				var bytes = value.CustomData2.FCurveColor.GetBytes();
				data.Add(bytes);
			}

			if (version >= ExporterVersion.Ver16Alpha1)
			{
				data.Add(AlphaCutoffValues.GetBytes(advanceValue.AlphaCutoffParam, version));
			}

			if (version >= ExporterVersion.Ver16Alpha3)
			{
				if (advanceValue.EnableFalloff)
				{
					data.Add((1).GetBytes());

					data.Add(advanceValue.FalloffParam.ColorBlendType);
					data.Add(advanceValue.FalloffParam.BeginColor);
					data.Add(advanceValue.FalloffParam.EndColor);
					data.Add(BitConverter.GetBytes(advanceValue.FalloffParam.Pow.Value));
				}
				else
				{
					data.Add((0).GetBytes());
				}
			}

			return data.ToArray().ToArray();
		}


		public static byte[] GetUVBytes(TextureInformation _TexInfo,
			Data.Value.Enum<Data.RendererCommonValues.UVType> _UVType,
			Data.RendererCommonValues.UVFixedParamater _Fixed,
			Data.RendererCommonValues.UVAnimationParamater _Animation,
			Data.RendererCommonValues.UVScrollParamater _Scroll,
			Data.RendererCommonValues.UVFCurveParamater _FCurve)
		{
			var serializer = new AdvancedUvSerializer(_UVType, _Fixed, _Animation, _Scroll, _FCurve);
			return serializer.SerializeUv(_TexInfo);
		}
	}
}
