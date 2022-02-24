#pragma once

#ifdef DEBUG
#include <cstdio>
#include <ctime>
#define FCMD_DEBUGMSG(source, severity, msg, ...)                            \
	switch (severity) {                                                      \
		case 0:                                                              \
			printf("[INFO] [%s]: " msg "\n", source, __VA_ARGS__);           \
			break;                                                           \
                                                                             \
		case 1:                                                              \
			printf("[WARNING] [%s]: " msg "\n", source, __VA_ARGS__);        \
			break;                                                           \
                                                                             \
		case 2:                                                              \
			fprintf(stderr, "[ERROR] [%s]: " msg "\n", source, __VA_ARGS__); \
			break;                                                           \
	}

#else
#define FCMD_DEBUGMSG(...)
#endif