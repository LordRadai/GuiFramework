#pragma once
#include "GuiFramework/Window/Control/GUIAutoVLayoutScroll.h"

namespace GuiFramework
{
	class GUITweakerGroup;
	class GUITweakerGroupItem;
	class GUIYawPitchTweaker;
	class GUIColorTweaker;

	class GUITweakerDialog : public GUIAutoVLayoutScroll
	{
		typedef GUITweakerDialog ThisClass;
		typedef GUIAutoVLayoutScroll SuperClass;
	public:
		GUITweakerDialog() {}
		GUITweakerDialog(TGUISharedString<dl_wchar> label);
		GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW&);
		GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerDialog() override;
		virtual void OnDelete() override;
		virtual dl_bool OnMouseWheel(const MouseEvent& event) override;
		virtual dl_bool OnUpdate(dl_float32 fDeltaTime) override;
		virtual dl_bool OnCreate() override;
		virtual dl_bool OnClose() override;

		GUITweakerGroup* GetCurrentGroup();

		GUITweakerGroup* BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags);
		void EndGroup();

		GUIYawPitchTweaker* CreateYawPitchTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR2& value, dl_uint flags);

		GUIColorTweaker* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4& value, dl_uint flags);
		GUIColorTweaker* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32& value, dl_uint flags);
	private:
		DLUT::DLVector<GUITweakerGroupItem*> m_items;
		DLUT::DLVector<GUITweakerGroup*> m_groups;
	};
}