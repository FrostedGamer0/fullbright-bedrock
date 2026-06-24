#pragma once
#include <windows.h>
#include <vector>

namespace Memory {
    // Gets the base address of Minecraft.Windows.exe
    uintptr_t GetBaseAddress();

    // Traverses a multilevel pointer chain (offsets read from bottom to top)
    uintptr_t FindDynamicAddress(uintptr_t baseAddress, const std::vector<unsigned int>& offsets);

    // Safely overwrites protected memory bytes
    bool Patch(uintptr_t address, void* value, size_t size);
}