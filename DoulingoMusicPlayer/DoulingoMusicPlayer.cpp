// DoulingoMusicPlayer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "utils.h"

int main()
{
	// select a piece
	std::vector<std::string> file_names{};
	get_filenames(file_names);

	if (file_names.size() == 0) {
		std::cout << "You need a .txt containing the music notes." << '\n';
		std::cin.get();
		exit(1);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file