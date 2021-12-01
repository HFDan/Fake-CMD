#include "runtime_modules.h"

#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

enum Instruction {
	PRNT = 0b10,
	INPT = 0b11,
	TOP = 0b00,
	BTM = 0b01,
	NXT = 0b110,
	PRV = 0b111,
	POP = 0b100,
	ADD = 0b1001,
	SUB = 0b1010,
	MUL = 0b1011,
	DIV = 0b1100,
	CLEAR = 0b1111,
	PUT = 0b1110
};

static std::map<std::string, Instruction> instructionTable{
	{"PRNT", Instruction::PRNT}, {"INPT", Instruction::INPT},
	{"TOP", Instruction::TOP},	 {"BTM", Instruction::BTM},
	{"NXT", Instruction::NXT},	 {"PRV", Instruction::PRV},
	{"POP", Instruction::POP},	 {"ADD", Instruction::ADD},
	{"SUB", Instruction::SUB},	 {"MUL", Instruction::MUL},
	{"DIV", Instruction::DIV},	 {"CLEAR", Instruction::CLEAR},
	{"PUT", Instruction::PUT}};

std::vector<std::string> stack;
size_t sp = 0;

void executeInstruction(Instruction i, std::vector<std::string> argv) {
	switch (i) {
		case Instruction::PRNT:
			for (auto it : argv) {
				printf("%s", it.c_str());
			}
			printf("\n");
			fflush(stdout);
			break;

		case Instruction::INPT: {
			std::string foo;
			std::getline(std::cin, foo);
			stack.push_back(foo);
			break;
		}

		case Instruction::TOP:
			sp = stack.size();
			break;

		case Instruction::BTM:
			sp = 0;
			break;

		case Instruction::NXT:
			if (sp != stack.size()) sp++;
			break;

		case Instruction::PRV:
			if (sp != 0) sp--;
			break;

		case Instruction::POP:
			stack.pop_back();
			if (sp >= stack.size()) sp = stack.size();
			break;

		case Instruction::ADD:
			if (!(sp >= stack.size())) {
				long long int res = std::stoll(stack[sp]) + std::stoll(argv[0]);
				stack[sp] = std::to_string(res);
			}
			break;

		case Instruction::SUB:
			if (!(sp >= stack.size())) {
				long long int res = std::stoll(stack[sp]) - std::stoll(argv[0]);
				stack[sp] = std::to_string(res);
			}
			break;

		case Instruction::MUL:
			if (!(sp >= stack.size())) {
				long long int res = std::stoll(stack[sp]) * std::stoll(argv[0]);
				stack[sp] = std::to_string(res);
			}
			break;

		case Instruction::DIV:
			if (!(sp >= stack.size())) {
				long long int res = std::stoll(stack[sp]) / std::stoll(argv[0]);
				stack[sp] = std::to_string(res);
			}
			break;

		case Instruction::CLEAR:
			stack.clear();
			sp = stack.size();
			break;

		case Instruction::PUT:
			printf("%s\n", stack[sp].c_str());
			break;

		default:
			fprintf(stderr, "Invalid instruction: 0x%x. Terminating...\n", i);
			std::terminate();
			break;
	}
}

void executeRuntimeModule(const std::string& filepath) {
	std::ifstream infile(filepath);
	std::string line;
	bool keepSpace = false;
	std::vector<std::string> args;
	while (getline(infile, line)) {
		std::string tok;
		std::string command;
		Instruction inst;
		size_t start_from = 0;
		for (auto it : line) {
			if (it == ' ') {
				start_from++;
				break;
			} else {
				command += it;
				start_from++;
			}
		}

		if (command == "PRNT") {
			inst = instructionTable[command];
			keepSpace = true;
		} else {
			inst = instructionTable[command];
		}

		for (size_t i = start_from; i < line.size(); i++) {
			if (std::isspace(line[i])) {
				if (keepSpace) {
					tok += ' ';
				}
				args.push_back(tok);
				tok.clear();
			} else {
				tok += line[i];
			}
		}
		args.push_back(tok);

		executeInstruction(inst, args);
	}
}