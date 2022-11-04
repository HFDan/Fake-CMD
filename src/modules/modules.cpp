#include "modules.h"

#include <unordered_map>
#include <string>

MODULEFUNC(tree);

MODULEFUNC(netstat);

MODULEFUNC(syskey);

MODULEFUNC(help);

extern const std::unordered_map<std::string, module> modules = {

	{"tree", tree}, 
	{"netstat", netstat},
	{"syskey", syskey},
	{"help", help}

};
