#pragma once
#include <dantelion2.h>
#include "GuiFramework/Globals.h"

namespace GuiFramework
{
	class GUIObject
	{
		typedef GUIObject ThisClass;
	public:
		GUIObject();

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const;
		virtual ~GUIObject();
		virtual void OnDelete() {}
		virtual void DeleteThis();

		static void* operator new(dl_size size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* p)
		{
			DLKR::Free(p, GUI_ALLOCATOR);
		}

	protected:
		dl_uint m_interactionFlags;

		typedef DLRF::DLRuntimeClass* (__fastcall* GetRuntimeClass_t)(const GUIObject*);
		typedef void(__fastcall* Destructor_t)(GUIObject*);
		typedef void(__fastcall* OnDelete_t)(GUIObject*);
	};
}