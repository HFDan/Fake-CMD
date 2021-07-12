#include "utility.h"
#include <vector>
#include <string>
#include <sstream>

command tokenizeCommand(const std::string& input) {
	std::vector<std::string> tokens;
	std::stringstream check1(input);
	std::string intermediate;

	while (std::getline(check1, intermediate, ' ')) {
		tokens.push_back(intermediate);
	}

	return tokens;
}
