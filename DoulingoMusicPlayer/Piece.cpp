#include <fstream>
#include <filesystem>
#include <cmath>

#include "Piece.h"

void Piece::load() const
{
	std::ifstream ifile;
	ifile.open(this->file_name);
	// TODO
}

void Piece::get_name() const
{
	std::string result{};
	// TODO
}

int Piece::get_duration() const
{
	return std::floor(1 / (double)this->bpm * this->notes.size() * 60);
}

std::string Piece::format_duration() const
{
	// TODO
}

std::string Piece::print() const
{
	return this->name + " - " + this->format_duration();
}

void Piece::play() const
{
	// TODO
	// starts a new thread
	// keeps updating console to show the progression of the piece
}
