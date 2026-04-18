#include "GUILayouter.h"

namespace GuiFramework
{
	DLRF::DLRuntimeClass* GUILayouter::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClass_t, 0x5c08f0, this);
	}

	GUILayouter::~GUILayouter()
	{
		CALL(Destructor_t, 0x5c1c60, this);
	}

	void GUILayouter::OnDelete()
	{
		CALL(OnDelete_t, 0x5c11b0, this);
	}

	GUISystem* GUILayouter::GetGUISystem() const
	{
		return CALL(GetGUISystem_t, 0x5c3100, this);
	}

	Rect GUILayouter::GetMaxSize() const
	{
		return CALL(GetMaxSize_t, 0x5c1210, this);
	}

	Rect GUILayouter::GetMinSize() const
	{
		return CALL(GetMinSize_t, 0x5c1250, this);
	}

	Rect GUILayouter::GetIdealSize() const
	{
		return CALL(GetIdealSize_t, 0x5c1290, this);
	}

	void GUILayouter::SetGeometry(const Rect& rect)
	{
		CALL(SetGeometry_t, 0x5c3490, this, rect);
	}

	Rect GUILayouter::GetGeometry() const
	{
		return CALL(GetGeometry_t, 0x5c12d0, this);
	}

	dl_bool GUILayouter::IsOwn(GUIObject* pObject) const
	{
		return CALL(IsOwn_t, 0x5c1310, this, pObject);
	}
}
