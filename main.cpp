#include "loader.h"
#include <algorithm>
#include "plugin.h"

const wchar_t * const LOADER_VERSION = L"1.0.0.0";
struct TheDll {
    HMODULE handle;
} dll;

struct d3d9_dll {
    FARPROC D3DPERF_BeginEvent;
    FARPROC D3DPERF_EndEvent;
    FARPROC D3DPERF_GetStatus;
    FARPROC D3DPERF_QueryRepeatFrame;
    FARPROC D3DPERF_SetMarker;
    FARPROC D3DPERF_SetOptions;
    FARPROC D3DPERF_SetRegion;
    FARPROC DebugSetLevel;
    FARPROC Direct3D9EnableMaximizedWindowedModeShim;
    FARPROC Direct3DCreate9;
    FARPROC Direct3DCreate9Ex;
    FARPROC Direct3DShaderValidatorCreate9;
    FARPROC PSGPError;
    FARPROC PSGPSampleTexture;
} d3d9;

__declspec(naked) void _D3DPERF_BeginEvent() { _asm { jmp[d3d9.D3DPERF_BeginEvent] } }
__declspec(naked) void _D3DPERF_EndEvent() { _asm { jmp[d3d9.D3DPERF_EndEvent] } }
__declspec(naked) void _D3DPERF_GetStatus() { _asm { jmp[d3d9.D3DPERF_GetStatus] } }
__declspec(naked) void _D3DPERF_QueryRepeatFrame() { _asm { jmp[d3d9.D3DPERF_QueryRepeatFrame] } }
__declspec(naked) void _D3DPERF_SetMarker() { _asm { jmp[d3d9.D3DPERF_SetMarker] } }
__declspec(naked) void _D3DPERF_SetOptions() { _asm { jmp[d3d9.D3DPERF_SetOptions] } }
__declspec(naked) void _D3DPERF_SetRegion() { _asm { jmp[d3d9.D3DPERF_SetRegion] } }
__declspec(naked) void _DebugSetLevel() { _asm { jmp[d3d9.DebugSetLevel] } }
__declspec(naked) void _Direct3D9EnableMaximizedWindowedModeShim() { _asm { jmp[d3d9.Direct3D9EnableMaximizedWindowedModeShim] } }
__declspec(naked) void _Direct3DCreate9() { _asm { jmp[d3d9.Direct3DCreate9] } }
__declspec(naked) void _Direct3DCreate9Ex() { _asm { jmp[d3d9.Direct3DCreate9Ex] } }
__declspec(naked) void _Direct3DShaderValidatorCreate9() { _asm { jmp[d3d9.Direct3DShaderValidatorCreate9] } }
__declspec(naked) void _PSGPError() { _asm { jmp[d3d9.PSGPError] } }
__declspec(naked) void _PSGPSampleTexture() { _asm { jmp[d3d9.PSGPSampleTexture] } }

struct version_dll {
    FARPROC GetFileVersionInfoA;
    FARPROC GetFileVersionInfoByHandle;
    FARPROC GetFileVersionInfoExA;
    FARPROC GetFileVersionInfoExW;
    FARPROC GetFileVersionInfoSizeA;
    FARPROC GetFileVersionInfoSizeExA;
    FARPROC GetFileVersionInfoSizeExW;
    FARPROC GetFileVersionInfoSizeW;
    FARPROC GetFileVersionInfoW;
    FARPROC VerFindFileA;
    FARPROC VerFindFileW;
    FARPROC VerInstallFileA;
    FARPROC VerInstallFileW;
    FARPROC VerLanguageNameA;
    FARPROC VerLanguageNameW;
    FARPROC VerQueryValueA;
    FARPROC VerQueryValueW;
} version;

__declspec(naked) void _GetFileVersionInfoA() { _asm { jmp[version.GetFileVersionInfoA] } }
__declspec(naked) void _GetFileVersionInfoByHandle() { _asm { jmp[version.GetFileVersionInfoByHandle] } }
__declspec(naked) void _GetFileVersionInfoExA() { _asm { jmp[version.GetFileVersionInfoExA] } }
__declspec(naked) void _GetFileVersionInfoExW() { _asm { jmp[version.GetFileVersionInfoExW] } }
__declspec(naked) void _GetFileVersionInfoSizeA() { _asm { jmp[version.GetFileVersionInfoSizeA] } }
__declspec(naked) void _GetFileVersionInfoSizeExA() { _asm { jmp[version.GetFileVersionInfoSizeExA] } }
__declspec(naked) void _GetFileVersionInfoSizeExW() { _asm { jmp[version.GetFileVersionInfoSizeExW] } }
__declspec(naked) void _GetFileVersionInfoSizeW() { _asm { jmp[version.GetFileVersionInfoSizeW] } }
__declspec(naked) void _GetFileVersionInfoW() { _asm { jmp[version.GetFileVersionInfoW] } }
__declspec(naked) void _VerFindFileA() { _asm { jmp[version.VerFindFileA] } }
__declspec(naked) void _VerFindFileW() { _asm { jmp[version.VerFindFileW] } }
__declspec(naked) void _VerInstallFileA() { _asm { jmp[version.VerInstallFileA] } }
__declspec(naked) void _VerInstallFileW() { _asm { jmp[version.VerInstallFileW] } }
__declspec(naked) void _VerLanguageNameA() { _asm { jmp[version.VerLanguageNameA] } }
__declspec(naked) void _VerLanguageNameW() { _asm { jmp[version.VerLanguageNameW] } }
__declspec(naked) void _VerQueryValueA() { _asm { jmp[version.VerQueryValueA] } }
__declspec(naked) void _VerQueryValueW() { _asm { jmp[version.VerQueryValueW] } }

struct winmm_dll {
    FARPROC CloseDriver;
    FARPROC DefDriverProc;
    FARPROC DriverCallback;
    FARPROC DrvGetModuleHandle;
    FARPROC GetDriverModuleHandle;
    FARPROC NotifyCallbackData;
    FARPROC OpenDriver;
    FARPROC PlaySound;
    FARPROC PlaySoundA;
    FARPROC PlaySoundW;
    FARPROC SendDriverMessage;
    FARPROC WOW32DriverCallback;
    FARPROC WOW32ResolveMultiMediaHandle;
    FARPROC WOWAppExit;
    FARPROC aux32Message;
    FARPROC auxGetDevCapsA;
    FARPROC auxGetDevCapsW;
    FARPROC auxGetNumDevs;
    FARPROC auxGetVolume;
    FARPROC auxOutMessage;
    FARPROC auxSetVolume;
    FARPROC joy32Message;
    FARPROC joyConfigChanged;
    FARPROC joyGetDevCapsA;
    FARPROC joyGetDevCapsW;
    FARPROC joyGetNumDevs;
    FARPROC joyGetPos;
    FARPROC joyGetPosEx;
    FARPROC joyGetThreshold;
    FARPROC joyReleaseCapture;
    FARPROC joySetCapture;
    FARPROC joySetThreshold;
    FARPROC mci32Message;
    FARPROC mciDriverNotify;
    FARPROC mciDriverYield;
    FARPROC mciExecute;
    FARPROC mciFreeCommandResource;
    FARPROC mciGetCreatorTask;
    FARPROC mciGetDeviceIDA;
    FARPROC mciGetDeviceIDFromElementIDA;
    FARPROC mciGetDeviceIDFromElementIDW;
    FARPROC mciGetDeviceIDW;
    FARPROC mciGetDriverData;
    FARPROC mciGetErrorStringA;
    FARPROC mciGetErrorStringW;
    FARPROC mciGetYieldProc;
    FARPROC mciLoadCommandResource;
    FARPROC mciSendCommandA;
    FARPROC mciSendCommandW;
    FARPROC mciSendStringA;
    FARPROC mciSendStringW;
    FARPROC mciSetDriverData;
    FARPROC mciSetYieldProc;
    FARPROC mid32Message;
    FARPROC midiConnect;
    FARPROC midiDisconnect;
    FARPROC midiInAddBuffer;
    FARPROC midiInClose;
    FARPROC midiInGetDevCapsA;
    FARPROC midiInGetDevCapsW;
    FARPROC midiInGetErrorTextA;
    FARPROC midiInGetErrorTextW;
    FARPROC midiInGetID;
    FARPROC midiInGetNumDevs;
    FARPROC midiInMessage;
    FARPROC midiInOpen;
    FARPROC midiInPrepareHeader;
    FARPROC midiInReset;
    FARPROC midiInStart;
    FARPROC midiInStop;
    FARPROC midiInUnprepareHeader;
    FARPROC midiOutCacheDrumPatches;
    FARPROC midiOutCachePatches;
    FARPROC midiOutClose;
    FARPROC midiOutGetDevCapsA;
    FARPROC midiOutGetDevCapsW;
    FARPROC midiOutGetErrorTextA;
    FARPROC midiOutGetErrorTextW;
    FARPROC midiOutGetID;
    FARPROC midiOutGetNumDevs;
    FARPROC midiOutGetVolume;
    FARPROC midiOutLongMsg;
    FARPROC midiOutMessage;
    FARPROC midiOutOpen;
    FARPROC midiOutPrepareHeader;
    FARPROC midiOutReset;
    FARPROC midiOutSetVolume;
    FARPROC midiOutShortMsg;
    FARPROC midiOutUnprepareHeader;
    FARPROC midiStreamClose;
    FARPROC midiStreamOpen;
    FARPROC midiStreamOut;
    FARPROC midiStreamPause;
    FARPROC midiStreamPosition;
    FARPROC midiStreamProperty;
    FARPROC midiStreamRestart;
    FARPROC midiStreamStop;
    FARPROC mixerClose;
    FARPROC mixerGetControlDetailsA;
    FARPROC mixerGetControlDetailsW;
    FARPROC mixerGetDevCapsA;
    FARPROC mixerGetDevCapsW;
    FARPROC mixerGetID;
    FARPROC mixerGetLineControlsA;
    FARPROC mixerGetLineControlsW;
    FARPROC mixerGetLineInfoA;
    FARPROC mixerGetLineInfoW;
    FARPROC mixerGetNumDevs;
    FARPROC mixerMessage;
    FARPROC mixerOpen;
    FARPROC mixerSetControlDetails;
    FARPROC mmDrvInstall;
    FARPROC mmGetCurrentTask;
    FARPROC mmTaskBlock;
    FARPROC mmTaskCreate;
    FARPROC mmTaskSignal;
    FARPROC mmTaskYield;
    FARPROC mmioAdvance;
    FARPROC mmioAscend;
    FARPROC mmioClose;
    FARPROC mmioCreateChunk;
    FARPROC mmioDescend;
    FARPROC mmioFlush;
    FARPROC mmioGetInfo;
    FARPROC mmioInstallIOProcA;
    FARPROC mmioInstallIOProcW;
    FARPROC mmioOpenA;
    FARPROC mmioOpenW;
    FARPROC mmioRead;
    FARPROC mmioRenameA;
    FARPROC mmioRenameW;
    FARPROC mmioSeek;
    FARPROC mmioSendMessage;
    FARPROC mmioSetBuffer;
    FARPROC mmioSetInfo;
    FARPROC mmioStringToFOURCCA;
    FARPROC mmioStringToFOURCCW;
    FARPROC mmioWrite;
    FARPROC mmsystemGetVersion;
    FARPROC mod32Message;
    FARPROC mxd32Message;
    FARPROC sndPlaySoundA;
    FARPROC sndPlaySoundW;
    FARPROC tid32Message;
    FARPROC timeBeginPeriod;
    FARPROC timeEndPeriod;
    FARPROC timeGetDevCaps;
    FARPROC timeGetSystemTime;
    FARPROC timeGetTime;
    FARPROC timeKillEvent;
    FARPROC timeSetEvent;
    FARPROC waveInAddBuffer;
    FARPROC waveInClose;
    FARPROC waveInGetDevCapsA;
    FARPROC waveInGetDevCapsW;
    FARPROC waveInGetErrorTextA;
    FARPROC waveInGetErrorTextW;
    FARPROC waveInGetID;
    FARPROC waveInGetNumDevs;
    FARPROC waveInGetPosition;
    FARPROC waveInMessage;
    FARPROC waveInOpen;
    FARPROC waveInPrepareHeader;
    FARPROC waveInReset;
    FARPROC waveInStart;
    FARPROC waveInStop;
    FARPROC waveInUnprepareHeader;
    FARPROC waveOutBreakLoop;
    FARPROC waveOutClose;
    FARPROC waveOutGetDevCapsA;
    FARPROC waveOutGetDevCapsW;
    FARPROC waveOutGetErrorTextA;
    FARPROC waveOutGetErrorTextW;
    FARPROC waveOutGetID;
    FARPROC waveOutGetNumDevs;
    FARPROC waveOutGetPitch;
    FARPROC waveOutGetPlaybackRate;
    FARPROC waveOutGetPosition;
    FARPROC waveOutGetVolume;
    FARPROC waveOutMessage;
    FARPROC waveOutOpen;
    FARPROC waveOutPause;
    FARPROC waveOutPrepareHeader;
    FARPROC waveOutReset;
    FARPROC waveOutRestart;
    FARPROC waveOutSetPitch;
    FARPROC waveOutSetPlaybackRate;
    FARPROC waveOutSetVolume;
    FARPROC waveOutUnprepareHeader;
    FARPROC waveOutWrite;
    FARPROC wid32Message;
    FARPROC wod32Message;
} winmm;

