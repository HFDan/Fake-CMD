#include <debug.h>
#include <modules/modules.h>
#include <modules/runtime_modules.h>
#include <utility/utility.h>

#include <chrono>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

extern std::map<std::string, module> modules;
extern std::map<std::string, std::string> runtimeModules;

int main(int argc, char **argv) {
	registerRuntimeCommands();

	for (auto it : runtimeModules) {
		FCMD_DEBUGMSG(
			"C++", 0, "Available runtimeModule: %s", it.first.c_str());
	}

	puts(
		"Microsoft Windows [Version 10.0.69420.6789]\n(c) Microsoft "
		"Corporation. All rights reserved.\n");

	while (true) {
		std::string input;
		fputs("C:\\WINDOWS\\System32>", stdout);
		fflush(stdout);
		std::getline(std::cin, input);

		command cmd = tokenizeCommand(input);

		if (cmd.empty()) {
			continue;
		}

		if (cmd[0] == "exit") {
			break;

		} else if (modules.count(cmd[0]) > 0) {
			auto func = modules[cmd[0]];
			func(cmd);

		} else if (runtimeModules.count(cmd[0]) > 0) {
			executeRuntimeModule(runtimeModules[cmd[0]]);

		} else {
			fprintf(stderr, "\"%s\" is not recognized as an internal or external command, operable program or batch file\n", cmd[0].c_str());
			fflush(stderr);
		}
	}

	return 0;
}
