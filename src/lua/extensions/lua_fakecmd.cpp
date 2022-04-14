// NOTE: This file is formatted like shit
// I hate myself
// TODO: Refactor this shit

#include <lua/extensions/lua_fakecmd.h>
#include <utility/utility.h>

#if defined(_WIN32)
#include <windows.h>
#elif defined(__linux__) 
#include <unistd.h>
#elif defined(__APPLE__)
#include <unistd.h>
#elif defined(__unix__)
#include <unistd.h>
#endif

#include <cstdlib>
#include <lua.hpp>
#include <string>
#include <fstream>

#pragma region Normal extensions
static int l_clear(lua_State* L) {
	system(CLEAR_COMMAND);
	return 0;
}

static int l_getDesktopDirectory(lua_State* L) {
#ifdef _WIN32
	hitFunctionStub(__FILE__, __LINE__);
#elif defined(__linux__)
	char username[32];
	getlogin_r(username, sizeof(username) / sizeof(*username));

	std::string dir = static_cast<std::string>("/home/") + username + "/Desktop/";
	lua_pushstring(L, dir.c_str());
#endif
	return 1;
}

static int l_getCurrentUser(lua_State* L) {
#ifdef _WIN32
	hitFunctionStub(__FILE__, __LINE__);
#else
	char username[32];
	getlogin_r(username, sizeof(username) / sizeof(*username));
	lua_pushstring(L, username);
#endif
	return 1;
}

/**
 * @brief Gets the OS that fakecmd is running on
 */
static int l_getOs(lua_State* L) {
#ifdef _WIN32
	lua_pushstring(L, "Windows");
#elif defined (__linux__)
	lua_pushstring(L, "Linux");
#elif defined (__APPLE__)
	lua_pushstring(L, "OSX");
#elif defined (__unix__)
	lua_pushstring(L, "Generic Unix-like");
#endif
	return 1;
}

#pragma endregion

#ifdef _WIN32
#pragma region Win32 Extensions
static int l_msgbox(lua_State* L) {
	const char* title = lua_tostring(L, 1);
	const char* content = lua_tostring(L, 2);
	MessageBoxA(NULL, title, content, MB_ICONERROR);
	return 0;
}
#pragma endregion

static const luaL_Reg fakecmd_win32 [] = {
	{"msgbox", l_msgbox},
	{NULL, NULL} // Sentinel
};
#endif

#pragma region Linux Extensions
#ifdef __linux__

static int l_getDistro(lua_State* L) {
	// This is a massive hack
	std::string ln;
	std::ifstream os_release("/etc/os-release");
	std::getline(os_release, ln);
	std::string distro = ln.substr(6, ln.length() - 7);
	lua_pushstring(L, distro.c_str());
	return 1;
}

static int l_msgbox (lua_State* L) {
	hitFunctionStub(__FILE__, __LINE__);
	return 0;
}

static const luaL_Reg fakecmd_unix [] = {
	{"getDistro", l_getDistro},
	{"msgbox", l_msgbox},
	{NULL, NULL}
};

#endif
#pragma endregion

static const luaL_Reg fakecmd_ext [] = {
	{"clear", l_clear},
	{"getOs", l_getOs},
	{"getCurrentUser", l_getCurrentUser},
	{"getDesktopDir", l_getDesktopDirectory},
	{NULL, NULL}
};

void l_fakecmd_loadluaextensions(lua_State* L) {
	//lua_newtable(L);
	//luaL_setfuncs(L, fakecmd_win32, 0);
	//lua_setglobal(L, "fakecmd_win32");

	//lua_newtable(L);
	//luaL_setfuncs(L, fakecmd_ext, 0);
	//lua_setglobal(L, "fakecmd_ext");

	luaL_newlib(L, fakecmd_ext);
	lua_setglobal(L, "fakecmd_ext");

#ifdef _WIN32
	luaL_newlib(L, fakecmd_win32);
	lua_setglobal(L, "fakecmd_win32");
#endif

#ifdef __linux__
	luaL_newlib(L, fakecmd_unix);
	lua_setglobal(L, "fakecmd_unix");
#endif
}
