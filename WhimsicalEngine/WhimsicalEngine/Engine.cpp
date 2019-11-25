
#include "pch.h"

#define BENCHMARK_MODE 0

WEEngine::WEEngine() :
    m_hWindow(nullptr),
    m_hInstance(nullptr),
    //m_uClientWidth(c_uBasicClientWidth),
    //m_uClientHeight(c_uBasicClientHeight),
    m_uClientWidth(uint32(STANDARD_CLIENT_WIDTH)),
    m_uClientHeight(uint32(STANDARD_CLIENT_HEIGHT)),
    m_uWindowWidth(0),
    m_uWindowHeight(0),
    m_bIsRunning(false),
    m_bIsFullScreen(false),
    m_pFrameRateManager(new WEFrameRateManager)
{
    //LY_LOG_INFO_FMT("Welcome to Whimsical Engine! Build date: {} {}", __DATE__, __TIME__);

    m_Resolutions[eResolutions_1280x720] = { 1280, 720 };
    m_Resolutions[eResolutions_1600x900] = { 1600, 900 };
    m_Resolutions[eResolutions_1920x1080] = { 1920, 1080 };
    m_Resolutions[eResolutions_Fullscreen] = { 0, 0 };
}

WEEngine::~WEEngine()
{
	// LY_SAFE_DELETE(m_pFrameRateManager);
	delete m_pFrameRateManager;
}

bool WEEngine::Initialize()
{
    StopWatch sw;

    ::SetUnhandledExceptionFilter(LPTOP_LEVEL_EXCEPTION_FILTER(WndUnhandledExceptionProc));

    HRESULT hr = ::CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
    if (FAILED(hr))
    {
        //LY_ASSERT_RF(0, "LYResourceManager::CoInitializeEx Failed!");
    }

    //LY_ASSERT_RF(m_pApp, "Need To BIND an App!!");

 //   LY_SAFE_PTR_INIT_CHECK(m_pFileManager, "LYEngine::m_pFileManager");

	//LY_SAFE_PTR_INIT_CHECK(m_pScriptManager, "LYEngine::m_pScriptManager");

 //   LY_SAFE_FUNC_CHECK(SyncEngineInstanceWithPyModule, "LYEngine::SyncEngineInstanceWithPyModule", true);

 //   LY_SAFE_FUNC_CHECK(RegisterClass, "LYEngine::RegisterClass", true);

 //   LY_SAFE_FUNC_CHECK(CreateWindow, "LYEngine::CreateWindow", true);

 //   LY_SAFE_PTR_INIT_CHECK(m_pSceneManager, "LYEngine::m_pSceneManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pInputManager, "LYEngine::m_pInputManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pRenderer, "LYEngine::m_Renderer");

 //   LY_SAFE_PTR_INIT_CHECK(m_pSystemManager, "LYEngine::m_pSystemManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pResourceManager, "LYEngine::m_pResourceManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pMaterialManager, "LYEngine::m_pMaterialManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pPrefabManager, "LYEngine::m_pPrefabManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pOctree, "LYEngine::m_pOctree");

 //   LY_SAFE_PTR_INIT_CHECK(m_pAudioManager, "LYEngine::m_pAudioManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pUiManager, "LYEngine::m_pUiManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pThreadJobManager, "LYEngine::m_pThreadJobManager");

 //   LY_SAFE_PTR_INIT_CHECK(m_pGameDataManager, "LYEngine::m_pGameDataManager");

 //   LY_LOG_INFO_FMT("LYEngine has been initialzed. Time elasped: {} ms", sw.ElapsedInMs());

    sw.Reset();

    //LY_SAFE_PTR_INIT_CHECK(m_pApp, "LYEngine::m_pApp");  // <- this is the last thing to initialze since this is the game itself!

    LoadConfiguration();

    //m_pRenderer->AddImGuiCallback(LYImGuiManager::CreateImGuiWindows);
    //m_pRenderer->AddImGuiCallback(LYMaterialManager::RenderMaterialImGuiWindow);
    //m_pRenderer->AddImGuiCallback(LYPrefabManager::RenderPrefabImGuiWindow);
    //m_pRenderer->SetScreenQuad(m_pResourceManager->GetMeshByName(LY_PRIMITIVE_QUAD));

    //ShowAndFocusWindow();

    m_bIsRunning = true;

    //GLYMemory->PrintStats();

    //LY_LOG_INFO_FMT("App {} has been initialzed. Time elasped: {} ms.", m_pApp->GetAppName(), sw.ElapsedInMs());

    return true;
}