__declspec(naked) void _CloseDriver() { _asm { jmp[winmm.CloseDriver] } }
__declspec(naked) void _DefDriverProc() { _asm { jmp[winmm.DefDriverProc] } }
__declspec(naked) void _DriverCallback() { _asm { jmp[winmm.DriverCallback] } }
__declspec(naked) void _DrvGetModuleHandle() { _asm { jmp[winmm.DrvGetModuleHandle] } }
__declspec(naked) void _GetDriverModuleHandle() { _asm { jmp[winmm.GetDriverModuleHandle] } }
__declspec(naked) void _NotifyCallbackData() { _asm { jmp[winmm.NotifyCallbackData] } }
__declspec(naked) void _OpenDriver() { _asm { jmp[winmm.OpenDriver] } }
__declspec(naked) void _PlaySound() { _asm { jmp[winmm.PlaySound] } }
__declspec(naked) void _PlaySoundA() { _asm { jmp[winmm.PlaySoundA] } }
__declspec(naked) void _PlaySoundW() { _asm { jmp[winmm.PlaySoundW] } }
__declspec(naked) void _SendDriverMessage() { _asm { jmp[winmm.SendDriverMessage] } }
__declspec(naked) void _WOW32DriverCallback() { _asm { jmp[winmm.WOW32DriverCallback] } }
__declspec(naked) void _WOW32ResolveMultiMediaHandle() { _asm { jmp[winmm.WOW32ResolveMultiMediaHandle] } }
__declspec(naked) void _WOWAppExit() { _asm { jmp[winmm.WOWAppExit] } }
__declspec(naked) void _aux32Message() { _asm { jmp[winmm.aux32Message] } }
__declspec(naked) void _auxGetDevCapsA() { _asm { jmp[winmm.auxGetDevCapsA] } }
__declspec(naked) void _auxGetDevCapsW() { _asm { jmp[winmm.auxGetDevCapsW] } }
__declspec(naked) void _auxGetNumDevs() { _asm { jmp[winmm.auxGetNumDevs] } }
__declspec(naked) void _auxGetVolume() { _asm { jmp[winmm.auxGetVolume] } }
__declspec(naked) void _auxOutMessage() { _asm { jmp[winmm.auxOutMessage] } }
__declspec(naked) void _auxSetVolume() { _asm { jmp[winmm.auxSetVolume] } }
__declspec(naked) void _joy32Message() { _asm { jmp[winmm.joy32Message] } }
__declspec(naked) void _joyConfigChanged() { _asm { jmp[winmm.joyConfigChanged] } }
__declspec(naked) void _joyGetDevCapsA() { _asm { jmp[winmm.joyGetDevCapsA] } }
__declspec(naked) void _joyGetDevCapsW() { _asm { jmp[winmm.joyGetDevCapsW] } }
__declspec(naked) void _joyGetNumDevs() { _asm { jmp[winmm.joyGetNumDevs] } }
__declspec(naked) void _joyGetPos() { _asm { jmp[winmm.joyGetPos] } }
__declspec(naked) void _joyGetPosEx() { _asm { jmp[winmm.joyGetPosEx] } }
__declspec(naked) void _joyGetThreshold() { _asm { jmp[winmm.joyGetThreshold] } }
__declspec(naked) void _joyReleaseCapture() { _asm { jmp[winmm.joyReleaseCapture] } }
__declspec(naked) void _joySetCapture() { _asm { jmp[winmm.joySetCapture] } }
__declspec(naked) void _joySetThreshold() { _asm { jmp[winmm.joySetThreshold] } }
__declspec(naked) void _mci32Message() { _asm { jmp[winmm.mci32Message] } }
__declspec(naked) void _mciDriverNotify() { _asm { jmp[winmm.mciDriverNotify] } }
__declspec(naked) void _mciDriverYield() { _asm { jmp[winmm.mciDriverYield] } }
__declspec(naked) void _mciExecute() { _asm { jmp[winmm.mciExecute] } }
__declspec(naked) void _mciFreeCommandResource() { _asm { jmp[winmm.mciFreeCommandResource] } }
__declspec(naked) void _mciGetCreatorTask() { _asm { jmp[winmm.mciGetCreatorTask] } }
__declspec(naked) void _mciGetDeviceIDA() { _asm { jmp[winmm.mciGetDeviceIDA] } }
__declspec(naked) void _mciGetDeviceIDFromElementIDA() { _asm { jmp[winmm.mciGetDeviceIDFromElementIDA] } }
__declspec(naked) void _mciGetDeviceIDFromElementIDW() { _asm { jmp[winmm.mciGetDeviceIDFromElementIDW] } }
__declspec(naked) void _mciGetDeviceIDW() { _asm { jmp[winmm.mciGetDeviceIDW] } }
__declspec(naked) void _mciGetDriverData() { _asm { jmp[winmm.mciGetDriverData] } }
__declspec(naked) void _mciGetErrorStringA() { _asm { jmp[winmm.mciGetErrorStringA] } }
__declspec(naked) void _mciGetErrorStringW() { _asm { jmp[winmm.mciGetErrorStringW] } }
__declspec(naked) void _mciGetYieldProc() { _asm { jmp[winmm.mciGetYieldProc] } }
__declspec(naked) void _mciLoadCommandResource() { _asm { jmp[winmm.mciLoadCommandResource] } }
__declspec(naked) void _mciSendCommandA() { _asm { jmp[winmm.mciSendCommandA] } }
__declspec(naked) void _mciSendCommandW() { _asm { jmp[winmm.mciSendCommandW] } }
__declspec(naked) void _mciSendStringA() { _asm { jmp[winmm.mciSendStringA] } }
__declspec(naked) void _mciSendStringW() { _asm { jmp[winmm.mciSendStringW] } }
__declspec(naked) void _mciSetDriverData() { _asm { jmp[winmm.mciSetDriverData] } }
__declspec(naked) void _mciSetYieldProc() { _asm { jmp[winmm.mciSetYieldProc] } }
__declspec(naked) void _mid32Message() { _asm { jmp[winmm.mid32Message] } }
__declspec(naked) void _midiConnect() { _asm { jmp[winmm.midiConnect] } }
__declspec(naked) void _midiDisconnect() { _asm { jmp[winmm.midiDisconnect] } }
__declspec(naked) void _midiInAddBuffer() { _asm { jmp[winmm.midiInAddBuffer] } }
__declspec(naked) void _midiInClose() { _asm { jmp[winmm.midiInClose] } }
__declspec(naked) void _midiInGetDevCapsA() { _asm { jmp[winmm.midiInGetDevCapsA] } }
__declspec(naked) void _midiInGetDevCapsW() { _asm { jmp[winmm.midiInGetDevCapsW] } }
__declspec(naked) void _midiInGetErrorTextA() { _asm { jmp[winmm.midiInGetErrorTextA] } }
__declspec(naked) void _midiInGetErrorTextW() { _asm { jmp[winmm.midiInGetErrorTextW] } }
__declspec(naked) void _midiInGetID() { _asm { jmp[winmm.midiInGetID] } }
__declspec(naked) void _midiInGetNumDevs() { _asm { jmp[winmm.midiInGetNumDevs] } }
__declspec(naked) void _midiInMessage() { _asm { jmp[winmm.midiInMessage] } }
__declspec(naked) void _midiInOpen() { _asm { jmp[winmm.midiInOpen] } }
__declspec(naked) void _midiInPrepareHeader() { _asm { jmp[winmm.midiInPrepareHeader] } }
__declspec(naked) void _midiInReset() { _asm { jmp[winmm.midiInReset] } }
__declspec(naked) void _midiInStart() { _asm { jmp[winmm.midiInStart] } }
__declspec(naked) void _midiInStop() { _asm { jmp[winmm.midiInStop] } }
__declspec(naked) void _midiInUnprepareHeader() { _asm { jmp[winmm.midiInUnprepareHeader] } }
__declspec(naked) void _midiOutCacheDrumPatches() { _asm { jmp[winmm.midiOutCacheDrumPatches] } }
__declspec(naked) void _midiOutCachePatches() { _asm { jmp[winmm.midiOutCachePatches] } }
__declspec(naked) void _midiOutClose() { _asm { jmp[winmm.midiOutClose] } }
__declspec(naked) void _midiOutGetDevCapsA() { _asm { jmp[winmm.midiOutGetDevCapsA] } }
__declspec(naked) void _midiOutGetDevCapsW() { _asm { jmp[winmm.midiOutGetDevCapsW] } }
__declspec(naked) void _midiOutGetErrorTextA() { _asm { jmp[winmm.midiOutGetErrorTextA] } }
__declspec(naked) void _midiOutGetErrorTextW() { _asm { jmp[winmm.midiOutGetErrorTextW] } }
__declspec(naked) void _midiOutGetID() { _asm { jmp[winmm.midiOutGetID] } }
__declspec(naked) void _midiOutGetNumDevs() { _asm { jmp[winmm.midiOutGetNumDevs] } }
__declspec(naked) void _midiOutGetVolume() { _asm { jmp[winmm.midiOutGetVolume] } }
__declspec(naked) void _midiOutLongMsg() { _asm { jmp[winmm.midiOutLongMsg] } }
__declspec(naked) void _midiOutMessage() { _asm { jmp[winmm.midiOutMessage] } }
__declspec(naked) void _midiOutOpen() { _asm { jmp[winmm.midiOutOpen] } }
__declspec(naked) void _midiOutPrepareHeader() { _asm { jmp[winmm.midiOutPrepareHeader] } }
__declspec(naked) void _midiOutReset() { _asm { jmp[winmm.midiOutReset] } }
__declspec(naked) void _midiOutSetVolume() { _asm { jmp[winmm.midiOutSetVolume] } }
__declspec(naked) void _midiOutShortMsg() { _asm { jmp[winmm.midiOutShortMsg] } }
__declspec(naked) void _midiOutUnprepareHeader() { _asm { jmp[winmm.midiOutUnprepareHeader] } }
__declspec(naked) void _midiStreamClose() { _asm { jmp[winmm.midiStreamClose] } }
__declspec(naked) void _midiStreamOpen() { _asm { jmp[winmm.midiStreamOpen] } }
__declspec(naked) void _midiStreamOut() { _asm { jmp[winmm.midiStreamOut] } }
__declspec(naked) void _midiStreamPause() { _asm { jmp[winmm.midiStreamPause] } }
__declspec(naked) void _midiStreamPosition() { _asm { jmp[winmm.midiStreamPosition] } }
__declspec(naked) void _midiStreamProperty() { _asm { jmp[winmm.midiStreamProperty] } }
__declspec(naked) void _midiStreamRestart() { _asm { jmp[winmm.midiStreamRestart] } }
__declspec(naked) void _midiStreamStop() { _asm { jmp[winmm.midiStreamStop] } }
__declspec(naked) void _mixerClose() { _asm { jmp[winmm.mixerClose] } }
__declspec(naked) void _mixerGetControlDetailsA() { _asm { jmp[winmm.mixerGetControlDetailsA] } }
__declspec(naked) void _mixerGetControlDetailsW() { _asm { jmp[winmm.mixerGetControlDetailsW] } }
__declspec(naked) void _mixerGetDevCapsA() { _asm { jmp[winmm.mixerGetDevCapsA] } }
__declspec(naked) void _mixerGetDevCapsW() { _asm { jmp[winmm.mixerGetDevCapsW] } }
__declspec(naked) void _mixerGetID() { _asm { jmp[winmm.mixerGetID] } }
__declspec(naked) void _mixerGetLineControlsA() { _asm { jmp[winmm.mixerGetLineControlsA] } }
__declspec(naked) void _mixerGetLineControlsW() { _asm { jmp[winmm.mixerGetLineControlsW] } }
__declspec(naked) void _mixerGetLineInfoA() { _asm { jmp[winmm.mixerGetLineInfoA] } }
__declspec(naked) void _mixerGetLineInfoW() { _asm { jmp[winmm.mixerGetLineInfoW] } }
__declspec(naked) void _mixerGetNumDevs() { _asm { jmp[winmm.mixerGetNumDevs] } }
__declspec(naked) void _mixerMessage() { _asm { jmp[winmm.mixerMessage] } }
__declspec(naked) void _mixerOpen() { _asm { jmp[winmm.mixerOpen] } }
__declspec(naked) void _mixerSetControlDetails() { _asm { jmp[winmm.mixerSetControlDetails] } }
__declspec(naked) void _mmDrvInstall() { _asm { jmp[winmm.mmDrvInstall] } }
__declspec(naked) void _mmGetCurrentTask() { _asm { jmp[winmm.mmGetCurrentTask] } }
__declspec(naked) void _mmTaskBlock() { _asm { jmp[winmm.mmTaskBlock] } }
__declspec(naked) void _mmTaskCreate() { _asm { jmp[winmm.mmTaskCreate] } }
__declspec(naked) void _mmTaskSignal() { _asm { jmp[winmm.mmTaskSignal] } }
__declspec(naked) void _mmTaskYield() { _asm { jmp[winmm.mmTaskYield] } }
__declspec(naked) void _mmioAdvance() { _asm { jmp[winmm.mmioAdvance] } }
__declspec(naked) void _mmioAscend() { _asm { jmp[winmm.mmioAscend] } }
__declspec(naked) void _mmioClose() { _asm { jmp[winmm.mmioClose] } }
__declspec(naked) void _mmioCreateChunk() { _asm { jmp[winmm.mmioCreateChunk] } }
__declspec(naked) void _mmioDescend() { _asm { jmp[winmm.mmioDescend] } }
__declspec(naked) void _mmioFlush() { _asm { jmp[winmm.mmioFlush] } }
__declspec(naked) void _mmioGetInfo() { _asm { jmp[winmm.mmioGetInfo] } }
__declspec(naked) void _mmioInstallIOProcA() { _asm { jmp[winmm.mmioInstallIOProcA] } }
__declspec(naked) void _mmioInstallIOProcW() { _asm { jmp[winmm.mmioInstallIOProcW] } }
__declspec(naked) void _mmioOpenA() { _asm { jmp[winmm.mmioOpenA] } }
__declspec(naked) void _mmioOpenW() { _asm { jmp[winmm.mmioOpenW] } }
__declspec(naked) void _mmioRead() { _asm { jmp[winmm.mmioRead] } }
__declspec(naked) void _mmioRenameA() { _asm { jmp[winmm.mmioRenameA] } }
__declspec(naked) void _mmioRenameW() { _asm { jmp[winmm.mmioRenameW] } }
__declspec(naked) void _mmioSeek() { _asm { jmp[winmm.mmioSeek] } }
__declspec(naked) void _mmioSendMessage() { _asm { jmp[winmm.mmioSendMessage] } }
__declspec(naked) void _mmioSetBuffer() { _asm { jmp[winmm.mmioSetBuffer] } }
__declspec(naked) void _mmioSetInfo() { _asm { jmp[winmm.mmioSetInfo] } }
__declspec(naked) void _mmioStringToFOURCCA() { _asm { jmp[winmm.mmioStringToFOURCCA] } }
__declspec(naked) void _mmioStringToFOURCCW() { _asm { jmp[winmm.mmioStringToFOURCCW] } }
__declspec(naked) void _mmioWrite() { _asm { jmp[winmm.mmioWrite] } }
__declspec(naked) void _mmsystemGetVersion() { _asm { jmp[winmm.mmsystemGetVersion] } }
__declspec(naked) void _mod32Message() { _asm { jmp[winmm.mod32Message] } }
__declspec(naked) void _mxd32Message() { _asm { jmp[winmm.mxd32Message] } }
__declspec(naked) void _sndPlaySoundA() { _asm { jmp[winmm.sndPlaySoundA] } }
__declspec(naked) void _sndPlaySoundW() { _asm { jmp[winmm.sndPlaySoundW] } }
__declspec(naked) void _tid32Message() { _asm { jmp[winmm.tid32Message] } }
__declspec(naked) void _timeBeginPeriod() { _asm { jmp[winmm.timeBeginPeriod] } }
__declspec(naked) void _timeEndPeriod() { _asm { jmp[winmm.timeEndPeriod] } }
__declspec(naked) void _timeGetDevCaps() { _asm { jmp[winmm.timeGetDevCaps] } }
__declspec(naked) void _timeGetSystemTime() { _asm { jmp[winmm.timeGetSystemTime] } }
__declspec(naked) void _timeGetTime() { _asm { jmp[winmm.timeGetTime] } }
__declspec(naked) void _timeKillEvent() { _asm { jmp[winmm.timeKillEvent] } }
__declspec(naked) void _timeSetEvent() { _asm { jmp[winmm.timeSetEvent] } }
__declspec(naked) void _waveInAddBuffer() { _asm { jmp[winmm.waveInAddBuffer] } }
__declspec(naked) void _waveInClose() { _asm { jmp[winmm.waveInClose] } }
__declspec(naked) void _waveInGetDevCapsA() { _asm { jmp[winmm.waveInGetDevCapsA] } }
__declspec(naked) void _waveInGetDevCapsW() { _asm { jmp[winmm.waveInGetDevCapsW] } }
__declspec(naked) void _waveInGetErrorTextA() { _asm { jmp[winmm.waveInGetErrorTextA] } }
__declspec(naked) void _waveInGetErrorTextW() { _asm { jmp[winmm.waveInGetErrorTextW] } }
__declspec(naked) void _waveInGetID() { _asm { jmp[winmm.waveInGetID] } }
__declspec(naked) void _waveInGetNumDevs() { _asm { jmp[winmm.waveInGetNumDevs] } }
__declspec(naked) void _waveInGetPosition() { _asm { jmp[winmm.waveInGetPosition] } }
__declspec(naked) void _waveInMessage() { _asm { jmp[winmm.waveInMessage] } }
__declspec(naked) void _waveInOpen() { _asm { jmp[winmm.waveInOpen] } }
__declspec(naked) void _waveInPrepareHeader() { _asm { jmp[winmm.waveInPrepareHeader] } }
__declspec(naked) void _waveInReset() { _asm { jmp[winmm.waveInReset] } }
__declspec(naked) void _waveInStart() { _asm { jmp[winmm.waveInStart] } }
__declspec(naked) void _waveInStop() { _asm { jmp[winmm.waveInStop] } }
__declspec(naked) void _waveInUnprepareHeader() { _asm { jmp[winmm.waveInUnprepareHeader] } }
__declspec(naked) void _waveOutBreakLoop() { _asm { jmp[winmm.waveOutBreakLoop] } }
__declspec(naked) void _waveOutClose() { _asm { jmp[winmm.waveOutClose] } }
__declspec(naked) void _waveOutGetDevCapsA() { _asm { jmp[winmm.waveOutGetDevCapsA] } }
__declspec(naked) void _waveOutGetDevCapsW() { _asm { jmp[winmm.waveOutGetDevCapsW] } }
__declspec(naked) void _waveOutGetErrorTextA() { _asm { jmp[winmm.waveOutGetErrorTextA] } }
__declspec(naked) void _waveOutGetErrorTextW() { _asm { jmp[winmm.waveOutGetErrorTextW] } }
__declspec(naked) void _waveOutGetID() { _asm { jmp[winmm.waveOutGetID] } }
__declspec(naked) void _waveOutGetNumDevs() { _asm { jmp[winmm.waveOutGetNumDevs] } }
__declspec(naked) void _waveOutGetPitch() { _asm { jmp[winmm.waveOutGetPitch] } }
__declspec(naked) void _waveOutGetPlaybackRate() { _asm { jmp[winmm.waveOutGetPlaybackRate] } }
__declspec(naked) void _waveOutGetPosition() { _asm { jmp[winmm.waveOutGetPosition] } }
__declspec(naked) void _waveOutGetVolume() { _asm { jmp[winmm.waveOutGetVolume] } }
__declspec(naked) void _waveOutMessage() { _asm { jmp[winmm.waveOutMessage] } }
__declspec(naked) void _waveOutOpen() { _asm { jmp[winmm.waveOutOpen] } }
__declspec(naked) void _waveOutPause() { _asm { jmp[winmm.waveOutPause] } }
__declspec(naked) void _waveOutPrepareHeader() { _asm { jmp[winmm.waveOutPrepareHeader] } }
__declspec(naked) void _waveOutReset() { _asm { jmp[winmm.waveOutReset] } }
__declspec(naked) void _waveOutRestart() { _asm { jmp[winmm.waveOutRestart] } }
__declspec(naked) void _waveOutSetPitch() { _asm { jmp[winmm.waveOutSetPitch] } }
__declspec(naked) void _waveOutSetPlaybackRate() { _asm { jmp[winmm.waveOutSetPlaybackRate] } }
__declspec(naked) void _waveOutSetVolume() { _asm { jmp[winmm.waveOutSetVolume] } }
__declspec(naked) void _waveOutUnprepareHeader() { _asm { jmp[winmm.waveOutUnprepareHeader] } }
__declspec(naked) void _waveOutWrite() { _asm { jmp[winmm.waveOutWrite] } }
__declspec(naked) void _wid32Message() { _asm { jmp[winmm.wid32Message] } }
__declspec(naked) void _wod32Message() { _asm { jmp[winmm.wod32Message] } }

