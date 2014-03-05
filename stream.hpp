#pragma once

#include <iostream>
#include <iomanip>

#define ASTRANT_STRING_CURRENT_PLACE_INFORMATION (std::string(__FILE__) + ":" + std::to_string(__LINE__) + "(" + __FUNCTION__ + ")")
#define ASTRANT_STREAM_CURRENT_PLACE_INFORMATION (std::string(__FILE__) + ":") << std::setw(4) << std::to_string(__LINE__) << "(" <<  std::setw(20) << __FUNCTION__ << ")"
#define ACOUT  std::cout << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << "\n"
#define ASDOUT std::cout << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << ": "
#define ACERR  std::cerr << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << "\n"
#define ASDERR std::cerr << ASTRANT_STREAM_CURRENT_PLACE_INFORMATION  << ": "

//! @{
//! @deprecated
#define COUT ACOUT
#define CERR ACERR
#define INFORMATION ASTRANT_STRING_CURRENT_PLACE_INFORMATION
#define VCOUT if(verbose) COUT
#define VCERR if(verbose) CERR
//! @}
