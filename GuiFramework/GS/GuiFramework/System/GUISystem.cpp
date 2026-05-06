#include "GUISystem.h"

namespace GuiFramework
{
	typedef void(__fastcall* GUISystem_ctor_t)(GUISystem*);

	typedef void(__fastcall* GUISystem_Connect_t)(GUISystem*, GUIObject*, GUISignalDecl, GUIMsgReceiver*, DLRF::DLMethodResolver<DLRF::DLMethodInvokeContext>*, dl_uint, dl_uint);
	typedef void(__fastcall* GUISystem_CreateTweaker_t)(GUISystem*, GUITweakerDialog*);

	typedef dl_bool(__fastcall* SetAfterWindow_t)(GUISystem*, GUIWindowBase*, GUIWindowBase*);
	typedef dl_int(__fastcall* RegisterWindow_t)(GUISystem*, GUIWindowBase*);

	typedef dl_int(__fastcall* SetFocus_t)(GUISystem*, GUIWindowBase*);

	GUISystem::GUISystem()
	{
		CALL(GUISystem_ctor_t, 0x528580, this);
	}

	GUISystem::~GUISystem()
	{
		CALL(Destructor_t, 0x52dfb0, this);
	}

	void GUISystem::Finalize()
	{
		CALL(Finalize_t, 0x52a190, this);
	}

	TGUI_RECT<int> GUISystem::GetMouseInfo()
	{
		return CALL(GetMouseInfo_t, 0x52a960, this);
	}

	GUIRootWindow* GUISystem::CreateRootWindow()
	{
		return CALL(CreateRootWindow_t, 0x52a9f0, this);
	}

	void GUISystem::MeasureTextExtent(Point2D& out)
	{
		CALL(MeasureTextExtent_t, 0x52aa70, this, out);
	}

	void GUISystem::SetClipboard(const dl_wchar* text)
	{
		CALL(SetClipboard_t, 0x52b4e0, this, text);
	}

	dl_bool GUISystem::GetClipboard(DLTX::DLString& out)
	{
		return CALL(GetClipboard_t, 0x52b570, this, out);
	}

	void GUISystem::Connect(GUIObject* pOwner, GUISignalDecl pSignalDeclaration, GUIMsgReceiver* pReceiver, DLRF::DLMethodResolver<DLRF::DLMethodInvokeContext>* pResolver, dl_uint param_5, dl_uint param_6)
	{
		CALL(GUISystem_Connect_t, 0x52a7a0, this, pOwner, pSignalDeclaration, pReceiver, pResolver, param_5, param_6);
	}
	
	void GUISystem::CreateTweaker(GUITweakerDialog* pWnd)
	{
		CALL(GUISystem_CreateTweaker_t, 0x52b640, this, pWnd);
	}

	dl_bool GUISystem::SetAfterWindow(GUIWindowBase* pWindow, GUIWindowBase* pAfter)
	{
		return CALL(SetAfterWindow_t, 0x52a570, this, pWindow, pAfter);
	}

	dl_int GUISystem::RegisterWindow(GUIWindowBase* pWindow)
	{
		return CALL(RegisterWindow_t, 0x52a490, this, pWindow);
	}

	dl_int GUISystem::SetFocus(GUIWindowBase* pWindow)
	{
		return CALL(SetFocus_t, 0x52a510, this, pWindow);
	}
}