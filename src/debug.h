#pragma once

#ifdef DEBUG
#include <cstdio>
#include <ctime>
static constexpr const char* debugMsgLevels[] = {
	"INFO",
	"WARNING",
	"ERROR"
};

#define FCMD_DEBUGMSG(source, severity, msg, ...)\
	printf("[%s] [%s]: " msg "\n", debugMsgLevels[severity],source, __VA_ARGS__)\

#else
#define FCMD_DEBUGMSG(...)
#endif
