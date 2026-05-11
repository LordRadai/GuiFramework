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

		typedef GUISystem* (_fastcall* GetGUISystem_t)(const GUILayoutItem*);
		typedef Rect(_fastcall* GetMaxSize_t)(const GUILayoutItem*);
		typedef Rect(_fastcall* GetMinSize_t)(const GUILayoutItem*);
		typedef Rect(_fastcall* GetIdealSize_t)(const GUILayoutItem*);
		typedef void(_fastcall* SetGeometry_t)(GUILayoutItem*, const Rect&);
		typedef Rect(_fastcall* GetGeometry_t)(const GUILayoutItem*);
		typedef dl_bool(_fastcall* IsOwn_t)(const GUILayoutItem*, GUIObject*);

#define SIGNAL_ON_SIZE_CHANGED (GUISignal*)(MODULE_ADDR + 0x1618530);
	};
}