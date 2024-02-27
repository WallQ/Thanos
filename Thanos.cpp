#include "Thanos.h"

Thanos::Thanos() {}

Thanos::~Thanos() {}

bool Thanos::isDirectory(const std::string& path) {
	if (!fs::exists(path)) {
		std::cerr << "Error: Path does not exist" << std::endl;
		return false;
	}

	if (!fs::is_directory(path)) {
		std::cerr << "Error: Path is not a directory" << std::endl;
		return false;
	}

	return true;
}

void Thanos::processFile(const fs::directory_entry& entry) {
	if (rand() % 2) {
		if (remove(entry)) {
			std::cout << "File " << entry << " has been deleted." << std::endl;
		}
	}
}

void Thanos::processDirectory(const fs::path& path, int level) {
	if (isDirectory(path.string())) {
		for (const auto& entry : fs::directory_iterator(path)) {
			if (fs::is_directory(entry.status())) {
				processDirectory(entry, level + 1);
			}
			else if (fs::is_regular_file(entry.status())) {
				processFile(entry);
			}
		}
	}
}

void Thanos::snapFingers() {
	std::cout << "I am inevitable." << std::endl;
	processDirectory(DELETE_PATH, 0);
}