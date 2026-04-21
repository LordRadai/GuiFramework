#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUILiteralString.inl"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/TGUIPoint.inl"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/System/GUISystem.h"
#include "GuiFramework/Render/GUIRenderContext.h"

namespace GuiFramework
{
    struct _GUI_SCROLL_POS
    {
        dl_uint ScrollPos;

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
        }
    };

    struct GUI_MOUSE_INFO
    {
        dl_int EventID;
        dl_int iVar4;
        dl_int X;
        dl_int Y;

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
        }
    };

    struct _GUI_CREATE_WINDOW
    {
        Rect16 Pos;
        dl_uint Flags;
        dl_uint iVarC;

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
        }
    };

    struct GUI_KEYSTROKE
    {
        dl_uint16 VirtualKey;
        dl_uint16 ScanCode;
        dl_uint Flags;
        dl_wchar UnicodeChar;

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
        }
    };

    struct _GUI_VIRTUAL_INPUT
    {
        dl_int InputID;

        bool IsKeyEvent(dl_char eventID) const
        {
            return InputID == eventID;
        }

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
        }
    };

    typedef _GUI_VIRTUAL_INPUT VirtualInput;

    typedef GUI_KEYSTROKE KeyEvent;

    typedef LRESULT GUI_NCHIT;
    typedef GUI_MOUSE_INFO MouseEvent;

    typedef dl_uint _GUI_SCROLLBAR_EVENT;

	class GUIWindowPainter;

    class GUIWindowBase : public GUIMsgReceiver
    {
        typedef GUIWindowBase ThisClass;
		typedef GUIMsgReceiver SuperClass;

    public:
		GUIWindowBase() {}
        GUIWindowBase(TGUISharedString<dl_wchar> label);

        virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
        virtual ~GUIWindowBase() override;
        virtual void OnDelete() override;
        virtual dl_bool AddChild(GUIWindowBase* pChild) { return false; }
		virtual DLUT::DLVector<GUIObject*>* GetChildrenVector() { return nullptr; }
		virtual Rect GetChildrenBaseCoord() const { return Rect(); }
		virtual GUIWindowBase* GetNextFocusWindow() const { return nullptr; }
        virtual dl_bool IsMoveChild() const { return true; }
		virtual dl_bool IsMoveSelf() const { return true; }
        virtual dl_bool OnMouseEvent(const MouseEvent& event);
		virtual dl_bool OnMouseMove(const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMouseMove(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
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
		virtual dl_bool OnNcLButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcLButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcRButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcRButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcLButtonDblClk(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcRButtonDblClk(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMButtonDblClk(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnNcMouseWheel(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_bool OnMouseLeave() { return false; }
		virtual dl_bool OnNcMouseLeave() { return false; }
        virtual dl_bool OnVirtualInput(const VirtualInput& input);
		virtual dl_bool AdjustScrollByChildFocus(GUIWindowBase* pChild) { return false; }
        virtual dl_bool OnNcCalcSize(Rect& out);
        virtual GUI_NCHIT OnNcHitTest(const Point2D& pt);
		virtual dl_bool OnCommand(unsigned int cmdId) { return false; }
        virtual dl_bool OnSetFocus() { return false; }
        virtual dl_bool OnKillFocus() { return false; }
		virtual dl_bool OnActivate(unsigned int state) { return false; }
		virtual dl_bool OnKeyDown(const KeyEvent& event) { return false; }
		virtual dl_bool OnKeyUp(const KeyEvent& event) { return false; }
		virtual dl_bool OnChar(const KeyEvent& event) { return false; }
		virtual dl_bool OnSize() { return false; }
		virtual dl_bool OnMove(dl_pointer param_2, dl_pointer param_3) { return false; }
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

        const dl_wchar* GetLabel() const { return m_name.c_str(); }
		GUIWindowBase* GetParentWindow() const { return m_pParentWindow.Get(); }
		GUISystem* GetGUISystem() const { return m_pGUISystem.Get(); }

    protected:
		TGUIObjectPtr<GUIWindowBase> m_pParentWindow;
        TGUIObjectPtr<GUIWindowBase> m_pVar18;
		TGUIObjectPtr<GUISystem> m_pGUISystem;
        GUIWindowPainter* m_pGUIWindowPainter;
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

        typedef dl_bool(__fastcall* AddChild_t)(GUIWindowBase*, GUIWindowBase*);
        typedef DLUT::DLVector<GUIObject*>* (__fastcall* GetChildrenVector_t)(GUIWindowBase*);
        typedef Rect(__fastcall* GetChildrenBaseCoord_t)(const GUIWindowBase*);
        typedef GUIWindowBase* (__fastcall* GetNextFocusWindow_t)(const GUIWindowBase*);
        typedef dl_bool(__fastcall* IsMoveChild_t)(const GUIWindowBase*);
        typedef dl_bool(__fastcall* IsMoveSelf_t)(const GUIWindowBase*);
        typedef dl_bool(__fastcall* OnMouseEvent_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnMouseMove_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcMouseMove_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnLButtonDown_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnLButtonUp_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnRButtonDown_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnRButtonUp_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnMButtonDown_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnMButtonUp_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnLButtonDblClk_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnRButtonDblClk_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnMButtonDblClk_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnMouseWheel_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcLButtonDown_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcLButtonUp_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcRButtonDown_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcRButtonUp_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcMButtonDown_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcMButtonUp_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcLButtonDblClk_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcRButtonDblClk_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcMButtonDblClk_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnNcMouseWheel_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_bool(__fastcall* OnMouseLeave_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnNcMouseLeave_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnVirtualInput_t)(GUIWindowBase*, const VirtualInput&);
        typedef dl_bool(__fastcall* AdjustScrollByChildFocus_t)(GUIWindowBase*, GUIWindowBase*);
        typedef dl_bool(__fastcall* OnNcCalcSize_t)(GUIWindowBase*, Rect&);
        typedef GUI_NCHIT(__fastcall* OnNcHitTest_t)(const GUIWindowBase*, const Point2D&);
        typedef dl_bool(__fastcall* OnCommand_t)(GUIWindowBase*, unsigned int);
        typedef dl_bool(__fastcall* OnSetFocus_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnKillFocus_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnActivate_t)(GUIWindowBase*, unsigned int);
        typedef dl_bool(__fastcall* OnKeyDown_t)(GUIWindowBase*, const KeyEvent&);
        typedef dl_bool(__fastcall* OnKeyUp_t)(GUIWindowBase*, const KeyEvent&);
        typedef dl_bool(__fastcall* OnChar_t)(GUIWindowBase*, const KeyEvent&);
        typedef dl_bool(__fastcall* OnSize_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnMove_Param_t)(GUIWindowBase*, dl_pointer, dl_pointer);
        typedef dl_bool(__fastcall* OnMove_Rect_t)(GUIWindowBase*, const Rect&);
        typedef dl_bool(__fastcall* OnMinimized_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnRestored_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnUpdate_t)(GUIWindowBase*, float);
        typedef dl_bool(__fastcall* OnCreate_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnPreCreate_t)(GUIWindowBase*);
        typedef dl_bool(__fastcall* OnClose_t)(GUIWindowBase*);
        typedef void(__fastcall* OnRender_t)(const GUIWindowBase*, GraphicsContext&);
        typedef void(__fastcall* OnNcRender_t)(const GUIWindowBase*, GraphicsContext&);
        typedef void(__fastcall* OnRenderWindow_t)(const GUIWindowBase*, GraphicsContext&);
        typedef void(__fastcall* OnVirtualInput_Const_t)(const GUIWindowBase*, const VirtualInput&);
    };
}
