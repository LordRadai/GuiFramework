#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	class GUIObject
	{
		typedef GUIObject ThisClass;
	public:
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const;

		virtual ~GUIObject();
		virtual void OnDelete() {}
		virtual void DeleteThis();
	};
}