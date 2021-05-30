#pragma once
#include <string>

class Piece
{
private:
	std::string name;

public:
	Piece(const std::string& name) : name{ name } {};

	void play() const;
};
