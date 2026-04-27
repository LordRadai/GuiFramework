#pragma once
#include "GuiFramework/System/GUIObject.h"
#include "GuiFramework/System/TGUISharedString.inl"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/TGUIObjectPtr.inl"

namespace GuiFramework
{
	class GUIListBox;

	class GUIListBoxItem : public GUIObject
	{
		typedef GUIListBoxItem ThisClass;
		typedef GUIObject SuperClass;
	public:
		GUIListBoxItem();
		GUIListBoxItem(TGUISharedString<dl_wchar> label, dl_float32 param_2);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIListBoxItem() override;
		virtual void OnDelete() override;
		virtual Rect GetSize() const;

		typedef Rect(__fastcall* GetSize_t)(const GUIListBoxItem*);
	protected:
		TGUIObjectPtr<GUIListBox> m_pListBox;
		TGUISharedString<dl_wchar> m_label;
		dl_uint m_iVar28;
		dl_float32 m_fVar2C;
	};
}