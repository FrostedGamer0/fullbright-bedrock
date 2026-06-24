#include "memory.h"

uintptr_t Memory::GetBaseAddress() {
    return (uintptr_t)GetModuleHandleA(NULL);
}

uintptr_t Memory::FindDynamicAddress(uintptr_t baseAddress, const std::vector<unsigned int>& offsets) {
    uintptr_t addr = baseAddress;

    for (size_t i = 0; i < offsets.size(); ++i) {
        // Dereference the current address to get the pointer it holds
        addr = *(uintptr_t*)addr;

        // If the pointer is null, the game structural path isn't active yet
        if (addr == 0) return 0;

        // Add the next offset in the chain
        addr += offsets[i];
    }

    return addr;
}

bool Memory::Patch(uintptr_t address, void* value, size_t size) {
    DWORD oldProtect;
    
    // Change page permissions to Read/Write/Execute
    if (!VirtualProtect((LPVOID)address, size, PAGE_EXECUTE_READWRITE, &oldProtect)) {
        return false;
    }
        
    // Copy our new value over the old memory
    memcpy((LPVOID)address, value, size);
    
    // Restore the game's original memory permissions
    VirtualProtect((LPVOID)address, size, oldProtect, &oldProtect);
    return true;
}