#pragma once
#include "GuiFramework/Window/Control/GUIPropertyLabel.h"
#include "GuiFramework/System/GUIBitsetProxy.inl"
#include "GuiFramework/System/GUIFormatter.inl"

namespace GuiFramework
{
	template<class ProxyClass, class Formatter = GUIPropertyFormatter>
	class TGUIProxyPropertyLabel : public GUIPropertyLabel
	{
		typedef TGUIProxyPropertyLabel<ProxyClass> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
	};

	template<unsigned int N, class Formatter >
	class TGUIProxyPropertyLabel<GUIBitsetProxy<N>, Formatter> : public GUIPropertyLabel
	{
		typedef TGUIProxyPropertyLabel<GUIBitsetProxy<N>, Formatter> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		TGUIProxyPropertyLabel(GUIWindowBase* pParent, TGUISharedString<dl_wchar> label, GUIBitsetProxy<N>* pBitset) :
			SuperClass(pParent, label, 1),
			m_proxy(*pBitset)
		{}

		virtual ~TGUIProxyPropertyLabel() override
		{
			OnDelete();
			UnRef();
			SuperClass::_Destroy();
		}

		virtual dl_bool GetValueString(DLTX::DLString& str) const override
		{
			m_formatter.Format(str, m_proxy.test());
			return true;
		}
	private:
		GUIBitsetProxy<N> m_proxy;
		Formatter m_formatter;
	};
}