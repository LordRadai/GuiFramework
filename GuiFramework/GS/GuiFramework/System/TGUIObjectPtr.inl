#pragma once

template<typename T>
class TGUIObjectPtr
{
	T* m_pPtr;
public:
	T& operator*() const { return *m_pPtr; }
	T* operator->() const { return m_pPtr; }
	void operator=(T* pPtr) { m_pPtr = pPtr; }
};