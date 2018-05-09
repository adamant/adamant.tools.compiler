#include "RuntimeLibrary.hpp"

// Type Declarations
class t_C;

// Function Declarations
inline t_C *_Nonnull new_t_C();
auto main_() -> void;

// Class Declarations

class t_C
{
public:
	auto method_() const -> str;
	static auto function_() -> str;
	auto construct() -> t_C *_Nonnull { return this; }
};

// Global Definitions

// Definitions

auto ::t_C::method_() const -> str
{
	auto self = this;
	return function_();
}

auto ::t_C::function_() -> str
{
	return str("hello");
}

inline t_C *_Nonnull new_t_C()
{
	return (new t_C())->construct();
}

auto main_() -> void
{
	t_C const *_Nonnull const c_ = new_t_C();
	c_->method_();
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