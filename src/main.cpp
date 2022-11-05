#include <debug.h>
#include <modules/modules.h>
#include <modules/runtime_modules.h>
#include <utility/utility.h>

#include <chrono>
#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <string>
#include <thread>
#include <vector>

#ifdef COMPILETIMEMODULES
extern const std::unordered_map<std::string, module> modules;
#endif

#ifdef LUASUPPORT
extern std::unordered_map<std::string, std::string> runtimeModules;
#endif

int main(int argc, char **argv) {
    #ifdef LUASUPPORT
	registerRuntimeCommands();

	for (const auto& [name, func] : runtimeModules) {
		FCMD_DEBUGMSG(
			"C++", 0, "Available runtimeModule: %s", name.c_str());
	}
    #endif

	puts(
		"Microsoft Windows [Version 10.0.69420.6789]\n(c) Microsoft "
		"Corporation. All rights reserved.\n");

    std::string input;
    // Doing it like this allows you to quit with Ctrl+D on linux
	while (fputs("C:\\WINDOWS\\System32>", stdout) && std::getline(std::cin, input)) {
		fflush(stdout);

		command cmd = tokenizeCommand(input);

		if (cmd.empty()) {
			continue;
		}

		if (cmd[0] == "exit") {
			break;

		} 

        #ifdef COMPILETIMEMODULES
        else if (modules.contains(cmd[0])) {
			auto func = modules.at(cmd[0]);
			func(cmd);

		}
        #endif

        #ifdef LUASUPPORT
        else if (runtimeModules.contains(cmd[0])) {
			executeRuntimeModule(runtimeModules[cmd[0]]);

		}
        #endif
        else {
			fprintf(stderr, "\"%s\" is not recognized as an internal or external command, operable program or batch file\n", cmd[0].c_str());
			fflush(stderr);
		}
	}

	return 0;
}
