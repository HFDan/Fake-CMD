#include <debug.h>
#include <lua/extensions/lua_fakecmd.h>
#include <utility/utility.h>

#include <string_view>
#include <string>
#include <unordered_map>
#include <filesystem>

#ifdef LUASUPPORT
#include "lua.hpp"
extern std::unordered_map<std::string, std::string> runtimeModules;

void executeRuntimeModule(std::string_view file) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	l_fakecmd_loadluaextensions(L);

	if (int err = luaL_dofile(L, file.data()) != LUA_OK) {
		std::string errormsg = lua_tostring(L, -1);
		FCMD_DEBUGMSG("LUA", 2, "%s", errormsg.c_str());
	}
	lua_close(L);
}

void registerRuntimeCommands() {
	const std::filesystem::path path(GetModulePath());

	if (!std::filesystem::exists(path) ||
		!std::filesystem::is_directory(
			path)) {  // Check if either the directory does not exist, or if
					  // it's not a directory, and create it.
		std::filesystem::create_directory(path);
	}

	for (const auto& entry : std::filesystem::directory_iterator{path}) {  // For each file in the directory 
        if (entry.path().filename().extension().generic_string() == ".lua") {
            const std::string name = entry.path().filename().replace_extension("").generic_string();
            const std::string filePath = entry.path().generic_string();
            runtimeModules.try_emplace(name, filePath);
        }
	}
}
#endif