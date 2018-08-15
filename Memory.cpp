#include "Memory.h"

Memory::Memory(void * memPtr) : memPtr(memPtr) { throwOutOfBoundsException = false; }
Memory::Memory(void * memPtr, long size) : memPtr(memPtr), size(size) { throwOutOfBoundsException = true; }