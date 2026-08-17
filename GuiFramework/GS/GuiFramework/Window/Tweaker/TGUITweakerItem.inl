#pragma once
#include "GUITweakerItem.h"
#include "GuiFramework/System/TGUIObjectPtr.inl"

#undef GetObject

namespace GuiFramework
{
	template<class T>
	class TGUITweakerItem : public GUITweakerItem
	{
		typedef TGUITweakerItem<T> ThisClass;
		typedef GUITweakerItem SuperClass;
	public:
		virtual ~TGUITweakerItem() override
		{
			OnDelete();
			UnRef();
			SuperClass::_Destroy();
		}

		virtual void OnDelete() override
		{
			if (this->m_pObject.Get())
				this->m_pObject->UnRef();
		}

		virtual void Close() override {}

		T* GetObject() const { return m_pObject.Get(); }
	private:
		TGUIObjectPtr<T> m_pObject;
	};
}