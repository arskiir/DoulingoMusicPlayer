#include <sstream>

#include "Segment.h"

Segment::Segment(const std::string& portion)
{
	this->parse(portion);
	this->dur = this->get_duration();
}

int Segment::get_duration() const
{
	return this->notes.size() * 60 / this->bpm;
}

void Segment::parse(const std::string& portion)
{
	std::stringstream buffer{ portion };
	buffer >> this->bpm; // This raises a fail flag when it sees '-'
	buffer.ignore(1); // ignores '-'
	buffer.clear();
	buffer >> this->notes;
}
