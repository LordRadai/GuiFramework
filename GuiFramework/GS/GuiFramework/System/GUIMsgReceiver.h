#pragma once
#include "GUIObject.h"

namespace GuiFramework
{
	class GUIMsgReceiver : public GUIObject
	{
		typedef GUIMsgReceiver ThisClass;
		typedef GUIObject SuperClass;

	public:
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIMsgReceiver() override;

		static void* operator new(dl_size size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* p)
		{
			DLKR::Free(p, GUI_ALLOCATOR);
		}
	};
}
