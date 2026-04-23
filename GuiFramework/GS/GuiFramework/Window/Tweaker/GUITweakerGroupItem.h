#pragma once
#include "GUITweakerItem.h"

namespace GuiFramework
{
	class GUITweakerGroup;

	class GUITweakerGroupItem : public GUITweakerItem
	{
		typedef GUITweakerGroupItem ThisClass;
		typedef GUITweakerItem SuperClass;
	public:
		GUITweakerGroupItem() {}
		GUITweakerGroupItem(GUITweakerGroup* pGroup);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUITweakerGroupItem() override;
		virtual void OnDelete() override;
		virtual void Update(dl_float32 dt) override;
		virtual void Close() override {}

	private:
		GUITweakerGroup* m_pGroup;
	};
}