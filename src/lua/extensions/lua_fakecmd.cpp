#include <lua/extensions/lua_fakecmd.h>

#include <cstdlib>
#include <lua.hpp>

static int l_clear(lua_State* L) {
	system("clear");
	return 0;
}

void l_fakecmd_loadluaextensions(lua_State* L) {
	lua_pushcfunction(L, l_clear);
	lua_setglobal(L, CLEAR_COMMAND);
}