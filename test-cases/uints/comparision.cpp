#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main__0() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main__0() -> void
{
	bit x__;
	x__ = i32(1).as_uint__0()->op__less_than(i32(2).as_uint__0());
	x__ = i32(1).as_uint__0()->op__less_than_or_equal(i32(2).as_uint__0());
	x__ = i32(1).as_uint__0()->op__greater_than(i32(2).as_uint__0());
	x__ = i32(1).as_uint__0()->op__greater_than_or_equal(i32(2).as_uint__0());
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