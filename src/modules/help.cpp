#include <cstdio>
#include <string>
#include <unordered_map>
#include "modules.h"

extern const std::unordered_map<std::string, module> modules;
extern std::unordered_map<std::string, std::string> runtimeModules;

MODULEFUNC(help) {

	puts("Available commands:");
	for (const auto& [name, func] : modules) {
		printf("%s\n", name.c_str());
	}	
	for (const auto& [name, func] : runtimeModules) {
		printf("%s\n", name.c_str());
	}

	return 0;
}
