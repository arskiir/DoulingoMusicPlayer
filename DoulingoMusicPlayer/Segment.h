#pragma once
#include <string>

// represents a segment that has only bpm
class Segment
{
private:
	std::string notes;
	unsigned short bpm;
	unsigned int dur;

public:
	// incoming portion is in this format: bpm-xxx...
	Segment(const std::string& portion);

	int get_duration() const;

private:
	// parse the portion to notes and bpm
	void parse(const std::string& portion);
};
