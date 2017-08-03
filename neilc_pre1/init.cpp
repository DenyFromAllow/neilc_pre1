#include "stdafx.h"

void InitTypes() {
	TypeMap[L"void"] = 0;

	TypeMap[L"i8"]			= Int8;			TypeMap[L"int8"]		= Int8;
	TypeMap[L"i16"]			= Int16;		TypeMap[L"int16"]		= Int16;		TypeMap[L"short"]	= Int16;
	TypeMap[L"i32"]			= Int32;		TypeMap[L"int32"]		= Int32;		TypeMap[L"int"]		= Int32;
	TypeMap[L"i64"]			= Int64;		TypeMap[L"int64"]		= Int64;		TypeMap[L"long"]	= Int64;
	TypeMap[L"i128"]		= Int128;		TypeMap[L"int128"]		= Int128;
	TypeMap[L"i256"]		= Int256;		TypeMap[L"int256"]		= Int256;
	TypeMap[L"ui8"]			= Uint8;		TypeMap[L"uint8"]		= Uint8;		TypeMap[L"byte"]	= Uint8;
	TypeMap[L"ui16"]		= Uint16;		TypeMap[L"uint16"]		= Uint16;		TypeMap[L"word"]	= Uint16;		TypeMap[L"ushort"]	= Uint16;
	TypeMap[L"ui32"]		= Uint32;		TypeMap[L"uint32"]		= Uint32;		TypeMap[L"dword"]	= Uint32;		TypeMap[L"uint"]	= Uint32;
	TypeMap[L"ui64"]		= Uint64;		TypeMap[L"uint64"]		= Uint64;		TypeMap[L"qword"]	= Uint64;		TypeMap[L"ulong"]	= Uint64;
	TypeMap[L"ui128"]		= Uint128;		TypeMap[L"uint128"]		= Uint128;
	TypeMap[L"ui256"]		= Uint256;		TypeMap[L"uint256"]		= Uint256;
	TypeMap[L"float"]		= Float;
	TypeMap[L"double"]		= Double;
	TypeMap[L"quadruple"]	= Quadruple;	TypeMap[L"quad"]		= Quadruple;	TypeMap[L"quad"]	= Quadruple;

	TypeMap[L"i8vector"]	= I8vector;		TypeMap[L"i8vec"]		= I8vector;		TypeMap[L"i8v"]		= I8vector;		TypeMap[L"int8vector"]		= I8vector;		TypeMap[L"int8vec"]		= I8vector;		TypeMap[L"int8v"]		= I8vector;
	TypeMap[L"i16vector"]	= I16vector;	TypeMap[L"i16vec"]		= I16vector;	TypeMap[L"i16v"]	= I16vector;	TypeMap[L"int16vector"]		= I16vector;	TypeMap[L"int16vec"]	= I16vector;	TypeMap[L"int16v"]		= I16vector;
	TypeMap[L"i32vector"]	= I32vector;	TypeMap[L"i32vec"]		= I32vector;	TypeMap[L"i32v"]	= I32vector;	TypeMap[L"int32vector"]		= I32vector;	TypeMap[L"int32vec"]	= I32vector;	TypeMap[L"int32v"]		= I32vector;
	TypeMap[L"i64vector"]	= I64vector;	TypeMap[L"i64vec"]		= I64vector;	TypeMap[L"i64v"]	= I64vector;	TypeMap[L"int64vector"]		= I64vector;	TypeMap[L"int64vec"]	= I64vector;	TypeMap[L"int64v"]		= I64vector;
	TypeMap[L"i128vector"]	= I128vector;	TypeMap[L"i128vec"]		= I128vector;	TypeMap[L"i128v"]	= I128vector;	TypeMap[L"int128vector"]	= I128vector;	TypeMap[L"int128vec"]	= I128vector;	TypeMap[L"int128v"]		= I128vector;
	TypeMap[L"i256vector"]	= I256vector;	TypeMap[L"i256vec"]		= I256vector;	TypeMap[L"i256v"]	= I256vector;	TypeMap[L"int256vector"]	= I256vector;	TypeMap[L"int256vec"]	= I256vector;	TypeMap[L"int256v"]		= I256vector;
	TypeMap[L"ui8vector"]	= Ui8vector;	TypeMap[L"ui8vec"]		= Ui8vector;	TypeMap[L"ui8v"]	= Ui8vector;	TypeMap[L"uint8vector"]		= Ui8vector;	TypeMap[L"uint8vec"]	= Ui8vector;	TypeMap[L"uint8v"]		= Ui8vector;	TypeMap[L"bytevector"]	= Ui8vector;	TypeMap[L"bytevec"]		= Ui8vector;	TypeMap[L"bytev"]	= Ui8vector;
	TypeMap[L"ui16vector"]	= Ui16vector;	TypeMap[L"ui16vec"]		= Ui16vector;	TypeMap[L"ui16v"]	= Ui16vector;	TypeMap[L"uint16vector"]	= Ui16vector;	TypeMap[L"uint16vec"]	= Ui16vector;	TypeMap[L"uint16v"]		= Ui16vector;	TypeMap[L"wordvector"]	= Ui16vector;	TypeMap[L"wordvec"]		= Ui16vector;	TypeMap[L"wordv"]	= Ui16vector;
	TypeMap[L"ui32vector"]	= Ui32vector;	TypeMap[L"ui32vec"]		= Ui32vector;	TypeMap[L"ui32v"]	= Ui32vector;	TypeMap[L"uint32vector"]	= Ui32vector;	TypeMap[L"uint32vec"]	= Ui32vector;	TypeMap[L"uint32v"]		= Ui32vector;	TypeMap[L"dwordvector"]	= Ui32vector;	TypeMap[L"dwordvec"]	= Ui32vector;	TypeMap[L"dwordv"]	= Ui32vector;
	TypeMap[L"ui64vector"]	= Ui64vector;	TypeMap[L"ui64vec"]		= Ui64vector;	TypeMap[L"ui64v"]	= Ui64vector;	TypeMap[L"uint64vector"]	= Ui64vector;	TypeMap[L"uint64vec"]	= Ui64vector;	TypeMap[L"uint64v"]		= Ui64vector;	TypeMap[L"qwordvector"]	= Ui64vector;	TypeMap[L"qwordvec"]	= Ui64vector;	TypeMap[L"qwordv"]	= Ui64vector;
	TypeMap[L"ui128vector"]	= Ui128vector;	TypeMap[L"ui128vec"]	= Ui128vector;	TypeMap[L"ui128v"]	= Ui128vector;	TypeMap[L"uint128vector"]	= Ui128vector;	TypeMap[L"uint128vec"]	= Ui128vector;	TypeMap[L"uint128v"]	= Ui128vector;
	TypeMap[L"ui256vector"]	= Ui256vector;	TypeMap[L"ui256vec"]	= Ui256vector;	TypeMap[L"ui256v"]	= Ui256vector;	TypeMap[L"uint256vector"]	= Ui256vector;	TypeMap[L"uint256vec"]	= Ui256vector;	TypeMap[L"uint256v"]	= Ui256vector;
	TypeMap[L"fvector"]		= Fvector;		TypeMap[L"fvec"]		= Fvector;		TypeMap[L"floatv"]	= Fvector;		TypeMap[L"floatvector"]		= Fvector;		TypeMap[L"floatvec"]	= Fvector;		TypeMap[L"vector"]		= Fvector;
	TypeMap[L"dvector"]		= Dvector;		TypeMap[L"dvec"]		= Dvector;		TypeMap[L"doublev"]	= Dvector;		TypeMap[L"doublevector"]	= Dvector;		TypeMap[L"doublevec"]	= Dvector;
	TypeMap[L"qvector"]		= Qvector;		TypeMap[L"qvec"]		= Qvector;		TypeMap[L"quadv"]	= Qvector;		TypeMap[L"quadvector"]		= Qvector;		TypeMap[L"quadvec"]		= Qvector;

	TypeMap[L"void"]				= Void;
	TypeMap[L"ansi"]				= Ansi;
	TypeMap[L"ascii"]				= Ascii;
	TypeMap[L"utf8"]				= Utf8;
	TypeMap[L"utf16little_endian"]	= utf16le;	TypeMap[L"utf16le"]	= utf16le;	TypeMap[L"utf16"]	= utf16le;
	TypeMap[L"utf16big_endian"]		= utf16be;	TypeMap[L"utf16be"]	= utf16be;
	TypeMap[L"utf32little_endian"]	= utf32le;	TypeMap[L"utf32le"]	= utf32le;	TypeMap[L"utf32"]	= utf32le;	TypeMap[L"ucs4little_endian"]	= utf32le;	TypeMap[L"ucs4le"]	= utf32le;	TypeMap[L"ucs4"]	= utf32le;
	TypeMap[L"utf32big_endian"]		= utf32be;	TypeMap[L"utf32be"]	= utf32be;									TypeMap[L"ucs4big_endian"]		= utf32be;	TypeMap[L"ucs4be"]	= utf32be;
	TypeMap[L"ucs2little_endian"]	= ucs2le;	TypeMap[L"ucs2le"]	= ucs2le;	TypeMap[L"ucs2"]	= ucs2le;
	TypeMap[L"ucs2big_endian"]		= ucs2be;	TypeMap[L"ucs2be"]	= ucs2be;
}