bool WEEngine::LoadConfiguration()
{
    //using namespace LYJsonWrapper;

    //LY_LOG_INFO("Loading config file");
    //std::ifstream configFile("config.json");
    //rapidjson::IStreamWrapper isw(configFile);

    //rapidjson::Document configJson;
    //configJson.ParseStream(isw);
    //
    //LY_LOG_INFO("Reading scene config file.");
    //m_pSceneManager->LoadConfiguration(GetRequiredParam<const char *>(configJson, "scene_config"));
    //LY_LOG_INFO("Reading renderer config file.");
    //m_pPhysicsManager->LoadConfiguration(GetRequiredParam<const char*>(configJson, "physics_config"));
    //LY_LOG_INFO("Reading physics config file.");
    //m_pRenderer->LoadConfiguration(GetRequiredParam<const char *>(configJson, "renderer_config"));
    //LY_LOG_INFO("Reading engine config file.");
    //LoadConfiguration(GetRequiredParam<const char *>(configJson, "engine_config"));
    //LY_LOG_INFO("Config files successfully read.");

    return true;
}

void WEEngine::LoadConfiguration(const std::string & a_filepath)
{
    //// open the JSON file
    //std::string engineFile = GLYEngine->GetResourceManager()->LoadTextFile(a_filepath.c_str());

    //// loop through the engine config
    //rapidjson::Document engineJSON;
    //engineJSON.Parse(engineFile.c_str());

    //m_bLevelEditorMode = engineJSON["LEVEL_EDIT_MODE"].GetBool();
    //m_bRenderImGui = engineJSON["RENDER_IMGUI"].GetBool();
    //m_bMultiThread = engineJSON["MULTITHREAD"].GetBool();

    //m_bIsFullScreen = engineJSON["WINDOW_SETTINGS"]["FULLSCREEN"].GetBool();
    //ShowCursor(engineJSON["SHOW_CURSOR"].GetBool());
    ////m_uPreviousClientWidth = engineJSON["WINDOW_SETTINGS"]["WIDTH"].GetUint();
    ////m_uPreviousClientHeight = engineJSON["WINDOW_SETTINGS"]["HEIGHT"].GetUint();

    //if (m_bIsFullScreen)
    //{
    //    m_uCurrResolutionIndex = eResolutions_Max - 1;
    //    TurnOnFullscreen();
    //}
    //else
    //{
    //    ToggleScreenSize();
    //}
}

// Finalization should be the reversed order of their initialization!
bool WEEngine::Finalize()
{
 //   LY_SAFE_PTR_FINAL_CHECK(m_pGameDataManager, "LYEngine::m_pGameDataManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pThreadJobManager, "LYEngine::m_pThreadJobManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pApp, "LYEngine::m_pApp");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pOctree, "LYEngine::m_pOctree");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pResourceManager, "LYEngine::m_pResourceManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pSystemManager, "LYEngine::m_pSystemManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pInputManager, "LYEngine::m_pInputManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pRenderer, "LYEngine::m_Renderer");

 //   LY_SAFE_FUNC_CHECK(DestoryWindowAnUnregisterClass, "DestoryWindowAnUnregisterClass", false);

	//LY_SAFE_PTR_FINAL_CHECK(m_pScriptManager, "LYEngine::m_pScriptManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pFileManager, "LYEngine::m_pFileManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pAudioManager, "LYEngine::m_pAudioManager");

 //   LY_SAFE_PTR_FINAL_CHECK(m_pUiManager, "LYEngine::m_pUiManager");

 //   GLYMemory->PrintStats();

    ::CoUninitialize();
    return true;
}

void WEEngine::Run()
{
	m_pFrameRateManager->Reset();
	MSG Message;
	ZeroMemory(&Message, sizeof(MSG));

	while (m_bIsRunning)
	{
		HandlePauseChange();
		HandleSceneChange();
		ProcessWindowsMessages(Message);

		MainLoopSingleThread();

		m_pTimer->CalculateFrameStats();
	}
}

void LYEngine::MainLoopSingleThread()
{

#if BENCHMARK_MODE
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
#endif
    m_pTimer->Tick();

    // deferred deleting of game objects
    m_pGameObjectManager->Update();

    m_pSystemManager->InitializeSystems();

    m_pInputManager->Update();

    DebugKeyInput();

	m_pEventManager->Update();

    m_pSystemManager->Update(m_bIsPaused);

    m_pRenderer->RenderOneFrame(m_bRenderImGui);

    m_pAudioManager->Update();

    m_pTimer->Throttle();

    // in case you feel like benchmarking, use the code below.
#if BENCHMARK_MODE
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "/************ Time elapesd: " << elapsed.count() << std::endl;
#endif
}

