#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUILiteralString.inl"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/TGUIPoint.inl"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/System/GUISystem.h"
#include "GuiFramework/System/GUIMouseEvent.h"
#include "GuiFramework/System/GUIVirtualInput.h"

#include "GuiFramework/Render/GUIRenderContext.h"

namespace GuiFramework
{
    struct _GUI_SCROLL_POS
    {
        dl_uint ScrollPos;

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 4, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
        }
    };

    struct _GUI_SCROLL_INFO
    {
		dl_uint iVar0;
		dl_uint iVar4;
		dl_uint iVar8;

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 4, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
		}
    };

    struct _GUI_CREATE_WINDOW
    {
        Rect16 Pos;
        dl_uint Flags;
        dl_uint iVarC;

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(size, 4, GUI_ALLOCATOR);
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
            return DLKR::AllocateAligned(size, 4, GUI_ALLOCATOR);
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GUI_ALLOCATOR);
        }
    };

    typedef GUI_KEYSTROKE KeyEvent;

    typedef LRESULT GUI_NCHIT;

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
        virtual dl_uint IsMoveChild() const { return true; }
        virtual dl_uint IsMoveSelf() const { return true; }
        virtual dl_uint OnMouseEvent(const MouseEvent& event);
        virtual dl_uint OnMouseMove(const MouseEvent& event) { return false; }
        virtual dl_uint OnNcMouseMove(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
        virtual dl_uint OnLButtonDown(const MouseEvent& event) { return false; }
        virtual dl_uint OnLButtonUp(const MouseEvent& event) { return false; }
        virtual dl_uint OnRButtonDown(const MouseEvent& event) { return false; }
        virtual dl_uint OnRButtonUp(const MouseEvent& event) { return false; }
		virtual dl_uint OnMButtonDown(const MouseEvent& event) { return false; }
		virtual dl_uint OnMButtonUp(const MouseEvent& event) { return false; }
		virtual dl_uint OnLButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_uint OnRButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_uint OnMButtonDblClk(const MouseEvent& event) { return false; }
		virtual dl_uint OnMouseWheel(const MouseEvent& event) { return false; }
		virtual dl_uint OnNcLButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcLButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcRButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcRButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcMButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcMButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcLButtonDblClk(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcRButtonDblClk(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcMButtonDblClk(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnNcMouseWheel(GUI_NCHIT ncHit, const MouseEvent& event) { return false; }
		virtual dl_uint OnMouseLeave() { return false; }
		virtual dl_uint OnNcMouseLeave() { return false; }
        virtual dl_uint OnVirtualInput(const VirtualInput& input);
		virtual dl_uint AdjustScrollByChildFocus(GUIWindowBase* pChild) { return false; }
        virtual dl_uint OnNcCalcSize(Rect& out);
        virtual GUI_NCHIT OnNcHitTest(const Point2D& pt);
		virtual dl_uint OnCommand(unsigned int cmdId) { return false; }
        virtual dl_uint OnSetFocus() { return false; }
        virtual dl_uint OnKillFocus() { return false; }
		virtual dl_uint OnActivate(unsigned int state) { return false; }
		virtual dl_uint OnKeyDown(const KeyEvent& event) { return false; }
		virtual dl_uint OnKeyUp(const KeyEvent& event) { return false; }
		virtual dl_uint OnChar(const KeyEvent& event) { return false; }
		virtual dl_uint OnSize() { return false; }
		virtual dl_uint OnMove(dl_pointer param_2, dl_pointer param_3) { return false; }
		virtual dl_uint OnMove(const Rect& rect) { return false; }
        virtual dl_uint OnMinimized() { return false; }
        virtual dl_uint OnRestored() { return false; }
        virtual dl_uint OnUpdate(float fDeltaTime) { return false; }
        virtual dl_uint OnCreate() { return false; }
        virtual dl_uint OnPreCreate(const _GUI_CREATE_WINDOW& createParams) { return false; }
        virtual dl_uint OnClose() { return false; }
        virtual void OnRender(GraphicsContext& gc) const;
        virtual void OnNcRender(GraphicsContext& gc) const;
        virtual void OnRenderWindow(GraphicsContext& gc) const;
        virtual void OnVirtualInputRender(GraphicsContext& gc) const {}

        const dl_wchar* GetLabel() const { return m_name.c_str(); }
		GUIWindowBase* GetParentWindow() const { return m_pParentWindow.Get(); }
		GUISystem* GetGUISystem() const { return m_pGUISystem.Get(); }

        dl_bool SetAfterWindow(GUIWindowBase* pAfter);

        typedef dl_bool(_fastcall* AddChild_t)(GUIWindowBase*, GUIWindowBase*);
        typedef DLUT::DLVector<GUIObject*>* (_fastcall* GetChildrenVector_t)(GUIWindowBase*);
        typedef Rect(_fastcall* GetChildrenBaseCoord_t)(const GUIWindowBase*);
        typedef GUIWindowBase* (_fastcall* GetNextFocusWindow_t)(const GUIWindowBase*);
        typedef dl_uint(_fastcall* IsMoveChild_t)(const GUIWindowBase*);
        typedef dl_uint(_fastcall* IsMoveSelf_t)(const GUIWindowBase*);
        typedef dl_uint(_fastcall* OnMouseEvent_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnMouseMove_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcMouseMove_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnLButtonDown_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnLButtonUp_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnRButtonDown_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnRButtonUp_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnMButtonDown_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnMButtonUp_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnLButtonDblClk_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnRButtonDblClk_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnMButtonDblClk_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnMouseWheel_t)(GUIWindowBase*, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcLButtonDown_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcLButtonUp_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcRButtonDown_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcRButtonUp_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcMButtonDown_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcMButtonUp_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcLButtonDblClk_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcRButtonDblClk_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcMButtonDblClk_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnNcMouseWheel_t)(GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
        typedef dl_uint(_fastcall* OnMouseLeave_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnNcMouseLeave_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnVirtualInput_t)(GUIWindowBase*, const VirtualInput&);
        typedef dl_uint(_fastcall* AdjustScrollByChildFocus_t)(GUIWindowBase*, GUIWindowBase*);
        typedef dl_uint(_fastcall* OnNcCalcSize_t)(GUIWindowBase*, Rect&);
        typedef GUI_NCHIT(_fastcall* OnNcHitTest_t)(const GUIWindowBase*, const Point2D&);
        typedef dl_uint(_fastcall* OnCommand_t)(GUIWindowBase*, unsigned int);
        typedef dl_uint(_fastcall* OnSetFocus_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnKillFocus_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnActivate_t)(GUIWindowBase*, unsigned int);
        typedef dl_uint(_fastcall* OnKeyDown_t)(GUIWindowBase*, const KeyEvent&);
        typedef dl_uint(_fastcall* OnKeyUp_t)(GUIWindowBase*, const KeyEvent&);
        typedef dl_uint(_fastcall* OnChar_t)(GUIWindowBase*, const KeyEvent&);
        typedef dl_uint(_fastcall* OnSize_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnMove_Param_t)(GUIWindowBase*, dl_pointer, dl_pointer);
        typedef dl_uint(_fastcall* OnMove_Rect_t)(GUIWindowBase*, const Rect&);
        typedef dl_uint(_fastcall* OnMinimized_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnRestored_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnUpdate_t)(GUIWindowBase*, float);
        typedef dl_uint(_fastcall* OnCreate_t)(GUIWindowBase*);
        typedef dl_uint(_fastcall* OnPreCreate_t)(GUIWindowBase*, const _GUI_CREATE_WINDOW&);
        typedef dl_uint(_fastcall* OnClose_t)(GUIWindowBase*);
        typedef void(_fastcall* OnRender_t)(const GUIWindowBase*, GraphicsContext&);
        typedef void(_fastcall* OnNcRender_t)(const GUIWindowBase*, GraphicsContext&);
        typedef void(_fastcall* OnRenderWindow_t)(const GUIWindowBase*, GraphicsContext&);
        typedef void(_fastcall* OnVirtualInputRender_t)(const GUIWindowBase*, GraphicsContext&);

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
    };
}
