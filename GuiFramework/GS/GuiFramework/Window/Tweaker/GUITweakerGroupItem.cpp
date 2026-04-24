#include "GUITweakerGroupItem.h"
#include "GUITweakerGroup.h"
#include <Call.h>

namespace GuiFramework
{
	typedef void(__fastcall* Constructor_t)(GUITweakerGroupItem*, GUITweakerGroup*);

	GUITweakerGroupItem::GUITweakerGroupItem(GUITweakerGroup* pGroup)
	{
		CALL(Constructor_t, 0x5557c0, this, pGroup);
	}

	DLRF::DLRuntimeClass* GUITweakerGroupItem::GetRuntimeClassOfThis() const
	{
		return CALL(GetRuntimeClassOfThis_t, 0x555770, this);
	}

	GUITweakerGroupItem::~GUITweakerGroupItem()
	{
		CALL(Destructor_t, 0x555cb0, this);
	}

	void GUITweakerGroupItem::OnDelete()
	{
		CALL(OnDelete_t, 0x555910, this);
	}

	void GUITweakerGroupItem::Update(dl_float32 dt)
	{
		CALL(Update_t, 0x5558a0, this, dt);
	}
}