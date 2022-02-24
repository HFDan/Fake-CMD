#include "modules.h"

#include <map>
#include <string>

MODULEFUNC(tree);

MODULEFUNC(netstat);

MODULEFUNC(syskey);

MODULEFUNC(help);

std::map<std::string, module> modules = {

	{"tree", tree}, 
	{"netstat", netstat},
	{"syskey", syskey},
	{"help", help}

};
