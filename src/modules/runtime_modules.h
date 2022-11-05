#pragma once
#include <string_view>

#ifdef LUASUPPORT
void executeRuntimeModule(std::string_view file);
void registerRuntimeCommands();
#endif