#include "stdafx.h"
using namespace std;

int main() {

	ifstream SourceFile("source", ios::binary);
	SourceFile.seekg(0, ios::end);
	uint32 filesize = SourceFile.tellg();
	char*InFile = new char[filesize + 1];
	SourceFile.seekg(0, ios::beg);
	SourceFile.read(InFile, filesize);
	InFile[filesize] = 0;

	SourceLength = ConvertFormat(SourceText, InFile);
	delete[]InFile;
	for (;;) {

	}
}