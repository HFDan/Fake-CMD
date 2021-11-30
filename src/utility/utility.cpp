#include <utility/utility.h>
#include <modules/modules.h>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <memory>

#ifdef WIN32
	#include <windows.h>
	#include <shlobj.h>
	#include <winerror.h>
	#include <minwindef.h>
	std::string __GetModulePath() {
		std::string Path = "";
		LPSTR foo = new char[MAX_PATH];
		if (SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, foo) != S_OK) {
			printf("Error getting path.\n");
		}
		Path = std::string(foo) + std::string(R"(\.fake_cmd\)");
		delete [] foo;
		return Path;
	}

#else
	#include <unistd.h>

	std::string __GetModulePath() {
		std::string Path = "";
		char* Username = new char[32]; // The username char limit in linux is 32 char as per man useradd
		getlogin_r(Username, 32);

		Path = std::string(R"(/home/)") + std::string(Username) + std::string(R"(/.fake_cmd/)");

		delete [] Username;
		return Path;
	}
#endif

command tokenizeCommand(const std::string& input) {
	std::vector<std::string> tokens;
	std::stringstream check1(input);
	std::string intermediate;

	while (std::getline(check1, intermediate, ' ')) {
		tokens.push_back(intermediate);
	}

	return tokens;
}

void registerRuntimeCommands(std::map<std::string, module>& modules) {
	const std::filesystem::path path(__GetModulePath());

	if (!std::filesystem::exists(path) || !std::filesystem::is_directory(path)) { // Check if either the directory does not exist, or if it's not a directory, and create it.
		std::filesystem::create_directory(path);
	}

	for (const auto& entry : std::filesystem::directory_iterator{path}) { // For each file in the directory
		std::fstream file(entry.path(), std::ios::in); // TODO: Implement
	}

	
}

