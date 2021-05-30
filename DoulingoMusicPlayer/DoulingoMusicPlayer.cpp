// DoulingoMusicPlayer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

#include "utils.h"
#include "Piece.h"

int main()
{
	// check for .txt files in the cwd
	std::vector<std::string> file_names{};
	get_filenames(file_names);

	// no .txt is found
	const unsigned int size{ file_names.size() };
	if (size == 0) {
		std::cout << "You need a .txt containing music notes." << '\n';
		std::ignore = _getch();
		exit(1);
	}

	// select a piece
	if (size == 1) {
		const auto& name{ file_names.at(0) };
		std::cout << "Found 1 piece.\n" << file_names.at(0) << "\nPress any key to start.\n";
		const Piece p{ name };
		std::ignore = _getch();
		p.play();
	}
	else {
		int count{ 1 };
		int selected{};
		while (true) {
			std::cout << "Found " << size << " pieces.\nSelect a number below.\n";
			for (const auto& name : file_names) {
				std::cout << count++ << " - " << name << '\n';
			}

			selected = std::cin.get();
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(LLONG_MAX, '\n');
				count = 1;
				system("cls");
				continue;
			}
			if (selected < 1 || selected > size) {
				count = 1;
				system("cls");
				continue;
			}

			break;
		}

		std::cout << "Press any key to start.\n";
		const Piece p{ file_names.at(selected - 1) }; // selected starts at 1, not 0
		std::ignore = _getch();
		p.play();
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