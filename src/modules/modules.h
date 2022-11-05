#pragma once

#include <map>
#include <string>
#include <vector>

#define MODULEFUNC(x) int x(std::vector<std::string> argv)

using module = int (*)(std::vector<std::string>);
