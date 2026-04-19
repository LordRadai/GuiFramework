#pragma once
#include "GUIWindowBase.h"

namespace GuiFramework
{
	class GUIScrollBarUtil;

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

		GUIWidget(TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIWidget() override;
		virtual void OnDelete() override;
		virtual dl_bool AddChild(GUIWindowBase* pChild) override;
		virtual DLUT::DLVector<GUIObject*>* GetChildrenVector() override;
		virtual Rect GetChildrenBaseCoord() const override;
		virtual GUIWindowBase* GetNextFocusWindow() const override;
		virtual dl_bool OnMouseMove(const MouseEvent& event) override;
		virtual dl_bool OnNcMouseMove(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_bool OnNcLButtonDown(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_bool OnNcLButtonUp(GUI_NCHIT ncHit, const MouseEvent& event) override;
		virtual dl_bool OnMouseLeave() override;
		virtual dl_bool OnNcMouseLeave() override;
		virtual dl_bool OnVirtualInput(const VirtualInput& input) override;
		virtual dl_bool OnNcCalcSize(Rect& out) override;
		virtual GUI_NCHIT OnNcHitTest(const Point2D& pt) override;
		virtual dl_bool OnMove(dl_pointer param_2, dl_pointer param_3) override { return true; }
		virtual dl_bool OnCreate() override;
		virtual dl_bool OnPreCreate() override;
		virtual dl_bool OnClose() override;
		virtual void OnRender(GraphicsContext& gc) const override;
		virtual void OnNcRender(GraphicsContext& gc) const override;
		virtual Rect GetDefaultSizeMin() const;
		virtual Rect GetDefaultSizeMax() const;
		virtual void ComputeNcShapeInfo(const _GUI_NC_SHAPE_PROP& prop, _GUI_NC_SHAPE_INFO& info) const;
		virtual dl_bool OnVScroll() { return false; }
		virtual dl_bool OnHScroll() { return false; }

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}

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

		typedef Rect(__fastcall* GetDefaultSizeMin_t)(const GUIWidget*);
		typedef Rect(__fastcall* GetDefaultSizeMax_t)(const GUIWidget*);
		typedef void(__fastcall* ComputeNcShapeInfo_t)(const GUIWidget*, const GUIWidget::_GUI_NC_SHAPE_PROP&, GUIWidget::_GUI_NC_SHAPE_INFO&);

	};
}
