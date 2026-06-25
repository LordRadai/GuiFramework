#pragma once
#include "GUICallbackObjectBase.h"

#include <functional>

namespace GuiFramework
{
	class TGUICallbackObject0 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject0() {}

		TGUICallbackObject0(std::function<void()> callback) : GUICallbackObjectBase()
		{
			this->m_callback = callback;
		}

		~TGUICallbackObject0() override {}

		void Invoke() override
		{
			this->m_callback();
		}

	private:
		std::function<void()> m_callback;
	};

	template<typename T>
	class TGUICallbackObject1 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject1() {}

		TGUICallbackObject1(std::function<void(T)> callback, T param_1) : GUICallbackObjectBase()
		{
			this->m_arg1 = param_1;
			this->m_callback = callback;
		}

		~TGUICallbackObject1() override {}

		void Invoke() override
		{
			this->m_callback(this->m_arg1);
		}

	private:
		T m_arg1;
		std::function<void(T)> m_callback;
	};

	template<typename T, typename U>
	class TGUICallbackObject2 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject2() {}

		TGUICallbackObject2(std::function<void(T, U)> callback, T param_1, U param_2) : GUICallbackObjectBase()
		{
			this->m_arg1 = param_1;
			this->m_arg2 = param_2;
			this->m_callback = callback;
		}

		~TGUICallbackObject2() override {}

		void Invoke() override
		{
			this->m_callback(this->m_arg1, this->m_arg2);
		}

	private:
		T m_arg1;
		U m_arg2;
		std::function<void(T, U)> m_callback;
	};

	template<typename T, typename U, typename V>
	class TGUICallbackObject3 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject3() {}

		TGUICallbackObject3(std::function<void(T, U, V)> callback, T param_1, U param_2, V param_3) : GUICallbackObjectBase()
		{
			this->m_arg1 = param_1;
			this->m_arg2 = param_2;
			this->m_arg3 = param_3;
			this->m_callback = callback;
		}

		~TGUICallbackObject3() override {}

		void Invoke() override
		{
			this->m_callback(this->m_arg1, this->m_arg2, this->m_arg3);
		}

	private:
		T m_arg1;
		U m_arg2;
		V m_arg3;
		std::function<void(T, U, V)> m_callback;
	};

	template<typename T, typename U, typename V, typename W>
	class TGUICallbackObject4 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject4() {}

		TGUICallbackObject4(std::function<void(T, U, V, W)> callback, T param_1, U param_2, V param_3, W param_4) : GUICallbackObjectBase()
		{
			this->m_arg1 = param_1;
			this->m_arg2 = param_2;
			this->m_arg3 = param_3;
			this->m_arg4 = param_4;
			this->m_callback = callback;
		}

		~TGUICallbackObject4() override {}

		void Invoke() override
		{
			this->m_callback(this->m_arg1, this->m_arg2, this->m_arg3, this->m_arg4);
		}

	private:
		T m_arg1;
		U m_arg2;
		V m_arg3;
		W m_arg4;
		std::function<void(T, U, V, W)> m_callback;
	};
}