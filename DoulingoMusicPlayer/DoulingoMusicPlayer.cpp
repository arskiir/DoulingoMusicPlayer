// DoulingoMusicPlayer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <map>

#include "utils.h"
#include "Piece.h"
#include "Segment.h"

std::map<char, int> Segment::key_map;

int main()
{
	// init key map
	Segment::initialize_key_map(Segment::key_map);

	// check for .txt files in the cwd
	std::vector<Piece> all_pieces{};
	get_all_pieces(all_pieces);

	// no .txt is found
	const unsigned int size{ all_pieces.size() };
	if (size == 0)
	{
		std::cout << "You need a .txt containing music notes.\n";
		std::ignore = _getch();
		exit(1);
	}

	// select a piece
	if (size == 1)
	{
		const auto& name{ all_pieces.at(0) };
		std::cout << "Found 1 piece.\n"
			<< all_pieces.at(0).str() << "\nPress any key to start.\n";
		std::ignore = _getch();
		all_pieces.at(0).play();
	}
	else
	{
		int count{ 1 };
		unsigned int selected;
		while (true)
		{
			std::cout << "Found " << size << " pieces.\nSelect a number below.\n";
			for (const auto& p : all_pieces)
			{
				std::cout << p.str();
			}

			std::cin >> selected;
			if (std::cin.fail())
			{
				std::cin.clear();
				std::cin.ignore(LLONG_MAX, '\n');
				count = 1;
				system("cls");
				continue;
			}
			if ((selected < 1) || (selected > size))
			{
				count = 1;
				system("cls");
				continue;
			}

			break;
		}

		std::cout << "Press any key to start.\n";
		std::ignore = _getch();
		all_pieces.at(selected - 1).play();
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