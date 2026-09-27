#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>
#include <vector>

class loader {
    static bool pluginsLoaded;
public:
    static int debugMode;
    static bool anyProcess;
    static bool LoadLib(std::wstring const &libName, HMODULE &handle);
    static void LoadPlugins();
    static std::wstring GetModulePath(HMODULE hmodule);
    static std::wstring GetModuleName(HMODULE hmodule);
    static std::wstring GetModuleDir(HMODULE hmodule);
};
