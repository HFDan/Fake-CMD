#include "modules.h"

MODULEFUNC(netstat) {
	// clang-format off
	printf(
R"(  Proto  Local Address          Foreign Address        State
TCP    127.0.0.1:69                                  NO_HACKERS_DETECTED 
TCP    142.250.74.20:443                             NO_HACKERS_DETECTED 
TCP    127.0.0.1:54332                               NO_HACKERS_DETECTED 
UDP    127.0.0.1:543434                              NO_HACKERS_DETECTED 
TCP    127.0.0.1:5435345                             NO_HACKERS_DETECTED 
TCP    127.0.0.1:543543                              NO_HACKERS_DETECTED 
UDP    127.0.0.1:765232                              NO_HACKERS_DETECTED
TCP    127.0.0.1:42344                               NO_HACKERS_DETECTED
TCP    127.0.0.1:4324                                NO_HACKERS_DETECTED
UDP    127.0.0.1:420                                 NO_HACKERS_DETECTED)"
"\n"
   	);
	// clang-format on

	return 0;
}
