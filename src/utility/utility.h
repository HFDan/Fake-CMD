#pragma once
#include <vector>
#include <string>
#include <sstream>
#include <modules/modules.h>

typedef std::vector<std::string> command;

command tokenizeCommand(const std::string& input);

std::string __GetModulePath(); // TODO: Backend this function in the future
void registerRuntimeCommands(std::map<std::string, module>& modules);