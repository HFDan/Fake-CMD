#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <random>
#include "modules.h"


MODULEFUNC(tree) {

	std::random_device randomDevice;
	std::mt19937 rng(randomDevice());
	std::uniform_int_distribution<std::mt19937::result_type> distribution(100, 500);

	for (unsigned long long int i = 0; i < distribution(rng); i++) {

		system("cls");
		printf("Scanning file %llu", i);

	}

	system("cls");
	printf(u8"\nAll files scanned:\n\n|___________|___________|______________|__________________________|\n|  Viruses  |  Hackers  | IP Infection |        Conclusion        |\n|___________+___________+______________+__________________________|\n| 0         | 0         | None         | PC: Healthy              |\n| All Clear | All Clear | All Clear    | Tech Support: Not needed |\n|           |           |              |                          |\n|___________|___________|______________|__________________________|\n\n\n");
	system("pause");
	system("cls");
}