void InitKeyWords() {
	KeyWordsMap[L"add"]		= Add;
	KeyWordsMap[L"adc"]		= Adc;
	KeyWordsMap[L"sub"]		= Sub;
	KeyWordsMap[L"sbb"]		= Sbb;
	KeyWordsMap[L"mul"]		= Mul;
	KeyWordsMap[L"imul"]	= Imul;
	KeyWordsMap[L"div"]		= Div;
	KeyWordsMap[L"idiv"]	= Idiv;
	KeyWordsMap[L"rem"]		= Rem;
	KeyWordsMap[L"irem"]	= Irem;
	KeyWordsMap[L"inc"]		= Inc;
	KeyWordsMap[L"dec"]		= Dec;
	KeyWordsMap[L"nec"]		= Nec;

	KeyWordsMap[L"mov"]		= Mov;
	KeyWordsMap[L"movsx"]	= Movsx;
	KeyWordsMap[L"movzx"]	= Movzx;
	KeyWordsMap[L"xchg"]	= Xchg;
	KeyWordsMap[L"cvtf2i"]	= Cvtf2i;
	KeyWordsMap[L"cvti2f"]	= Cvti2f;

	KeyWordsMap[L"abs"]		= Abs;
	KeyWordsMap[L"rcp"]		= Rcp;
	KeyWordsMap[L"min"]		= Min;
	KeyWordsMap[L"max"]		= Max;
	KeyWordsMap[L"sqrt"]	= Sqrt;
	KeyWordsMap[L"rsqrt"]	= Rsqrt;

	KeyWordsMap[L"and"]		= And;
	KeyWordsMap[L"andnot"]	= Andnot;
	KeyWordsMap[L"or"]		= Or;
	KeyWordsMap[L"not"]		= Not;
	KeyWordsMap[L"xor"]		= Xor;

	KeyWordsMap[L"shl"]		= Shl;
	KeyWordsMap[L"shr"]		= Shr;

	KeyWordsMap[L"sal"]		= Sal;
	KeyWordsMap[L"sar"]		= Sar;
	KeyWordsMap[L"rol"]		= Rol;
	KeyWordsMap[L"ror"]		= Ror;
	KeyWordsMap[L"rcl"]		= Rcl;
	KeyWordsMap[L"rcr"]		= Rcr;

	KeyWordsMap[L"jmp"]		= Jmp;

	KeyWordsMap[L"cmp"]		= Cmp;
	KeyWordsMap[L"test"]	= Test;
	KeyWordsMap[L"lea"]		= Lea;

	KeyWordsMap[L"ja"]		= Ja;		KeyWordsMap[L"jnbe"]	= Ja;
	KeyWordsMap[L"jb"]		= Jb;		KeyWordsMap[L"jnae"]	= Jb;
	KeyWordsMap[L"jg"]		= Jg;		KeyWordsMap[L"jnle"]	= Jg;
	KeyWordsMap[L"jl"]		= Jl;		KeyWordsMap[L"jnge"]	= Jl;
	KeyWordsMap[L"jae"]		= Jae;		KeyWordsMap[L"jnb"]		= Jae;
	KeyWordsMap[L"jbe"]		= Jbe;		KeyWordsMap[L"jna"]		= Jbe;
	KeyWordsMap[L"jge"]		= Jge;		KeyWordsMap[L"jnl"]		= Jge;
	KeyWordsMap[L"jle"]		= Jle;		KeyWordsMap[L"jng"]		= Jle;

	KeyWordsMap[L"je"]		= Je;		KeyWordsMap[L"jz"]		= Je;
	KeyWordsMap[L"jne"]		= Jne;		KeyWordsMap[L"jnz"]		= Jne;
	KeyWordsMap[L"js"]		= Js;
	KeyWordsMap[L"jns"]		= Jns;
	KeyWordsMap[L"jc"]		= Jc;
	KeyWordsMap[L"jnc"]		= Jnc;
	KeyWordsMap[L"jo"]		= Jo;
	KeyWordsMap[L"jno"]		= Jno;

	KeyWordsMap[L"cmova"]	= Cmova;	KeyWordsMap[L"cmovnbe"]	= Cmova;
	KeyWordsMap[L"cmpvb"]	= Cmpvb;	KeyWordsMap[L"cmovnae"]	= Cmpvb;
	KeyWordsMap[L"cmovg"]	= Cmovg;	KeyWordsMap[L"cmovnle"]	= Cmovg;
	KeyWordsMap[L"cmovl"]	= Cmovl;	KeyWordsMap[L"cmovnge"]	= Cmovl;
	KeyWordsMap[L"cmovae"]	= Cmovae;	KeyWordsMap[L"cmovnb"]	= Cmovae;
	KeyWordsMap[L"cmpvbe"]	= Cmpvbe;	KeyWordsMap[L"cmovna"]	= Cmpvbe;
	KeyWordsMap[L"cmovge"]	= Cmovge;	KeyWordsMap[L"cmovnl"]	= Cmovge;
	KeyWordsMap[L"cmovle"]	= Cmovle;	KeyWordsMap[L"cmovng"]	= Cmovle;

	KeyWordsMap[L"cmove"]	= Cmove;	KeyWordsMap[L"cmovz"]	= Cmove;
	KeyWordsMap[L"cmovne"]	= Cmovne;	KeyWordsMap[L"cmovnz"]	= Cmovne;
	KeyWordsMap[L"cmovs"]	= Cmovs;
	KeyWordsMap[L"cmovns"]	= Cmovns;
	KeyWordsMap[L"cmovc"]	= Cmovc;
	KeyWordsMap[L"cmovnc"]	= Cmovnc;
	KeyWordsMap[L"cmovo"]	= Cmovo;
	KeyWordsMap[L"cmovno"]	= Cmovno;

	KeyWordsMap[L"call"]	= Call;
	KeyWordsMap[L"ret"]		= Ret;		KeyWordsMap[L"return"] = Ret;
	KeyWordsMap[L"preret"]	= Preret;

	KeyWordsMap[L"movsb"]	= Movsb;
	KeyWordsMap[L"movsw"]	= Movsw;
	KeyWordsMap[L"movsd"]	= Movsd;
	KeyWordsMap[L"movsq"]	= Movsq;

	KeyWordsMap[L"stosb"]	= Stosb;
	KeyWordsMap[L"stosw"]	= Stosw;
	KeyWordsMap[L"stosd"]	= Stosd;
	KeyWordsMap[L"stosq"]	= Stosq;

	KeyWordsMap[L"offset"]	= Offset;
	KeyWordsMap[L"sizeof"]	= Sizeof;
}