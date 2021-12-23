#include <debug.h>

#include <string>

#include "lua.hpp"

void executeRuntimeModule(std::string file) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	int err = luaL_dofile(L, file.c_str());

	if (err != LUA_OK) {
		std::string errormsg = lua_tostring(L, -1);
		FCMD_DEBUGMSG("LUA", 2, "%s", errormsg.c_str());
	}
	lua_close(L);
}