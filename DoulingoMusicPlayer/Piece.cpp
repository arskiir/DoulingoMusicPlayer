#include <fstream>
#include <filesystem>
#include <sstream>

#include "Piece.h"

void Piece::load()
{
	std::ifstream ifile;
	ifile.open(this->file_path);
	// TODO
}

void Piece::init_name()
{
	this->name = std::filesystem::path(this->file_path).stem().string();
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
	std::string result{};


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
