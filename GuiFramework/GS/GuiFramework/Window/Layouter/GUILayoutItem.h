#pragma once
#include "GuiFramework/System/GUIMsgReceiver.h"
#include "GuiFramework/System/TGUIRect.inl"

namespace GuiFramework
{
	class GUISystem;

	class GUILayoutItem : public GUIMsgReceiver
	{
	public:
		GUILayoutItem() : GUIMsgReceiver() {}

		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const override;
		virtual ~GUILayoutItem() override;
		virtual void OnDelete() override {}
		virtual GUISystem* GetGUISystem() const = 0;
		virtual Rect GetMaxSize() const = 0;
		virtual Rect GetMinSize() const = 0;
		virtual Rect GetIdealSize() const = 0;
		virtual void SetGeometry(const Rect& rect) = 0;
		virtual Rect GetGeometry() const = 0;
		virtual dl_bool IsOwn(GUIObject* pObject) const = 0;

		typedef GUISystem* (__fastcall* GetGUISystem_t)(const GUILayoutItem*);
		typedef Rect(__fastcall* GetMaxSize_t)(const GUILayoutItem*);
		typedef Rect(__fastcall* GetMinSize_t)(const GUILayoutItem*);
		typedef Rect(__fastcall* GetIdealSize_t)(const GUILayoutItem*);
		typedef void(__fastcall* SetGeometry_t)(GUILayoutItem*, const Rect&);
		typedef Rect(__fastcall* GetGeometry_t)(const GUILayoutItem*);
		typedef dl_bool(__fastcall* IsOwn_t)(const GUILayoutItem*, GUIObject*);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(size, 8, GUI_ALLOCATOR);
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GUI_ALLOCATOR);
		}
	};
}