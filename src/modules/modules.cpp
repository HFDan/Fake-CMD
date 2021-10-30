#include <map>
#include <string>
#include "modules.h"

MODULEFUNC(tree);

MODULEFUNC(netstat);

MODULEFUNC(syskey);

std::map<std::string, module> modules = {

		{"tree",    tree},
		{"netstat", netstat},
		{"syskey", 	syskey}

};