void LYEngine::MainSimulationLoop()
{
#if BENCHMARK_MODE
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
#endif

    // deferred deleting of game objects
    m_pGameObjectManager->Update();

    m_pTimer->Tick();

    m_pSystemManager->InitializeSystems();

    m_pInputManager->Update();

    DebugKeyInput();

	m_pEventManager->Update();

    m_pSystemManager->Update(m_bIsPaused);
    
    m_pAudioManager->Update();

    m_pTimer->Throttle();

    // in case you feel like benchmar king, use the code below.
#if BENCHMARK_MODE
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "/************ Time elapesd: " << elapsed.count() << std::endl;
#endif

    m_pTimer->CalculateFrameStats();
}

void LYEngine::DebugKeyInput()
{

    if (m_pInputManager->IsKeyReleased(LYKeys::Escape))
    {
        if (!m_pSceneManager->IsCurrentScenePausable() && !m_bLockUnPause)
        {
            LY_LOG_INFO("ESC Released: About to quit the engine...Bye!");
            m_bIsRunning = false;
        }
        else
        {
            if (!m_bLockUnPause)
            {
                Pause(!m_bIsPaused);
            }
        }
    }

    if (m_pInputManager->IsKeyTriggered(LYKeys::F1))
    {
        LY_LOG_INFO("Reload Python Scripts");
        m_pScriptManager->ReloadAllPyScripts();
    }

    if (m_pInputManager->IsKeyTriggered(LYKeys::F2))
    {
        m_pEventManager->BroadcastEventToSubscribers(new LYDebugEvent);
    }

	if (m_pInputManager->IsKeyTriggered(LYKeys::F8))
	{
		m_pAudioManager->ToggleBGM();
	}

    if (m_pInputManager->IsKeyReleased(LYKeys::F11))
    {
        m_uCurrResolutionIndex++;
        if (m_uCurrResolutionIndex >= eResolutions_Max)
            m_uCurrResolutionIndex = 0;

        if (m_uCurrResolutionIndex == eResolutions_Fullscreen)
            TurnOnFullscreen();
        else
            ToggleScreenSize();
    }

    if (m_pInputManager->IsKeyTriggered(LYKeys::X))
    {
        //m_bIsPaused = !m_bIsPaused;
    }
    //if (m_pInputManager->IsKeyTriggered(LYKeys::D))
    //{
    //    m_bIsDebug = !m_bIsDebug;
    //}
}

void LYEngine::TurnOnFullscreen()
{
    m_uClientWidth = ::GetSystemMetrics(SM_CXSCREEN);
    m_uClientHeight = ::GetSystemMetrics(SM_CYSCREEN);
    m_bIsFullScreen = true;

    LY_LOG_DEBUG("Resizing...");
    ResizeWindow();
    if (!m_pRenderer->ResizeBuffers(m_bIsFullScreen, m_uClientWidth, m_uClientHeight, m_uCurrResolutionIndex, true))
    {
        LY_LOG_CRITCAL("Failed to resize buffers properly.");
    }
}

void LYEngine::TurnOffFullscreen()
{
    m_uClientWidth = m_uPreviousClientWidth;
    m_uClientHeight = m_uPreviousClientHeight;
    m_bIsFullScreen = false;

    LY_LOG_DEBUG("Resizing...");
    ResizeWindow();
    if (!m_pRenderer->ResizeBuffers(m_bIsFullScreen, m_uClientWidth, m_uClientHeight, true))
    {
        LY_LOG_CRITCAL("Failed to resize buffers properly.");
    }
}

void LYEngine::ToggleScreenSize()
{
    m_uClientWidth = m_Resolutions[m_uCurrResolutionIndex].m_uWidth;
    m_uClientHeight = m_Resolutions[m_uCurrResolutionIndex].m_uHeight;
    m_bIsFullScreen = false;

    LY_LOG_DEBUG("Resizing...");
    if (!ResizeWindow())
    {
        LY_LOG_CRITCAL("Window failed to resize buffers properly.");
    }
    if (!m_pRenderer->ResizeBuffers(m_bIsFullScreen, m_uClientWidth, m_uClientHeight, m_uCurrResolutionIndex, true))
    {
        LY_LOG_CRITCAL("Buffers failed to resize buffers properly.");
    }
}

