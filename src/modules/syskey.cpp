#include <algorithm>
#include <cstdio>
#include <iterator>
#ifdef _WIN32
#include <windows.h>
#endif
#include "modules.h"

#ifndef _WIN32
MODULEFUNC(syskey) {
#ifndef NDEBUG  // Only print this while debugging. Do not rat yourself out.
    fputs("This module cannot run on macos/Linux, Sorry...\n", stderr);
#else
    fputs("Syskey has encountered a problem and must quit.\n", stderr);
#endif
    return 0;
}
#else
MODULEFUNC(syskey) {
    if (std::find(std::begin(argv), std::end(argv), "debug") == std::end(argv)) {
        MessageBox(
            NULL,
            "Syskey has encountered a problem and must quit.\nError code: "
            "B3nch0d",
            "Syskey",
            MB_OK | MB_ICONERROR);
    }

    return 0;
}
#endif