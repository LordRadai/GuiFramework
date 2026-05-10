#pragma once
#include "GUIOnOffTweaker.h"
#include "GuiFramework/System/TGUIBitFieldProxy.inl"

namespace GuiFramework
{
    template<class ProxyClass>
    class TGUIProxyOnOffTweaker : public GUIOnOffTweaker
    {};

    template<typename T>
    class TGUIProxyOnOffTweaker<TGUIBitFieldProxy<T>> : public GUIOnOffTweaker
    {
        typedef TGUIProxyOnOffTweaker<TGUIBitFieldProxy<T>> ThisClass;
        typedef GUIOnOffTweaker SuperClass;
    public:
        virtual ~TGUIProxyOnOffTweaker() override
        {
            OnDelete();
            UnRef();
            SuperClass::~GUIOnOffTweaker();
        }

        virtual void OnDelete() override
        {
            m_proxy.Finalize();
            SuperClass::OnDelete();
        }

        virtual void Update(dl_float32 dt) override
        {
            if (this->m_proxy.pValue == nullptr)
                return;

            T currentBitValue = this->m_proxy.GetValue();

            if (currentBitValue == this->m_valueOld)
            {
                dl_uint32 uiChecked = this->IsChecked();

                bool bUiState = (uiChecked != 0);
                bool bCacheState = (this->m_valueOld != 0);

                if (bUiState != bCacheState)
                {
                    if (this->m_flags < 0)
                    {
                        this->SetCheck(this->m_valueOld != 0);
                    }
                    else
                    {
                        this->m_valueOld = bUiState ? (T)1 : (T)0;
                        this->m_proxy = this->m_valueOld;
                        this->InvokeCallback();
                    }
                }
            }
            else
            {
                this->m_valueOld = currentBitValue;
                this->SetCheck(this->m_valueOld != 0);
            }
        }

        virtual void Close() override
        {
            m_proxy.Finalize();
            SuperClass::Close();
        };

    protected:
        TGUIBitFieldProxy<T> m_proxy;
        T m_valueOld;
    };
}