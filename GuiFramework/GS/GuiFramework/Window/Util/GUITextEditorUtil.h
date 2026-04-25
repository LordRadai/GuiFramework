#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/System/GUISystem.h"
#include "GuiFramework/System/GUIFont.h"

namespace GuiFramework
{
	class GUITextEditorUtil : public GUIMsgReceiver
	{
		typedef GUITextEditorUtil ThisClass;
		typedef GUIMsgReceiver SuperClass;
	public:
		GUITextEditorUtil() {}
		GUITextEditorUtil(GUISystem* pGUISystem);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITextEditorUtil() override;
		virtual void OnDelete() override;

		dl_uint Copy();
		dl_uint Cut();
		dl_uint Paste();
		dl_uint SelectAll();
		dl_uint Insert(const dl_wchar* str);
		const dl_wchar* GetLineString(dl_uint lineIndex) const;
		dl_uint OnDragMove(dl_uint x, dl_uint y);
		dl_uint DeleteAll();
	protected:
		dl_uint _Insert(const dl_wchar* str, dl_uint size);

		TGUIObjectPtr<GUISystem> m_pSystem;
		DLUT::DLVector<dl_wchar*> m_lines;
		TGUIObjectPtr<GUIFont> m_pFont;
		dl_int m_iVar40;
		dl_int m_selectionStart;
		dl_int m_iVar48;
		dl_int m_selectionEnd;
		dl_int m_iVar50;
		dl_int m_iVar54;
		dl_int m_iVar58;
		dl_int m_iVar5C;
		dl_int m_iVar60;
		dl_int m_iVar64;
	};
}