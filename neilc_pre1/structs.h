#pragma once

struct Block {
	enum class Type :uint8 {
		Function,
		Class,
		Struct,
		Enum,
		Parameters,
		ReturnValues
	};
	Type BlockType;
	void *Entity;
	Block *prev;
};
