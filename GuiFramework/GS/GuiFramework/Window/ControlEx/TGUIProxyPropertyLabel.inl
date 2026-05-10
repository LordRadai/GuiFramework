#pragma once
#include "GuiFramework/Window/Control/GUIPropertyLabel.h"
#include "GuiFramework/System/GUIBitsetProxy.h"
#include "GuiFramework/System/GUIFormatter.h"

namespace GuiFramework
{
	template<class ProxyClass, class Formatter = GUIPropertyFormatter>
	class TGUIProxyPropertyLabel : public GUIPropertyLabel
	{
		typedef TGUIProxyPropertyLabel<ProxyClass> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
	};

	template<unsigned int N, class Formatter>
	class TGUIProxyPropertyLabel<GUIBitsetProxy<N>, Formatter> : public GUIPropertyLabel
	{
		typedef TGUIProxyPropertyLabel<GUIBitsetProxy<N>, Formatter> ThisClass;
		typedef GUIPropertyLabel SuperClass;
	public:
		virtual ~TGUIProxyPropertyLabel() override
		{
			OnDelete();
			UnRef();
			SuperClass::_Destroy();
		}

		virtual void OnDelete() override
		{
			this->m_pProxy = nullptr;
			SuperClass::OnDelete();
		}

		virtual dl_uint OnClose() override
		{
			this->m_pProxy = nullptr;
			return SuperClass::OnClose();
		}

		virtual void GetValueString(DLTX::DLString& str) const override;
	private:
		GUIBitsetProxy<N>* m_pProxy;
		dl_uint m_bitIndex;
	};
}