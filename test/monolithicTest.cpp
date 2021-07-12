#include <gtest/gtest.h>
#include <map>
#include <string>
#include <vector>
#include "modules.h"
#include "utility/utility.h"

extern std::map<std::string, module> modules;

TEST(MonolithicTest, ArgumentParser) {
	std::string withArgs = "command -s -t -i -a -l";
	std::vector<std::string> withArgsV = {"command", "-s", "-t", "-i", "-a", "-l"};
	ASSERT_EQ(withArgsV, tokenizeCommand(withArgs));

	std::string withoutArgs = "command";
	std::vector<std::string> withoutArgsV = {"command"};
	ASSERT_EQ(withoutArgsV, tokenizeCommand(withoutArgs));
}

TEST(MonolithicTest, AllModules) {
	for (const auto &it : modules) {
		std::vector<std::string> args = {it.first};
		ASSERT_NE(it.second, nullptr) << "Command: " << it.first << " returns nullptr. Aborting...";
		EXPECT_EQ(0, it.second(args));
	}
}
