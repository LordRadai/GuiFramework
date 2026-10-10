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
		TGUIPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, T* value) : SuperClass(pParent, label, 1), m_value(value)
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
			m_formatter.Format(str, *m_value);

			return true;
		}

	private:
		T* m_value;
		Formatter m_formatter;
	};

	template<typename T>
	class TGUIPropertyLabel<T, TGUIValueToStringFormatter<T>> : public GUIPropertyLabel
	{
		typedef TGUIPropertyLabel<T, TGUIValueToStringFormatter<T>> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		TGUIPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, T* value, TGUIValueStringPairData<T>* pData) : SuperClass(pParent, label, 1), m_value(value), m_formatter(pData)
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
			m_formatter.Format(str, *m_value);

			return true;
		}

	private:
		T* m_value;
		TGUIValueToStringFormatter<T> m_formatter;
	};

	// Property label that formats its value by calling a const member function on its owner. The value is stored by copy.
	template<class Owner, typename T>
	class TGUICbPropertyLabel : public GUIPropertyLabel
	{
		typedef TGUICbPropertyLabel<Owner, T> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		typedef void (Owner::*FormatFn_t)(DLTX::DLString& str, T value) const;

		TGUICbPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, Owner* pOwner, FormatFn_t pFormatFn, T value) : SuperClass(pParent, label, 1)
			, m_pOwner(pOwner), m_pFormatFn(pFormatFn), m_value(value)
		{
		}

		virtual ~TGUICbPropertyLabel() override
		{
			OnDelete();
			UnRef();
			SuperClass::_Destroy();
		}

		virtual void OnDelete() override
		{
			this->m_pOwner = nullptr;
			SuperClass::OnDelete();
		}

		virtual dl_uint OnClose() override
		{
			this->m_pOwner = nullptr;
			return SuperClass::OnClose();
		}

		virtual dl_bool GetValueString(DLTX::DLString& str) const override
		{
			if (m_pOwner == nullptr || m_pFormatFn == nullptr)
				return false;

			(m_pOwner->*m_pFormatFn)(str, m_value);

			return true;
		}

	private:
		Owner* m_pOwner;
		FormatFn_t m_pFormatFn;
		T m_value;
	};
}