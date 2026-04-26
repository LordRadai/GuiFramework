#pragma once
#include "GuiFramework/System/GUIObject.h"

namespace GuiFramework
{
	class GUIRangeDataBase : public GUIObject
	{
		typedef GUIRangeDataBase ThisClass;
		typedef GUIObject SuperClass;
	public:
		GUIRangeDataBase();

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIRangeDataBase() override;
		virtual dl_bool StringToValue(const dl_wchar* str) = 0;
		virtual dl_bool ValueToString(DLTX::DLString& str) const = 0;
		virtual dl_bool MoveValue(dl_uint direction, dl_uint step) = 0;
		virtual void ResetToOriginal() = 0;
		virtual void GetSliderRange(dl_int& min, dl_int& max) const = 0;
		virtual dl_bool SliderToValue(dl_int sliderPos) = 0;
		virtual dl_uint ValueToSlider() const = 0;

		void Finalize();
	};
}
