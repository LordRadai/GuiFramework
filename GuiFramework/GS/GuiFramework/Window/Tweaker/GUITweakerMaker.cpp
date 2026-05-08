#include "GUITweakerMaker.h"

namespace GuiFramework
{
	GUITweakerMaker::GUITweakerMaker(GUITweakerMaker* pTweakerMaker)
	{
        if (pTweakerMaker == nullptr)
            return;

        _PushGroup(pTweakerMaker->GetCurrentGroup());
	}

	GUITweakerMaker::GUITweakerMaker(GUITweakerGroup* pGroup)
	{
        if (pGroup == nullptr)
            return;

		_PushGroup(pGroup);
	}

	GUITweakerMaker::GUITweakerMaker(GUITweakerDialog* pDialog)
	{
        if (pDialog == nullptr)
            return;

		_PushGroup(pDialog->GetCurrentGroup());
	}

    GUITweakerMaker::~GUITweakerMaker()
    {
        DL_ASSERT(m_groups.size() <= 1);

        if (m_groups.size() == 1)
        {
            GUITweakerGroup* pBack = m_groups.back();

            if (pBack != nullptr)
                pBack->UnRef();

            m_groups.pop_back();
        }

        for (auto* pGroup : m_groups)
        {
            if (pGroup != nullptr)
                pGroup->UnRef();
        }

        m_groups.clear();
	}

	GUITweakerGroup* GUITweakerMaker::BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags)
	{
        DL_ASSERT(!this->m_groups.empty());

		GUITweakerGroup* pCurrentGroup = this->GetCurrentGroup();

        if (pCurrentGroup == nullptr)
			return nullptr;

		GUITweakerGroup* pNewGroup = pCurrentGroup->CreateSubGroup(label, flags);

		_PushGroup(pNewGroup);

		return pNewGroup;
	}

	void GUITweakerMaker::EndGroup()
	{
		_PopGroup();
	}

	GUITweakerGroup* GUITweakerMaker::GetCurrentGroup()
	{
        return this->m_groups.back();
    }

    void GUITweakerMaker::AddItem(GUITweakerGroupItem* pItem)
    {
        DL_ASSERT(!this->m_groups.empty());

        if (pItem == nullptr)
            return;

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return;

        pGroup->AddItem(pItem);
	}

    void GUITweakerMaker::SetFirstOpenCallback(GUITweakerGroup::FirstOpenCallback_t pCallback, dl_size param1, dl_size param2)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return;

		pGroup->SetFirstOpenCallback(pCallback, param1, param2);
    }

    TGUIColorTweaker<DLMT::DL_COLOR_32>* GUITweakerMaker::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return nullptr;

		return pGroup->CreateColorTweaker(label, v, flags);
    }

    TGUIColorTweaker<DLMT2::DL_COLOR_U8>* GUITweakerMaker::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags)
    {
        DL_ASSERT(!this->m_groups.empty());

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateColorTweaker(label, v, flags);
    }

    TGUIColorTweaker<DLMT::DL_VECTOR4>* GUITweakerMaker::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags)
    {
        DL_ASSERT(!this->m_groups.empty());

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateColorTweaker(label, v, flags);
    }

    TGUIComboTweaker<dl_int8>* GUITweakerMaker::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int8>* items)
    {
        DL_ASSERT(!this->m_groups.empty());

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

		if (pGroup == nullptr)
			return nullptr;

		return pGroup->CreateComboTweaker(label, v, numItems, items);
    }

    TGUIComboTweaker<dl_uint8>* GUITweakerMaker::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint8>* items)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return nullptr;

        return pGroup->CreateComboTweaker(label, v, numItems, items);
    }

    TGUIComboTweaker<dl_int16>* GUITweakerMaker::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int16>* items)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return nullptr;

        return pGroup->CreateComboTweaker(label, v, numItems, items);
    }

    TGUIComboTweaker<dl_uint16>* GUITweakerMaker::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint16* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint16>* items)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return nullptr;

        return pGroup->CreateComboTweaker(label, v, numItems, items);
    }

    TGUIComboTweaker<dl_int>* GUITweakerMaker::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_int* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_int>* items)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return nullptr;

        return pGroup->CreateComboTweaker(label, v, numItems, items);
    }

    TGUIComboTweaker<dl_uint8>* GUITweakerMaker::CreateComboTweaker(TGUISharedString<dl_wchar> label, dl_uint8* v, dl_uint numItems, TGUI_COMBO_TWEAKER_ITEM<dl_uint8>* items)
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        if (pGroup == nullptr)
            return nullptr;

        return pGroup->CreateComboTweaker(label, v, numItems, items);
    }

    void GUITweakerMaker::_PushGroup(GUITweakerGroup* pGroup)
    {
		DL_ASSERT(pGroup == nullptr || !m_groups.empty());

        if (pGroup != nullptr)
            pGroup->AddRef();

        if (!m_groups.empty() &&
            m_groups.size() >= m_groups.capacity() &&
            m_groups.capacity() > 20)
        {
            auto it = m_groups.begin();
            while (it != m_groups.end())
            {
                if ((*it)->IsFlagSet(2))
                {
                    ++it;
                    continue;
                }

                auto dst = it;
                auto src = it + 1;
                while (src != m_groups.end())
                {
                    if (*src != *dst)
                    {
                        if (*dst != nullptr)
                            (*dst)->UnRef();
                        *dst = *src;
                        if (*src != nullptr)
                            (*src)->AddRef();
                    }
                    ++dst;
                    ++src;
                }

                if (m_groups.back() != nullptr)
                    m_groups.back()->UnRef();

                m_groups.pop_back();
            }
        }

        m_groups.push_back(pGroup);

        if (pGroup != nullptr)
            pGroup->UnRef();
    }

    void GUITweakerMaker::_PopGroup()
    {
        DL_ASSERT(!this->m_groups.empty());

        GUITweakerGroup* pBack = m_groups.back();

        if (pBack != nullptr)
            pBack->UnRef();

        m_groups.pop_back();
	}
}