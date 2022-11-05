#include <cstdio>
#include <string>
#include <unordered_map>
#include "modules.h"

extern const std::unordered_map<std::string, module> modules;
#ifdef LUASUPPORT
extern std::unordered_map<std::string, std::string> runtimeModules;
#endif

MODULEFUNC(help) {

	puts("Available commands:");
	for (const auto& [name, func] : modules) {
		printf("%s\n", name.c_str());
	}	
    #ifdef LUASUPPORT
	for (const auto& [name, func] : runtimeModules) {
		printf("%s\n", name.c_str());
	}
    #endif

	return 0;
}
