#pragma once

template<typename T>
class Singleton
{
public:
    virtual                                         ~Singleton() = default;
    static T*                                       GetInstance();
    Singleton(const Singleton&)                 = delete;
    Singleton& operator= (const Singleton)      = delete;
    Singleton& operator= (const Singleton&&)    = delete;
	
	// Called only in DLL, for syncronize singleton instance
	static bool										_SetInstance(T* a_instance);

protected:
    Singleton()                                   = default;

private:
	static T*										m_Instance;
};

template<typename T>
T* Singleton<T>::m_Instance = nullptr;

template<typename T>
T* Singleton<T>::GetInstance()
{
	if (!Singleton<T>::m_Instance)
	{
		static T s_instance;
		Singleton<T>::m_Instance = &s_instance;
	}

	return Singleton<T>::m_Instance;}

/// return false if there already exists and override it
template<typename T>
bool Singleton<T>::_SetInstance(T* a_instance)
{
	bool b_alreadyExist = Singleton<T>::m_Instance != nullptr;

	Singleton<T>::m_Instance = a_instance;

	return b_alreadyExist;
}