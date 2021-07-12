#pragma once

#include <map>
#include <vector>
#include <string>

#define MODULEFUNC(x) int x(std::vector<std::string> argv)

typedef int(*module)(std::vector<std::string>);
