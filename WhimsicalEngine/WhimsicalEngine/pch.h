// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

#ifndef PCH_H
#define PCH_H

using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;
using uint64 = unsigned long long;
using int8 = signed char;
using int16 = short;
using int32 = int;
using int64 = long long;

// C++
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
#include <stack>
#include <thread>
#include <fstream>
#include <functional>
#include <utility>
#include <filesystem>

// Win32 API
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <Windows.h>
#include <wincodec.h>


// Engine
#include "Singleton.h"
#include "Engine.h"
#include "FrameRateManager.h"

#endif //PCH_H
