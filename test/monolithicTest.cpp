#include <gtest/gtest.h>

#include <map>
#include <string>
#include <vector>

#include "modules.h"

extern std::map<std::string, module> modules;

TEST(MonolithicTest, AllModules) {
	for (const auto &it : modules) {
		std::vector<std::string> args = {it.first, "debug"};
		ASSERT_NE(it.second, nullptr)
			<< "Command: " << it.first << " returns nullptr. Aborting...";
		EXPECT_EQ(0, it.second(args));
	}
}
