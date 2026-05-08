#pragma once
#include "GUITweakerBase.h"
#include "GUIMultiNumericEditor.h"

namespace GuiFramework
{
	class GUIMultiTweaker : public GUITweakerBase
	{
		typedef GUIMultiTweaker ThisClass;
		typedef GUITweakerBase SuperClass;
	public:
		GUIMultiTweaker(dl_uint numValues, TGUISharedString<dl_wchar> label);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIMultiTweaker() override;
		virtual void OnDelete() override;
		virtual void Update(dl_float32 dt) override {}
		virtual void Close() override;

		dl_bool Create(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label);
	protected:
		void _Destroy();

		TGUIObjectPtr<GUIMultiNumericEditor> m_pMultiNumericEditor;
	};
}