void LYEngine::Pause(bool a_bPause)
{
    if (m_bIsPaused != a_bPause)
    {
        m_bDirtyPause = true;
    }
}

void LYEngine::Exit()
{
    m_bIsRunning = false;
}

bool LYEngine::RegisterClass()
{
    m_hInstance = ::GetModuleHandle(nullptr);
    LY_ASSERT_RF(m_hInstance, "GetModuleHandle Failed.");

    // Below are place holders
    LPCSTR pszIconID = nullptr;
    LPCSTR pszSmallIconID = nullptr;
    LPCSTR pszCursorID = nullptr;
    LPCSTR pszMenuID = nullptr;

    WNDCLASSEX WndClass;
    ZeroMemory(&WndClass, sizeof(WndClass));
    WndClass.cbSize = sizeof(WNDCLASSEX);
    WndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    WndClass.lpfnWndProc = HWndProc;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = m_hInstance;
    WndClass.hIcon = pszIconID ? LoadIcon(m_hInstance, pszIconID) : LoadIcon(nullptr, IDI_APPLICATION);
    WndClass.hCursor = pszCursorID ? LoadCursor(m_hInstance, pszCursorID) : LoadCursor(nullptr, IDC_ARROW);
    WndClass.hbrBackground = (HBRUSH)::GetStockObject(BLACK_BRUSH);
    WndClass.lpszMenuName = pszMenuID;
    WndClass.lpszClassName = m_pApp->GetClassName();
    WndClass.hIconSm = pszSmallIconID ? LoadIcon(m_hInstance, pszSmallIconID) : WndClass.hIcon;

    if (!::RegisterClassEx(&WndClass))
    {
        return false;
    }

    return true;
}

bool LYEngine::CreateWindow()
{
    const uint32 uScreenWidth = ::GetSystemMetrics(SM_CXSCREEN);
    const uint32 uScreenHeight = ::GetSystemMetrics(SM_CYSCREEN);
    int32 iPositionX = (uScreenWidth - m_uClientWidth) / 2;
    int32 iPositionY = (uScreenHeight - m_uClientHeight) / 2;

    //const DWORD uStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    const DWORD uStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
    const DWORD uExStyle = WS_EX_APPWINDOW;

    RECT clientRect = { 0, 0, LONG(m_uClientWidth), LONG(m_uClientHeight) };

    ::AdjustWindowRectEx(&clientRect, uStyle, FALSE, uExStyle);

    m_uWindowWidth = clientRect.right - clientRect.left;
    m_uWindowHeight = clientRect.bottom - clientRect.top;

    m_hWindow = ::CreateWindowEx(uExStyle,
                                 m_pApp->GetClassName(),
                                 m_pApp->GetAppName(),
                                 uStyle,
                                 iPositionX, iPositionY,
                                 m_uWindowWidth,
                                 m_uWindowHeight,
                                 nullptr, nullptr, m_hInstance, nullptr);
     
    if (!m_hWindow)
    {
        return false;
    }

    return true;
}

bool LYEngine::ResizeWindow()
{
    DWORD uStyle;
    if (m_bIsFullScreen)
    {
        //const DWORD uExStyle = WS_EX_APPWINDOW;
        //::SetWindowLongA(m_hWindow, GWL_EXSTYLE, uExStyle);

        uStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_CHILD;
    }
    else
    {
        uStyle = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
    }

    if (::SetWindowLongPtrA(m_hWindow, GWL_STYLE, uStyle) == 0)
        return false;

    HDWP _hdwp = BeginDeferWindowPos(1);
    uint32 flags = SWP_SHOWWINDOW | SWP_FRAMECHANGED;

    // ::AdjustWindowRectEx converts client to window size
    const DWORD uExStyle = WS_EX_APPWINDOW;
    RECT clientRect = { 0, 0, LONG(m_uClientWidth), LONG(m_uClientHeight) };

    ::AdjustWindowRectEx(&clientRect, uStyle, FALSE, uExStyle);

    m_uWindowWidth = clientRect.right - clientRect.left;
    m_uWindowHeight = clientRect.bottom - clientRect.top;

    ::DeferWindowPos(
        _hdwp, m_hWindow, 
        HWND_TOP, 
        0, 0, m_uWindowWidth/*m_uClientWidth*/, m_uWindowHeight/*m_uClientHeight*/,
        flags);
    ::EndDeferWindowPos(_hdwp);

    return true;
}

