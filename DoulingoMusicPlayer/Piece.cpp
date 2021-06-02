#include <fstream>
#include <filesystem>
#include <sstream>
#include <thread>
#include <iostream>

#include "Piece.h"

Piece::Piece(const std::string& file_path) : file_path{ file_path }
{
	this->init_name();
	this->load_file();
	this->duration = this->get_duration();
};

void Piece::load_file()
{
	std::ifstream ifile;
	ifile.open(this->file_path);
	std::string line{};
	while (!ifile.eof()) {
		std::getline(ifile, line);
		this->segments.emplace_back(line);
	}
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
	unsigned int mins{ this->duration / 60 };
	unsigned int secs{ this->duration % 60 };

	std::stringstream buffer;
	buffer << mins;
	if (secs < 10) buffer << ":0"; else buffer << ":";
	buffer << secs;

	return buffer.str();
}

void Piece::_play() const
{
	for (const auto& segment : this->segments) {
		segment.play();
	}
}

std::string Piece::str() const
{
	return this->name + " - " + this->format_duration();
}

void Piece::play() const
{
	// TODO use a thread
	// starts a new thread
	// keeps updating console to show the progression of the piece
	this->_play();
}