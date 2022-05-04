#include <chrono>
#include <cstdio>
#include <random>
#include <thread>

#include "modules.h"

MODULEFUNC(tree) {
	std::random_device randomDevice;
	std::mt19937 rng(randomDevice());
	std::uniform_int_distribution<std::mt19937::result_type> distribution(
		100, 500);

	for (unsigned long long int i = 0; i < distribution(rng); i++) {
		system(CLEAR_COMMAND);
		printf("Scanning file %llu", i);
		fflush(stdout);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	system(CLEAR_COMMAND);
	// clang-format off
	printf(
R"(All files scanned:

_________________________________________________________________
|  Viruses  |  Hackers  | IP Infection |        Conclusion        |
|___________+___________+______________+__________________________|
| 0         | 0         | None         | PC: Healthy              |
| All Clear | All Clear | All Clear    | Tech Support: Not needed |
|           |           |              |                          |
|___________|___________|______________|__________________________|)"
	);
	// clang-format on
	fflush(stdout);
	std::this_thread::sleep_for(std::chrono::seconds(10));
	system(CLEAR_COMMAND);

	return 0;
}