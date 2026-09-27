#include "loader.h"
#include "plugin.h"

bool loader::pluginsLoaded = false;
int loader::debugMode = 0;
bool loader::anyProcess = false;

bool loader::LoadLib(std::wstring const &libName, HMODULE &handle) {
    wchar_t systemDir[MAX_PATH + 1];
    GetSystemDirectoryW(systemDir, MAX_PATH);
    auto libPath = std::wstring(systemDir) + L"\\" + libName;
    handle = LoadLibraryW(libPath.c_str());
    if (handle == 0) {
        if (debugMode)
            plugin::InternalError(L"Failed to load %s\nFull path: %s\nError: %d", libName.c_str(), libPath.c_str(), GetLastError());
        return false;
    }
    return true;
}

void loader::LoadPlugins() {
    if (!pluginsLoaded) {
        WIN32_FIND_DATAW fd;
        HANDLE hFind = FindFirstFileW(L"plugins\\*.asi", &fd);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (!(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    if (GetModuleHandleW(fd.cFileName) == NULL) {
                        if (debugMode)
                            plugin::InternalMessage(L"Loading plugin: %s", fd.cFileName);
                        std::wstring plugin_path = std::wstring(L"plugins\\") + fd.cFileName;
                        auto h = LoadLibraryW(plugin_path.c_str());
                        if (h == NULL && debugMode)
                            plugin::InternalError(L"Failed to load plugin %s (error %d)", fd.cFileName, GetLastError());
                    }
                }
            } while (FindNextFileW(hFind, &fd));
            FindClose(hFind);
        }
        HMODULE hExecutableInstance = GetModuleHandle(NULL);
        IMAGE_NT_HEADERS* ntHeader = (IMAGE_NT_HEADERS*)((DWORD)hExecutableInstance + ((IMAGE_DOS_HEADER*)hExecutableInstance)->e_lfanew);
        SIZE_T size = ntHeader->OptionalHeader.SizeOfImage;
        DWORD oldProtect;
        VirtualProtect((VOID*)hExecutableInstance, size, PAGE_EXECUTE_READWRITE, &oldProtect);
        pluginsLoaded = true;
    }
}

std::wstring loader::GetModulePath(HMODULE hmodule) {
    static constexpr auto INITIAL_BUFFER_SIZE = MAX_PATH;
    static constexpr auto MAX_ITERATIONS = 7;
    std::wstring ret;
    auto bufferSize = INITIAL_BUFFER_SIZE;
    for (size_t iterations = 0; iterations < MAX_ITERATIONS; ++iterations) {
        ret.resize(bufferSize);
        auto charsReturned = GetModuleFileNameW(hmodule, &ret[0], bufferSize);
        if (charsReturned < ret.length()) {
            ret.resize(charsReturned);
            return ret;
        }
        else
            bufferSize *= 2;
    }
    return std::wstring();
}

std::wstring loader::GetModuleName(HMODULE hmodule) {
    auto modulePath = GetModulePath(hmodule);
    if (!modulePath.empty()) {
        auto lastSlash = modulePath.find_last_of(L"/\\");
        if (lastSlash != std::wstring::npos)
            modulePath = modulePath.substr(lastSlash + 1);
        return modulePath;
    }
    return std::wstring();
}

std::wstring loader::GetModuleDir(HMODULE hmodule) {
    std::wstring modulePath = GetModulePath(hmodule);
    if (!modulePath.empty()) {
        auto lastSlash = modulePath.find_last_of(L"/\\");
        if (lastSlash != std::wstring::npos) {
            modulePath.resize(lastSlash + 1);
            return modulePath;
        }
    }
    return std::wstring();
}
