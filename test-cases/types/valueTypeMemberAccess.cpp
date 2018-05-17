#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> i32;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> i32
{
	string const s__ = string("abc");
	return s__.index_of__1(code_point('c'));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		return main__0().value;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}