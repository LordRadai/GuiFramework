#pragma once
#include "GUIObject.h"
#include "TGUISharedString.inl"

namespace GuiFramework
{
	class GUITweakerDialog;

	class GUIFont : public GUIObject
	{
		typedef GUIFont ThisClass;
		typedef GUIObject SuperClass;
	public:
		GUIFont();

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUIFont() override;
		virtual void OnDelete() override {}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}

		void CreateTweaker(TGUISharedString<dl_wchar>& title, GUITweakerDialog* pWnd);

	private:
		DLMT::DL_COLOR_32 m_color;
		DLMT::DL_VECTOR2 m_size;
		DLMT::DL_VECTOR2 m_shadowOffset;
		dl_bool m_hasShadow;
		dl_bool m_isBold;
		dl_uchar m_horizontalAlign;
		dl_uchar m_verticalAlign;
		dl_int m_fontId;
		dl_int m_height;
		dl_int m_defaultHeight;
	};
}
