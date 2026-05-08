#pragma once
#include "GUIObject.h"
#include "TGUISharedString.inl"

namespace GuiFramework
{
	template<typename T>
	class TGUI_VALUE_STRING_PAIR
	{
	public:
		TGUI_VALUE_STRING_PAIR() : m_value(), m_string() {}
		TGUI_VALUE_STRING_PAIR(const T& value, const TGUISharedString<T>& str) : m_value(value), m_string(str) {}

		inline TGUI_VALUE_STRING_PAIR<T>& operator=(const TGUI_VALUE_STRING_PAIR<T>& other)
		{
			m_string = other.m_string;
			m_value = other.m_value;

			return *this;
		}

		TGUISharedString<T> m_string;
		T m_value;
	};

	template<typename T>
	struct TGUI_COMBO_TWEAKER_ITEM
	{
		const dl_wchar* Name;
		T Value;

		TGUI_COMBO_TWEAKER_ITEM() : Name(nullptr), Value() {}
		TGUI_COMBO_TWEAKER_ITEM(const dl_wchar* name, T value) : Name(name), Value(value) {}
	};

	template<typename T>
	class TGUIValueStringPairData : public GUIObject
	{
		typedef TGUIValueStringPairData<T> ThisClass;
		typedef GUIObject SuperClass;
	public:
		TGUIValueStringPairData() : SuperClass() {}

		TGUIValueStringPairData(TGUI_COMBO_TWEAKER_ITEM<T>* items, dl_uint numItems) : SuperClass()
		{
			for (dl_uint i = 0; i < numItems; ++i)
				AddPair(items[i].Value, items[i].Name);
		}

		void AddPair(const T& value, const TGUISharedString<T>& str)
		{
			TGUI_VALUE_STRING_PAIR<T>* pNewPair = new TGUI_VALUE_STRING_PAIR<T>(value, str);
			m_pairs.push_back(pNewPair);
		}

		void RemovePair(dl_int index)
		{
			if (index < 0 || index >= m_pairs.size())
				return;

			TGUI_VALUE_STRING_PAIR<T>* pPair = m_pairs[index];

			if (pPair != nullptr)
				delete pPair;

			m_pairs.erase(m_pairs.begin() + index);
		}

		void ClearPairs()
		{
			for (auto* pPair : m_pairs)
			{
				if (pPair != nullptr)
					delete pPair;
			}

			m_pairs.clear();
		}

		TGUI_COMBO_TWEAKER_ITEM<T>* GetValueStringPair(dl_int index) const
		{
			if (index < 0 || index >= m_pairs.size())
				return nullptr;

			return m_pairs[index];
		}

		T GetValueByIndex(dl_int index) const
		{
			TGUI_COMBO_TWEAKER_ITEM<T>* pPair = GetValueStringPair(index);
			return pPair ? pPair->Value : T();
		}

		T GetValueByString(const TGUISharedString<T>& str) const
		{
			for (dl_int i = 0; i < m_pairs.size(); ++i)
			{
				TGUI_COMBO_TWEAKER_ITEM<T>* pPair = m_pairs[i];

				if (pPair != nullptr && pPair->Name == str)
					return pPair->Value;
			}

			return T();
		}

		const dl_wchar* GetStringByValue(const T& value) const
		{
			for (dl_int i = 0; i < m_pairs.size(); ++i)
			{
				TGUI_COMBO_TWEAKER_ITEM<T>* pPair = m_pairs[i];

				if (pPair != nullptr && pPair->Value == value)
					return pPair->Name;
			}

			return nullptr;
		}

		dl_uint FindIndexByValue(const T& value) const
		{
			for (dl_int i = 0; i < m_pairs.size(); ++i)
			{
				TGUI_COMBO_TWEAKER_ITEM<T>* pPair = m_pairs[i];

				if (pPair != nullptr && pPair->Value == value)
					return i;
			}

			return -1;
		}

		dl_size GetNumPairs() const { return m_pairs.size(); }

	protected:
		DLUT::DLVector<TGUI_COMBO_TWEAKER_ITEM<T>*> m_pairs;
	};
}