bool WEEngine::DestoryWindowAnUnregisterClass()
{
    if (m_bIsFullScreen)
    {
        ChangeDisplaySettings(nullptr, 0);
    }

    DestroyWindow(m_hWindow);
    m_hWindow = nullptr;

    UnregisterClass(m_pApp->GetClassName(), m_hInstance);
    m_hInstance = nullptr;
    return true;
}

bool LYEngine::SyncEngineInstanceWithPyModule()
{
    HMODULE moduleDLL = ::LoadLibrary("LYModule.pyd");

    if (!moduleDLL)
    {
        LY_LOG_DEBUG("Unable to load LYModule.pyd");
        return false;
    }

    typedef bool(*p_func)(LYEngine*);
    p_func func = (p_func)GetProcAddress(moduleDLL, "SyncEngineInstance");

    if (!func)
    {
        LY_LOG_DEBUG("Unable to get address of function SyncEngineInstance from LYModule.pyd");
        return false;
    }

    bool b_alreadyexist = func(GLYEngine);

    if (b_alreadyexist)
    {
        LY_LOG_DEBUG("DLL already creates an engine instance. Should not happened");
    }
    else
    {
        LY_LOG_DEBUG("Sync With DLL Success");
    }

    return true;
}

void LYEngine::RunMultiThreaded()
{
    m_pTimer->Reset();
    MSG Message;
    ZeroMemory(&Message, sizeof(MSG));

    m_pThreadJobManager->KickStart();
    while (m_bIsRunning)
    {
        HandlePauseChange();
        HandleSceneChange();
        ProcessWindowsMessages(Message);

        m_pThreadJobManager->Update();
    }
}

void LYEngine::RunSingleThreaded()
{
    m_pTimer->Reset();
    MSG Message;
    ZeroMemory(&Message, sizeof(MSG));

    m_pThreadJobManager->Finalize();
    while (m_bIsRunning)
    {
        HandlePauseChange();
        HandleSceneChange();
        ProcessWindowsMessages(Message);

        MainLoopSingleThread();

        m_pTimer->CalculateFrameStats();
    }
}

void LYEngine::ProcessWindowsMessages(MSG& a_message)
{
    while (::PeekMessage(&a_message, NULL, 0, 0, PM_REMOVE))
    {
        if (a_message.message == WM_QUIT)
        {
            m_bIsRunning = false;
            break;
        }
        else
        {
            ::TranslateMessage(&a_message);
            ::DispatchMessage(&a_message);
        }
    }
}

void LYEngine::HandleSceneChange()
{
    // for scene initialization or scene change
    if (m_pSceneManager->m_IsDirty)
    {
        m_pEventManager->ClearTimedEvents();
        m_pPhysicsManager->ClearColliderPairs();
        m_pSceneManager->LoadCurrentScene();

        // SetUp Camera Info
        m_pSystemManager->UpdateSpecificSystem("LYTransformSystem");
        m_pSystemManager->UpdateSpecificSystem("LYCameraSystem");



        //m_pSystemManager->InitializeSystems();
    }
}

