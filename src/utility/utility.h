#pragma once
#include <modules/modules.h>

#include <sstream>
#include <string>
#include <vector>

typedef std::vector<std::string> command;

command tokenizeCommand(const std::string& input);

std::string __GetModulePath();	// TODO: Backend this function in the future
void registerRuntimeCommands();