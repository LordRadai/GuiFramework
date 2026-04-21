#pragma once
#include "GUIMsgReceiver.h"
#include "TGUIStringStorage.inl"
#include "TGUIRect.inl"
#include "TGUIPoint.inl"
#include "GuiFramework/Signal/GUISignalManager.h"
#include "GuiFramework/Window/GUIWindowManager.h"

namespace GuiFramework
{
	class GUIWindowPainter;
	class GUIFont;
	class GUITweakerDialog;
	class GUIRootWindow;

	class GUISystem : public GUIMsgReceiver
	{
	public:
		GUISystem();

		virtual ~GUISystem() override;
		virtual void Finalize();
		virtual TGUI_RECT<int> GetMouseInfo();
		virtual dl_int PopKeyStroke() { return 0; }
		virtual GUIRootWindow* CreateRootWindow();
		virtual dl_int BeginFont() { return 0; }
		virtual void MeasureTextExtent(Point2D* out);
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

		GUIWindowManager* GetWindowManager() const { return m_pGUIWindowManager.Get(); }

		/**
		 * @brief Connect a signal to a message receiver. The method resolver is used to resolve the method to call on the receiver when the signal is emitted.
		 */
		void Connect(GUIObject* pOwner, GUISignalDecl pSignalDeclaration, GUIMsgReceiver* pReceiver, DLRF::DLMethodResolver<DLRF::DLMethodInvokeContext>* pResolver, dl_uint param_5, dl_uint param_6);
		
		/**
		* @brief Create GUISystem editor window.
		*/
		void CreateTweaker(GUITweakerDialog* pWnd);
	protected:
		dl_int m_isDrawing;
		TGUIObjectPtr<GUIWindowManager> m_pGUIWindowManager;
		GUIWindowPainter* m_pGUIWindowPainter;
		GUISignalManager* m_pSignalManager;
		dl_uint* m_sysInts;
		dl_float32* m_sysFloats;
		DLMT::DL_COLOR_32* m_sysColors;
		TGUIObjectPtr<GUIFont>* m_sysFonts;
		dl_int m_iVar50;
		dl_float32 m_fVar54;
		DLTX::DLString m_string;
		dl_int16 m_sVar88;
		dl_int m_iVar8C;
		dl_int m_iVar90;
		dl_uint64 m_rng;
		TGUIStringStorage<dl_wchar> m_stringStorage;

		typedef void(__fastcall* Finalize_t)(GUISystem*);
		typedef TGUI_RECT<int>(__fastcall* GetMouseInfo_t)(GUISystem*);
		typedef GUIRootWindow* (__fastcall* CreateRootWindow_t)(GUISystem*);
		typedef void(__fastcall* MeasureTextExtent_t)(GUISystem*, TGUI_POINT<int>*);
		typedef void(__fastcall* SetClipboard_t)(GUISystem*, const dl_wchar*);
		typedef dl_bool(__fastcall* GetClipboard_t)(GUISystem*, DLTX::DLString*);
	};
}
