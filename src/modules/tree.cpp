#include <cstdio>
#include <chrono>
#include <thread>
#include <random>
#include "modules.h"

#if WIN32
const char* CLEAR_COMMAND = "cls";
#else
const char* CLEAR_COMMAND = "clear";
#endif

MODULEFUNC(tree) {
	// TODO: This function seems to not work, atleast under linux
	std::random_device randomDevice;
	std::mt19937 rng(randomDevice());
	std::uniform_int_distribution<std::mt19937::result_type> distribution(100, 500);

	for (unsigned long long int i = 0; i < distribution(rng); i++) {

		system(CLEAR_COMMAND);
		printf("Scanning file %llu", i);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));

	}

	system(CLEAR_COMMAND);
	printf(u8"\nAll files scanned:\n\n|___________|___________|______________|__________________________|\n|  Viruses  |  Hackers  | IP Infection |        Conclusion        |\n|___________+___________+______________+__________________________|\n| 0         | 0         | None         | PC: Healthy              |\n| All Clear | All Clear | All Clear    | Tech Support: Not needed |\n|           |           |              |                          |\n|___________|___________|______________|__________________________|\n\n\n");
	std::this_thread::sleep_for(std::chrono::seconds(10));
	system(CLEAR_COMMAND);

	return 0;
}