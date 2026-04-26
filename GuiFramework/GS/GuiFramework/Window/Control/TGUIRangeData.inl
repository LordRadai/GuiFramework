#pragma once
#include "GUIRangeDataBase.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIRangeData : public GUIRangeDataBase
	{
		typedef TGUIRangeData<T> ThisClass;
		typedef GUIRangeDataBase SuperClass;
	public:
		virtual ~TGUIRangeData() override
		{
			Finalize();
		}

		virtual dl_bool StringToValue(const dl_wchar* str) override
		{
			T oldValue = this->m_value;
			T newValue = static_cast<T>(std::stoll(str));

			if (newValue < this->m_min)
				newValue = this->m_min;

			else if (newValue > this->m_max)
				newValue = this->m_max;

			this->m_value = newValue;

			return (oldValue != this->m_value);
		}

		virtual dl_bool ValueToString(DLTX::DLString& str) const override
		{
			T value = this->m_value;
			DLTX::DLFormat::Format(&str, L"%lld", value);

			return true;
		}

		virtual dl_bool MoveValue(dl_uint direction, dl_uint isLargeStep) override
		{
			dl_int oldValue = this->m_value;
			dl_int multiplier = (isLargeStep == 0) ? 1 : 10;

			dl_int offset = this->m_stepSize * direction * multiplier;
			this->m_value += offset;

			if (direction < 1)
			{
				if (oldValue < this->m_value)
					this->m_value = this->m_min;
			}
			else if (this->m_value < oldValue)
			{
				this->m_value = this->m_max;
			}

			if (this->m_value < this->m_min)
				this->m_value = this->m_min;
			else if (this->m_value > this->m_max)
				this->m_value = this->m_max;

			return (oldValue != this->m_value);
		}

		virtual void ResetToOriginal() override
		{
			this->m_value = this->m_original;
		}

		virtual void GetSliderRange(dl_int& min, dl_int& max) const override
		{
			_GetSliderRange(min, max);
		}

		virtual dl_bool SliderToValue(dl_int sliderPos) override
		{
			dl_int oldValue = this->m_value;
			this->m_value = _SliderToValue(sliderPos);

			return (oldValue != this->m_value);
		}

		virtual dl_uint ValueToSlider() const override
		{
			return _ValueToSlider(this->m_value);
		}
	private:
		void _GetSliderRange(dl_int& min, dl_int& max, ...) const
		{
			min = 0;
			if constexpr (std::is_floating_point_v<T>)
				max = static_cast<dl_int>(std::ceil((this->m_max - this->m_min) / this->m_step));
			else
				max = static_cast<dl_int>((this->m_max - this->m_min + this->m_step - 1) / this->m_step);

			if (max > 65535) max = 65535;
		}

		T _SliderToValue(dl_int sliderPos) const
		{
			dl_float64 valueInterval = static_cast<dl_float64>(this->m_max) - static_cast<dl_float64>(this->m_min);
			dl_float64 numSteps = (this->m_step > 0) ? std::ceil(valueInterval / static_cast<dl_float64>(this->m_step)) : 0;

			dl_float64 result;
			if (numSteps < 65535.0)
				result = (static_cast<dl_float64>(sliderPos) * static_cast<dl_float64>(this->m_step)) + static_cast<dl_float64>(this->m_min);
			else
				result = (static_cast<dl_float64>(sliderPos) * valueInterval) / 65535.0 + static_cast<dl_float64>(this->m_min);

			if (result < static_cast<dl_float64>(this->m_min)) return this->m_min;
			if (result > static_cast<dl_float64>(this->m_max)) return this->m_max;

			return static_cast<T>(result);
		}

		dl_uint _ValueToSlider(dl_int sliderPos) const
		{
			dl_uint sliderValue;
			dl_int min, max;
			_GetSliderRange(min, max);

			if (max > 65535)
				sliderValue = static_cast<dl_uint>(((static_cast<dl_float64>(this->m_value) - static_cast<dl_float64>(this->m_min)) * static_cast<T>(65535)) / (static_cast<dl_float64>(this->m_max) - static_cast<dl_float64>(this->m_min)));
			else
				sliderValue = static_cast<dl_uint>((static_cast<dl_float64>(this->m_value - this->m_min) / static_cast<dl_float64>(this->m_step)));

			return sliderValue;
		}

		T m_max;
		T m_min;
		T m_value;
		T m_step;
		T m_original;
		T m_mult;
	};

	template<>
	inline dl_bool TGUIRangeData<dl_float32>::StringToValue(const dl_wchar* str)
	{
		try
		{
			dl_float32 oldValue = this->m_value;
			dl_float32 newValue;

			dl_float64 parsedValue = std::stod(str);

			if (this->m_mult == 1.0f)
				newValue = static_cast<dl_float32>(parsedValue);
			else
				newValue = static_cast<dl_float32>(parsedValue) / this->m_mult;

			dl_float32 finalValue = newValue;

			if (newValue < this->m_min)
				finalValue = this->m_min;
			else if (newValue > this->m_max)
				finalValue = this->m_max;

			this->m_value = finalValue;

			return (oldValue != this->m_value);
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	template<>
	inline dl_bool TGUIRangeData<dl_float32>::ValueToString(DLTX::DLString& str) const
	{
		dl_float32 value = this->m_value;

		if (this->m_mult != 1.f)
			value = this->m_value * this->m_mult;

		DLTX::DLFormat::Format(&str, L"%.4f", value);

		return true;
	}

	template<>
	inline dl_bool TGUIRangeData<dl_float64>::StringToValue(const dl_wchar* str)
	{
		try
		{
			dl_float64 oldValue = this->m_value;
			dl_float64 newValue = std::stod(str);

			if (newValue < this->m_min)
				newValue = this->m_min;
			else if (newValue > this->m_max)
				newValue = this->m_max;

			this->m_value = newValue;

			return (oldValue != this->m_value);
		}
		catch (const std::exception&)
		{
			return false;
		}
	}

	template<>
	inline dl_bool TGUIRangeData<dl_float64>::ValueToString(DLTX::DLString& str) const
	{
		dl_float64 value = this->m_value;
		DLTX::DLFormat::Format(&str, L"%.4f", value);
		return true;
	}
}