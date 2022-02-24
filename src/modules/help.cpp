#include <cstdio>
#include <string>
#include <map>
#include "modules.h"

extern std::map<std::string, module> modules;
extern std::map<std::string, std::string> runtimeModules;

MODULEFUNC(help) {

	puts("Available commands:");
	for (auto it : modules) {
		printf("%s\n", it.first.c_str());
	}	
	for (auto it : runtimeModules) {
		printf("%s\n", it.first.c_str());
	}

	return 0;
}
