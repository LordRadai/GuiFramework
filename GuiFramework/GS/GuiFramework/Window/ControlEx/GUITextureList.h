#pragma once
#include "GUITextureViewer.h"
#include "GuiFramework/Window/Control/GUIListView.h"

namespace GuiFramework
{
	class GUITextureList : public GUIWidget
	{
		typedef GUITextureList ThisClass;
		typedef GUIWidget SuperClass;
	public:
		GUITextureList() : GUIWidget() {}
		GUITextureList(TGUISharedString<dl_wchar> label);
		GUITextureList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW& createParams);
		GUITextureList(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags, dl_uint param_4 = 0);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITextureList() override;
		virtual void OnDelete() override;
		virtual dl_uint OnSize() override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnClose() override;

		dl_uint AddTexture(TGUISharedString<dl_wchar> name, GUITextureBase* pTexture, TGUISharedString<dl_wchar> path);
	protected:
		TGUIObjectPtr<GUITextureViewer> m_pTextureViewer;
		TGUIObjectPtr<GUIListView> m_pListView;
	};
}