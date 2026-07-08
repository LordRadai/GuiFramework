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
        DL_ASSERT(!m_groups.empty(), L"Begin/end group mismatch");

		while (!m_groups.empty())
			_PopGroup();

        m_groups.clear();
	}

	GUITweakerGroup* GUITweakerMaker::BeginGroup(TGUISharedString<dl_wchar> label, dl_uint flags)
	{
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

		GUITweakerGroup* pCurrentGroup = this->GetCurrentGroup();

        if (pCurrentGroup == nullptr)
			return nullptr;

		GUITweakerGroupItem* pNewGroup = pCurrentGroup->CreateSubGroup(label, flags);
		GUITweakerGroup* pGroup = pNewGroup->GetGroup();

		_PushGroup(pGroup);

		return pGroup;
	}

	void GUITweakerMaker::EndGroup()
	{
        DL_ASSERT(!m_groups.empty(), L"Begin/end group mismatch!");

		_PopGroup();
	}

	GUITweakerGroup* GUITweakerMaker::GetCurrentGroup()
	{
        return this->m_groups.back();
    }

    void GUITweakerMaker::AddItem(GUITweakerGroupItem* pItem)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

        if (pItem == nullptr)
            return;

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        pGroup->AddItem(pItem);
	}

    void GUITweakerMaker::SetFirstOpenCallback(GUITweakerGroup::FirstOpenCallback_t pCallback, dl_size param1, dl_size param2)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

		pGroup->SetFirstOpenCallback(pCallback, param1, param2);
    }

    TGUIColorTweaker<DLMT::DL_COLOR_32>* GUITweakerMaker::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_COLOR_32* v, dl_uint flags)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

		return pGroup->CreateColorTweaker(label, v, flags);
    }

    TGUIColorTweaker<DLMT2::DL_COLOR_U8>* GUITweakerMaker::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT2::DL_COLOR_U8* v, dl_uint flags)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

		return pGroup->CreateColorTweaker(label, v, flags);
    }

    TGUIColorTweaker<DLMT::DL_VECTOR4>* GUITweakerMaker::CreateColorTweaker(TGUISharedString<dl_wchar> label, DLMT::DL_VECTOR4* v, dl_uint flags)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

		return pGroup->CreateColorTweaker(label, v, flags);
    }

    GUITextureList* GUITweakerMaker::CreateTextureList(TGUISharedString<dl_wchar> label)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

        return pGroup->CreateTextureList(label);
	}

    GUITextureViewer* GUITweakerMaker::CreateTextureViewer(TGUISharedString<dl_wchar> label, GUITextureBase* pTexture)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

		GUITweakerGroup* pGroup = this->GetCurrentGroup();

		return pGroup->CreateTextureViewer(label, pTexture);
    }

    GUITriggerTweaker* GUITweakerMaker::CreateTrigger(TGUISharedString<dl_wchar> label)
    {
        DL_ASSERT(!this->m_groups.empty(), L"no group!");

        GUITweakerGroup* pGroup = this->GetCurrentGroup();

        return pGroup->CreateTrigger(label);
    }

    void GUITweakerMaker::_PushGroup(GUITweakerGroup* pGroup)
    {
        m_groups.push_back(pGroup);
    }

    void GUITweakerMaker::_PopGroup()
    {        
        m_groups.pop_back();
	}
}