#pragma once

extern wchar_t *SourceText;
extern int SourceLength;
extern int SourcePointer;
extern int CurrentLine;
extern std::map<std::wstring, int> KeyWordsMap;
extern std::map<std::wstring, int> TypeMap;