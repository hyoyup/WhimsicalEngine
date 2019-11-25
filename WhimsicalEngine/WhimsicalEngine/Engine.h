
#pragma once
#ifndef W_ENGINE_H
#define W_ENGINE_H
//
//namespace DirectX
//{
//    class GamePad;
//}

//class LYApplication;
//class LYTimer;
//class LYRenderer;
//class LYFileManager;
//class LYResourceManager;
//class LYMaterialManager;
//class LYPrefabManager;
//class LYInputManager;
//class LYScriptManager;
//class LYGameObjectManager;
//class LYSystemManager;
//class LYEventManager;
//class LYSceneManager;
//class LYOctree;
//class LYPhysicsManager;
//class LYAudioManager;
//class LYUiManager;
//class LYMapManager;
//class LYThreadJobManager;
//class LYGameDataManager;

// forward declaration
class WEFrameRateManager;

class WEEngine :
    Singleton<WEEngine>
{
public:

    static constexpr float      STANDARD_CLIENT_WIDTH   = 1280.f;
    static constexpr float      STANDARD_CLIENT_HEIGHT  = 720.f;

                                WEEngine();
    virtual                     ~WEEngine();


    bool                        Initialize();
    bool                        Finalize();

    void                        Run();
    void                        DebugKeyInput();
    void                        TurnOnFullscreen();
    void                        TurnOffFullscreen();
    void                        ToggleScreenSize();

    void                        Pause(bool a_bPause);
    void                        Exit();

    //inline void                 BindApp(LYApplication* a_pApp, int a_iArgc, char** a_pszArgv);
    //inline LYApplication*       GetApp() const;

    //inline uint32               GetClientWidth() const;
    //inline uint32               GetClientHeight() const;

    //inline HWND                 GetWindowHandle() const;

    //inline bool                 IsFullScreen() const;

    //inline void                 ShowAndFocusWindow() const;

    bool                        LoadConfiguration();
    void                        LoadConfiguration(const std::string & a_filepath);
	
	/*	 TODO: ADD EACH MANAGER
	inline LYTimer*             GetTimer() const;
    inline LYRenderer*          GetRenderer() const;

    inline LYFileManager*       GetFileManager() const;
    inline LYResourceManager*   GetResourceManager() const;
    inline LYMaterialManager*   GetMaterialManager() const;
    inline LYPrefabManager*     GetPrefabManager() const;
    inline LYInputManager*      GetInputManager() const;
    inline LYScriptManager*     GetLyScriptManager() const;
    inline LYGameObjectManager* GetGameObjectManager() const;
    inline LYSystemManager*     GetSystemMananger() const;
    inline LYEventManager*      GetEventManager() const;
    inline LYSceneManager*      GetSceneManager() const;
    inline LYOctree*            GetOctree() const;
    inline LYPhysicsManager*    GetPhysicsManager() const;
    inline LYScriptManager*     GetScriptManager() const;
    inline LYAudioManager*      GetAudioManager() const;
    inline LYUiManager*         GetUiManager() const;
    inline LYMapManager*        GetMapManager() const;
    inline LYGameDataManager*   GetGameDataManager() const;
	
	*/

    inline bool IsDebugMode() { return m_bIsDebug; }

    inline uint32               GetCurrentResolutionIndex() const { return m_uCurrResolutionIndex; }
private:

    bool                        RegisterClass();
    //bool                        CreateWindow();
    bool                        ResizeWindow();
    bool                        DestoryWindowAnUnregisterClass();
    void                        ProcessWindowsMessages(MSG& a_message);
    void                        HandleSceneChange();
    void                        HandlePauseChange();
	void						MainLoop();

    static LRESULT CALLBACK     HWndProc(HWND a_hWindow, UINT a_uMessage, WPARAM a_uWideParam, LPARAM a_uLongParam);
    static LONG WINAPI          WndUnhandledExceptionProc(struct _EXCEPTION_POINTERS * a_pExceptionInfo);

private:


    HWND                        m_hWindow;
    HINSTANCE                   m_hInstance;
    std::vector<std::string>    m_AppArguments;

    uint32                      m_uClientWidth;
    uint32                      m_uClientHeight;

    uint32                      m_uPreviousClientWidth;
    uint32                      m_uPreviousClientHeight;

    uint32                      m_uWindowWidth;  // this is not the actual render width
    uint32                      m_uWindowHeight; // this is not the actual render height

    bool                        m_bIsRunning;
    bool                        m_bIsFullScreen;

    // Managers
	WEFrameRateManager*			m_pFrameRateManager;
 //   LYFileManager*              m_pFileManager;
 //   LYResourceManager*          m_pResourceManager;
 //   LYMaterialManager*          m_pMaterialManager;
 //   LYPrefabManager*            m_pPrefabManager;
 //   LYInputManager*             m_pInputManager;
	//LYScriptManager*			m_pScriptManager;
 //   LYGameObjectManager*        m_pGameObjectManager;
 //   LYSystemManager*            m_pSystemManager;
 //   LYEventManager*             m_pEventManager;
 //   LYSceneManager*             m_pSceneManager;
 //   LYOctree*                   m_pOctree;
 //   LYPhysicsManager*           m_pPhysicsManager;
 //   LYAudioManager*             m_pAudioManager;
 //   LYUiManager*                m_pUiManager;
 //   LYMapManager*               m_pMapManager;
 //   LYThreadJobManager*         m_pThreadJobManager;
 //   LYGameDataManager*          m_pGameDataManager;

    // APIs
    //LYTimer*                    m_pTimer;
    //LYRenderer*                 m_pRenderer;

    bool                        m_bIsPaused = false;
    bool                        m_bDirtyPause = false;
    bool                        m_bLockUnPause = false;
    bool                        m_bIsDebug = false;
    bool                        m_bLevelEditorMode = false;
    bool                        m_bRenderImGui = true;
    bool                        m_bMultiThread = false;

    struct ResolutionSetting {
        uint32 m_uWidth, m_uHeight;
    };
    enum Resolutions {
        eResolutions_1280x720,
        eResolutions_1600x900,
        eResolutions_1920x1080,
        eResolutions_Fullscreen,

        eResolutions_Max
    };
    ResolutionSetting           m_Resolutions[eResolutions_Max];
    uint32                      m_uCurrResolutionIndex = 0;
};

#define GWE_Engine Singleton<WEEngine>::GetInstance();
#define GWE_Time Singleton<FrameRateManager>::GetInstance();

#endif