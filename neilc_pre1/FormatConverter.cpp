#include "stdafx.h"

int ConvertFormat(wchar_t *&dst, char *src) {
	enum TextFormat : unsigned char {
		unknown,
		ansi,
		utf8,
		ucs2,
		ucs2BigEndian
	};

	TextFormat format = unknown;
	int length;

	if ((!src) || (src[0] == 0)) {
		dst = nullptr;
		return 0;
	}

	//���bom
	if (src[0] == 0xFF && src[1] == 0xFE) {
		format = ucs2;
		src += 2;
	} else if (src[0] == 0xFE && src[1] == 0xFF) {
		format = ucs2BigEndian;
		src += 2;
	} else if (src[0] == 0xEF && src[1] == 0xBB && src[2] == 0xBF) {
		format = utf8;
		src += 3;
	}

	if (src[0] == 0) {
		dst = nullptr;
		return 0;
	}

	//���û��bom�������ansi��utf8��������з�ASCII�ַ�����utf8��������Ϊutf8���룬������Ϊansi����
	if (format == unknown) {
		for (int i = 0; src[i]; i++) {
			if ((uint8)src[i] < 0x80) {
				continue;
			}
			int utf8ByteCount;
			if ((uint8)src[i] < 0b11000000 || (uint8)src[i] > 0b11111101) {
				format = ansi;
				break;
			} else if ((uint8)src[i] < 0b11100000) {
				utf8ByteCount = 2;
			} else if ((uint8)src[i] < 0b11110000) {
				utf8ByteCount = 3;
			} else if ((uint8)src[i] < 0b11111000) {
				utf8ByteCount = 4;
			} else if ((uint8)src[i] < 0b11111100) {
				utf8ByteCount = 5;
			} else if ((uint8)src[i] < 0b11111110) {
				utf8ByteCount = 6;
			}

			//��0�ֽ��Ѿ��������ӵ�1�ֽڿ�ʼ��
			for (int j = 1; j < utf8ByteCount; j++) {
				i++;
				if ((uint8)src[i] < 0b10000000 || (uint8)src[i] > 0b10111111) {
					format = ansi;
					break;
				}
			}
		}
		if (format == unknown) {
			format = utf8;
		}
	}

	if (format == ansi) {
		length = MultiByteToWideChar(CP_ACP, NULL, src, -1, nullptr, 0);
		dst = new wchar_t[length];
		MultiByteToWideChar(CP_ACP, NULL, src, -1, dst, length);
		//dst[length] = 0;
		return length;
	} else if (format == utf8) {
		length = MultiByteToWideChar(CP_UTF8, NULL, src, -1, nullptr, 0);
		dst = new wchar_t[length];
		MultiByteToWideChar(CP_UTF8, NULL, src, -1, dst, length);
		//dst[length] = 0;
		return length;
	} else if (format == ucs2) {
		dst = nullptr;
		return 0;
	} else if (format == ucs2BigEndian) {
		dst = nullptr;
		return 0;
	}
	dst = nullptr;
	return 0;
}