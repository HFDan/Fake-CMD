#include <debug.h>
#include <modules/modules.h>
#include <utility/utility.h>

#include <filesystem>
#include <fstream>
#include <unordered_map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

extern std::unordered_map<std::string, std::string> runtimeModules;

#ifdef _WIN32
#include <Shlobj.h>
#include <windows.h>
std::string GetModulePath() {
	std::string Path = "";
	LPSTR foo = new char[MAX_PATH];
	if (SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, foo) != S_OK) {
		printf("Error getting path.\n");
	}
	Path = std::string(foo) + std::string(R"(\.fake_cmd\)");
	delete[] foo;
	return Path;
}

#else
#include <unistd.h>

std::string GetModulePath() {
	std::string Path = "";
	auto Username = new char[32];	// The username char limit in linux is 32
									// chars as per man useradd
	getlogin_r(Username, 32);

	Path = std::string(R"(/home/)") + std::string(Username) +
		   std::string(R"(/.fake_cmd/)");

	delete[] Username;
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

void __hitFunctionStub(const char* file, int line) {
	FCMD_DEBUGMSG("C++", 1, "Hit function stub in file %s at line %i", file, line);	
}
