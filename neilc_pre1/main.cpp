#include "stdafx.h"
using namespace std;

int main() {
	InitSeparator();
	InitTypes();

	ifstream SourceFile("source1", ios::binary);
	SourceFile.seekg(0, ios::end);
	uint32 filesize = SourceFile.tellg();
	char*InFile = new char[filesize + 1];
	SourceFile.seekg(0, ios::beg);
	SourceFile.read(InFile, filesize);
	InFile[filesize] = 0;

	SourceLength = ConvertFormat(SourceText, InFile);
	delete[]InFile;
	for (;;) {
		std::wstring token = GetToken();
		if (token == L"\n") {
			token = L"\\n";
		}
		std::wcout << token << L' ' << std::hex << GetTypeID(token) << std::endl;
		if (SourcePointer >= SourceLength - 1) {
			break;
		}
	}
	return 0;
}