#include <windows.h>
#include "memory.h"

DWORD WINAPI ModThread(LPVOID lpParam) {
    uintptr_t base = Memory::GetBaseAddress(); // 1. Get game base address
    
    uintptr_t staticModulePointer = base + 0x10C7CFE0; // 2. Calculate the start point of your chain (Base + Red offset in Cheat Engine)

    std::vector<unsigned int> brightnessOffsets = { 0xD8, 0x1B8, 0x18 }; // 3. Define offsets from bottom to top (excluding the base module offset)

    float customBrightness = 10.0f;

    // Loop to keep the modification alive while the DLL is attached
    while (true) {
        uintptr_t brightnessAddress = Memory::FindDynamicAddress(staticModulePointer, brightnessOffsets); // Resolve the exact pointer coordinates in real-time

        if (brightnessAddress != 0) {
            Memory::Patch(brightnessAddress, &customBrightness, sizeof(float)); // Write value
        }
        Sleep(50); //to keep CPU usage at 0%
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule); // Disable thread library calls optimized for injection speed
        CreateThread(NULL, 0, ModThread, hModule, 0, NULL); // Spawn our mod logic loop on its own independent thread
    }
    return TRUE;
}