#pragma once
#include "GuiFramework/Window/GUIWindowBase.h"

namespace GuiFramework
{
	class GUIScrollBarUtil;

	enum GUI_SCROLLBAR_TYPE : dl_uint
	{
		GUI_SCROLLBAR_TYPE_HORZ,
		GUI_SCROLLBAR_TYPE_VERT,

		GUI_SCROLLBAR_TYPE_MAX
	};

	class GUIWidget : public GUIWindowBase
	{
		typedef GUIWidget ThisClass;
		typedef GUIWindowBase SuperClass;

	public:
		struct _GUI_NC_SHAPE_INFO
		{
		};

		struct _GUI_NC_SHAPE_PROP
		{
		};

		GUIWidget() {}
		GUIWidget(TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIWidget() override;
		virtual void OnDelete() override;
		virtual dl_bool AddChild(GUIWindowBase* pChild) override;
		virtual DLUT::DLVector<GUIObject*>* GetChildrenVector() override;
		virtual Rect GetChildrenBaseCoord() const override;
		virtual GUIWindowBase* GetNextFocusWindow() const override;
		virtual dl_uint OnMouseMove(const MouseEvent& event) override;
		virtual dl_uint OnNcMouseMove(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_uint OnNcLButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_uint OnNcLButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_uint OnMouseLeave() override;
		virtual dl_uint OnNcMouseLeave() override;
		virtual dl_uint OnVirtualInput(const VirtualInput& input) override;
		virtual dl_uint OnNcCalcSize(Rect& out) override;
		virtual GUI_NCHIT OnNcHitTest(const Point2D& pt) override;
		virtual dl_uint OnMove(dl_pointer param_2, dl_pointer param_3) override { return true; }
		virtual dl_uint OnCreate() override;
		virtual dl_uint OnPreCreate(const _GUI_CREATE_WINDOW& createParams) override;
		virtual dl_uint OnClose() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnNcRender(GraphicsContext& gc) const override;
		virtual Rect GetDefaultSizeMin() const;
		virtual Rect GetDefaultSizeMax() const;
		virtual void ComputeNcShapeInfo(const _GUI_NC_SHAPE_PROP& prop, _GUI_NC_SHAPE_INFO& info) const;
		virtual dl_uint OnVScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) { return false; }
		virtual dl_uint OnHScroll(_GUI_SCROLLBAR_EVENT event, const _GUI_SCROLL_POS& pos) { return false; }

		typedef Rect(__fastcall* GetDefaultSizeMin_t)(const GUIWidget*);
		typedef Rect(__fastcall* GetDefaultSizeMax_t)(const GUIWidget*);
		typedef void(__fastcall* ComputeNcShapeInfo_t)(const GUIWidget*, const GUIWidget::_GUI_NC_SHAPE_PROP&, GUIWidget::_GUI_NC_SHAPE_INFO&);
		typedef dl_uint(__fastcall* OnVScroll_t)(GUIWidget*, _GUI_SCROLLBAR_EVENT, const _GUI_SCROLL_POS&);
		typedef dl_uint(__fastcall* OnHScroll_t)(GUIWidget*, _GUI_SCROLLBAR_EVENT, const _GUI_SCROLL_POS&);
	protected:
		DLUT::DLVector<GUIWidget*> m_childWidgets;
		GUIScrollBarUtil* m_pScrollBars[2];
		dl_int m_iVar0xa8;
		dl_int m_iVar0xac;
		dl_uchar m_actionType;
		dl_uchar m_bVarB1;
		dl_uchar m_bVarB2;
		dl_uchar m_bVarB3;
		dl_uint m_iVarB4;
		dl_int16 m_sVarB8;
		dl_uchar m_bVarBA[74];
		dl_int m_iVar104;
		dl_int m_iVar108;	
	};
}