struct dbghelp_dll {
    FARPROC DbgHelpCreateUserDump;
    FARPROC DbgHelpCreateUserDumpW;
    FARPROC EnumDirTree;
    FARPROC EnumDirTreeW;
    FARPROC EnumerateLoadedModules;
    FARPROC EnumerateLoadedModules64;
    FARPROC EnumerateLoadedModulesEx;
    FARPROC EnumerateLoadedModulesExW;
    FARPROC EnumerateLoadedModulesW64;
    FARPROC ExtensionApiVersion;
    FARPROC FindDebugInfoFile;
    FARPROC FindDebugInfoFileEx;
    FARPROC FindDebugInfoFileExW;
    FARPROC FindExecutableImage;
    FARPROC FindExecutableImageEx;
    FARPROC FindExecutableImageExW;
    FARPROC FindFileInPath;
    FARPROC FindFileInSearchPath;
    FARPROC GetTimestampForLoadedLibrary;
    FARPROC ImageDirectoryEntryToData;
    FARPROC ImageDirectoryEntryToDataEx;
    FARPROC ImageNtHeader;
    FARPROC ImageRvaToSection;
    FARPROC ImageRvaToVa;
    FARPROC ImagehlpApiVersion;
    FARPROC ImagehlpApiVersionEx;
    FARPROC MakeSureDirectoryPathExists;
    FARPROC MiniDumpReadDumpStream;
    FARPROC MiniDumpWriteDump;
    FARPROC SearchTreeForFile;
    FARPROC SearchTreeForFileW;
    FARPROC StackWalk;
    FARPROC StackWalk64;
    FARPROC SymAddSourceStream;
    FARPROC SymAddSourceStreamA;
    FARPROC SymAddSourceStreamW;
    FARPROC SymAddSymbol;
    FARPROC SymAddSymbolW;
    FARPROC SymCleanup;
    FARPROC SymDeleteSymbol;
    FARPROC SymDeleteSymbolW;
    FARPROC SymEnumLines;
    FARPROC SymEnumLinesW;
    FARPROC SymEnumProcesses;
    FARPROC SymEnumSourceFileTokens;
    FARPROC SymEnumSourceFiles;
    FARPROC SymEnumSourceFilesW;
    FARPROC SymEnumSourceLines;
    FARPROC SymEnumSourceLinesW;
    FARPROC SymEnumSym;
    FARPROC SymEnumSymbols;
    FARPROC SymEnumSymbolsForAddr;
    FARPROC SymEnumSymbolsForAddrW;
    FARPROC SymEnumSymbolsW;
    FARPROC SymEnumTypes;
    FARPROC SymEnumTypesByName;
    FARPROC SymEnumTypesByNameW;
    FARPROC SymEnumTypesW;
    FARPROC SymEnumerateModules;
    FARPROC SymEnumerateModules64;
    FARPROC SymEnumerateModulesW64;
    FARPROC SymEnumerateSymbols;
    FARPROC SymEnumerateSymbols64;
    FARPROC SymEnumerateSymbolsW;
    FARPROC SymEnumerateSymbolsW64;
    FARPROC SymFindDebugInfoFile;
    FARPROC SymFindDebugInfoFileW;
    FARPROC SymFindExecutableImage;
    FARPROC SymFindExecutableImageW;
    FARPROC SymFindFileInPath;
    FARPROC SymFindFileInPathW;
    FARPROC SymFromAddr;
    FARPROC SymFromAddrW;
    FARPROC SymFromIndex;
    FARPROC SymFromIndexW;
    FARPROC SymFromName;
    FARPROC SymFromNameW;
    FARPROC SymFromToken;
    FARPROC SymFromTokenW;
    FARPROC SymFunctionTableAccess;
    FARPROC SymFunctionTableAccess64;
    FARPROC SymGetFileLineOffsets64;
    FARPROC SymGetHomeDirectory;
    FARPROC SymGetHomeDirectoryW;
    FARPROC SymGetLineFromAddr;
    FARPROC SymGetLineFromAddr64;
    FARPROC SymGetLineFromAddrW64;
    FARPROC SymGetLineFromName;
    FARPROC SymGetLineFromName64;
    FARPROC SymGetLineFromNameW64;
    FARPROC SymGetLineNext;
    FARPROC SymGetLineNext64;
    FARPROC SymGetLineNextW64;
    FARPROC SymGetLinePrev;
    FARPROC SymGetLinePrev64;
    FARPROC SymGetLinePrevW64;
    FARPROC SymGetModuleBase;
    FARPROC SymGetModuleBase64;
    FARPROC SymGetModuleInfo;
    FARPROC SymGetModuleInfo64;
    FARPROC SymGetModuleInfoW;
    FARPROC SymGetModuleInfoW64;
    FARPROC SymGetOmapBlockBase;
    FARPROC SymGetOmaps;
    FARPROC SymGetOptions;
    FARPROC SymGetScope;
    FARPROC SymGetScopeW;
    FARPROC SymGetSearchPath;
    FARPROC SymGetSearchPathW;
    FARPROC SymGetSourceFile;
    FARPROC SymGetSourceFileFromToken;
    FARPROC SymGetSourceFileFromTokenW;
    FARPROC SymGetSourceFileToken;
    FARPROC SymGetSourceFileTokenW;
    FARPROC SymGetSourceFileW;
    FARPROC SymGetSourceVarFromToken;
    FARPROC SymGetSourceVarFromTokenW;
    FARPROC SymGetSymFromAddr;
    FARPROC SymGetSymFromAddr64;
    FARPROC SymGetSymFromName;
    FARPROC SymGetSymFromName64;
    FARPROC SymGetSymNext;
    FARPROC SymGetSymNext64;
    FARPROC SymGetSymPrev;
    FARPROC SymGetSymPrev64;
    FARPROC SymGetSymbolFile;
    FARPROC SymGetSymbolFileW;
    FARPROC SymGetTypeFromName;
    FARPROC SymGetTypeFromNameW;
    FARPROC SymGetTypeInfo;
    FARPROC SymGetTypeInfoEx;
    FARPROC SymGetUnwindInfo;
    FARPROC SymInitialize;
    FARPROC SymInitializeW;
    FARPROC SymLoadModule;
    FARPROC SymLoadModule64;
    FARPROC SymLoadModuleEx;
    FARPROC SymLoadModuleExW;
    FARPROC SymMatchFileName;
    FARPROC SymMatchFileNameW;
    FARPROC SymMatchString;
    FARPROC SymMatchStringA;
    FARPROC SymMatchStringW;
    FARPROC SymNext;
    FARPROC SymNextW;
    FARPROC SymPrev;
    FARPROC SymPrevW;
    FARPROC SymRefreshModuleList;
    FARPROC SymRegisterCallback;
    FARPROC SymRegisterCallback64;
    FARPROC SymRegisterCallbackW64;
    FARPROC SymRegisterFunctionEntryCallback;
    FARPROC SymRegisterFunctionEntryCallback64;
    FARPROC SymSearch;
    FARPROC SymSearchW;
    FARPROC SymSetContext;
    FARPROC SymSetHomeDirectory;
    FARPROC SymSetHomeDirectoryW;
    FARPROC SymSetOptions;
    FARPROC SymSetParentWindow;
    FARPROC SymSetScopeFromAddr;
    FARPROC SymSetScopeFromIndex;
    FARPROC SymSetSearchPath;
    FARPROC SymSetSearchPathW;
    FARPROC SymSrvDeltaName;
    FARPROC SymSrvDeltaNameW;
    FARPROC SymSrvGetFileIndexInfo;
    FARPROC SymSrvGetFileIndexInfoW;
    FARPROC SymSrvGetFileIndexString;
    FARPROC SymSrvGetFileIndexStringW;
    FARPROC SymSrvGetFileIndexes;
    FARPROC SymSrvGetFileIndexesW;
    FARPROC SymSrvGetSupplement;
    FARPROC SymSrvGetSupplementW;
    FARPROC SymSrvIsStore;
    FARPROC SymSrvIsStoreW;
    FARPROC SymSrvStoreFile;
    FARPROC SymSrvStoreFileW;
    FARPROC SymSrvStoreSupplement;
    FARPROC SymSrvStoreSupplementW;
    FARPROC SymUnDName;
    FARPROC SymUnDName64;
    FARPROC SymUnloadModule;
    FARPROC SymUnloadModule64;
    FARPROC UnDecorateSymbolName;
    FARPROC UnDecorateSymbolNameW;
    FARPROC WinDbgExtensionDllInit;
    FARPROC block;
    FARPROC chksym;
    FARPROC dbghelp;
    FARPROC dh;
    FARPROC fptr;
    FARPROC homedir;
    FARPROC itoldyouso;
    FARPROC lmi;
    FARPROC lminfo;
    FARPROC omap;
    FARPROC srcfiles;
    FARPROC stack_force_ebp;
    FARPROC stackdbg;
    FARPROC sym;
    FARPROC symsrv;
    FARPROC vc7fpo;
} dbghelp;

