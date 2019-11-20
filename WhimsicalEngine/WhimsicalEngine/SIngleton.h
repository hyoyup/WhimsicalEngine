#pragma once

template<typename T>
class LYSingleton
{
public:
    virtual                                         ~LYSingleton() = default;
    static T*                                       GetInstance();
    LYSingleton(const LYSingleton&)                 = delete;
    LYSingleton& operator= (const LYSingleton)      = delete;
    LYSingleton& operator= (const LYSingleton&&)    = delete;
	
	// Called only in DLL, for syncronize singleton instance
	static bool										_SetInstance(T* a_instance);

protected:
    LYSingleton()                                   = default;

private:
	static T*										m_Instance;
};

template<typename T>
T* LYSingleton<T>::m_Instance = nullptr;

template<typename T>
T* LYSingleton<T>::GetInstance()
{
	if (!LYSingleton<T>::m_Instance)
	{
		static T s_instance;
		LYSingleton<T>::m_Instance = &s_instance;
	}

	return LYSingleton<T>::m_Instance;}

/// return false if there already exists and override it
template<typename T>
bool LYSingleton<T>::_SetInstance(T* a_instance)
{
	bool b_alreadyExist = LYSingleton<T>::m_Instance != nullptr;

	LYSingleton<T>::m_Instance = a_instance;

	return b_alreadyExist;
}