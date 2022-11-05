#pragma once
#ifdef LUASUPPORT
#include <lua.hpp>

void l_fakecmd_loadluaextensions(lua_State* L);
#endif
