#pragma once
#include "GUILayouter.h"

namespace GuiFramework
{
	class GUIVertLayouter : public GUILayouter
	{
		typedef GUIVertLayouter ThisClass;
		typedef GUILayouter SuperClass;

	public:
		GUIVertLayouter(GUIWidget* pOwner);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIVertLayouter() override;
		virtual void OnDelete() override;
		virtual dl_bool OnOwnerSizeChanged(const TGUI_SIZE<int>& size) override;
		virtual dl_bool AutoAdd(GUIWindowBase* pWindow) override;
		virtual dl_bool AutoRemove(GUIWindowBase* pWindow) override;

	protected:
		DLUT::DLVector<TGUIObjectPtr<GUILayoutItem>> m_layoutItems;
		dl_uint16 m_sVar60;
		dl_uint16 m_sVar62;
		dl_uint m_iVar64;
		dl_uint m_iVar68;
		dl_uint m_iVar6C;
	};
}
