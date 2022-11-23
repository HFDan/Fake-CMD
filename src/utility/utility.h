#pragma once
#include <debug.h>
#include <modules/modules.h>

#include <sstream>
#include <string>
#include <vector>

#ifndef NDEBUG
#define hitFunctionStub(file, line) FCMD_DEBUGMSG("C++", 1, "Hit function stub in file %s at line %i", file, line);
#else
#define hitFunctionStub(file, line)
#endif

typedef std::vector<std::string> command;

command tokenizeCommand(const std::string& input);

#ifdef LUASUPPORT
std::string GetModulePath();
#endif