__declspec(naked) void _DbgHelpCreateUserDump() { _asm { jmp[dbghelp.DbgHelpCreateUserDump] } }
__declspec(naked) void _DbgHelpCreateUserDumpW() { _asm { jmp[dbghelp.DbgHelpCreateUserDumpW] } }
__declspec(naked) void _EnumDirTree() { _asm { jmp[dbghelp.EnumDirTree] } }
__declspec(naked) void _EnumDirTreeW() { _asm { jmp[dbghelp.EnumDirTreeW] } }
__declspec(naked) void _EnumerateLoadedModules() { _asm { jmp[dbghelp.EnumerateLoadedModules] } }
__declspec(naked) void _EnumerateLoadedModules64() { _asm { jmp[dbghelp.EnumerateLoadedModules64] } }
__declspec(naked) void _EnumerateLoadedModulesEx() { _asm { jmp[dbghelp.EnumerateLoadedModulesEx] } }
__declspec(naked) void _EnumerateLoadedModulesExW() { _asm { jmp[dbghelp.EnumerateLoadedModulesExW] } }
__declspec(naked) void _EnumerateLoadedModulesW64() { _asm { jmp[dbghelp.EnumerateLoadedModulesW64] } }
__declspec(naked) void _ExtensionApiVersion() { _asm { jmp[dbghelp.ExtensionApiVersion] } }
__declspec(naked) void _FindDebugInfoFile() { _asm { jmp[dbghelp.FindDebugInfoFile] } }
__declspec(naked) void _FindDebugInfoFileEx() { _asm { jmp[dbghelp.FindDebugInfoFileEx] } }
__declspec(naked) void _FindDebugInfoFileExW() { _asm { jmp[dbghelp.FindDebugInfoFileExW] } }
__declspec(naked) void _FindExecutableImage() { _asm { jmp[dbghelp.FindExecutableImage] } }
__declspec(naked) void _FindExecutableImageEx() { _asm { jmp[dbghelp.FindExecutableImageEx] } }
__declspec(naked) void _FindExecutableImageExW() { _asm { jmp[dbghelp.FindExecutableImageExW] } }
__declspec(naked) void _FindFileInPath() { _asm { jmp[dbghelp.FindFileInPath] } }
__declspec(naked) void _FindFileInSearchPath() { _asm { jmp[dbghelp.FindFileInSearchPath] } }
__declspec(naked) void _GetTimestampForLoadedLibrary() { _asm { jmp[dbghelp.GetTimestampForLoadedLibrary] } }
__declspec(naked) void _ImageDirectoryEntryToData() { _asm { jmp[dbghelp.ImageDirectoryEntryToData] } }
__declspec(naked) void _ImageDirectoryEntryToDataEx() { _asm { jmp[dbghelp.ImageDirectoryEntryToDataEx] } }
__declspec(naked) void _ImageNtHeader() { _asm { jmp[dbghelp.ImageNtHeader] } }
__declspec(naked) void _ImageRvaToSection() { _asm { jmp[dbghelp.ImageRvaToSection] } }
__declspec(naked) void _ImageRvaToVa() { _asm { jmp[dbghelp.ImageRvaToVa] } }
__declspec(naked) void _ImagehlpApiVersion() { _asm { jmp[dbghelp.ImagehlpApiVersion] } }
__declspec(naked) void _ImagehlpApiVersionEx() { _asm { jmp[dbghelp.ImagehlpApiVersionEx] } }
__declspec(naked) void _MakeSureDirectoryPathExists() { _asm { jmp[dbghelp.MakeSureDirectoryPathExists] } }
__declspec(naked) void _MiniDumpReadDumpStream() { _asm { jmp[dbghelp.MiniDumpReadDumpStream] } }
__declspec(naked) void _MiniDumpWriteDump() { _asm { jmp[dbghelp.MiniDumpWriteDump] } }
__declspec(naked) void _SearchTreeForFile() { _asm { jmp[dbghelp.SearchTreeForFile] } }
__declspec(naked) void _SearchTreeForFileW() { _asm { jmp[dbghelp.SearchTreeForFileW] } }
__declspec(naked) void _StackWalk() { _asm { jmp[dbghelp.StackWalk] } }
__declspec(naked) void _StackWalk64() { _asm { jmp[dbghelp.StackWalk64] } }
__declspec(naked) void _SymAddSourceStream() { _asm { jmp[dbghelp.SymAddSourceStream] } }
__declspec(naked) void _SymAddSourceStreamA() { _asm { jmp[dbghelp.SymAddSourceStreamA] } }
__declspec(naked) void _SymAddSourceStreamW() { _asm { jmp[dbghelp.SymAddSourceStreamW] } }
__declspec(naked) void _SymAddSymbol() { _asm { jmp[dbghelp.SymAddSymbol] } }
__declspec(naked) void _SymAddSymbolW() { _asm { jmp[dbghelp.SymAddSymbolW] } }
__declspec(naked) void _SymCleanup() { _asm { jmp[dbghelp.SymCleanup] } }
__declspec(naked) void _SymDeleteSymbol() { _asm { jmp[dbghelp.SymDeleteSymbol] } }
__declspec(naked) void _SymDeleteSymbolW() { _asm { jmp[dbghelp.SymDeleteSymbolW] } }
__declspec(naked) void _SymEnumLines() { _asm { jmp[dbghelp.SymEnumLines] } }
__declspec(naked) void _SymEnumLinesW() { _asm { jmp[dbghelp.SymEnumLinesW] } }
__declspec(naked) void _SymEnumProcesses() { _asm { jmp[dbghelp.SymEnumProcesses] } }
__declspec(naked) void _SymEnumSourceFileTokens() { _asm { jmp[dbghelp.SymEnumSourceFileTokens] } }
__declspec(naked) void _SymEnumSourceFiles() { _asm { jmp[dbghelp.SymEnumSourceFiles] } }
__declspec(naked) void _SymEnumSourceFilesW() { _asm { jmp[dbghelp.SymEnumSourceFilesW] } }
__declspec(naked) void _SymEnumSourceLines() { _asm { jmp[dbghelp.SymEnumSourceLines] } }
__declspec(naked) void _SymEnumSourceLinesW() { _asm { jmp[dbghelp.SymEnumSourceLinesW] } }
__declspec(naked) void _SymEnumSym() { _asm { jmp[dbghelp.SymEnumSym] } }
__declspec(naked) void _SymEnumSymbols() { _asm { jmp[dbghelp.SymEnumSymbols] } }
__declspec(naked) void _SymEnumSymbolsForAddr() { _asm { jmp[dbghelp.SymEnumSymbolsForAddr] } }
__declspec(naked) void _SymEnumSymbolsForAddrW() { _asm { jmp[dbghelp.SymEnumSymbolsForAddrW] } }
__declspec(naked) void _SymEnumSymbolsW() { _asm { jmp[dbghelp.SymEnumSymbolsW] } }
__declspec(naked) void _SymEnumTypes() { _asm { jmp[dbghelp.SymEnumTypes] } }
__declspec(naked) void _SymEnumTypesByName() { _asm { jmp[dbghelp.SymEnumTypesByName] } }
__declspec(naked) void _SymEnumTypesByNameW() { _asm { jmp[dbghelp.SymEnumTypesByNameW] } }
__declspec(naked) void _SymEnumTypesW() { _asm { jmp[dbghelp.SymEnumTypesW] } }
__declspec(naked) void _SymEnumerateModules() { _asm { jmp[dbghelp.SymEnumerateModules] } }
__declspec(naked) void _SymEnumerateModules64() { _asm { jmp[dbghelp.SymEnumerateModules64] } }
__declspec(naked) void _SymEnumerateModulesW64() { _asm { jmp[dbghelp.SymEnumerateModulesW64] } }
__declspec(naked) void _SymEnumerateSymbols() { _asm { jmp[dbghelp.SymEnumerateSymbols] } }
__declspec(naked) void _SymEnumerateSymbols64() { _asm { jmp[dbghelp.SymEnumerateSymbols64] } }
__declspec(naked) void _SymEnumerateSymbolsW() { _asm { jmp[dbghelp.SymEnumerateSymbolsW] } }
__declspec(naked) void _SymEnumerateSymbolsW64() { _asm { jmp[dbghelp.SymEnumerateSymbolsW64] } }
__declspec(naked) void _SymFindDebugInfoFile() { _asm { jmp[dbghelp.SymFindDebugInfoFile] } }
__declspec(naked) void _SymFindDebugInfoFileW() { _asm { jmp[dbghelp.SymFindDebugInfoFileW] } }
__declspec(naked) void _SymFindExecutableImage() { _asm { jmp[dbghelp.SymFindExecutableImage] } }
__declspec(naked) void _SymFindExecutableImageW() { _asm { jmp[dbghelp.SymFindExecutableImageW] } }
__declspec(naked) void _SymFindFileInPath() { _asm { jmp[dbghelp.SymFindFileInPath] } }
__declspec(naked) void _SymFindFileInPathW() { _asm { jmp[dbghelp.SymFindFileInPathW] } }
__declspec(naked) void _SymFromAddr() { _asm { jmp[dbghelp.SymFromAddr] } }
__declspec(naked) void _SymFromAddrW() { _asm { jmp[dbghelp.SymFromAddrW] } }
__declspec(naked) void _SymFromIndex() { _asm { jmp[dbghelp.SymFromIndex] } }
__declspec(naked) void _SymFromIndexW() { _asm { jmp[dbghelp.SymFromIndexW] } }
__declspec(naked) void _SymFromName() { _asm { jmp[dbghelp.SymFromName] } }
__declspec(naked) void _SymFromNameW() { _asm { jmp[dbghelp.SymFromNameW] } }
__declspec(naked) void _SymFromToken() { _asm { jmp[dbghelp.SymFromToken] } }
__declspec(naked) void _SymFromTokenW() { _asm { jmp[dbghelp.SymFromTokenW] } }
__declspec(naked) void _SymFunctionTableAccess() { _asm { jmp[dbghelp.SymFunctionTableAccess] } }
__declspec(naked) void _SymFunctionTableAccess64() { _asm { jmp[dbghelp.SymFunctionTableAccess64] } }
__declspec(naked) void _SymGetFileLineOffsets64() { _asm { jmp[dbghelp.SymGetFileLineOffsets64] } }
__declspec(naked) void _SymGetHomeDirectory() { _asm { jmp[dbghelp.SymGetHomeDirectory] } }
__declspec(naked) void _SymGetHomeDirectoryW() { _asm { jmp[dbghelp.SymGetHomeDirectoryW] } }
__declspec(naked) void _SymGetLineFromAddr() { _asm { jmp[dbghelp.SymGetLineFromAddr] } }
__declspec(naked) void _SymGetLineFromAddr64() { _asm { jmp[dbghelp.SymGetLineFromAddr64] } }
__declspec(naked) void _SymGetLineFromAddrW64() { _asm { jmp[dbghelp.SymGetLineFromAddrW64] } }
__declspec(naked) void _SymGetLineFromName() { _asm { jmp[dbghelp.SymGetLineFromName] } }
__declspec(naked) void _SymGetLineFromName64() { _asm { jmp[dbghelp.SymGetLineFromName64] } }
__declspec(naked) void _SymGetLineFromNameW64() { _asm { jmp[dbghelp.SymGetLineFromNameW64] } }
__declspec(naked) void _SymGetLineNext() { _asm { jmp[dbghelp.SymGetLineNext] } }
__declspec(naked) void _SymGetLineNext64() { _asm { jmp[dbghelp.SymGetLineNext64] } }
__declspec(naked) void _SymGetLineNextW64() { _asm { jmp[dbghelp.SymGetLineNextW64] } }
__declspec(naked) void _SymGetLinePrev() { _asm { jmp[dbghelp.SymGetLinePrev] } }
__declspec(naked) void _SymGetLinePrev64() { _asm { jmp[dbghelp.SymGetLinePrev64] } }
__declspec(naked) void _SymGetLinePrevW64() { _asm { jmp[dbghelp.SymGetLinePrevW64] } }
__declspec(naked) void _SymGetModuleBase() { _asm { jmp[dbghelp.SymGetModuleBase] } }
__declspec(naked) void _SymGetModuleBase64() { _asm { jmp[dbghelp.SymGetModuleBase64] } }
__declspec(naked) void _SymGetModuleInfo() { _asm { jmp[dbghelp.SymGetModuleInfo] } }
__declspec(naked) void _SymGetModuleInfo64() { _asm { jmp[dbghelp.SymGetModuleInfo64] } }
__declspec(naked) void _SymGetModuleInfoW() { _asm { jmp[dbghelp.SymGetModuleInfoW] } }
__declspec(naked) void _SymGetModuleInfoW64() { _asm { jmp[dbghelp.SymGetModuleInfoW64] } }
__declspec(naked) void _SymGetOmapBlockBase() { _asm { jmp[dbghelp.SymGetOmapBlockBase] } }
__declspec(naked) void _SymGetOmaps() { _asm { jmp[dbghelp.SymGetOmaps] } }
__declspec(naked) void _SymGetOptions() { _asm { jmp[dbghelp.SymGetOptions] } }
__declspec(naked) void _SymGetScope() { _asm { jmp[dbghelp.SymGetScope] } }
__declspec(naked) void _SymGetScopeW() { _asm { jmp[dbghelp.SymGetScopeW] } }
__declspec(naked) void _SymGetSearchPath() { _asm { jmp[dbghelp.SymGetSearchPath] } }
__declspec(naked) void _SymGetSearchPathW() { _asm { jmp[dbghelp.SymGetSearchPathW] } }
__declspec(naked) void _SymGetSourceFile() { _asm { jmp[dbghelp.SymGetSourceFile] } }
__declspec(naked) void _SymGetSourceFileFromToken() { _asm { jmp[dbghelp.SymGetSourceFileFromToken] } }
__declspec(naked) void _SymGetSourceFileFromTokenW() { _asm { jmp[dbghelp.SymGetSourceFileFromTokenW] } }
__declspec(naked) void _SymGetSourceFileToken() { _asm { jmp[dbghelp.SymGetSourceFileToken] } }
__declspec(naked) void _SymGetSourceFileTokenW() { _asm { jmp[dbghelp.SymGetSourceFileTokenW] } }
__declspec(naked) void _SymGetSourceFileW() { _asm { jmp[dbghelp.SymGetSourceFileW] } }
__declspec(naked) void _SymGetSourceVarFromToken() { _asm { jmp[dbghelp.SymGetSourceVarFromToken] } }
__declspec(naked) void _SymGetSourceVarFromTokenW() { _asm { jmp[dbghelp.SymGetSourceVarFromTokenW] } }
__declspec(naked) void _SymGetSymFromAddr() { _asm { jmp[dbghelp.SymGetSymFromAddr] } }
__declspec(naked) void _SymGetSymFromAddr64() { _asm { jmp[dbghelp.SymGetSymFromAddr64] } }
__declspec(naked) void _SymGetSymFromName() { _asm { jmp[dbghelp.SymGetSymFromName] } }
__declspec(naked) void _SymGetSymFromName64() { _asm { jmp[dbghelp.SymGetSymFromName64] } }
__declspec(naked) void _SymGetSymNext() { _asm { jmp[dbghelp.SymGetSymNext] } }
__declspec(naked) void _SymGetSymNext64() { _asm { jmp[dbghelp.SymGetSymNext64] } }
__declspec(naked) void _SymGetSymPrev() { _asm { jmp[dbghelp.SymGetSymPrev] } }
__declspec(naked) void _SymGetSymPrev64() { _asm { jmp[dbghelp.SymGetSymPrev64] } }
__declspec(naked) void _SymGetSymbolFile() { _asm { jmp[dbghelp.SymGetSymbolFile] } }
__declspec(naked) void _SymGetSymbolFileW() { _asm { jmp[dbghelp.SymGetSymbolFileW] } }
__declspec(naked) void _SymGetTypeFromName() { _asm { jmp[dbghelp.SymGetTypeFromName] } }
__declspec(naked) void _SymGetTypeFromNameW() { _asm { jmp[dbghelp.SymGetTypeFromNameW] } }
__declspec(naked) void _SymGetTypeInfo() { _asm { jmp[dbghelp.SymGetTypeInfo] } }
__declspec(naked) void _SymGetTypeInfoEx() { _asm { jmp[dbghelp.SymGetTypeInfoEx] } }
__declspec(naked) void _SymGetUnwindInfo() { _asm { jmp[dbghelp.SymGetUnwindInfo] } }
__declspec(naked) void _SymInitialize() { _asm { jmp[dbghelp.SymInitialize] } }
__declspec(naked) void _SymInitializeW() { _asm { jmp[dbghelp.SymInitializeW] } }
__declspec(naked) void _SymLoadModule() { _asm { jmp[dbghelp.SymLoadModule] } }
__declspec(naked) void _SymLoadModule64() { _asm { jmp[dbghelp.SymLoadModule64] } }
__declspec(naked) void _SymLoadModuleEx() { _asm { jmp[dbghelp.SymLoadModuleEx] } }
__declspec(naked) void _SymLoadModuleExW() { _asm { jmp[dbghelp.SymLoadModuleExW] } }
__declspec(naked) void _SymMatchFileName() { _asm { jmp[dbghelp.SymMatchFileName] } }
__declspec(naked) void _SymMatchFileNameW() { _asm { jmp[dbghelp.SymMatchFileNameW] } }
__declspec(naked) void _SymMatchString() { _asm { jmp[dbghelp.SymMatchString] } }
__declspec(naked) void _SymMatchStringA() { _asm { jmp[dbghelp.SymMatchStringA] } }
__declspec(naked) void _SymMatchStringW() { _asm { jmp[dbghelp.SymMatchStringW] } }
__declspec(naked) void _SymNext() { _asm { jmp[dbghelp.SymNext] } }
__declspec(naked) void _SymNextW() { _asm { jmp[dbghelp.SymNextW] } }
__declspec(naked) void _SymPrev() { _asm { jmp[dbghelp.SymPrev] } }
__declspec(naked) void _SymPrevW() { _asm { jmp[dbghelp.SymPrevW] } }
__declspec(naked) void _SymRefreshModuleList() { _asm { jmp[dbghelp.SymRefreshModuleList] } }
__declspec(naked) void _SymRegisterCallback() { _asm { jmp[dbghelp.SymRegisterCallback] } }
__declspec(naked) void _SymRegisterCallback64() { _asm { jmp[dbghelp.SymRegisterCallback64] } }
__declspec(naked) void _SymRegisterCallbackW64() { _asm { jmp[dbghelp.SymRegisterCallbackW64] } }
__declspec(naked) void _SymRegisterFunctionEntryCallback() { _asm { jmp[dbghelp.SymRegisterFunctionEntryCallback] } }
__declspec(naked) void _SymRegisterFunctionEntryCallback64() { _asm { jmp[dbghelp.SymRegisterFunctionEntryCallback64] } }
__declspec(naked) void _SymSearch() { _asm { jmp[dbghelp.SymSearch] } }
__declspec(naked) void _SymSearchW() { _asm { jmp[dbghelp.SymSearchW] } }
__declspec(naked) void _SymSetContext() { _asm { jmp[dbghelp.SymSetContext] } }
__declspec(naked) void _SymSetHomeDirectory() { _asm { jmp[dbghelp.SymSetHomeDirectory] } }
__declspec(naked) void _SymSetHomeDirectoryW() { _asm { jmp[dbghelp.SymSetHomeDirectoryW] } }
__declspec(naked) void _SymSetOptions() { _asm { jmp[dbghelp.SymSetOptions] } }
__declspec(naked) void _SymSetParentWindow() { _asm { jmp[dbghelp.SymSetParentWindow] } }
__declspec(naked) void _SymSetScopeFromAddr() { _asm { jmp[dbghelp.SymSetScopeFromAddr] } }
__declspec(naked) void _SymSetScopeFromIndex() { _asm { jmp[dbghelp.SymSetScopeFromIndex] } }
__declspec(naked) void _SymSetSearchPath() { _asm { jmp[dbghelp.SymSetSearchPath] } }
__declspec(naked) void _SymSetSearchPathW() { _asm { jmp[dbghelp.SymSetSearchPathW] } }
__declspec(naked) void _SymSrvDeltaName() { _asm { jmp[dbghelp.SymSrvDeltaName] } }
__declspec(naked) void _SymSrvDeltaNameW() { _asm { jmp[dbghelp.SymSrvDeltaNameW] } }
__declspec(naked) void _SymSrvGetFileIndexInfo() { _asm { jmp[dbghelp.SymSrvGetFileIndexInfo] } }
__declspec(naked) void _SymSrvGetFileIndexInfoW() { _asm { jmp[dbghelp.SymSrvGetFileIndexInfoW] } }
__declspec(naked) void _SymSrvGetFileIndexString() { _asm { jmp[dbghelp.SymSrvGetFileIndexString] } }
__declspec(naked) void _SymSrvGetFileIndexStringW() { _asm { jmp[dbghelp.SymSrvGetFileIndexStringW] } }
__declspec(naked) void _SymSrvGetFileIndexes() { _asm { jmp[dbghelp.SymSrvGetFileIndexes] } }
__declspec(naked) void _SymSrvGetFileIndexesW() { _asm { jmp[dbghelp.SymSrvGetFileIndexesW] } }
__declspec(naked) void _SymSrvGetSupplement() { _asm { jmp[dbghelp.SymSrvGetSupplement] } }
__declspec(naked) void _SymSrvGetSupplementW() { _asm { jmp[dbghelp.SymSrvGetSupplementW] } }
__declspec(naked) void _SymSrvIsStore() { _asm { jmp[dbghelp.SymSrvIsStore] } }
__declspec(naked) void _SymSrvIsStoreW() { _asm { jmp[dbghelp.SymSrvIsStoreW] } }
__declspec(naked) void _SymSrvStoreFile() { _asm { jmp[dbghelp.SymSrvStoreFile] } }
__declspec(naked) void _SymSrvStoreFileW() { _asm { jmp[dbghelp.SymSrvStoreFileW] } }
__declspec(naked) void _SymSrvStoreSupplement() { _asm { jmp[dbghelp.SymSrvStoreSupplement] } }
__declspec(naked) void _SymSrvStoreSupplementW() { _asm { jmp[dbghelp.SymSrvStoreSupplementW] } }
__declspec(naked) void _SymUnDName() { _asm { jmp[dbghelp.SymUnDName] } }
__declspec(naked) void _SymUnDName64() { _asm { jmp[dbghelp.SymUnDName64] } }
__declspec(naked) void _SymUnloadModule() { _asm { jmp[dbghelp.SymUnloadModule] } }
__declspec(naked) void _SymUnloadModule64() { _asm { jmp[dbghelp.SymUnloadModule64] } }
__declspec(naked) void _UnDecorateSymbolName() { _asm { jmp[dbghelp.UnDecorateSymbolName] } }
__declspec(naked) void _UnDecorateSymbolNameW() { _asm { jmp[dbghelp.UnDecorateSymbolNameW] } }
__declspec(naked) void _WinDbgExtensionDllInit() { _asm { jmp[dbghelp.WinDbgExtensionDllInit] } }
__declspec(naked) void _block() { _asm { jmp[dbghelp.block] } }
__declspec(naked) void _chksym() { _asm { jmp[dbghelp.chksym] } }
__declspec(naked) void _dbghelp() { _asm { jmp[dbghelp.dbghelp] } }
__declspec(naked) void _dh() { _asm { jmp[dbghelp.dh] } }
__declspec(naked) void _fptr() { _asm { jmp[dbghelp.fptr] } }
__declspec(naked) void _homedir() { _asm { jmp[dbghelp.homedir] } }
__declspec(naked) void _itoldyouso() { _asm { jmp[dbghelp.itoldyouso] } }
__declspec(naked) void _lmi() { _asm { jmp[dbghelp.lmi] } }
__declspec(naked) void _lminfo() { _asm { jmp[dbghelp.lminfo] } }
__declspec(naked) void _omap() { _asm { jmp[dbghelp.omap] } }
__declspec(naked) void _srcfiles() { _asm { jmp[dbghelp.srcfiles] } }
__declspec(naked) void _stack_force_ebp() { _asm { jmp[dbghelp.stack_force_ebp] } }
__declspec(naked) void _stackdbg() { _asm { jmp[dbghelp.stackdbg] } }
__declspec(naked) void _sym() { _asm { jmp[dbghelp.sym] } }
__declspec(naked) void _symsrv() { _asm { jmp[dbghelp.symsrv] } }
__declspec(naked) void _vc7fpo() { _asm { jmp[dbghelp.vc7fpo] } }

