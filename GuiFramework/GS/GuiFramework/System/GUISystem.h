#pragma once
#include "GUIMsgReceiver.h"
#include "TGUIStringStorage.inl"
#include "TGUIRect.inl"
#include "TGUIPoint.inl"

namespace GuiFramework
{
	class GUIWindowManager;
	class GUIWindowPainter;
	class GUIFont;
	class GUITweakerDialog;
	class GUIRootWindow;

	class GUISystem : public GUIMsgReceiver
	{
		class GUISystemEvents
		{
			DLUT::DLVector<dl_pointer> m_pEvents[31];
			DLUT::DLVector<dl_pointer> m_pVar3E0[2];
			dl_int m_state;
		};

	public:
		GUISystem();

		virtual ~GUISystem() override;
		virtual void Finalize();
		virtual TGUI_RECT<int> GetMouseInfo();
		virtual dl_int PopKeyStroke() { return 0; }
		virtual GUIRootWindow* CreateRootWindow();
		virtual dl_int BeginFont() { return 0; }
		virtual void MeasureTextExtent(TGUI_POINT<int>* out);
		virtual void EndFont() {}
		virtual void SetClipboard(const dl_wchar* text);
		virtual dl_bool GetClipboard(DLTX::DLString* out);
		virtual dl_uint GetUserIntNum() const { return 0; }
		virtual dl_uint GetUserFloatNum() const { return 0; }
		virtual dl_uint GetUserColorNum() const { return 0; }
		virtual dl_uint GetUserFontNum() const { return 0; }
		virtual dl_bool SetCursor(dl_uint16 cursorIdx) { return false; }
		virtual void OnPreUpdate(dl_float32 dt) {}
		virtual void OnPostUpdate(dl_float32 dt) {}

		GUIWindowManager* GetWindowManager() const { return m_pGUIWindowManager; }

		//GUITweakerDialog* AddTweakerDialog(const dl_wchar* title, dl_bool bUnique = true, dl_int width = 290, dl_int m_height = 400, dl_uint flags = GuiFramework::GUITweakerBase::GuiStyleFlags_Invisible | GuiFramework::GUITweakerBase::GuiStyleFlags_Titlebar | GuiFramework::GUITweakerBase::GuiStyleFlags_3DFrame | GuiFramework::GUITweakerBase::GuiStyleFlags_VScrollbar | GuiFramework::GUITweakerBase::GuiStyleFlags_Collapse | GuiFramework::GUITweakerBase::GuiStyleFlags_Destroy);
		//GUIPopUpMenuNode* AddPopUpMenuNode(const dl_wchar* title, dl_uint flags = 0);
		//dl_bool IsGUIOpen();

		//void RegisterEvent(GUISystem* param_2, dl_wchar**, GUIMsgReceiver* pItem, DLRF::DLMethodResolver<DLRF::DLMethodInvokeContext>* pDLMethod, dl_uint param_5, dl_uint param_6);
		/*
		* @brief Create GUISystem editor window.
		*/
		//void CreateSystemEditorGUI();

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	protected:
		dl_int m_isDrawing;
		GUIWindowManager* m_pGUIWindowManager;
		GUIWindowPainter* m_pGUIWindowPainter;
		GUISystemEvents* m_pEvents;
		dl_uint* m_sysInts;
		dl_float32* m_sysFloats;
		DLMT::DL_COLOR_32* m_sysColors;
		GUIFont** m_sysFonts;
		dl_int m_iVar50;
		dl_float32 m_fVar54;
		DLTX::DLString m_string;
		dl_int16 m_sVar88;
		dl_int m_iVar8C;
		dl_int m_iVar90;
		dl_uint64 m_rng;
		TGUIStringStorage<dl_wchar> m_stringStorage;
	};
}
