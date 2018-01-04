#include "RuntimeLibrary.h"

// Type Declarations

// Function Declarations
auto Main_() -> p_int;

// Class Declarations

// Global Definitions

// Definitions

auto Main_() -> p_int
{
	p_int result_;
	result_ = p_int(42);
	result_->op_AddAssign(p_int(1));
	result_->op_SubtractAssign(p_int(1));
	return result_;
}

// Entry Point Adapter
std::int32_t main(int argc, char const *const * argv)
{
	return Main_().Value;
}