#include "GUISystem.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUISystem_ctor_t)(GUISystem*);

	typedef void(__fastcall* GUISystem_dtor_t)(GUISystem*);
	typedef void(__fastcall* GUISystem_Finalize_t)(GUISystem*);
	typedef TGUI_RECT<int>(__fastcall* GUISystem_GetMouseInfo_t)(GUISystem*);
	typedef GUIRootWindow* (__fastcall* GUISystem_CreateRootWindow_t)(GUISystem*);
	typedef void(__fastcall* GUISystem_MeasureTextExtent_t)(GUISystem*, TGUI_POINT<int>*);
	typedef void(__fastcall* GUISystem_SetClipboard_t)(GUISystem*, const dl_wchar*);
	typedef dl_bool(__fastcall* GUISystem_GetClipboard_t)(GUISystem*, DLTX::DLString*);

	typedef void(__fastcall* GUISystem_Connect_t)(GUISystem*, GUIObject*, GUISignal::GUISignalDecl, GUIMsgReceiver*, DLRF::DLMethodResolver<DLRF::DLMethodInvokeContext>*, dl_uint, dl_uint);
	typedef void(__fastcall* GUISystem_CreateTweaker_t)(GUISystem*, GUITweakerDialog*);

	GUISystem::GUISystem()
	{
		CALL(GUISystem_ctor_t, 0x528580, this);
	}

	GUISystem::~GUISystem()
	{
		CALL(GUISystem_dtor_t, 0x52dfb0, this);
	}

	void GUISystem::Finalize()
	{
		CALL(GUISystem_Finalize_t, 0x52a190, this);
	}

	TGUI_RECT<int> GUISystem::GetMouseInfo()
	{
		return CALL(GUISystem_GetMouseInfo_t, 0x52a960, this);
	}

	GUIRootWindow* GUISystem::CreateRootWindow()
	{
		return CALL(GUISystem_CreateRootWindow_t, 0x52a9f0, this);
	}

	void GUISystem::MeasureTextExtent(Point2D* out)
	{
		CALL(GUISystem_MeasureTextExtent_t, 0x52aa70, this, out);
	}

	void GUISystem::SetClipboard(const dl_wchar* text)
	{
		CALL(GUISystem_SetClipboard_t, 0x52b4e0, this, text);
	}

	dl_bool GUISystem::GetClipboard(DLTX::DLString* out)
	{
		return CALL(GUISystem_GetClipboard_t, 0x52b570, this, out);
	}

	void GUISystem::Connect(GUIObject* pOwner, GUISignal::GUISignalDecl pSignalDeclaration, GUIMsgReceiver* pReceiver, DLRF::DLMethodResolver<DLRF::DLMethodInvokeContext>* pResolver, dl_uint param_5, dl_uint param_6)
	{
		CALL(GUISystem_Connect_t, 0x52a7a0, this, pOwner, pSignalDeclaration, pReceiver, pResolver, param_5, param_6);
	}
	
	void GUISystem::CreateTweaker(GUITweakerDialog* pWnd)
	{
		CALL(GUISystem_CreateTweaker_t, 0x52b640, this, pWnd);
	}
}