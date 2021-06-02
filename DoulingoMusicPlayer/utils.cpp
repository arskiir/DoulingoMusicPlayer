#include <vector>
#include <filesystem>

#include "Piece.h"

void get_all_pieces(std::vector<Piece>& all_pieces)
{
	// pushes back all pieces constructed from files that end with .txt
	namespace fs = std::filesystem;
	for (auto& p : fs::directory_iterator(fs::current_path()))
	{
		const std::string ext{ p.path().extension().string() };
		if (ext == ".txt")
			all_pieces.emplace_back(p.path().string());
	}
}