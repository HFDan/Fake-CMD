#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <stdexcept>
#include <chrono>
#include "modules/modules.h"

extern std::map<std::string, module> modules;

int main(int argc, char** argv) {

	puts("Microsoft Windows [Version 10.0.69420.6789]\n(c) Microsoft Corporation. All rights reserved.\n");

	while (true) {

		std::string input;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		fputs("C:\\WINDOWS\\System32>", stdout);
		fflush(stdout);
		std::cin >> input;

		if (input == "exit") {
			break;

		} else if(modules.count(input) > 0) {
			auto func = modules[input];
			func();
		} else {
			fputs("Unknown Command\n", stderr);
			fflush(stderr);
		}

	}

	return 0;

}