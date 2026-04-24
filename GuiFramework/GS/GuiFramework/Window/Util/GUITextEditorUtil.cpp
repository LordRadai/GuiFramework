#include "GUITextEditorUtil.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(const GUITextEditorUtil*, GUISystem*);

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
}