struct dinput8_dll {
    FARPROC DirectInput8Create;
    FARPROC DllRegisterServer;
    FARPROC DllUnregisterServer;
    FARPROC GetdfDIJoystick;
} dinput8;

__declspec(naked) void _DirectInput8Create() { _asm { jmp[dinput8.DirectInput8Create] } }
__declspec(naked) void _DllRegisterServer() { _asm { jmp[dinput8.DllRegisterServer] } }
__declspec(naked) void _DllUnregisterServer() { _asm { jmp[dinput8.DllUnregisterServer] } }
__declspec(naked) void _GetdfDIJoystick() { _asm { jmp[dinput8.GetdfDIJoystick] } }

struct xinput1_3_dll {
    FARPROC DllMain;
    FARPROC XInputEnable;
    FARPROC XInputGetBatteryInformation;
    FARPROC XInputGetCapabilities;
    FARPROC XInputGetDSoundAudioDeviceGuids;
    FARPROC XInputGetKeystroke;
    FARPROC XInputGetState;
    FARPROC XInputSetState;
} xinput1_3;

__declspec(naked) void _DllMain() { _asm { jmp[xinput1_3.DllMain] } }
__declspec(naked) void _XInputEnable() { _asm { jmp[xinput1_3.XInputEnable] } }
__declspec(naked) void _XInputGetBatteryInformation() { _asm { jmp[xinput1_3.XInputGetBatteryInformation] } }
__declspec(naked) void _XInputGetCapabilities() { _asm { jmp[xinput1_3.XInputGetCapabilities] } }
__declspec(naked) void _XInputGetDSoundAudioDeviceGuids() { _asm { jmp[xinput1_3.XInputGetDSoundAudioDeviceGuids] } }
__declspec(naked) void _XInputGetKeystroke() { _asm { jmp[xinput1_3.XInputGetKeystroke] } }
__declspec(naked) void _XInputGetState() { _asm { jmp[xinput1_3.XInputGetState] } }
__declspec(naked) void _XInputSetState() { _asm { jmp[xinput1_3.XInputSetState] } }

struct dsound_dll {
    FARPROC DirectSoundCaptureCreate;
    FARPROC DirectSoundCaptureCreate8;
    FARPROC DirectSoundCaptureEnumerateA;
    FARPROC DirectSoundCaptureEnumerateW;
    FARPROC DirectSoundCreate;
    FARPROC DirectSoundCreate8;
    FARPROC DirectSoundEnumerateA;
    FARPROC DirectSoundEnumerateW;
    FARPROC DirectSoundFullDuplexCreate;
    FARPROC GetDeviceID;
} dsound;

__declspec(naked) void _DirectSoundCaptureCreate() { _asm { jmp[dsound.DirectSoundCaptureCreate] } }
__declspec(naked) void _DirectSoundCaptureCreate8() { _asm { jmp[dsound.DirectSoundCaptureCreate8] } }
__declspec(naked) void _DirectSoundCaptureEnumerateA() { _asm { jmp[dsound.DirectSoundCaptureEnumerateA] } }
__declspec(naked) void _DirectSoundCaptureEnumerateW() { _asm { jmp[dsound.DirectSoundCaptureEnumerateW] } }
__declspec(naked) void _DirectSoundCreate() { _asm { jmp[dsound.DirectSoundCreate] } }
__declspec(naked) void _DirectSoundCreate8() { _asm { jmp[dsound.DirectSoundCreate8] } }
__declspec(naked) void _DirectSoundEnumerateA() { _asm { jmp[dsound.DirectSoundEnumerateA] } }
__declspec(naked) void _DirectSoundEnumerateW() { _asm { jmp[dsound.DirectSoundEnumerateW] } }
__declspec(naked) void _DirectSoundFullDuplexCreate() { _asm { jmp[dsound.DirectSoundFullDuplexCreate] } }
__declspec(naked) void _GetDeviceID() { _asm { jmp[dsound.GetDeviceID] } }

struct ddraw_dll {
    FARPROC AcquireDDThreadLock;
    FARPROC CompleteCreateSysmemSurface;
    FARPROC D3DParseUnknownCommand;
    FARPROC DDGetAttachedSurfaceLcl;
    FARPROC DDInternalLock;
    FARPROC DDInternalUnlock;
    FARPROC DSoundHelp;
    FARPROC DirectDrawCreate;
    FARPROC DirectDrawCreateClipper;
    FARPROC DirectDrawCreateEx;
    FARPROC DirectDrawEnumerateA;
    FARPROC DirectDrawEnumerateExA;
    FARPROC DirectDrawEnumerateExW;
    FARPROC DirectDrawEnumerateW;
    FARPROC GetDDSurfaceLocal;
    FARPROC GetOLEThunkData;
    FARPROC GetSurfaceFromDC;
    FARPROC RegisterSpecialCase;
    FARPROC ReleaseDDThreadLock;
    FARPROC SetAppCompatData;
} ddraw;

__declspec(naked) void _AcquireDDThreadLock() { _asm { jmp[ddraw.AcquireDDThreadLock] } }
__declspec(naked) void _CompleteCreateSysmemSurface() { _asm { jmp[ddraw.CompleteCreateSysmemSurface] } }
__declspec(naked) void _D3DParseUnknownCommand() { _asm { jmp[ddraw.D3DParseUnknownCommand] } }
__declspec(naked) void _DDGetAttachedSurfaceLcl() { _asm { jmp[ddraw.DDGetAttachedSurfaceLcl] } }
__declspec(naked) void _DDInternalLock() { _asm { jmp[ddraw.DDInternalLock] } }
__declspec(naked) void _DDInternalUnlock() { _asm { jmp[ddraw.DDInternalUnlock] } }
__declspec(naked) void _DSoundHelp() { _asm { jmp[ddraw.DSoundHelp] } }
__declspec(naked) void _DirectDrawCreate() { _asm { jmp[ddraw.DirectDrawCreate] } }
__declspec(naked) void _DirectDrawCreateClipper() { _asm { jmp[ddraw.DirectDrawCreateClipper] } }
__declspec(naked) void _DirectDrawCreateEx() { _asm { jmp[ddraw.DirectDrawCreateEx] } }
__declspec(naked) void _DirectDrawEnumerateA() { _asm { jmp[ddraw.DirectDrawEnumerateA] } }
__declspec(naked) void _DirectDrawEnumerateExA() { _asm { jmp[ddraw.DirectDrawEnumerateExA] } }
__declspec(naked) void _DirectDrawEnumerateExW() { _asm { jmp[ddraw.DirectDrawEnumerateExW] } }
__declspec(naked) void _DirectDrawEnumerateW() { _asm { jmp[ddraw.DirectDrawEnumerateW] } }
__declspec(naked) void _GetDDSurfaceLocal() { _asm { jmp[ddraw.GetDDSurfaceLocal] } }
__declspec(naked) void _GetOLEThunkData() { _asm { jmp[ddraw.GetOLEThunkData] } }
__declspec(naked) void _GetSurfaceFromDC() { _asm { jmp[ddraw.GetSurfaceFromDC] } }
__declspec(naked) void _RegisterSpecialCase() { _asm { jmp[ddraw.RegisterSpecialCase] } }
__declspec(naked) void _ReleaseDDThreadLock() { _asm { jmp[ddraw.ReleaseDDThreadLock] } }
__declspec(naked) void _SetAppCompatData() { _asm { jmp[ddraw.SetAppCompatData] } }

struct d3d8_dll {
    FARPROC Direct3D8EnableMaximizedWindowedModeShim;
    FARPROC Direct3DCreate8;
    FARPROC ValidatePixelShader;
    FARPROC ValidateVertexShader;
} d3d8;

__declspec(naked) void _Direct3D8EnableMaximizedWindowedModeShim() { _asm { jmp[d3d8.Direct3D8EnableMaximizedWindowedModeShim] } }
__declspec(naked) void _Direct3DCreate8() { _asm { jmp[d3d8.Direct3DCreate8] } }
__declspec(naked) void _ValidatePixelShader() { _asm { jmp[d3d8.ValidatePixelShader] } }
__declspec(naked) void _ValidateVertexShader() { _asm { jmp[d3d8.ValidateVertexShader] } }

struct shared_dll {
    FARPROC DllCanUnloadNow;
    FARPROC DllGetClassObject;
    FARPROC DebugSetMute;
} shared;

__declspec(naked) void _DllCanUnloadNow() { _asm { jmp[shared.DllCanUnloadNow] } }
__declspec(naked) void _DllGetClassObject() { _asm { jmp[shared.DllGetClassObject] } }
__declspec(naked) void _DebugSetMute() { _asm { jmp[shared.DebugSetMute] } }

uintptr_t OrigInitImports = 0;
uintptr_t InitImportsCallAddr = 0;
uintptr_t GetStartupInfoAddr = 0;
uintptr_t OrigEntryPoint = 0;

void __stdcall MyGetStartupInfoW(LPSTARTUPINFOW lpStartupInfo) {
    loader::LoadPlugins();
    GetStartupInfoW(lpStartupInfo);
}

void OnInitImports() {
    plugin::patch::RedirectCall(InitImportsCallAddr, (void *)OrigInitImports);
    plugin::CallDynGlobal(OrigInitImports);
    plugin::patch::SetPointer(GetStartupInfoAddr, MyGetStartupInfoW);
}

