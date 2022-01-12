#pragma once

#include <map>
#include <string>
#include <vector>

#define MODULEFUNC(x) int x(std::vector<std::string> argv)

typedef int (*module)(std::vector<std::string>);
