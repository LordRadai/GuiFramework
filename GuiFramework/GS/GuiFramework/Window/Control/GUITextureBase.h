#pragma once
#include "GuiFramework/System/GUIObject.h"
#include "GuiFramework/Render/GUIRenderImplBase.h"

namespace GuiFramework
{
	enum GUI_TEXTURE_TYPE : dl_int
	{
		GUITEXTYPE_INVALID = -1,
		GUITEXTYPE_NONE,
		GUITEXTYPE_CUBE,
		GUITEXTYPE_2,
		GUITEXTYPE_3,
		GUITEXTYPE_2D,

		GUITEXTYPE_NUM
	};

	class GUITextureBase : public GUIObject
	{
	public:
		GUITextureBase() : GUIObject() {}
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITextureBase() {}
		virtual dl_uint GetWidth() = 0;
		virtual dl_uint GetHeight() { return 0; }
		virtual dl_uint GetDepth() { return 0; }
		virtual dl_int GetTextureType() { return -1; }
		virtual dl_int GetFormat() { return 0x86; }
		virtual dl_uint GetMipMapLevelNum() { return 0; }
		virtual dl_bool Apply(dl_uint mipLevel, GUIRenderImplBase* pRenderImpl) { return false; }
	};
}