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

		void AddRef();
		void UnRef();
		dl_uint GetRefAndFlags() const { return m_nRefAndFlags; }
		dl_bool IsFlagSet(dl_uint flag) const { return (m_nRefAndFlags & flag) != 0; }

		typedef DLRF::DLRuntimeClass* (_fastcall* GetRuntimeClassOfThis_t)(const GUIObject*);
		typedef void(_fastcall* Destructor_t)(GUIObject*);
		typedef void(_fastcall* OnDelete_t)(GUIObject*);
	protected:
		void _Destroy();

		typedef void(_fastcall* _Destroy_t)(GUIObject*);

		dl_uint m_nRefAndFlags;
	};
}