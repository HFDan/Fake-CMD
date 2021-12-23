#include <debug.h>
#include <modules/modules.h>
#include <modules/runtime_modules.h>
#include <utility/utility.h>

#include <chrono>
#include <iostream>
#include <map>
#include <string>
#include <thread>
#include <vector>

extern std::map<std::string, module> modules;
extern std::map<std::string, std::string> runtimeModules;

int main(int argc, char **argv) {
	FCMD_DEBUGMSG(
		"C++", 0, "Evaluated runtime module path is:\n%s\n",
		__GetModulePath().c_str());

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
		std::this_thread::sleep_for(std::chrono::milliseconds(
			100));	// TODO: This is bad practice, but it`s the only way to stop
					// a race condition between stderr and stdout
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
			fputs("Unknown Command\n", stderr);
			fflush(stderr);
		}
	}

	return 0;
}