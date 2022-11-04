#include <gtest/gtest.h>

#include <unordered_map>
#include <string>
#include <vector>

#include "modules.h"

extern const std::unordered_map<std::string, module> modules;

TEST(MonolithicTest, AllModules) {
	for (const auto& [name, func] : modules) {
		std::vector<std::string> args = {name, "debug"};
		ASSERT_NE(func, nullptr)
			<< "Command: " << name << " returns nullptr. Aborting...";
		EXPECT_EQ(0, func(args));
	}
}
