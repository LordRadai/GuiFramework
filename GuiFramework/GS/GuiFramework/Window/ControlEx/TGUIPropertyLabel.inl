#pragma once
#include "GuiFramework/Window/Control/GUIPropertyLabel.h"
#include "GuiFramework/System/GUIFormatter.h"

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
			DLTX::DLFormat<dl_wchar>::Format(str, Formatter::IntegerFormatString, *m_value);

			return true;
		}

	private:
		T* m_value;
		Formatter m_formatter;
	};

	template<>
	inline dl_bool TGUIPropertyLabel<dl_bool, GUIBoolFormatter>::GetValueString(DLTX::DLString& str) const
	{
		str = (*m_value) ? GUIBoolFormatter::TrueString : GUIBoolFormatter::FalseString;
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<dl_float32, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat<dl_wchar>::Format(str, GUIPropertyFormatter::FloatFormatString, *m_value);
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<DLMT::DL_VECTOR2, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat<dl_wchar>::Format(str, GUIPropertyFormatter::Vector2FormatString, m_value->x, m_value->y);
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<DLMT::DL_VECTOR3, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat<dl_wchar>::Format(str, GUIPropertyFormatter::Vector3FormatString, m_value->x, m_value->y, m_value->z);
		return true;
	}

	template<>
	inline dl_bool TGUIPropertyLabel<DLMT::DL_VECTOR4, GUIPropertyFormatter>::GetValueString(DLTX::DLString& str) const
	{
		DLTX::DLFormat<dl_wchar>::Format(str, GUIPropertyFormatter::Vector4FormatString, m_value->x, m_value->y, m_value->z, m_value->w);
		return true;
	}
}