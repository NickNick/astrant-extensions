#include <sstream>
#include <string>

namespace astrant {
	using std::string;
	using std::stringstream;

	template <typename T>
	string to_string(T const& x){
		stringstream s;
		s << x;
		return s.str();
	}
}