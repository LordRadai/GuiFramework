#pragma once
#include "GUIOnOffTweaker.h"
#include "GuiFramework/System/TGUIBitFieldProxy.inl"

namespace GuiFramework
{
    // ProxyClass must provide: typedef ValueType, IsValid(), GetValue(), SetValue(const ValueType&), Detach()
    template<class ProxyClass>
    class TGUIProxyOnOffTweaker : public GUIOnOffTweaker
    {
        typedef TGUIProxyOnOffTweaker<ProxyClass> ThisClass;
        typedef GUIOnOffTweaker SuperClass;
        typedef typename ProxyClass::ValueType T;
    public:
        TGUIProxyOnOffTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label, const ProxyClass& proxy) :
            GUIOnOffTweaker(pParent, label),
            m_proxy(proxy),
            m_valueOld(T())
        {
            if (m_proxy.IsValid())
            {
                m_valueOld = m_proxy.GetValue();
                this->SetCheck(m_valueOld != T());
            }
        }

        virtual ~TGUIProxyOnOffTweaker() override
        {
            OnDelete();
            UnRef();
            SuperClass::~GUIOnOffTweaker();
        }

        virtual void OnDelete() override
        {
            m_proxy.Detach();
            SuperClass::OnDelete();
        }

        virtual void Update(dl_float32 dt) override
        {
            if (!this->m_proxy.IsValid())
                return;

            T currentValue = this->m_proxy.GetValue();

            if (currentValue == this->m_valueOld)
            {
                bool bUiState = (this->IsChecked() != 0);
                bool bCacheState = (this->m_valueOld != T());

                if (bUiState != bCacheState)
                {
                    if (this->m_flags < 0)
                    {
                        this->SetCheck(bCacheState);
                    }
                    else
                    {
                        this->m_valueOld = bUiState ? (T)1 : (T)0;
                        this->m_proxy.SetValue(this->m_valueOld);
                        this->InvokeCallback();
                    }
                }
            }
            else
            {
                this->m_valueOld = currentValue;
                this->SetCheck(this->m_valueOld != T());
            }
        }

        virtual void Close() override
        {
            m_proxy.Detach();
            SuperClass::Close();
        };

    protected:
        ProxyClass m_proxy;
        T m_valueOld;
    };

    template<typename T>
    class TGUIProxyOnOffTweaker<TGUIBitFieldProxy<T>> : public GUIOnOffTweaker
    {
        typedef TGUIProxyOnOffTweaker<TGUIBitFieldProxy<T>> ThisClass;
        typedef GUIOnOffTweaker SuperClass;
    public:
		TGUIProxyOnOffTweaker(GUIWidget* pParent, TGUISharedString<dl_wchar> label, T* pValue, dl_uint32 bitOffset, dl_uint32 bitSize = 1) :
			GUIOnOffTweaker(pParent, label),
			m_proxy(pValue, bitOffset, bitSize),
			m_valueOld(0)
		{
			if (pValue != nullptr)
			{
				m_valueOld = m_proxy.GetValue();
				this->SetCheck(m_valueOld != 0);
			}
		}

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
            if (!this->m_proxy.HasValue())
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