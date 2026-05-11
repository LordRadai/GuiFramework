#pragma once
#include "GUITweakerBase.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"
#include "GuiFramework/Window/ControlEx/GUIColorSelector.h"

namespace GuiFramework
{
	class GUIColorTweaker : public GUITweakerBase
	{
		typedef GUIColorTweaker ThisClass;
		typedef GUITweakerBase SuperClass;
	public:
		GUIColorTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label, dl_uint flags);

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIColorTweaker() override;
		virtual void OnDelete() override;
		virtual void Update(dl_float32 dt) override;
		virtual void Close() override;
		virtual void OnUpdate() {}

		void SetColor(const DLMT::DL_VECTOR4& color);
		void SetColor(const DLMT::DL_COLOR_32& color);
		void SetColor(const DLMT2::DL_COLOR_U8& color);
		//void SetColor(dl_pointer color);

		void GetFloatColor(DLMT::DL_VECTOR4& outColor) const;
		void GetIntColor(DLMT::DL_COLOR_32& outColor) const;
		void GetU8Color(DLMT2::DL_COLOR_U8& outColor) const;
		//void GetHDRColor(dl_pointer outColor) const;

		typedef void(_fastcall* OnUpdate_t)(GUIColorTweaker*);
	protected:
		void _Destroy();

		TGUIObjectPtr<GUIColorSelector> m_pColorSelector;
		dl_uint m_iVar28;
	};
}