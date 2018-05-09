#include "RuntimeLibrary.hpp"

// Type Declarations

// Function Declarations
auto main_() -> void;

// Class Declarations

// Global Definitions

// Definitions

auto main_() -> void
{
	bit x_;
	x_ = i32(1).as_uint_()->op_less_than(i32(2).as_uint_());
	x_ = i32(1).as_uint_()->op_less_than_or_equal(i32(2).as_uint_());
	x_ = i32(1).as_uint_()->op_greater_than(i32(2).as_uint_());
	x_ = i32(1).as_uint_()->op_greater_than_or_equal(i32(2).as_uint_());
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	try
	{
		main_();
		return 0;
	}
	catch(std::exception &ex)
	{
		std::printf("Program exited due to error:\n");
		std::printf("%s", ex.what());
		return 70;
	}
}