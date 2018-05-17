#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	i32 x__;
	x__ = i32(1).op__add(i32(3).op__subtract(i32(1))->op__divide(i32(2)));
	x__ = i32(1).op__add(i32(3))->op__subtract(i32(1).op__divide(i32(2)));
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main__0();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}