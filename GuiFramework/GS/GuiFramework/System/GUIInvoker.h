#pragma once
#include <dantelion2.h>

namespace GuiFramework
{
	class GUIInvoker
	{
		typedef GUIInvoker ThisClass;
	public:
		GUIInvoker() {}

		virtual ~GUIInvoker() {}
		virtual void Invoke(DLRF::DLMethodInvokeContext* pCtx) = 0;
		virtual void Invoke(DLRF::DLMethodInvokeContext* pCtx, dl_pointer pSignalInfo) = 0;
	};
}