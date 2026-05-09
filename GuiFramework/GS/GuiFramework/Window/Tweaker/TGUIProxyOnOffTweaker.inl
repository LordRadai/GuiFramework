#pragma once
#include "GUIOnOffTweaker.h"
#include "GuiFramework/System/TGUIBitFieldProxy.inl"

namespace GuiFramework
{
#pragma once
#include "GUIOnOffTweaker.h"

    namespace GuiFramework
    {
        template<class ProxyClass>
        class TGUIProxyOnOffTweaker : public GUIOnOffTweaker
        {
            typedef TGUIProxyOnOffTweaker<ProxyClass> ThisClass;
            typedef GUIOnOffTweaker SuperClass;
        public:
            using ValueType = decltype(std::declval<ProxyClass>().GetValue());

            TGUIProxyOnOffTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label, ProxyClass proxy) : SuperClass(pParent, label), m_proxy(proxy), m_valueOld(proxy.GetValue())
            {
                SetCheck(IsCheckBoxToggled());
			}

            virtual void Update(dl_float32 dt) override;

        protected:
            ProxyClass m_proxy;
            ValueType  m_valueOld;
        };
    }
}