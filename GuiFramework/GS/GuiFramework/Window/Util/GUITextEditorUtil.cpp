#include "GUITextEditorUtil.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUITextEditorUtil*, GUISystem*);

	typedef dl_uint(__fastcall* Insert_t)(const GUITextEditorUtil*, const dl_wchar*);
	typedef dl_uint(__fastcall* _Insert_t)(const GUITextEditorUtil*, const dl_wchar*, dl_uint);

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
}