#pragma once
#include "GuiFramework/Window/Control/GUIPropertyLabel.h"
#include "GuiFramework/System/GUIFormatter.inl"

namespace GuiFramework
{
	template<typename T, typename Formatter = GUIPropertyFormatter>
	class TGUIPropertyLabel : public GUIPropertyLabel
	{
		typedef TGUIPropertyLabel<T, Formatter> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		TGUIPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, T* value, dl_int flags) : SuperClass(pParent, label, flags), m_value(value)
		{
		}

		virtual ~TGUIPropertyLabel() override
		{
			OnDelete();
			UnRef();
			SuperClass::_Destroy();
		}

		virtual void OnDelete() override
		{
			this->m_value = nullptr;
			SuperClass::OnDelete();
		}

		virtual dl_uint OnClose() override
		{
			this->m_value = nullptr;
			return SuperClass::OnClose();
		}

		virtual dl_bool GetValueString(DLTX::DLString& str) const override
		{
			Formatter::Format(str, *m_value);

			return true;
		}

	private:
		T* m_value;
		Formatter m_formatter;
	};
}