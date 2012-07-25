#pragma once

#include <iostream>

#define INFORMATION __FILE__ << ":" << __LINE__ << "(" << __FUNCTION__ << ")"
#define COUT std::cout << INFORMATION << "\n"
#define CERR std::cerr << INFORMATION << "\n"

#define VCOUT if(verbose) COUT
#define VCERR if(verbose) CERR
