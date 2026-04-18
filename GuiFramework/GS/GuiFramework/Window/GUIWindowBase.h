#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUILiteralString.inl"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/TGUIPoint.inl"
#include "GuiFramework/System/GUISystem.h"
#include "GuiFramework/Render/GUIRenderContext.h"

namespace GuiFramework
{
    class GUIWindowBase : public GUIMsgReceiver
    {
        typedef GUIWindowBase ThisClass;
		typedef GUIMsgReceiver SuperClass;

    public:
        struct GUI_MOUSE_EVENT_INFO
        {
            dl_int EventID;
            dl_int iVar4;
            dl_int X;
			dl_int Y;
        };

		struct _GUI_VIRTUAL_INPUT
        {
            dl_int InputID;

            bool IsKeyEvent(dl_char eventID) const
            {
                return InputID == eventID;
			}
		};

        struct GUI_KEYSTROKE
        {
			dl_uint16 VirtualKey;
			dl_uint16 ScanCode;
            dl_uint Flags;
			dl_wchar UnicodeChar;
        };

		typedef GUI_MOUSE_EVENT_INFO MouseEvent;
		typedef _GUI_VIRTUAL_INPUT VirtualInput;
		typedef GUI_KEYSTROKE KeyEvent;
		typedef GUIRenderContext GraphicsContext;

        virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
        virtual ~GUIWindowBase() override;
        virtual void OnDelete() override;
        virtual dl_bool AddChild(GUIWindowBase* pChild) { return false; }
		virtual DLUT::DLVector<GUIObject*> GetChildrenVector() { return nullptr; }
		virtual Rect GetChildrenBaseCoord() const { return Rect(); }
		virtual GUIWindowBase* GetNextFocusWindow() const { return nullptr; }
        virtual dl_bool IsMoveChild() const { return true; }
		virtual dl_bool IsMoveSelf() const { return true; }
        virtual dl_bool OnMouseEvent(const MouseEvent& event);
		virtual dl_bool OnMouseMove(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMouseMove(const MouseEvent& event) { return false; }
		virtual dl_bool OnLButtonDown(const MouseEvent& event) { return false; }
		virtual dl_bool OnLButtonUp(const MouseEvent& event) { return false; }
		virtual dl_bool OnRButtonDown(const MouseEvent& event) { return false; }
		virtual dl_bool OnRButtonUp(const MouseEvent& event) { return false; }
		virtual dl_bool OnMButtonDown(const MouseEvent& event) { return false; }
		virtual dl_bool OnMButtonUp(const MouseEvent& event) { return false; }
		virtual dl_bool OnLButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_bool OnRButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_bool OnMButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_bool OnMouseWheel(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcLButtonDown(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcLButtonUp(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcRButtonDown(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcRButtonUp(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMButtonDown(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMButtonUp(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcLButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcRButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMouseWheel(const MouseEvent& event) { return false; }
		virtual dl_bool OnMouseLeave() { return false; }
		virtual dl_bool OnNcMouseLeave() { return false; }
        virtual dl_bool OnVirtualInput(const VirtualInput& input);
		virtual dl_bool AdjustScroll() { return false; }
        virtual dl_bool OnNcCalcSize();
        virtual dl_int OnNcHitTest(const Point2D& pt);
		virtual dl_bool OnCommand(unsigned int cmdId) { return false; }
        virtual dl_bool OnSetFocus() { return false; }
        virtual dl_bool OnKillFocus() { return false; }
		virtual dl_bool OnActivate(unsigned int state) { return false; }
		virtual dl_bool OnKeyDown(const KeyEvent& event) { return false; }
		virtual dl_bool OnKeyUp(const KeyEvent& event) { return false; }
		virtual dl_bool OnChar(const KeyEvent& event) { return false; }
		virtual dl_bool OnSize() { return false; }
		virtual dl_bool OnMove() { return false; }
		virtual dl_bool OnMove(const Rect& rect) { return false; }
        virtual dl_bool OnMinimized() { return false; }
        virtual dl_bool OnRestored() { return false; }
        virtual dl_bool OnUpdate(float fDeltaTime) { return false; }
        virtual dl_bool OnCreate() { return false; }
        virtual dl_bool OnPreCreate() { return false; }
        virtual dl_bool OnClose() { return false; }
        virtual void OnRender(GraphicsContext& gc) const;
        virtual void OnNcRender(GraphicsContext& gc) const;
        virtual void OnRenderWindow(GraphicsContext& gc) const;
        virtual void OnVirtualInput(const VirtualInput& input) const {}

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
        }

        const dl_wchar* GetLabel() const { return m_name.c_str(); }

    protected:
        GUIWindowBase* pParentWindow;
        GUIWindowBase* pVar18;
        GUISystem* pGuiSystem;
        dl_pointer* pGUIWindowPainter;
        TGUILiteralString<dl_wchar> m_name;
        Rect m_position;
        dl_uint m_styleFlags;
        dl_int m_iVar54;
        Rect16 m_contentOffset;
		dl_uint16 m_uVar64;
		dl_uint16 m_uVar66;
        dl_char m_bVar68;
        dl_char m_bVar69;
        dl_char m_bVar6a;
        dl_char m_bVar6b;
        dl_char m_bVar6c;
        dl_char m_bVar6d;
        dl_char m_bVar6e;
        dl_char m_bVar6f;
        dl_int16 m_sVar70;
        dl_int16 m_sVar72;
        dl_int m_iVar74;
    };
}
