#include <gtest/gtest.h>
#include <map>
#include <string>
#include <modules.h>

extern std::map<std::string, module> modules;

TEST(MonolithicTest, AllModules) {


	for (const auto& it : modules) {
		ASSERT_NE(it.second, nullptr) << "Command: " << it.first << " returns nullptr. Aborting...";
		EXPECT_EQ(0, it.second());

	}


}