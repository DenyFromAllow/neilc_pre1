#include "stdafx.h"

wchar_t *SourceText = nullptr;
int SourceLength = 0;
int SourcePointer = 0;
int CurrentLine = 1;
std::map<std::wstring, uint32> KeyWordsMap;
std::map<std::wstring, uint32> TypeMap;

std::map<std::wstring, uint32> VariablesMap;
std::map<std::wstring, uint32> FunctionsMap;