void LYEngine::HandlePauseChange()
{
    if (m_bDirtyPause)
    {
        m_bDirtyPause = false;
        // Game Pause
        m_bIsPaused = !m_bIsPaused;
        m_pUiManager->m_CurrentUiLayer = m_bIsPaused ? LYUiManager::eUiLayer_system : LYUiManager::eUiLayer_game;
        //float fTimeScale = m_bIsPaused ? 0.0f : 1.0f;
        //m_pTimer->SetTimeScale(fTimeScale);
        if (m_bIsPaused)
        {
            m_pEventManager->BroadcastEventToSubscribers(new LYPauseEvent());
        }
        else
        {
            m_pEventManager->BroadcastEventToSubscribers(new LYUnPauseEvent());
        }
    }
}

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LYEngine::HWndProc(HWND a_hWindow, UINT a_uMessage, WPARAM a_uWideParam, LPARAM a_uLongParam)
{
    ImGui_ImplWin32_WndProcHandler(a_hWindow, a_uMessage, a_uWideParam, a_uLongParam);

    switch (a_uMessage)
    {
    case WM_ACTIVATEAPP:
    {
        DirectX::Mouse::ProcessMessage(a_uMessage, a_uWideParam, a_uLongParam);
        DirectX::Keyboard::ProcessMessage(a_uMessage, a_uWideParam, a_uLongParam);
        break;
    }
    case WM_KEYDOWN:
    case WM_SYSKEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYUP:
    {
        DirectX::Keyboard::ProcessMessage(a_uMessage, a_uWideParam, a_uLongParam);
        break;
    }
    case WM_QUIT:
    case WM_DESTROY:
    case WM_CLOSE:
    {
        ::PostQuitMessage(0);
        break;
    }
    case WM_INPUT:
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MOUSEWHEEL:
    case WM_XBUTTONDOWN:
    case WM_XBUTTONUP:
    case WM_MOUSEHOVER:
    {
        DirectX::Mouse::ProcessMessage(a_uMessage, a_uWideParam, a_uLongParam);
        break;
    }
    case WM_MOVE:
    case WM_SIZE:
    case WM_ACTIVATE:
    case WM_SETFOCUS:
    case WM_KILLFOCUS:
    case WM_ENABLE:
    case WM_SHOWWINDOW:
    case WM_SETCURSOR:
    case WM_MOUSEACTIVATE:
    case WM_QUEUESYNC:
    case WM_GETMINMAXINFO:
    case WM_WINDOWPOSCHANGING:
    case WM_WINDOWPOSCHANGED:
    case WM_DISPLAYCHANGE:
    case WM_NCMOUSEMOVE:
    case WM_NCLBUTTONDOWN:
    case WM_NCLBUTTONUP:
    case WM_NCLBUTTONDBLCLK:
    case WM_NCRBUTTONDOWN:
    case WM_NCRBUTTONUP:
    case WM_NCRBUTTONDBLCLK:
    case WM_NCMBUTTONDOWN:
    case WM_NCMBUTTONUP:
    case WM_NCMBUTTONDBLCLK:
    case WM_LBUTTONDBLCLK:
    case WM_RBUTTONDBLCLK:
    case WM_MBUTTONDBLCLK:
    case WM_MOUSEHWHEEL:
    case WM_NCMOUSELEAVE:
    case WM_MOUSELEAVE:
    case WM_CUT:
    case WM_COPY:
    case WM_PASTE:
    case WM_CLEAR:
    case WM_UNDO:
    default:
        return ::DefWindowProc(a_hWindow, a_uMessage, a_uWideParam, a_uLongParam);
        break;
    }

    return 0;
}

LONG WINAPI LYEngine::WndUnhandledExceptionProc(struct _EXCEPTION_POINTERS * a_pExceptionInfo)
{
    std::time_t time = std::time(nullptr);
    std::tm local_time;
    localtime_s(&local_time, &time);

    std::stringstream strFilename;
    strFilename << "LYCrash_" << GLYEngine->GetApp()->GetAppName() << "_" << std::put_time(&local_time, "%Y_%m_%d-%I_%M");

    LYRenderer* pRenderer = GLYEngine->GetRenderer();
    if (pRenderer)
    {
        auto strScreenshotName = (strFilename.str() + ".png");
        if (pRenderer->SaveScreenshotToFile(strScreenshotName.c_str()))
        {
            LY_LOG_DEBUG_FMT("Crash screenshot saved: {}", strScreenshotName.c_str());
        }
    }
    auto strDumpName = (strFilename.str() + ".dmp");
    HANDLE hFile = ::CreateFileA(strDumpName.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    LY_LOG_DEBUG_FMT("Crash dump generated: {}", strDumpName.c_str());

    _MINIDUMP_EXCEPTION_INFORMATION ExInfo;
    ExInfo.ThreadId = ::GetCurrentThreadId();
    ExInfo.ExceptionPointers = a_pExceptionInfo;
    ExInfo.ClientPointers = FALSE;

#ifndef _DEBUG
    MINIDUMP_TYPE type = (MINIDUMP_TYPE)(MiniDumpNormal |
        MiniDumpWithDataSegs |
        MiniDumpWithPrivateReadWriteMemory |
        MiniDumpWithHandleData |
        MiniDumpWithFullMemoryInfo |
        MiniDumpWithThreadInfo |
        MiniDumpWithUnloadedModules);
#else
    MINIDUMP_TYPE type = (MINIDUMP_TYPE)(MiniDumpNormal |
        MiniDumpWithDataSegs |
        MiniDumpWithPrivateReadWriteMemory |
        MiniDumpWithHandleData |
        MiniDumpWithFullMemory |
        MiniDumpWithFullMemoryInfo |
        MiniDumpWithThreadInfo |
        MiniDumpWithUnloadedModules |
        MiniDumpWithProcessThreadData);
#endif

    ::MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), hFile, type, &ExInfo, NULL, NULL);
    ::CloseHandle(hFile);
    return EXCEPTION_CONTINUE_SEARCH;
}
