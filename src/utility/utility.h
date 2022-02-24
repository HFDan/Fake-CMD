#pragma once
#include <modules/modules.h>

#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::string> command;

command tokenizeCommand(const std::string& input);

// std::string __GetModulePath();
// // Function has been backended
void registerRuntimeCommands();