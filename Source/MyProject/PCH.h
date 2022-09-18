#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "Delegates/Delegate.h"
#include "stddef.h"

// Helpful things
#define A2T(str) ANSI_TO_TCHAR(str)
#define T2A(str) TCHAR_TO_ANSI(str)
#define Log2(format, ...) UE_LOG(LogTemp, Warning, TEXT(format), __VA_ARGS__)
typedef size_t uint;
#define ArBit(bit) FArchive_Serialize_BitfieldBool(Ar, bit)
#define ArVar(var) Ar << var

