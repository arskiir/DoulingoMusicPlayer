#include <fstream>
#include <filesystem>
#include <cmath>

#include "Piece.h"

void Piece::load()
{
	std::ifstream ifile;
	ifile.open(this->file_name);
	// TODO
}

void Piece::get_name()
{
	std::string result{};
	// TODO
}

int Piece::get_duration() const
{
	int dur{};
	for (const auto& segment : this->segments) {
		dur += segment.get_duration();
	}
	return dur;
}

std::string Piece::format_duration() const
{
	short mins{};
	short secs{};

	
	// TODO
}

std::string Piece::str() const
{
	return this->name + " - " + this->format_duration();
}

void Piece::play() const
{
	// TODO
	// starts a new thread
	// keeps updating console to show the progression of the piece
}
