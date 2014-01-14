#pragma once

#include <iostream>

#define INFORMATION (std::string(__FILE__) + ":" + std::to_string(__LINE__) + "(" + __FUNCTION__ + ")")
#define COUT std::cout << INFORMATION << "\n"
#define CERR std::cerr << INFORMATION << "\n"

#define ACOUT COUT
#define ACERR CERR

#define VCOUT if(verbose) COUT
#define VCERR if(verbose) CERR
