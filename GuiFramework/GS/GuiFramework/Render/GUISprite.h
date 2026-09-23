#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	struct GUI_SPRITE_RECT
	{
		DLMT::DL_VECTOR4AL Min;
		DLMT::DL_VECTOR4AL Max;
		DLMT::DL_COLOR_32 Color;

		GUI_SPRITE_RECT(dl_float32 minX, dl_float32 minY, dl_float32 maxX, dl_float32 maxY, DLMT::DL_COLOR_32 color)
			: Min(minX, minY, 0.0f, 0.0f), Max(maxX, maxY, 0.0f, 0.0f), Color(color) {}
	};

	struct GUI_SPRITE_GOURAUD_RECT
	{
		DLMT::DL_VECTOR4AL Min;
		DLMT::DL_VECTOR4AL Max;
		DLMT::DL_COLOR_32 Color0;
		DLMT::DL_COLOR_32 Color1;
		DLMT::DL_COLOR_32 Color2;
		DLMT::DL_COLOR_32 Color3;

		GUI_SPRITE_GOURAUD_RECT(dl_float32 minX, dl_float32 minY, dl_float32 maxX, dl_float32 maxY,
			DLMT::DL_COLOR_32 color0, DLMT::DL_COLOR_32 color1, DLMT::DL_COLOR_32 color2, DLMT::DL_COLOR_32 color3)
			: Min(minX, minY, 0.0f, 0.0f), Max(maxX, maxY, 0.0f, 0.0f),
			Color0(color0), Color1(color1), Color2(color2), Color3(color3) {}
	};
}