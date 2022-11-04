#pragma once
#include <modules/modules.h>

#include <sstream>
#include <string>
#include <vector>

#ifndef NDEBUG
#define hitFunctionStub(file, line) __hitFunctionStub(file, line)
void __hitFunctionStub(const char* file, int line);
#else
#define hitFunctionStub(file, line)
#endif

typedef std::vector<std::string> command;

command tokenizeCommand(const std::string& input);

std::string GetModulePath();
void registerRuntimeCommands();

