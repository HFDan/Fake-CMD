#include <string>

#include "lua.hpp"

void executeRuntimeModule(std::string file) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);

	int err = luaL_dofile(L, file.c_str());

	if (err == LUA_OK) {
	} else {
		std::string errormsg = lua_tostring(L, -1);
		fprintf(stderr, "[LUA]: %s\n", errormsg.c_str());
	}
	lua_close(L);
}