void NAKED DelayedLoadPlugins() {
    __asm call loader::LoadPlugins
    __asm mov eax, OrigEntryPoint
    __asm jmp eax
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        std::wstring gameDir = loader::GetModuleDir(NULL);
        std::wstring loaderSettingsFile = gameDir + L"plugins\\loader.ini";
        loader::debugMode = GetPrivateProfileIntW(L"LOADER", L"DEBUG_MODE", false, loaderSettingsFile.c_str());
        loader::anyProcess = GetPrivateProfileIntW(L"LOADER", L"ANY_PROCESS", false, loaderSettingsFile.c_str()) != 0;
        std::wstring moduleName = plugin::ToLower(loader::GetModuleName(hModule));
        std::wstring procName = plugin::ToLower(PES::GetProcessName());
        if (loader::debugMode == 2)
            plugin::InternalMessage(L"Module: %s\nProcess: %s", moduleName.c_str(), procName.c_str());
        bool loadingResult = false;
        if (moduleName == L"d3d9.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            d3d9.D3DPERF_BeginEvent = GetProcAddress(dll.handle, "D3DPERF_BeginEvent");
            d3d9.D3DPERF_EndEvent = GetProcAddress(dll.handle, "D3DPERF_EndEvent");
            d3d9.D3DPERF_GetStatus = GetProcAddress(dll.handle, "D3DPERF_GetStatus");
            d3d9.D3DPERF_QueryRepeatFrame = GetProcAddress(dll.handle, "D3DPERF_QueryRepeatFrame");
            d3d9.D3DPERF_SetMarker = GetProcAddress(dll.handle, "D3DPERF_SetMarker");
            d3d9.D3DPERF_SetOptions = GetProcAddress(dll.handle, "D3DPERF_SetOptions");
            d3d9.D3DPERF_SetRegion = GetProcAddress(dll.handle, "D3DPERF_SetRegion");
            d3d9.DebugSetLevel = GetProcAddress(dll.handle, "DebugSetLevel");
            shared.DebugSetMute = GetProcAddress(dll.handle, "DebugSetMute");
            d3d9.Direct3D9EnableMaximizedWindowedModeShim = GetProcAddress(dll.handle, "Direct3D9EnableMaximizedWindowedModeShim");
            d3d9.Direct3DCreate9 = GetProcAddress(dll.handle, "Direct3DCreate9");
            d3d9.Direct3DCreate9Ex = GetProcAddress(dll.handle, "Direct3DCreate9Ex");
            d3d9.Direct3DShaderValidatorCreate9 = GetProcAddress(dll.handle, "Direct3DShaderValidatorCreate9");
            d3d9.PSGPError = GetProcAddress(dll.handle, "PSGPError");
            d3d9.PSGPSampleTexture = GetProcAddress(dll.handle, "PSGPSampleTexture");
        }
        else if (moduleName == L"winmm.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            winmm.CloseDriver = GetProcAddress(dll.handle, "CloseDriver");
            winmm.DefDriverProc = GetProcAddress(dll.handle, "DefDriverProc");
            winmm.DriverCallback = GetProcAddress(dll.handle, "DriverCallback");
            winmm.DrvGetModuleHandle = GetProcAddress(dll.handle, "DrvGetModuleHandle");
            winmm.GetDriverModuleHandle = GetProcAddress(dll.handle, "GetDriverModuleHandle");
            winmm.NotifyCallbackData = GetProcAddress(dll.handle, "NotifyCallbackData");
            winmm.OpenDriver = GetProcAddress(dll.handle, "OpenDriver");
            winmm.PlaySound = GetProcAddress(dll.handle, "PlaySound");
            winmm.PlaySoundA = GetProcAddress(dll.handle, "PlaySoundA");
            winmm.PlaySoundW = GetProcAddress(dll.handle, "PlaySoundW");
            winmm.SendDriverMessage = GetProcAddress(dll.handle, "SendDriverMessage");
            winmm.WOW32DriverCallback = GetProcAddress(dll.handle, "WOW32DriverCallback");
            winmm.WOW32ResolveMultiMediaHandle = GetProcAddress(dll.handle, "WOW32ResolveMultiMediaHandle");
            winmm.WOWAppExit = GetProcAddress(dll.handle, "WOWAppExit");
            winmm.aux32Message = GetProcAddress(dll.handle, "aux32Message");
            winmm.auxGetDevCapsA = GetProcAddress(dll.handle, "auxGetDevCapsA");
            winmm.auxGetDevCapsW = GetProcAddress(dll.handle, "auxGetDevCapsW");
            winmm.auxGetNumDevs = GetProcAddress(dll.handle, "auxGetNumDevs");
            winmm.auxGetVolume = GetProcAddress(dll.handle, "auxGetVolume");
            winmm.auxOutMessage = GetProcAddress(dll.handle, "auxOutMessage");
            winmm.auxSetVolume = GetProcAddress(dll.handle, "auxSetVolume");
            winmm.joy32Message = GetProcAddress(dll.handle, "joy32Message");
            winmm.joyConfigChanged = GetProcAddress(dll.handle, "joyConfigChanged");
            winmm.joyGetDevCapsA = GetProcAddress(dll.handle, "joyGetDevCapsA");
            winmm.joyGetDevCapsW = GetProcAddress(dll.handle, "joyGetDevCapsW");
            winmm.joyGetNumDevs = GetProcAddress(dll.handle, "joyGetNumDevs");
            winmm.joyGetPos = GetProcAddress(dll.handle, "joyGetPos");
            winmm.joyGetPosEx = GetProcAddress(dll.handle, "joyGetPosEx");
            winmm.joyGetThreshold = GetProcAddress(dll.handle, "joyGetThreshold");
            winmm.joyReleaseCapture = GetProcAddress(dll.handle, "joyReleaseCapture");
            winmm.joySetCapture = GetProcAddress(dll.handle, "joySetCapture");
            winmm.joySetThreshold = GetProcAddress(dll.handle, "joySetThreshold");
            winmm.mci32Message = GetProcAddress(dll.handle, "mci32Message");
            winmm.mciDriverNotify = GetProcAddress(dll.handle, "mciDriverNotify");
            winmm.mciDriverYield = GetProcAddress(dll.handle, "mciDriverYield");
            winmm.mciExecute = GetProcAddress(dll.handle, "mciExecute");
            winmm.mciFreeCommandResource = GetProcAddress(dll.handle, "mciFreeCommandResource");
            winmm.mciGetCreatorTask = GetProcAddress(dll.handle, "mciGetCreatorTask");
            winmm.mciGetDeviceIDA = GetProcAddress(dll.handle, "mciGetDeviceIDA");
            winmm.mciGetDeviceIDFromElementIDA = GetProcAddress(dll.handle, "mciGetDeviceIDFromElementIDA");
            winmm.mciGetDeviceIDFromElementIDW = GetProcAddress(dll.handle, "mciGetDeviceIDFromElementIDW");
            winmm.mciGetDeviceIDW = GetProcAddress(dll.handle, "mciGetDeviceIDW");
            winmm.mciGetDriverData = GetProcAddress(dll.handle, "mciGetDriverData");
            winmm.mciGetErrorStringA = GetProcAddress(dll.handle, "mciGetErrorStringA");
            winmm.mciGetErrorStringW = GetProcAddress(dll.handle, "mciGetErrorStringW");
            winmm.mciGetYieldProc = GetProcAddress(dll.handle, "mciGetYieldProc");
            winmm.mciLoadCommandResource = GetProcAddress(dll.handle, "mciLoadCommandResource");
            winmm.mciSendCommandA = GetProcAddress(dll.handle, "mciSendCommandA");
            winmm.mciSendCommandW = GetProcAddress(dll.handle, "mciSendCommandW");
            winmm.mciSendStringA = GetProcAddress(dll.handle, "mciSendStringA");
            winmm.mciSendStringW = GetProcAddress(dll.handle, "mciSendStringW");
            winmm.mciSetDriverData = GetProcAddress(dll.handle, "mciSetDriverData");
            winmm.mciSetYieldProc = GetProcAddress(dll.handle, "mciSetYieldProc");
            winmm.mid32Message = GetProcAddress(dll.handle, "mid32Message");
            winmm.midiConnect = GetProcAddress(dll.handle, "midiConnect");
            winmm.midiDisconnect = GetProcAddress(dll.handle, "midiDisconnect");
            winmm.midiInAddBuffer = GetProcAddress(dll.handle, "midiInAddBuffer");
            winmm.midiInClose = GetProcAddress(dll.handle, "midiInClose");
            winmm.midiInGetDevCapsA = GetProcAddress(dll.handle, "midiInGetDevCapsA");
            winmm.midiInGetDevCapsW = GetProcAddress(dll.handle, "midiInGetDevCapsW");
            winmm.midiInGetErrorTextA = GetProcAddress(dll.handle, "midiInGetErrorTextA");
            winmm.midiInGetErrorTextW = GetProcAddress(dll.handle, "midiInGetErrorTextW");
            winmm.midiInGetID = GetProcAddress(dll.handle, "midiInGetID");
            winmm.midiInGetNumDevs = GetProcAddress(dll.handle, "midiInGetNumDevs");
            winmm.midiInMessage = GetProcAddress(dll.handle, "midiInMessage");
            winmm.midiInOpen = GetProcAddress(dll.handle, "midiInOpen");
            winmm.midiInPrepareHeader = GetProcAddress(dll.handle, "midiInPrepareHeader");
            winmm.midiInReset = GetProcAddress(dll.handle, "midiInReset");
            winmm.midiInStart = GetProcAddress(dll.handle, "midiInStart");
            winmm.midiInStop = GetProcAddress(dll.handle, "midiInStop");
            winmm.midiInUnprepareHeader = GetProcAddress(dll.handle, "midiInUnprepareHeader");
            winmm.midiOutCacheDrumPatches = GetProcAddress(dll.handle, "midiOutCacheDrumPatches");
            winmm.midiOutCachePatches = GetProcAddress(dll.handle, "midiOutCachePatches");
            winmm.midiOutClose = GetProcAddress(dll.handle, "midiOutClose");
            winmm.midiOutGetDevCapsA = GetProcAddress(dll.handle, "midiOutGetDevCapsA");
            winmm.midiOutGetDevCapsW = GetProcAddress(dll.handle, "midiOutGetDevCapsW");
            winmm.midiOutGetErrorTextA = GetProcAddress(dll.handle, "midiOutGetErrorTextA");
            winmm.midiOutGetErrorTextW = GetProcAddress(dll.handle, "midiOutGetErrorTextW");
            winmm.midiOutGetID = GetProcAddress(dll.handle, "midiOutGetID");
            winmm.midiOutGetNumDevs = GetProcAddress(dll.handle, "midiOutGetNumDevs");
            winmm.midiOutGetVolume = GetProcAddress(dll.handle, "midiOutGetVolume");
            winmm.midiOutLongMsg = GetProcAddress(dll.handle, "midiOutLongMsg");
            winmm.midiOutMessage = GetProcAddress(dll.handle, "midiOutMessage");
            winmm.midiOutOpen = GetProcAddress(dll.handle, "midiOutOpen");
            winmm.midiOutPrepareHeader = GetProcAddress(dll.handle, "midiOutPrepareHeader");
            winmm.midiOutReset = GetProcAddress(dll.handle, "midiOutReset");
            winmm.midiOutSetVolume = GetProcAddress(dll.handle, "midiOutSetVolume");
            winmm.midiOutShortMsg = GetProcAddress(dll.handle, "midiOutShortMsg");
            winmm.midiOutUnprepareHeader = GetProcAddress(dll.handle, "midiOutUnprepareHeader");
            winmm.midiStreamClose = GetProcAddress(dll.handle, "midiStreamClose");
            winmm.midiStreamOpen = GetProcAddress(dll.handle, "midiStreamOpen");
            winmm.midiStreamOut = GetProcAddress(dll.handle, "midiStreamOut");
            winmm.midiStreamPause = GetProcAddress(dll.handle, "midiStreamPause");
            winmm.midiStreamPosition = GetProcAddress(dll.handle, "midiStreamPosition");
            winmm.midiStreamProperty = GetProcAddress(dll.handle, "midiStreamProperty");
            winmm.midiStreamRestart = GetProcAddress(dll.handle, "midiStreamRestart");
            winmm.midiStreamStop = GetProcAddress(dll.handle, "midiStreamStop");
            winmm.mixerClose = GetProcAddress(dll.handle, "mixerClose");
            winmm.mixerGetControlDetailsA = GetProcAddress(dll.handle, "mixerGetControlDetailsA");
            winmm.mixerGetControlDetailsW = GetProcAddress(dll.handle, "mixerGetControlDetailsW");
            winmm.mixerGetDevCapsA = GetProcAddress(dll.handle, "mixerGetDevCapsA");
            winmm.mixerGetDevCapsW = GetProcAddress(dll.handle, "mixerGetDevCapsW");
            winmm.mixerGetID = GetProcAddress(dll.handle, "mixerGetID");
            winmm.mixerGetLineControlsA = GetProcAddress(dll.handle, "mixerGetLineControlsA");
            winmm.mixerGetLineControlsW = GetProcAddress(dll.handle, "mixerGetLineControlsW");
            winmm.mixerGetLineInfoA = GetProcAddress(dll.handle, "mixerGetLineInfoA");
            winmm.mixerGetLineInfoW = GetProcAddress(dll.handle, "mixerGetLineInfoW");
            winmm.mixerGetNumDevs = GetProcAddress(dll.handle, "mixerGetNumDevs");
            winmm.mixerMessage = GetProcAddress(dll.handle, "mixerMessage");
            winmm.mixerOpen = GetProcAddress(dll.handle, "mixerOpen");
            winmm.mixerSetControlDetails = GetProcAddress(dll.handle, "mixerSetControlDetails");
            winmm.mmDrvInstall = GetProcAddress(dll.handle, "mmDrvInstall");
            winmm.mmGetCurrentTask = GetProcAddress(dll.handle, "mmGetCurrentTask");
            winmm.mmTaskBlock = GetProcAddress(dll.handle, "mmTaskBlock");
            winmm.mmTaskCreate = GetProcAddress(dll.handle, "mmTaskCreate");
            winmm.mmTaskSignal = GetProcAddress(dll.handle, "mmTaskSignal");
            winmm.mmTaskYield = GetProcAddress(dll.handle, "mmTaskYield");
            winmm.mmioAdvance = GetProcAddress(dll.handle, "mmioAdvance");
            winmm.mmioAscend = GetProcAddress(dll.handle, "mmioAscend");
            winmm.mmioClose = GetProcAddress(dll.handle, "mmioClose");
            winmm.mmioCreateChunk = GetProcAddress(dll.handle, "mmioCreateChunk");
            winmm.mmioDescend = GetProcAddress(dll.handle, "mmioDescend");
            winmm.mmioFlush = GetProcAddress(dll.handle, "mmioFlush");
            winmm.mmioGetInfo = GetProcAddress(dll.handle, "mmioGetInfo");
            winmm.mmioInstallIOProcA = GetProcAddress(dll.handle, "mmioInstallIOProcA");
            winmm.mmioInstallIOProcW = GetProcAddress(dll.handle, "mmioInstallIOProcW");
            winmm.mmioOpenA = GetProcAddress(dll.handle, "mmioOpenA");
            winmm.mmioOpenW = GetProcAddress(dll.handle, "mmioOpenW");
            winmm.mmioRead = GetProcAddress(dll.handle, "mmioRead");
            winmm.mmioRenameA = GetProcAddress(dll.handle, "mmioRenameA");
            winmm.mmioRenameW = GetProcAddress(dll.handle, "mmioRenameW");
            winmm.mmioSeek = GetProcAddress(dll.handle, "mmioSeek");
            winmm.mmioSendMessage = GetProcAddress(dll.handle, "mmioSendMessage");
            winmm.mmioSetBuffer = GetProcAddress(dll.handle, "mmioSetBuffer");
            winmm.mmioSetInfo = GetProcAddress(dll.handle, "mmioSetInfo");
            winmm.mmioStringToFOURCCA = GetProcAddress(dll.handle, "mmioStringToFOURCCA");
            winmm.mmioStringToFOURCCW = GetProcAddress(dll.handle, "mmioStringToFOURCCW");
            winmm.mmioWrite = GetProcAddress(dll.handle, "mmioWrite");
            winmm.mmsystemGetVersion = GetProcAddress(dll.handle, "mmsystemGetVersion");
            winmm.mod32Message = GetProcAddress(dll.handle, "mod32Message");
            winmm.mxd32Message = GetProcAddress(dll.handle, "mxd32Message");
            winmm.sndPlaySoundA = GetProcAddress(dll.handle, "sndPlaySoundA");
            winmm.sndPlaySoundW = GetProcAddress(dll.handle, "sndPlaySoundW");
            winmm.tid32Message = GetProcAddress(dll.handle, "tid32Message");
            winmm.timeBeginPeriod = GetProcAddress(dll.handle, "timeBeginPeriod");
            winmm.timeEndPeriod = GetProcAddress(dll.handle, "timeEndPeriod");
            winmm.timeGetDevCaps = GetProcAddress(dll.handle, "timeGetDevCaps");
            winmm.timeGetSystemTime = GetProcAddress(dll.handle, "timeGetSystemTime");
            winmm.timeGetTime = GetProcAddress(dll.handle, "timeGetTime");
            winmm.timeKillEvent = GetProcAddress(dll.handle, "timeKillEvent");
            winmm.timeSetEvent = GetProcAddress(dll.handle, "timeSetEvent");
            winmm.waveInAddBuffer = GetProcAddress(dll.handle, "waveInAddBuffer");
            winmm.waveInClose = GetProcAddress(dll.handle, "waveInClose");
            winmm.waveInGetDevCapsA = GetProcAddress(dll.handle, "waveInGetDevCapsA");
            winmm.waveInGetDevCapsW = GetProcAddress(dll.handle, "waveInGetDevCapsW");
            winmm.waveInGetErrorTextA = GetProcAddress(dll.handle, "waveInGetErrorTextA");
            winmm.waveInGetErrorTextW = GetProcAddress(dll.handle, "waveInGetErrorTextW");
            winmm.waveInGetID = GetProcAddress(dll.handle, "waveInGetID");
            winmm.waveInGetNumDevs = GetProcAddress(dll.handle, "waveInGetNumDevs");
            winmm.waveInGetPosition = GetProcAddress(dll.handle, "waveInGetPosition");
            winmm.waveInMessage = GetProcAddress(dll.handle, "waveInMessage");
            winmm.waveInOpen = GetProcAddress(dll.handle, "waveInOpen");
            winmm.waveInPrepareHeader = GetProcAddress(dll.handle, "waveInPrepareHeader");
            winmm.waveInReset = GetProcAddress(dll.handle, "waveInReset");
            winmm.waveInStart = GetProcAddress(dll.handle, "waveInStart");
            winmm.waveInStop = GetProcAddress(dll.handle, "waveInStop");
            winmm.waveInUnprepareHeader = GetProcAddress(dll.handle, "waveInUnprepareHeader");
            winmm.waveOutBreakLoop = GetProcAddress(dll.handle, "waveOutBreakLoop");
            winmm.waveOutClose = GetProcAddress(dll.handle, "waveOutClose");
            winmm.waveOutGetDevCapsA = GetProcAddress(dll.handle, "waveOutGetDevCapsA");
            winmm.waveOutGetDevCapsW = GetProcAddress(dll.handle, "waveOutGetDevCapsW");
            winmm.waveOutGetErrorTextA = GetProcAddress(dll.handle, "waveOutGetErrorTextA");
            winmm.waveOutGetErrorTextW = GetProcAddress(dll.handle, "waveOutGetErrorTextW");
            winmm.waveOutGetID = GetProcAddress(dll.handle, "waveOutGetID");
            winmm.waveOutGetNumDevs = GetProcAddress(dll.handle, "waveOutGetNumDevs");
            winmm.waveOutGetPitch = GetProcAddress(dll.handle, "waveOutGetPitch");
            winmm.waveOutGetPlaybackRate = GetProcAddress(dll.handle, "waveOutGetPlaybackRate");
            winmm.waveOutGetPosition = GetProcAddress(dll.handle, "waveOutGetPosition");
            winmm.waveOutGetVolume = GetProcAddress(dll.handle, "waveOutGetVolume");
            winmm.waveOutMessage = GetProcAddress(dll.handle, "waveOutMessage");
            winmm.waveOutOpen = GetProcAddress(dll.handle, "waveOutOpen");
            winmm.waveOutPause = GetProcAddress(dll.handle, "waveOutPause");
            winmm.waveOutPrepareHeader = GetProcAddress(dll.handle, "waveOutPrepareHeader");
            winmm.waveOutReset = GetProcAddress(dll.handle, "waveOutReset");
            winmm.waveOutRestart = GetProcAddress(dll.handle, "waveOutRestart");
            winmm.waveOutSetPitch = GetProcAddress(dll.handle, "waveOutSetPitch");
            winmm.waveOutSetPlaybackRate = GetProcAddress(dll.handle, "waveOutSetPlaybackRate");
            winmm.waveOutSetVolume = GetProcAddress(dll.handle, "waveOutSetVolume");
            winmm.waveOutUnprepareHeader = GetProcAddress(dll.handle, "waveOutUnprepareHeader");
            winmm.waveOutWrite = GetProcAddress(dll.handle, "waveOutWrite");
            winmm.wid32Message = GetProcAddress(dll.handle, "wid32Message");
            winmm.wod32Message = GetProcAddress(dll.handle, "wod32Message");
        }
        else if (moduleName == L"version.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            version.GetFileVersionInfoA = GetProcAddress(dll.handle, "GetFileVersionInfoA");
            version.GetFileVersionInfoByHandle = GetProcAddress(dll.handle, "GetFileVersionInfoByHandle");
            version.GetFileVersionInfoExA = GetProcAddress(dll.handle, "GetFileVersionInfoExA");
            version.GetFileVersionInfoExW = GetProcAddress(dll.handle, "GetFileVersionInfoExW");
            version.GetFileVersionInfoSizeA = GetProcAddress(dll.handle, "GetFileVersionInfoSizeA");
            version.GetFileVersionInfoSizeExA = GetProcAddress(dll.handle, "GetFileVersionInfoSizeExA");
            version.GetFileVersionInfoSizeExW = GetProcAddress(dll.handle, "GetFileVersionInfoSizeExW");
            version.GetFileVersionInfoSizeW = GetProcAddress(dll.handle, "GetFileVersionInfoSizeW");
            version.GetFileVersionInfoW = GetProcAddress(dll.handle, "GetFileVersionInfoW");
            version.VerFindFileA = GetProcAddress(dll.handle, "VerFindFileA");
            version.VerFindFileW = GetProcAddress(dll.handle, "VerFindFileW");
            version.VerInstallFileA = GetProcAddress(dll.handle, "VerInstallFileA");
            version.VerInstallFileW = GetProcAddress(dll.handle, "VerInstallFileW");
            version.VerLanguageNameA = GetProcAddress(dll.handle, "VerLanguageNameA");
            version.VerLanguageNameW = GetProcAddress(dll.handle, "VerLanguageNameW");
            version.VerQueryValueA = GetProcAddress(dll.handle, "VerQueryValueA");
            version.VerQueryValueW = GetProcAddress(dll.handle, "VerQueryValueW");
        }
        else if (moduleName == L"dbghelp.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            dbghelp.DbgHelpCreateUserDump = GetProcAddress(dll.handle, "DbgHelpCreateUserDump");
            dbghelp.DbgHelpCreateUserDumpW = GetProcAddress(dll.handle, "DbgHelpCreateUserDumpW");
            dbghelp.EnumDirTree = GetProcAddress(dll.handle, "EnumDirTree");
            dbghelp.EnumDirTreeW = GetProcAddress(dll.handle, "EnumDirTreeW");
            dbghelp.EnumerateLoadedModules = GetProcAddress(dll.handle, "EnumerateLoadedModules");
            dbghelp.EnumerateLoadedModules64 = GetProcAddress(dll.handle, "EnumerateLoadedModules64");
            dbghelp.EnumerateLoadedModulesEx = GetProcAddress(dll.handle, "EnumerateLoadedModulesEx");
            dbghelp.EnumerateLoadedModulesExW = GetProcAddress(dll.handle, "EnumerateLoadedModulesExW");
            dbghelp.EnumerateLoadedModulesW64 = GetProcAddress(dll.handle, "EnumerateLoadedModulesW64");
            dbghelp.ExtensionApiVersion = GetProcAddress(dll.handle, "ExtensionApiVersion");
            dbghelp.FindDebugInfoFile = GetProcAddress(dll.handle, "FindDebugInfoFile");
            dbghelp.FindDebugInfoFileEx = GetProcAddress(dll.handle, "FindDebugInfoFileEx");
            dbghelp.FindDebugInfoFileExW = GetProcAddress(dll.handle, "FindDebugInfoFileExW");
            dbghelp.FindExecutableImage = GetProcAddress(dll.handle, "FindExecutableImage");
            dbghelp.FindExecutableImageEx = GetProcAddress(dll.handle, "FindExecutableImageEx");
            dbghelp.FindExecutableImageExW = GetProcAddress(dll.handle, "FindExecutableImageExW");
            dbghelp.FindFileInPath = GetProcAddress(dll.handle, "FindFileInPath");
            dbghelp.FindFileInSearchPath = GetProcAddress(dll.handle, "FindFileInSearchPath");
            dbghelp.GetTimestampForLoadedLibrary = GetProcAddress(dll.handle, "GetTimestampForLoadedLibrary");
            dbghelp.ImageDirectoryEntryToData = GetProcAddress(dll.handle, "ImageDirectoryEntryToData");
            dbghelp.ImageDirectoryEntryToDataEx = GetProcAddress(dll.handle, "ImageDirectoryEntryToDataEx");
            dbghelp.ImageNtHeader = GetProcAddress(dll.handle, "ImageNtHeader");
            dbghelp.ImageRvaToSection = GetProcAddress(dll.handle, "ImageRvaToSection");
            dbghelp.ImageRvaToVa = GetProcAddress(dll.handle, "ImageRvaToVa");
            dbghelp.ImagehlpApiVersion = GetProcAddress(dll.handle, "ImagehlpApiVersion");
            dbghelp.ImagehlpApiVersionEx = GetProcAddress(dll.handle, "ImagehlpApiVersionEx");
            dbghelp.MakeSureDirectoryPathExists = GetProcAddress(dll.handle, "MakeSureDirectoryPathExists");
            dbghelp.MiniDumpReadDumpStream = GetProcAddress(dll.handle, "MiniDumpReadDumpStream");
            dbghelp.MiniDumpWriteDump = GetProcAddress(dll.handle, "MiniDumpWriteDump");
            dbghelp.SearchTreeForFile = GetProcAddress(dll.handle, "SearchTreeForFile");
            dbghelp.SearchTreeForFileW = GetProcAddress(dll.handle, "SearchTreeForFileW");
            dbghelp.StackWalk = GetProcAddress(dll.handle, "StackWalk");
            dbghelp.StackWalk64 = GetProcAddress(dll.handle, "StackWalk64");
            dbghelp.SymAddSourceStream = GetProcAddress(dll.handle, "SymAddSourceStream");
            dbghelp.SymAddSourceStreamA = GetProcAddress(dll.handle, "SymAddSourceStreamA");
            dbghelp.SymAddSourceStreamW = GetProcAddress(dll.handle, "SymAddSourceStreamW");
            dbghelp.SymAddSymbol = GetProcAddress(dll.handle, "SymAddSymbol");
            dbghelp.SymAddSymbolW = GetProcAddress(dll.handle, "SymAddSymbolW");
            dbghelp.SymCleanup = GetProcAddress(dll.handle, "SymCleanup");
            dbghelp.SymDeleteSymbol = GetProcAddress(dll.handle, "SymDeleteSymbol");
            dbghelp.SymDeleteSymbolW = GetProcAddress(dll.handle, "SymDeleteSymbolW");
            dbghelp.SymEnumLines = GetProcAddress(dll.handle, "SymEnumLines");
            dbghelp.SymEnumLinesW = GetProcAddress(dll.handle, "SymEnumLinesW");
            dbghelp.SymEnumProcesses = GetProcAddress(dll.handle, "SymEnumProcesses");
            dbghelp.SymEnumSourceFileTokens = GetProcAddress(dll.handle, "SymEnumSourceFileTokens");
            dbghelp.SymEnumSourceFiles = GetProcAddress(dll.handle, "SymEnumSourceFiles");
            dbghelp.SymEnumSourceFilesW = GetProcAddress(dll.handle, "SymEnumSourceFilesW");
            dbghelp.SymEnumSourceLines = GetProcAddress(dll.handle, "SymEnumSourceLines");
            dbghelp.SymEnumSourceLinesW = GetProcAddress(dll.handle, "SymEnumSourceLinesW");
            dbghelp.SymEnumSym = GetProcAddress(dll.handle, "SymEnumSym");
            dbghelp.SymEnumSymbols = GetProcAddress(dll.handle, "SymEnumSymbols");
            dbghelp.SymEnumSymbolsForAddr = GetProcAddress(dll.handle, "SymEnumSymbolsForAddr");
            dbghelp.SymEnumSymbolsForAddrW = GetProcAddress(dll.handle, "SymEnumSymbolsForAddrW");
            dbghelp.SymEnumSymbolsW = GetProcAddress(dll.handle, "SymEnumSymbolsW");
            dbghelp.SymEnumTypes = GetProcAddress(dll.handle, "SymEnumTypes");
            dbghelp.SymEnumTypesByName = GetProcAddress(dll.handle, "SymEnumTypesByName");
            dbghelp.SymEnumTypesByNameW = GetProcAddress(dll.handle, "SymEnumTypesByNameW");
            dbghelp.SymEnumTypesW = GetProcAddress(dll.handle, "SymEnumTypesW");
            dbghelp.SymEnumerateModules = GetProcAddress(dll.handle, "SymEnumerateModules");
            dbghelp.SymEnumerateModules64 = GetProcAddress(dll.handle, "SymEnumerateModules64");
            dbghelp.SymEnumerateModulesW64 = GetProcAddress(dll.handle, "SymEnumerateModulesW64");
            dbghelp.SymEnumerateSymbols = GetProcAddress(dll.handle, "SymEnumerateSymbols");
            dbghelp.SymEnumerateSymbols64 = GetProcAddress(dll.handle, "SymEnumerateSymbols64");
            dbghelp.SymEnumerateSymbolsW = GetProcAddress(dll.handle, "SymEnumerateSymbolsW");
            dbghelp.SymEnumerateSymbolsW64 = GetProcAddress(dll.handle, "SymEnumerateSymbolsW64");
            dbghelp.SymFindDebugInfoFile = GetProcAddress(dll.handle, "SymFindDebugInfoFile");
            dbghelp.SymFindDebugInfoFileW = GetProcAddress(dll.handle, "SymFindDebugInfoFileW");
            dbghelp.SymFindExecutableImage = GetProcAddress(dll.handle, "SymFindExecutableImage");
            dbghelp.SymFindExecutableImageW = GetProcAddress(dll.handle, "SymFindExecutableImageW");
            dbghelp.SymFindFileInPath = GetProcAddress(dll.handle, "SymFindFileInPath");
            dbghelp.SymFindFileInPathW = GetProcAddress(dll.handle, "SymFindFileInPathW");
            dbghelp.SymFromAddr = GetProcAddress(dll.handle, "SymFromAddr");
            dbghelp.SymFromAddrW = GetProcAddress(dll.handle, "SymFromAddrW");
            dbghelp.SymFromIndex = GetProcAddress(dll.handle, "SymFromIndex");
            dbghelp.SymFromIndexW = GetProcAddress(dll.handle, "SymFromIndexW");
            dbghelp.SymFromName = GetProcAddress(dll.handle, "SymFromName");
            dbghelp.SymFromNameW = GetProcAddress(dll.handle, "SymFromNameW");
            dbghelp.SymFromToken = GetProcAddress(dll.handle, "SymFromToken");
            dbghelp.SymFromTokenW = GetProcAddress(dll.handle, "SymFromTokenW");
            dbghelp.SymFunctionTableAccess = GetProcAddress(dll.handle, "SymFunctionTableAccess");
            dbghelp.SymFunctionTableAccess64 = GetProcAddress(dll.handle, "SymFunctionTableAccess64");
            dbghelp.SymGetFileLineOffsets64 = GetProcAddress(dll.handle, "SymGetFileLineOffsets64");
            dbghelp.SymGetHomeDirectory = GetProcAddress(dll.handle, "SymGetHomeDirectory");
            dbghelp.SymGetHomeDirectoryW = GetProcAddress(dll.handle, "SymGetHomeDirectoryW");
            dbghelp.SymGetLineFromAddr = GetProcAddress(dll.handle, "SymGetLineFromAddr");
            dbghelp.SymGetLineFromAddr64 = GetProcAddress(dll.handle, "SymGetLineFromAddr64");
            dbghelp.SymGetLineFromAddrW64 = GetProcAddress(dll.handle, "SymGetLineFromAddrW64");
            dbghelp.SymGetLineFromName = GetProcAddress(dll.handle, "SymGetLineFromName");
            dbghelp.SymGetLineFromName64 = GetProcAddress(dll.handle, "SymGetLineFromName64");
            dbghelp.SymGetLineFromNameW64 = GetProcAddress(dll.handle, "SymGetLineFromNameW64");
            dbghelp.SymGetLineNext = GetProcAddress(dll.handle, "SymGetLineNext");
            dbghelp.SymGetLineNext64 = GetProcAddress(dll.handle, "SymGetLineNext64");
            dbghelp.SymGetLineNextW64 = GetProcAddress(dll.handle, "SymGetLineNextW64");
            dbghelp.SymGetLinePrev = GetProcAddress(dll.handle, "SymGetLinePrev");
            dbghelp.SymGetLinePrev64 = GetProcAddress(dll.handle, "SymGetLinePrev64");
            dbghelp.SymGetLinePrevW64 = GetProcAddress(dll.handle, "SymGetLinePrevW64");
            dbghelp.SymGetModuleBase = GetProcAddress(dll.handle, "SymGetModuleBase");
            dbghelp.SymGetModuleBase64 = GetProcAddress(dll.handle, "SymGetModuleBase64");
            dbghelp.SymGetModuleInfo = GetProcAddress(dll.handle, "SymGetModuleInfo");
            dbghelp.SymGetModuleInfo64 = GetProcAddress(dll.handle, "SymGetModuleInfo64");
            dbghelp.SymGetModuleInfoW = GetProcAddress(dll.handle, "SymGetModuleInfoW");
            dbghelp.SymGetModuleInfoW64 = GetProcAddress(dll.handle, "SymGetModuleInfoW64");
            dbghelp.SymGetOmapBlockBase = GetProcAddress(dll.handle, "SymGetOmapBlockBase");
            dbghelp.SymGetOmaps = GetProcAddress(dll.handle, "SymGetOmaps");
            dbghelp.SymGetOptions = GetProcAddress(dll.handle, "SymGetOptions");
            dbghelp.SymGetScope = GetProcAddress(dll.handle, "SymGetScope");
            dbghelp.SymGetScopeW = GetProcAddress(dll.handle, "SymGetScopeW");
            dbghelp.SymGetSearchPath = GetProcAddress(dll.handle, "SymGetSearchPath");
            dbghelp.SymGetSearchPathW = GetProcAddress(dll.handle, "SymGetSearchPathW");
            dbghelp.SymGetSourceFile = GetProcAddress(dll.handle, "SymGetSourceFile");
            dbghelp.SymGetSourceFileFromToken = GetProcAddress(dll.handle, "SymGetSourceFileFromToken");
            dbghelp.SymGetSourceFileFromTokenW = GetProcAddress(dll.handle, "SymGetSourceFileFromTokenW");
            dbghelp.SymGetSourceFileToken = GetProcAddress(dll.handle, "SymGetSourceFileToken");
            dbghelp.SymGetSourceFileTokenW = GetProcAddress(dll.handle, "SymGetSourceFileTokenW");
            dbghelp.SymGetSourceFileW = GetProcAddress(dll.handle, "SymGetSourceFileW");
            dbghelp.SymGetSourceVarFromToken = GetProcAddress(dll.handle, "SymGetSourceVarFromToken");
            dbghelp.SymGetSourceVarFromTokenW = GetProcAddress(dll.handle, "SymGetSourceVarFromTokenW");
            dbghelp.SymGetSymFromAddr = GetProcAddress(dll.handle, "SymGetSymFromAddr");
            dbghelp.SymGetSymFromAddr64 = GetProcAddress(dll.handle, "SymGetSymFromAddr64");
            dbghelp.SymGetSymFromName = GetProcAddress(dll.handle, "SymGetSymFromName");
            dbghelp.SymGetSymFromName64 = GetProcAddress(dll.handle, "SymGetSymFromName64");
            dbghelp.SymGetSymNext = GetProcAddress(dll.handle, "SymGetSymNext");
            dbghelp.SymGetSymNext64 = GetProcAddress(dll.handle, "SymGetSymNext64");
            dbghelp.SymGetSymPrev = GetProcAddress(dll.handle, "SymGetSymPrev");
            dbghelp.SymGetSymPrev64 = GetProcAddress(dll.handle, "SymGetSymPrev64");
            dbghelp.SymGetSymbolFile = GetProcAddress(dll.handle, "SymGetSymbolFile");
            dbghelp.SymGetSymbolFileW = GetProcAddress(dll.handle, "SymGetSymbolFileW");
            dbghelp.SymGetTypeFromName = GetProcAddress(dll.handle, "SymGetTypeFromName");
            dbghelp.SymGetTypeFromNameW = GetProcAddress(dll.handle, "SymGetTypeFromNameW");
            dbghelp.SymGetTypeInfo = GetProcAddress(dll.handle, "SymGetTypeInfo");
            dbghelp.SymGetTypeInfoEx = GetProcAddress(dll.handle, "SymGetTypeInfoEx");
            dbghelp.SymGetUnwindInfo = GetProcAddress(dll.handle, "SymGetUnwindInfo");
            dbghelp.SymInitialize = GetProcAddress(dll.handle, "SymInitialize");
            dbghelp.SymInitializeW = GetProcAddress(dll.handle, "SymInitializeW");
            dbghelp.SymLoadModule = GetProcAddress(dll.handle, "SymLoadModule");
            dbghelp.SymLoadModule64 = GetProcAddress(dll.handle, "SymLoadModule64");
            dbghelp.SymLoadModuleEx = GetProcAddress(dll.handle, "SymLoadModuleEx");
            dbghelp.SymLoadModuleExW = GetProcAddress(dll.handle, "SymLoadModuleExW");
            dbghelp.SymMatchFileName = GetProcAddress(dll.handle, "SymMatchFileName");
            dbghelp.SymMatchFileNameW = GetProcAddress(dll.handle, "SymMatchFileNameW");
            dbghelp.SymMatchString = GetProcAddress(dll.handle, "SymMatchString");
            dbghelp.SymMatchStringA = GetProcAddress(dll.handle, "SymMatchStringA");
            dbghelp.SymMatchStringW = GetProcAddress(dll.handle, "SymMatchStringW");
            dbghelp.SymNext = GetProcAddress(dll.handle, "SymNext");
            dbghelp.SymNextW = GetProcAddress(dll.handle, "SymNextW");
            dbghelp.SymPrev = GetProcAddress(dll.handle, "SymPrev");
            dbghelp.SymPrevW = GetProcAddress(dll.handle, "SymPrevW");
            dbghelp.SymRefreshModuleList = GetProcAddress(dll.handle, "SymRefreshModuleList");
            dbghelp.SymRegisterCallback = GetProcAddress(dll.handle, "SymRegisterCallback");
            dbghelp.SymRegisterCallback64 = GetProcAddress(dll.handle, "SymRegisterCallback64");
            dbghelp.SymRegisterCallbackW64 = GetProcAddress(dll.handle, "SymRegisterCallbackW64");
            dbghelp.SymRegisterFunctionEntryCallback = GetProcAddress(dll.handle, "SymRegisterFunctionEntryCallback");
            dbghelp.SymRegisterFunctionEntryCallback64 = GetProcAddress(dll.handle, "SymRegisterFunctionEntryCallback64");
            dbghelp.SymSearch = GetProcAddress(dll.handle, "SymSearch");
            dbghelp.SymSearchW = GetProcAddress(dll.handle, "SymSearchW");
            dbghelp.SymSetContext = GetProcAddress(dll.handle, "SymSetContext");
            dbghelp.SymSetHomeDirectory = GetProcAddress(dll.handle, "SymSetHomeDirectory");
            dbghelp.SymSetHomeDirectoryW = GetProcAddress(dll.handle, "SymSetHomeDirectoryW");
            dbghelp.SymSetOptions = GetProcAddress(dll.handle, "SymSetOptions");
            dbghelp.SymSetParentWindow = GetProcAddress(dll.handle, "SymSetParentWindow");
            dbghelp.SymSetScopeFromAddr = GetProcAddress(dll.handle, "SymSetScopeFromAddr");
            dbghelp.SymSetScopeFromIndex = GetProcAddress(dll.handle, "SymSetScopeFromIndex");
            dbghelp.SymSetSearchPath = GetProcAddress(dll.handle, "SymSetSearchPath");
            dbghelp.SymSetSearchPathW = GetProcAddress(dll.handle, "SymSetSearchPathW");
            dbghelp.SymSrvDeltaName = GetProcAddress(dll.handle, "SymSrvDeltaName");
            dbghelp.SymSrvDeltaNameW = GetProcAddress(dll.handle, "SymSrvDeltaNameW");
            dbghelp.SymSrvGetFileIndexInfo = GetProcAddress(dll.handle, "SymSrvGetFileIndexInfo");
            dbghelp.SymSrvGetFileIndexInfoW = GetProcAddress(dll.handle, "SymSrvGetFileIndexInfoW");
            dbghelp.SymSrvGetFileIndexString = GetProcAddress(dll.handle, "SymSrvGetFileIndexString");
            dbghelp.SymSrvGetFileIndexStringW = GetProcAddress(dll.handle, "SymSrvGetFileIndexStringW");
            dbghelp.SymSrvGetFileIndexes = GetProcAddress(dll.handle, "SymSrvGetFileIndexes");
            dbghelp.SymSrvGetFileIndexesW = GetProcAddress(dll.handle, "SymSrvGetFileIndexesW");
            dbghelp.SymSrvGetSupplement = GetProcAddress(dll.handle, "SymSrvGetSupplement");
            dbghelp.SymSrvGetSupplementW = GetProcAddress(dll.handle, "SymSrvGetSupplementW");
            dbghelp.SymSrvIsStore = GetProcAddress(dll.handle, "SymSrvIsStore");
            dbghelp.SymSrvIsStoreW = GetProcAddress(dll.handle, "SymSrvIsStoreW");
            dbghelp.SymSrvStoreFile = GetProcAddress(dll.handle, "SymSrvStoreFile");
            dbghelp.SymSrvStoreFileW = GetProcAddress(dll.handle, "SymSrvStoreFileW");
            dbghelp.SymSrvStoreSupplement = GetProcAddress(dll.handle, "SymSrvStoreSupplement");
            dbghelp.SymSrvStoreSupplementW = GetProcAddress(dll.handle, "SymSrvStoreSupplementW");
            dbghelp.SymUnDName = GetProcAddress(dll.handle, "SymUnDName");
            dbghelp.SymUnDName64 = GetProcAddress(dll.handle, "SymUnDName64");
            dbghelp.SymUnloadModule = GetProcAddress(dll.handle, "SymUnloadModule");
            dbghelp.SymUnloadModule64 = GetProcAddress(dll.handle, "SymUnloadModule64");
            dbghelp.UnDecorateSymbolName = GetProcAddress(dll.handle, "UnDecorateSymbolName");
            dbghelp.UnDecorateSymbolNameW = GetProcAddress(dll.handle, "UnDecorateSymbolNameW");
            dbghelp.WinDbgExtensionDllInit = GetProcAddress(dll.handle, "WinDbgExtensionDllInit");
            dbghelp.block = GetProcAddress(dll.handle, "block");
            dbghelp.chksym = GetProcAddress(dll.handle, "chksym");
            dbghelp.dbghelp = GetProcAddress(dll.handle, "dbghelp");
            dbghelp.dh = GetProcAddress(dll.handle, "dh");
            dbghelp.fptr = GetProcAddress(dll.handle, "fptr");
            dbghelp.homedir = GetProcAddress(dll.handle, "homedir");
            dbghelp.itoldyouso = GetProcAddress(dll.handle, "itoldyouso");
            dbghelp.lmi = GetProcAddress(dll.handle, "lmi");
            dbghelp.lminfo = GetProcAddress(dll.handle, "lminfo");
            dbghelp.omap = GetProcAddress(dll.handle, "omap");
            dbghelp.srcfiles = GetProcAddress(dll.handle, "srcfiles");
            dbghelp.stack_force_ebp = GetProcAddress(dll.handle, "stack_force_ebp");
            dbghelp.stackdbg = GetProcAddress(dll.handle, "stackdbg");
            dbghelp.sym = GetProcAddress(dll.handle, "sym");
            dbghelp.symsrv = GetProcAddress(dll.handle, "symsrv");
            dbghelp.vc7fpo = GetProcAddress(dll.handle, "vc7fpo");
        }
        else if (moduleName == L"dinput8.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            dinput8.DirectInput8Create = GetProcAddress(dll.handle, "DirectInput8Create");
            shared.DllCanUnloadNow = GetProcAddress(dll.handle, "DllCanUnloadNow");
            shared.DllGetClassObject = GetProcAddress(dll.handle, "DllGetClassObject");
            dinput8.DllRegisterServer = GetProcAddress(dll.handle, "DllRegisterServer");
            dinput8.DllUnregisterServer = GetProcAddress(dll.handle, "DllUnregisterServer");
            dinput8.GetdfDIJoystick = GetProcAddress(dll.handle, "GetdfDIJoystick");
        }
        else if (moduleName == L"xinput1_3.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            xinput1_3.DllMain = GetProcAddress(dll.handle, "DllMain");
            xinput1_3.XInputEnable = GetProcAddress(dll.handle, "XInputEnable");
            xinput1_3.XInputGetBatteryInformation = GetProcAddress(dll.handle, "XInputGetBatteryInformation");
            xinput1_3.XInputGetCapabilities = GetProcAddress(dll.handle, "XInputGetCapabilities");
            xinput1_3.XInputGetDSoundAudioDeviceGuids = GetProcAddress(dll.handle, "XInputGetDSoundAudioDeviceGuids");
            xinput1_3.XInputGetKeystroke = GetProcAddress(dll.handle, "XInputGetKeystroke");
            xinput1_3.XInputGetState = GetProcAddress(dll.handle, "XInputGetState");
            xinput1_3.XInputSetState = GetProcAddress(dll.handle, "XInputSetState");
        }
        else if (moduleName == L"dsound.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            dsound.DirectSoundCaptureCreate = GetProcAddress(dll.handle, "DirectSoundCaptureCreate");
            dsound.DirectSoundCaptureCreate8 = GetProcAddress(dll.handle, "DirectSoundCaptureCreate8");
            dsound.DirectSoundCaptureEnumerateA = GetProcAddress(dll.handle, "DirectSoundCaptureEnumerateA");
            dsound.DirectSoundCaptureEnumerateW = GetProcAddress(dll.handle, "DirectSoundCaptureEnumerateW");
            dsound.DirectSoundCreate = GetProcAddress(dll.handle, "DirectSoundCreate");
            dsound.DirectSoundCreate8 = GetProcAddress(dll.handle, "DirectSoundCreate8");
            dsound.DirectSoundEnumerateA = GetProcAddress(dll.handle, "DirectSoundEnumerateA");
            dsound.DirectSoundEnumerateW = GetProcAddress(dll.handle, "DirectSoundEnumerateW");
            dsound.DirectSoundFullDuplexCreate = GetProcAddress(dll.handle, "DirectSoundFullDuplexCreate");
            shared.DllCanUnloadNow = GetProcAddress(dll.handle, "DllCanUnloadNow");
            shared.DllGetClassObject = GetProcAddress(dll.handle, "DllGetClassObject");
            dsound.GetDeviceID = GetProcAddress(dll.handle, "GetDeviceID");
        }
        else if (moduleName == L"ddraw.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            ddraw.AcquireDDThreadLock = GetProcAddress(dll.handle, "AcquireDDThreadLock");
            ddraw.CompleteCreateSysmemSurface = GetProcAddress(dll.handle, "CompleteCreateSysmemSurface");
            ddraw.D3DParseUnknownCommand = GetProcAddress(dll.handle, "D3DParseUnknownCommand");
            ddraw.DDGetAttachedSurfaceLcl = GetProcAddress(dll.handle, "DDGetAttachedSurfaceLcl");
            ddraw.DDInternalLock = GetProcAddress(dll.handle, "DDInternalLock");
            ddraw.DDInternalUnlock = GetProcAddress(dll.handle, "DDInternalUnlock");
            ddraw.DSoundHelp = GetProcAddress(dll.handle, "DSoundHelp");
            ddraw.DirectDrawCreate = GetProcAddress(dll.handle, "DirectDrawCreate");
            ddraw.DirectDrawCreateClipper = GetProcAddress(dll.handle, "DirectDrawCreateClipper");
            ddraw.DirectDrawCreateEx = GetProcAddress(dll.handle, "DirectDrawCreateEx");
            ddraw.DirectDrawEnumerateA = GetProcAddress(dll.handle, "DirectDrawEnumerateA");
            ddraw.DirectDrawEnumerateExA = GetProcAddress(dll.handle, "DirectDrawEnumerateExA");
            ddraw.DirectDrawEnumerateExW = GetProcAddress(dll.handle, "DirectDrawEnumerateExW");
            ddraw.DirectDrawEnumerateW = GetProcAddress(dll.handle, "DirectDrawEnumerateW");
            shared.DllCanUnloadNow = GetProcAddress(dll.handle, "DllCanUnloadNow");
            shared.DllGetClassObject = GetProcAddress(dll.handle, "DllGetClassObject");
            ddraw.GetDDSurfaceLocal = GetProcAddress(dll.handle, "GetDDSurfaceLocal");
            ddraw.GetOLEThunkData = GetProcAddress(dll.handle, "GetOLEThunkData");
            ddraw.GetSurfaceFromDC = GetProcAddress(dll.handle, "GetSurfaceFromDC");
            ddraw.RegisterSpecialCase = GetProcAddress(dll.handle, "RegisterSpecialCase");
            ddraw.ReleaseDDThreadLock = GetProcAddress(dll.handle, "ReleaseDDThreadLock");
            ddraw.SetAppCompatData = GetProcAddress(dll.handle, "SetAppCompatData");
        }
        else if (moduleName == L"d3d8.dll") {
            loadingResult = loader::LoadLib(moduleName, dll.handle);
            shared.DebugSetMute = GetProcAddress(dll.handle, "DebugSetMute");
            d3d8.Direct3D8EnableMaximizedWindowedModeShim = GetProcAddress(dll.handle, "Direct3D8EnableMaximizedWindowedModeShim");
            d3d8.Direct3DCreate8 = GetProcAddress(dll.handle, "Direct3DCreate8");
            d3d8.ValidatePixelShader = GetProcAddress(dll.handle, "ValidatePixelShader");
            d3d8.ValidateVertexShader = GetProcAddress(dll.handle, "ValidateVertexShader");
        }

        if (loader::debugMode == 2 && !loadingResult)
            plugin::InternalMessage(L"Failed to load " + moduleName);
        if (loader::anyProcess || (plugin::StartsWith(procName, L"pes") || plugin::StartsWith(procName, L"settings"))) {
            auto ep = PES::GetEntryPoint();
            if (loader::debugMode) {
                plugin::InternalMessage(L"Plugin Loader (%s) was attached to process.\n\n  Loader module: %s\n  Process name: %s\n  EntryPoint: 0x%X\n\nLoading plugins...",
                    LOADER_VERSION, moduleName.c_str(), loader::GetModuleName(NULL).c_str(), ep);
            }
            loader::LoadPlugins();
        }
    }
    return TRUE;
}
