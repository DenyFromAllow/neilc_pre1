#pragma once

class UnexpectedEndOfFileException {
public:
	int Line;
	UnexpectedEndOfFileException(int InLine) :Line(InLine) {}
};

class LeftTokenWasUnmatchedAtTheEndOfFileException {
public:
	wchar_t LeftToken;
	int Line;
	
	LeftTokenWasUnmatchedAtTheEndOfFileException(wchar_t InLeftToken, int InLine) :LeftToken(InLeftToken), Line(InLine) {}
};

class TooManyCharactersInConstantException {
public:
	int Line;
	TooManyCharactersInConstantException(int InLine) :Line(InLine) {}
};

class InvalidHexNumberException {
public:
	int Line;
	InvalidHexNumberException(int InLine) :Line(InLine) {}
};

class UnexpectedNewLineException {
public:
	int Line;
	UnexpectedNewLineException(int InLine) :Line(InLine) {}
};

class UnknownCharacterException {
public:
	int Line;
	UnknownCharacterException(int InLine) :Line(InLine) {}
};