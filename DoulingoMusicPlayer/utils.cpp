#include <vector>
#include <string>
#include <filesystem>
#include <iostream>

void get_filenames(std::vector<std::string>& file_names) {
	// pushes back all files in cwd to the vector passed in
	namespace fs = std::filesystem;
	for (auto& p : fs::directory_iterator(fs::current_path())) {
		const std::string ext{ p.path().extension().string() };
		if (ext == ".txt") file_names.push_back(p.path().string());
	}
}
