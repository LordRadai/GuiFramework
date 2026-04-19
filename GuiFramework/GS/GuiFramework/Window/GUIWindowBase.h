#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUILiteralString.inl"
#include "GuiFramework/System/TGUIRect.inl"
#include "GuiFramework/System/TGUIPoint.inl"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/System/GUISystem.h"
#include "GuiFramework/System/GUIMouse.h"
#include "GuiFramework/System/GUIVirtualInput.h"
#include "GuiFramework/System/GUIKeyStroke.h"
#include "GuiFramework/Render/GUIRenderContext.h"

namespace GuiFramework
{
    class GUIWindowBase : public GUIMsgReceiver
    {
        typedef GUIWindowBase ThisClass;
		typedef GUIMsgReceiver SuperClass;

    public:
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
		virtual dl_bool AdjustScroll() { return false; }
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
        GUIWindowBase* m_pParentWindow;
        GUIWindowBase* m_pVar18;
		TGUIObjectPtr<GUISystem> m_pGUISystem;
        dl_pointer* m_pGUIWindowPainter;
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
		typedef dl_bool(__fastcall* OnMouseEvent_t)(const GUIWindowBase*, const MouseEvent&);
		typedef dl_bool(__fastcall* OnMouseMove_t)(const GUIWindowBase*, const MouseEvent&);
		typedef dl_bool(__fastcall* OnNcMouseMove_t)(const GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
		typedef dl_bool(__fastcall* OnNcLButtonDown_t)(const GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
		typedef dl_bool(__fastcall* OnNcLButtonUp_t)(const GUIWindowBase*, GUI_NCHIT, const MouseEvent&);
		typedef dl_bool(__fastcall* OnMouseLeave_t)(const GUIWindowBase*);
		typedef dl_bool(__fastcall* OnNcMouseLeave_t)(const GUIWindowBase*);
		typedef dl_bool(__fastcall* OnVirtualInput_t)(const GUIWindowBase*, const GUIWindowBase::VirtualInput&);
		typedef dl_bool(__fastcall* OnNcCalcSize_t)(const GUIWindowBase*, Rect&);
		typedef GUI_NCHIT(__fastcall* OnNcHitTest_t)(const GUIWindowBase*, const Point2D&);
		typedef dl_bool(__fastcall* OnCreate_t)(const GUIWindowBase*);
		typedef dl_bool(__fastcall* OnPreCreate_t)(const GUIWindowBase*);
		typedef dl_bool(__fastcall* OnClose_t)(const GUIWindowBase*);
		typedef void(__fastcall* OnRender_t)(const GUIWindowBase*, GraphicsContext&);
		typedef void(__fastcall* OnNcRender_t)(const GUIWindowBase*, GraphicsContext&);
		typedef void(__fastcall* OnRenderWindow_t)(const GUIWindowBase*, GraphicsContext&);
    };
}
