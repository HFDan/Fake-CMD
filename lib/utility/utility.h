#pragma once
#include <vector>
#include <string>
#include <sstream>

typedef std::vector<std::string> command;

command tokenizeCommand(const std::string& input);