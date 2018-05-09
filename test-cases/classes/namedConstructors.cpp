#include "RuntimeLibrary.hpp"

// Type Declarations
class t_C;

// Function Declarations
inline t_C *_Nonnull new_t_C(str const name_);
inline t_C *_Nonnull new_t_C__one(str const name_);
inline t_C *_Nonnull new_t_C__two(str const name_);
auto main_() -> void;

// Class Declarations

class t_C
{
public:
	str name_;
	i32 kind_;
	auto construct(str const name_) -> t_C *_Nonnull;
	auto construct_one(str const name_) -> t_C *_Nonnull;
	auto construct_two(str const name_) -> t_C *_Nonnull;
};

// Global Definitions

// Definitions

auto t_C::construct(str const name_) -> t_C *_Nonnull
{
	t_C *_Nonnull self = this;
	self->name_ = name_;
	self->kind_ = i32(0);
	return self;
}

inline t_C *_Nonnull new_t_C(str const name_)
{
	return (new t_C())->construct(name_);
}

auto t_C::construct_one(str const name_) -> t_C *_Nonnull
{
	t_C *_Nonnull self = this;
	self->name_ = name_;
	self->kind_ = i32(1);
	return self;
}

inline t_C *_Nonnull new_t_C__one(str const name_)
{
	return (new t_C())->construct_one(name_);
}

auto t_C::construct_two(str const name_) -> t_C *_Nonnull
{
	t_C *_Nonnull self = this;
	self->name_ = name_;
	self->kind_ = i32(2);
	return self;
}

inline t_C *_Nonnull new_t_C__two(str const name_)
{
	return (new t_C())->construct_two(name_);
}

auto main_() -> void
{
	new_t_C(str("0"));
	new_t_C__one(str("1"));
	new_t_C__two(str("2"));
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