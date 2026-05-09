#pragma once
#include "GuiFramework/Window/Control/GUIAutoVLayout.h"
#include "GUITweakerGroupItem.h"
#include "TGUIColorTweaker.inl"
#include "TGUIComboTweaker.inl"
#include "TGUIMultiTweaker.inl"

namespace GuiFramework
{
	class GUITweakerGroup : public GUIAutoVLayout
	{
		typedef GUITweakerGroup ThisClass;
		typedef GUIAutoVLayout SuperClass;
	public:
		typedef void(__fastcall* FirstOpenCallback_t)(GUITweakerGroup*, dl_size, dl_size);

		GUITweakerGroup() {}
		GUITweakerGroup(TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerGroup() override;
		virtual void OnDelete() override;
		virtual dl_uint OnRestored() override;
		virtual dl_uint OnClose() override;

		void AddItem(GUITweakerItem* pItem);
		GUITweakerGroup* CreateSubGroup(TGUISharedString<dl_wchar> label, dl_uint flags);

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags);

		template<typename T>
		TGUIComboTweaker<T>* CreateComboTweaker(TGUISharedString<dl_wchar> label, T* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<T>* items)
		{
			TGUIValueStringPairData<T>* data = new TGUIValueStringPairData<T>(items, numItems);
			TGUIComboTweaker<T>* pTweaker = new TGUIComboTweaker<T>(this, label, v, data);

			if (pTweaker)
				this->AddItem(pTweaker);

			return pTweaker;
		}

		template<typename T>
		TGUIMultiTweaker<T>* CreateMultiTweaker(TGUISharedString<dl_wchar> label, dl_uint numValues, T* v, T min, T max, T step, dl_float32 mult = 1.f)
		{
			TGUIMultiTweaker<T>* pTweaker = new TGUIMultiTweaker<T>(this, label, numValues, v, min, max, step, mult);

			if (pTweaker)
				this->AddItem(pTweaker);

			return pTweaker;
		}
		
		void SetFirstOpenCallback(FirstOpenCallback_t pCallback, dl_size param1, dl_size param2);
	protected:
		DLUT::DLVector<GUITweakerGroupItem*> m_items;
		FirstOpenCallback_t m_pRestoredCb;
		dl_size m_cbParam1;
		dl_size m_cbParam2;
		dl_uint m_iVar150;
	};
}
