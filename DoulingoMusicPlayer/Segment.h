#pragma once
#include <string>
#include <map>

// represents a segment that has only bpm
class Segment
{
private:
	std::string notes;
	unsigned short bpm;
	unsigned int dur;
public:
	static std::map<char, int> key_map;

	static void initialize_key_map(std::map<char, int>& key_map);


	// incoming portion is in this format: bpm-xxx...
	Segment(const std::string& portion);

	int get_duration() const;

	void play() const;

private:
	static int get_code(char note);

	// parse the portion to notes and bpm
	void parse(const std::string& portion);

	// send the key input
	void send_key(char note) const;
};
