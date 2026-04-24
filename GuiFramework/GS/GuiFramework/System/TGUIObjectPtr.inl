#pragma once
#include "GUIObject.h"

namespace GuiFramework
{
    template <class T>
    class TGUIObjectPtr 
    {
    public:
        TGUIObjectPtr() : m_ptr(nullptr) 
        {
            static_assert(std::is_base_of<GUIObject, T>::value, "T must be a child of GUIObject");
        }

        TGUIObjectPtr(T* pObj) : m_ptr(pObj) 
        {
            static_assert(std::is_base_of<GUIObject, T>::value, "T must be a child of GUIObject");
            if (m_ptr)
                _AddRef();
        }

        ~TGUIObjectPtr() 
        {
            _UnRef();
        }

        TGUIObjectPtr& operator=(T* pObj) 
        {
            static_assert(std::is_base_of<GUIObject, T>::value, "T must be a child of GUIObject");
            if (m_ptr != pObj) 
            {
                _UnRef();
                m_ptr = pObj;
                if (m_ptr)
                    _AddRef();
            }

            return *this;
        }

        T* operator->() const { return m_ptr; }
        T& operator*() const { return *m_ptr; }

        void operator=(const TGUIObjectPtr& other) 
        {
            if (this != &other) 
            {
                _UnRef();
                m_ptr = other.m_ptr;

                if (m_ptr)
                    _AddRef();
            }
		}

        void operator=(TGUIObjectPtr& other) 
        {
            if (this != &other)
            {
                _UnRef();
                m_ptr = other.m_ptr;

                if (m_ptr)
                    _AddRef();
            }
		}

        T* Get() const { return m_ptr; }

        static void* operator new(dl_size size)
        {
            return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
        }

        static void operator delete(void* p)
        {
            DLKR::Free(p, GUI_ALLOCATOR);
        }
    private:
        T* m_ptr;

        void _UnRef() 
        {
            if (m_ptr)
                m_ptr->UnRef();
        }

        void _AddRef() 
        {
            if (m_ptr)
                m_ptr->AddRef();
        }
    };
}