#pragma once
#include "GuiFramework/System/GUIObject.h"
#include "GuiFramework/Render/GUIRenderContext.h"

namespace GuiFramework
{
	class GUITextureBase : public GUIObject
	{
	public:
		GUITextureBase() : GUIObject() {}
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITextureBase() {}
		virtual dl_uint GetWidth() = 0;
		virtual dl_uint GetHeight() { return 0; }
		virtual dl_uint GetDepth() { return 0; }
		virtual dl_int GetTextureFormat() { return -1; }
		virtual dl_int GetFormat() { return 0x86; }
		virtual dl_int GetMipMapLevel() { return 0; }
		virtual dl_int Apply(GraphicsContext& gc) { return 0; }
	};
}