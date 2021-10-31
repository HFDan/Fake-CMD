#include <utility/utility.h>
#include <modules/modules.h>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <memory>
#include <yaml-cpp/yaml.h>

#ifdef WIN32
	#include <windows.h>
	#include <shlobj.h>
	#include <winerror.h>
	#include <minwindef.h>
	std::string __GetModulePath() {
		std::string path = "";
		LPSTR foo = new char[MAX_PATH];
		if (SHGetFolderPath(NULL, CSIDL_PROFILE, NULL, 0, foo) != S_OK) {
			printf("Error getting path.\n");
		}
		path = std::string(foo) + std::string(R"(\.fake_cmd\)");
		delete [] foo;
		return path;
	}

#else
	#include <unistd.h>

	std::string __GetModulePath() {
		std::string path = "";
		char* username = new char[32]; // The username char limit in linux is 32 char as per man useradd
		getlogin_r(username, 32);

		path = std::string(R"(/home/)") + std::string(username) + std::string(R"(/.fake_cmd/)");

		delete [] username;
		return path;
	}

	const std::filesystem::path ModulePath(__GetModulePath());
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
	
}

