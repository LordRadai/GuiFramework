#include "GUITextEditorUtil.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUITextEditorUtil*, GUISystem*);

	typedef dl_uint(__fastcall* Insert_t)(const GUITextEditorUtil*, const dl_wchar*);
	typedef dl_uint(__fastcall* _Insert_t)(const GUITextEditorUtil*, const dl_wchar*, dl_uint);

	typedef dl_uint(__fastcall* Copy_t)(const GUITextEditorUtil*);
	typedef dl_uint(__fastcall* Cut_t)(const GUITextEditorUtil*);
	typedef dl_uint(__fastcall* Paste_t)(const GUITextEditorUtil*);
	typedef dl_uint(__fastcall* SelectAll_t)(const GUITextEditorUtil*);
	typedef const dl_wchar*(__fastcall* GetLineString_t)(const GUITextEditorUtil*, dl_uint);
	typedef dl_uint(__fastcall* OnDragMove_t)(const GUITextEditorUtil*, dl_uint, dl_uint);

	GUITextEditorUtil::GUITextEditorUtil(GUISystem* pGUISystem)
	{
		CALL(Constructor_t, 0x5892b0, this, pGUISystem);
	}

	DLRF::DLRuntimeClass* GUITextEditorUtil::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x589260, this);
	}

	GUITextEditorUtil::~GUITextEditorUtil()
	{
		CALL(Destructor_t, 0x58e750, this);
	}

	void GUITextEditorUtil::OnDelete()
	{
		CALL(OnDelete_t, 0x58e0a0, this);
	}

	dl_uint GUITextEditorUtil::Insert(const dl_wchar* str)
	{
		return CALL(Insert_t, 0x589bd0, this, str);
	}

	dl_uint GUITextEditorUtil::_Insert(const dl_wchar* str, dl_uint size)
	{
		return CALL(_Insert_t, 0x58c650, this, str, size);
	}

	dl_uint GUITextEditorUtil::Copy()
	{
		return CALL(Copy_t, 0x58a0b0, this);
	}

	dl_uint GUITextEditorUtil::Cut()
	{
		return CALL(Cut_t, 0x58a320, this);
	}

	dl_uint GUITextEditorUtil::Paste()
	{
		return CALL(Paste_t, 0x58a2b0, this);
	}

	dl_uint GUITextEditorUtil::SelectAll()
	{
		return CALL(SelectAll_t, 0x58a390, this);
	}

	const dl_wchar* GUITextEditorUtil::GetLineString(dl_uint lineIndex) const
	{
		return CALL(GetLineString_t, 0x58a540, this, lineIndex);
	}

	dl_uint GUITextEditorUtil::OnDragMove(dl_uint x, dl_uint y)
	{
		return CALL(OnDragMove_t, 0x58a5c0, this, x, y);
	}
}