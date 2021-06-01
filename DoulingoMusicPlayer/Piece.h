#pragma once
#include <string>

class Piece
{
private:
	std::string file_name;
	std::string name;
	std::string notes;
	unsigned short bpm;

public:
	Piece(const std::string &file_name) : file_name{file_name}
	{
		this->get_name();
	};

	// gets the name of the piece and initializes this->name
	void get_name() const;

	// load all the notes in the text file into a container class
	void load() const;

	// plays the piece by sending key inputs
	void play() const;

	// returns the duration of the piece in seconds
	int get_duration() const;

	// returns string in human readable format
	std::string print() const;

	// formats the duration in seconds to "min:sec" format and returns it
	std::string format_duration() const;

	friend std::ostream &operator<<(std::ostream &out, Piece piece)
	{
		out << piece.print();
		return out;
	}
};
