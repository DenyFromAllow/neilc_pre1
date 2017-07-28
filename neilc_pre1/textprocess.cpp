#include "stdafx.h"

bool Separator[128];

void InitSeparator() {
	memset(Separator, 0, 128);

	Separator['('] = true;
	Separator[')'] = true;
	Separator['['] = true;
	Separator[']'] = true;
	Separator['{'] = true;
	Separator['}'] = true;

	Separator[';'] = true;
	Separator[','] = true;
	Separator[':'] = true;
	Separator['.'] = true;
	Separator['~'] = true;
	Separator['\"'] = true;
	Separator['\''] = true;
	Separator['#'] = true;
}

std::wstring GetToken() {
	if ((!SourceText) || (!SourceLength) || !(SourceLength < SourcePointer)) {
		return L"";
	}
	wchar_t Buffer[64];
	std::wstring OutString;
	int BufferIndex = 0;
	/*
	enum CharType :uint8 {
		WhiteSpace,
		NumberEnglishAndUnicode,
		Separator,//Newline is a separator
	};
	CharType FirstCharType;*/
	for (;;) {
		if (SourceText[SourcePointer] == ' ' || SourceText[SourcePointer] == '\t') {
			SourcePointer++;
		} else if (SourceText[SourcePointer] == '/') {
			if (SourceText[SourcePointer + 1] == '/') {
				SourcePointer += 2;
				while (SourceText[SourcePointer] != '\n' && SourceText[SourcePointer] != 0) {
					SourcePointer++;
				}
			} else if (SourceText[SourcePointer + 1] == '*') {
				SourcePointer += 2;
				while (SourceText[SourcePointer] != 0) {
					if (SourceText[SourcePointer] == '*' && SourceText[SourcePointer + 1] == '/') {
						SourcePointer += 2;
						break;
					}
					SourcePointer++;
				}
			}
		} else {
			break;
		}
	}

	if (SourceText[SourcePointer] == 0) {
		return L"";
	}

	if (SourceText[SourcePointer] == '\r') {
		if (SourceText[SourcePointer + 1] == '\n') {
			SourcePointer += 2;
			CurrentLine++;
			return L"\n";
		}
		SourcePointer++;
		CurrentLine++;
		return L"\n";
	} else if (SourceText[SourcePointer] == '\n') {
		SourcePointer++;
		CurrentLine++;
		return L"\n";
	}

	if (Separator[SourceText[SourcePointer]]) {
		return OutString + SourceText[SourcePointer++];
	}

	if (SourceText[SourcePointer] == '\"') {
		int StartLine = CurrentLine;
		for (;;) {
			Buffer[BufferIndex] = SourceText[SourcePointer];
			BufferIndex++;
			SourcePointer++;
			if (BufferIndex >= 64) {
				OutString.append(Buffer, 64);
				BufferIndex = 0;
			}
			if (SourceText[SourcePointer] == '\\') {
				SourcePointer++;
				wchar_t NextChar;
				switch (SourceText[SourcePointer]) {
				case L'\r': {
					SourcePointer++;
					if (SourceText[SourcePointer] == '\n') {
						SourcePointer++;
					}
					CurrentLine++;
					continue;
					break;
				}
				case L'\n': {
					SourcePointer++;
					CurrentLine++;
					continue;
					break;
				}
				case L'\a': { NextChar = '\a'; break; }
				case L'b': { NextChar = '\b'; break; }
				case L'f': { NextChar = '\f'; break; }
				case L'n': { NextChar = '\n'; break; }
				case L'r': { NextChar = '\r'; break; }
				case L't': { NextChar = '\t'; break; }
				case L'v': { NextChar = '\v'; break; }
				case L'\\': { NextChar = '\\'; break; }
				case L'\'': { NextChar = '\''; break; }
				case L'\"': { NextChar = '\"'; break; }
				case L'x': {
					NextChar = 0;
					SourcePointer++;
					if (SourceText[SourcePointer] >= '0' && SourceText[SourcePointer] <= '9') {
						NextChar += SourceText[SourcePointer] - '0';
					}else if(SourceText[SourcePointer] >= 'a' && SourceText[SourcePointer] <= 'f') {
						NextChar += SourceText[SourcePointer] - 'a' + 0xa;
					} else if (SourceText[SourcePointer] >= 'A' && SourceText[SourcePointer] <= 'F') {
						NextChar += SourceText[SourcePointer] - 'A' + 0xA;
					} else {
						throw(InvalidHexNumberException(CurrentLine));
					}
					for (int i = 1; 1 < 4; i++) {
						SourcePointer++;
						if (SourceText[SourcePointer] >= '0' && SourceText[SourcePointer] <= '9') {
							NextChar <<= 4;
							NextChar += SourceText[SourcePointer] - '0';
						} else if (SourceText[SourcePointer] >= 'a' && SourceText[SourcePointer] <= 'f') {
							NextChar <<= 4;
							NextChar += SourceText[SourcePointer] - 'a' + 0xa;
						} else if (SourceText[SourcePointer] >= 'A' && SourceText[SourcePointer] <= 'F') {
							NextChar <<= 4;
							NextChar += SourceText[SourcePointer] - 'A' + 0xA;
						} else {
							SourcePointer--;
							break;
						}
					}
					break;
				}
				default: {
					NextChar = SourceText[SourcePointer];
					break;
				}
				}
				Buffer[BufferIndex] = NextChar;
				BufferIndex++;
				SourcePointer++;
				if (BufferIndex >= 64) {
					OutString.append(Buffer, 64);
					BufferIndex = 0;
				}
			} else if (SourceText[SourcePointer] == '\"') {
				Buffer[BufferIndex] = SourceText[SourcePointer];
				BufferIndex++;
				SourcePointer++;
				if (BufferIndex >= 64) {
					OutString.append(Buffer, 64);
					BufferIndex = 0;
				}
				OutString.append(Buffer, BufferIndex);
				return OutString;
			} else if (SourceText[SourcePointer] == 0) {
				throw(LeftTokenWasUnmatchedAtTheEndOfFileException(L'\"', StartLine));
			}
		}
		OutString.append(Buffer, BufferIndex);
		return OutString;
	}

	if (SourceText[SourcePointer] == '\'') {
		Buffer[BufferIndex] = '\'';
		BufferIndex++;
		SourcePointer++;
		if (SourceText[SourcePointer] == '\\') {
			SourcePointer++;
			wchar_t NextChar;
			switch (SourceText[SourcePointer]) {
			case L'\a': { NextChar = '\a'; break; }
			case L'b': { NextChar = '\b'; break; }
			case L'f': { NextChar = '\f'; break; }
			case L'n': { NextChar = '\n'; break; }
			case L'r': { NextChar = '\r'; break; }
			case L't': { NextChar = '\t'; break; }
			case L'v': { NextChar = '\v'; break; }
			case L'\\': { NextChar = '\\'; break; }
			case L'\'': { NextChar = '\''; break; }
			case L'\"': { NextChar = '\"'; break; }
			case L'x': {
				NextChar = 0;
				SourcePointer++;
				if (SourceText[SourcePointer] >= '0' && SourceText[SourcePointer] <= '9') {
					NextChar += SourceText[SourcePointer] - '0';
				} else if (SourceText[SourcePointer] >= 'a' && SourceText[SourcePointer] <= 'f') {
					NextChar += SourceText[SourcePointer] - 'a' + 0xa;
				} else if (SourceText[SourcePointer] >= 'A' && SourceText[SourcePointer] <= 'F') {
					NextChar += SourceText[SourcePointer] - 'A' + 0xA;
				} else {
					throw(InvalidHexNumberException(CurrentLine));
				}
				for (int i = 1; 1 < 4; i++) {
					SourcePointer++;
					if (SourceText[SourcePointer] >= '0' && SourceText[SourcePointer] <= '9') {
						NextChar <<= 4;
						NextChar += SourceText[SourcePointer] - '0';
					} else if (SourceText[SourcePointer] >= 'a' && SourceText[SourcePointer] <= 'f') {
						NextChar <<= 4;
						NextChar += SourceText[SourcePointer] - 'a' + 0xa;
					} else if (SourceText[SourcePointer] >= 'A' && SourceText[SourcePointer] <= 'F') {
						NextChar <<= 4;
						NextChar += SourceText[SourcePointer] - 'A' + 0xA;
					} else {
						SourcePointer--;
						break;
					}
				}
				break;
			}
			default: {
				NextChar = SourceText[SourcePointer];
				break;
			}
			}
			Buffer[BufferIndex] = NextChar;
			BufferIndex++;
			SourcePointer++;
			if (BufferIndex >= 64) {
				OutString.append(Buffer, 64);
				BufferIndex = 0;
			}
		} else if(SourceText[SourcePointer]=='\r'|| SourceText[SourcePointer] == '\n') {
			throw(UnexpectedNewLineException(CurrentLine));
		} else {
			Buffer[BufferIndex] = SourceText[SourcePointer];
			BufferIndex++;
			SourcePointer++;
			if (BufferIndex >= 64) {
				OutString.append(Buffer, 64);
				BufferIndex = 0;
			}
		}
		if(SourceText[SourcePointer] == '\r' || SourceText[SourcePointer] == '\n') {
			throw(UnexpectedNewLineException(CurrentLine));
		} else if (SourceText[SourcePointer] == '\'') {
			throw(TooManyCharactersInConstantException(CurrentLine));
		}

		Buffer[BufferIndex] = '\'';
		BufferIndex++;
		SourcePointer++;
		OutString.append(Buffer, BufferIndex);
		return OutString;
	}
	
	if (SourceText[SourcePointer] == 0 && SourcePointer != SourcePointer - 1) {
		throw(UnexpectedEndOfFileException(CurrentLine));
	}

	if ((SourceText[SourcePointer] <= 'A' || SourceText[SourcePointer] >= 'Z')
		&& (SourceText[SourcePointer] <= 'a' || SourceText[SourcePointer] >= 'z')
		&& (SourceText[SourcePointer] <= '0' || SourceText[SourcePointer] >= '9')
		&& SourceText[SourcePointer] < 128) {
		throw(UnknownCharacterException(CurrentLine));
	}

	for (;;) {
		if ((SourceText[SourcePointer] >= 'A'&&SourceText[SourcePointer] <= 'Z')
			|| (SourceText[SourcePointer] >= 'a'&&SourceText[SourcePointer] <= 'z')
			|| (SourceText[SourcePointer] >= '0'&&SourceText[SourcePointer] <= '9')
			|| SourceText[SourcePointer] >= 128) {
			Buffer[BufferIndex] = SourceText[SourcePointer];
			BufferIndex++;
			SourcePointer++;
			if (BufferIndex >= 64) {
				OutString.append(Buffer, 64);
				BufferIndex = 0;
			}
		} else {
			OutString.append(Buffer, BufferIndex);
			return OutString;
		}
	}
}