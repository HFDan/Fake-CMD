#pragma once
#include <map>
#include <string>
#include "modules.h"

MODULEFUNC(tree);

std::map<std::string, module> modules = {

		{"tree", tree}

};