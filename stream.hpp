#pragma once

#include <iostream>

#define INFORMATION __FILE__ << ":" << __LINE__ << "(" << __FUNCTION__ << ")"
#define ACOUT std::cout << INFORMATION << "\n"
#define ACERR std::cerr << INFORMATION << "\n"
