#include <sstream>
#include <iostream>
#include <Windows.h>
#include <map>

#include "Segment.h"

int Segment::get_code(char note)
{
	return key_map[note];
}


void Segment::initialize_key_map(std::map<char, int>& key_map)
{
	key_map['1'] = 0x31;
	key_map['2'] = 0x32;
	key_map['3'] = 0x33;
	key_map['4'] = 0x34;
	key_map['0'] = 0x30;
}

Segment::Segment(const std::string& portion)
{
	this->parse(portion);
	this->dur = this->get_duration();
}

int Segment::get_duration() const
{
	return this->notes.size() * 60 / this->bpm;
}

void Segment::play() const
{
	unsigned int pause_interval{ (unsigned int)(1 / (float)this->bpm * 60 * 1000) }; // in millisecond
	for (const auto note : this->notes) {
		this->send_key(note);
		Sleep(pause_interval);
	}
}

void Segment::parse(const std::string& portion)
{
	std::stringstream buffer{ portion };
	buffer >> this->bpm; // This raises a fail flag when it sees '-'
	buffer.ignore(1); // ignores '-'
	buffer.clear();
	buffer >> this->notes;
}

void Segment::send_key(char note) const
{
	INPUT ip;
	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.wVk = Segment::get_code(note);
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));
}