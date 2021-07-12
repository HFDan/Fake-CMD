#pragma once

#include <map>
#include <string>
#include "modules.h"

MODULEFUNC(tree);

MODULEFUNC(netstat);

std::map<std::string, module> modules = {

		{"tree",    tree},
		{"netstat", netstat}

};