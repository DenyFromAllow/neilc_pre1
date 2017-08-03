#pragma once

using uint8  = unsigned char;
using uint16 = unsigned short int;
using uint32 = unsigned long  int;
using uint64 = unsigned long  long;

using int8  = signed char;
using int16 = signed short int;
using int32 = signed long  int;
using int64 = signed long  long;

using uint128 = uint64[2];
using uint256 = uint64[4];
using int128 = int64[2];
using int256 = int64[4];

#include "structs.h"
#include "enum.h"
#include "exceptions.h"
#include "GlobalVaribles.h"

int ConvertFormat(wchar_t *&dst, char *src);
void InitSeparator();
void InitTypes();
std::wstring GetToken();
uint32 GetTypeID(std::wstring Name);