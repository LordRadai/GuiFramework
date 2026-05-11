#pragma once
#include "GUITweakerGroup.h"
#include "GUITweakerDialog.h"

namespace GuiFramework
{
	class GUITweakerMaker
	{
	public:
		GUITweakerMaker(GUITweakerMaker* pTweakerMaker);
		GUITweakerMaker(GUITweakerGroup* pGroup);
		GUITweakerMaker(GUITweakerDialog* pDialog);

		~GUITweakerMaker();

		GUITweakerGroup* BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags);
		void EndGroup();
		GUITweakerGroup* GetCurrentGroup();

		void AddItem(GUITweakerGroupItem* pItem);
		void SetFirstOpenCallback(GUITweakerGroup::FirstOpenCallback_t pCallback, dl_size param1, dl_size param2);

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags);

		GUITextureList* CreateTextureList(TGUISharedString<dl_wchar> label);
		GUITextureViewer* CreateTextureViewer(TGUISharedString<dl_wchar> label, GUITextureBase* pTexture);

		GUITriggerTweaker* CreateTrigger(TGUISharedString<dl_wchar> label);

		template<typename T>
		TGUIComboTweaker<T>* CreateComboTweaker(TGUISharedString<dl_wchar> label, T* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<T>* items)
		{
			DL_ASSERT(!this->m_groups.empty());

			GUITweakerGroup* pGroup = this->GetCurrentGroup();

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateComboTweaker<T>(label, v, numItems, items);
		}

		template<typename T>
		TGUIMultiTweaker<T>* CreateMultiTweaker(TGUISharedString<dl_wchar> label, dl_uint numValues, T* v, T min, T max, T step, dl_float32 mult = 1.f)
		{
			DL_ASSERT(!this->m_groups.empty());

			GUITweakerGroup* pGroup = this->GetCurrentGroup();

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateMultiTweaker<T>(label, numValues, v, min, max, step, mult);
		}

		template<typename T>
		TGUIOnOffTweaker<T>* CreateOnOffTweaker(TGUISharedString<dl_wchar> label, T* v)
		{
			DL_ASSERT(!this->m_groups.empty());

			GUITweakerGroup* pGroup = this->GetCurrentGroup();

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateOnOffTweaker<T>(label, v);
		}

		template<typename T>
		TGUIProxyOnOffTweaker<T>* CreateProxyOnOffTweaker(TGUISharedString<dl_wchar> label, T* v)
		{
			DL_ASSERT(!this->m_groups.empty());

			GUITweakerGroup* pGroup = this->GetCurrentGroup();

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateProxyOnOffTweaker<T>(label, v);
		}

		template<typename T>
		TGUIPropertyLabel<T>* CreatePropertyLabel(TGUISharedString<dl_wchar> label, T* v)
		{
			DL_ASSERT(!this->m_groups.empty());

			GUITweakerGroup* pGroup = this->GetCurrentGroup();

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreatePropertyLabel<T>(label, v);
		}

		template<typename T>
		TGUIRangeTweaker<T>* CreateTweaker(TGUISharedString<dl_wchar> label, T* pValue, T min, T max, T step, dl_float32 mult = 1.f)
		{
			DL_ASSERT(!this->m_groups.empty());

			GUITweakerGroup* pGroup = this->GetCurrentGroup();

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateTweaker<T>(label, pValue, min, max, step, mult);
		}
	protected:
		void _PushGroup(GUITweakerGroup* pGroup);
		void _PopGroup();

		DLUT::DLVector<GUITweakerGroup*> m_groups;
	};
}