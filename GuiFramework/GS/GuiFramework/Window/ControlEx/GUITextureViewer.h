#pragma once
#include "GuiFramework/Window/GUIWidget.h"
#include "GuiFramework/Window/Control/GUITextureBase.h"

namespace GuiFramework
{
	class GUITextureViewer : public GUIWidget
	{
	public:
		enum FLAGS : dl_uint
		{
		};

		enum FIT_MODE : dl_uint
		{
		};

		GUITextureViewer() : GUIWidget() {}
		GUITextureViewer(TGUISharedString<dl_wchar> label);
		GUITextureViewer(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams);
		GUITextureViewer(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4 = 0);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITextureViewer() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnLButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnLButtonUp(const MouseEvent& event) override;
		virtual dl_uint OnRButtonDown(const MouseEvent& event) override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnCommand(dl_uint cmdId) override;
		virtual dl_uint OnSize() override;
		virtual void OnRender(GraphicsContext& gc) const override;

	protected:
		TGUIObjectPtr<GUITextureBase> m_texture;
		dl_int m_zoomLevel;
		dl_uint16 m_iVar11C;
		dl_uint16 m_iVar11E;
		dl_int16 m_mipMapLevel;
		dl_int m_iVar124;
		dl_int m_iVar128;
		dl_int m_iVar12C;
		dl_int m_iVar130;
		dl_uint m_flags;
		dl_uint m_fitMode;
	};
}