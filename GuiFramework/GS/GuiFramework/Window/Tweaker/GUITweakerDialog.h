#pragma once
#include "GuiFramework/Window/Control/GUIAutoVLayoutScroll.h"
#include "GUITweakerGroup.h"

namespace GuiFramework
{
	class GUITweakerDialog : public GUIAutoVLayoutScroll
	{
		typedef GUITweakerDialog ThisClass;
		typedef GUIAutoVLayoutScroll SuperClass;
	public:
		GUITweakerDialog() {}
		GUITweakerDialog(TGUISharedString<dl_wchar> label);
		GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, const _GUI_CREATE_WINDOW&);
		GUITweakerDialog(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, dl_uint flags = 0x51502);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerDialog() override;
		virtual void OnDelete() override;
		virtual dl_uint OnMouseWheel(const MouseEvent& event) override;
		virtual dl_uint OnUpdate(dl_float32 fDeltaTime) override;
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnClose() override;

		GUITweakerGroup* GetCurrentGroup();

		GUITweakerGroup* BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags = 0);
		void EndGroup();

		TGUIColorTweaker<DLMT::DL_COLOR_32>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags = 0);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags = 0);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags = 0);

		GUITextureList* CreateTextureList(TGUISharedString<dl_wchar> label);
		GUITextureViewer* CreateTextureViewer(TGUISharedString<dl_wchar> label, GUITextureBase* pTexture);

		GUITriggerTweaker* CreateTrigger(TGUISharedString<dl_wchar> label);

		template<typename T>
		TGUIComboTweaker<T>* CreateComboTweaker(TGUISharedString<dl_wchar> label, T* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<T>* items)
		{
			GUITweakerGroup* pGroup = GetCurrentGroup();

			DL_ASSERT(pGroup, L"No tweaker group was created. Create one before calling this.");

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateComboTweaker(label, v, numItems, items);
		}

		template<typename T>
		TGUIMultiTweaker<T>* CreateMultiTweaker(TGUISharedString<dl_wchar> label, dl_uint numValues, T* v, T min, T max, T step, dl_float32 mult = 1.f)
		{
			GUITweakerGroup* pGroup = GetCurrentGroup();

			DL_ASSERT(pGroup, L"No tweaker group was created. Create one before calling this.");

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateMultiTweaker(label, numValues, v, min, max, step, mult);
		}

		template<typename T>
		TGUIOnOffTweaker<T>* CreateOnOffTweaker(TGUISharedString<dl_wchar> label, T* v)
		{
			GUITweakerGroup* pGroup = GetCurrentGroup();

			DL_ASSERT(pGroup, L"No tweaker group was created. Create one before calling this.");

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateOnOffTweaker(label, v);
		}
		
		template<typename T>
		TGUIProxyOnOffTweaker<T>* CreateProxyOnOffTweaker(TGUISharedString<dl_wchar> label, T* v)
		{
			GUITweakerGroup* pGroup = GetCurrentGroup();

			DL_ASSERT(pGroup, L"No tweaker group was created. Create one before calling this.");

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateProxyOnOffTweaker(label, v);
		}

		template<typename T>
		TGUIPropertyLabel<T>* CreatePropertyLabel(TGUISharedString<dl_wchar> label, T* v)
		{
			GUITweakerGroup* pGroup = GetCurrentGroup();

			DL_ASSERT(pGroup, L"No tweaker group was created. Create one before calling this.");

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreatePropertyLabel(label, v);
		}

		template<typename T>
		TGUIRangeTweaker<T>* CreateTweaker(TGUISharedString<dl_wchar> label, T* pValue, T min, T max, T step, dl_float32 mult = 1.f)
		{
			GUITweakerGroup* pGroup = GetCurrentGroup();

			DL_ASSERT(pGroup, L"No tweaker group was created. Create one before calling this.");

			if (pGroup == nullptr)
				return nullptr;

			return pGroup->CreateTweaker(label, pValue, min, max, step, mult);
		}

	private:
		DLUT::DLVector<GUITweakerGroupItem*> m_items;
		DLUT::DLVector<GUITweakerGroup*> m_groups;
	};
}