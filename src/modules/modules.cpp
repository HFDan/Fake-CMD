#include "modules.h"

#include <string>
#include <unordered_map>

MODULEFUNC(tree);

MODULEFUNC(netstat);

MODULEFUNC(syskey);

MODULEFUNC(help);

extern const std::unordered_map<std::string, module> modules = {

    {"tree", tree}, {"netstat", netstat}, {"syskey", syskey}, {"help", help}

};
