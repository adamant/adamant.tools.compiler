#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__1(system__console__Console__0 mut ref const console__);

// Class Declarations

// Global Definitions

// Definitions

void mut main__1(system__console__Console__0 mut ref const console__)
{
	string mut x__ = string__0op__add(string__0op__add(string__0op__add(((string){{6},(uint8_t*)u8"Hello "}), ((string){{7},(uint8_t*)u8"World! "})), int_to_string__1(((int32){4}))), code_point_to_string__1(((code_point){/*c*/0x63})));
	console_write_line__2(console__, x__);
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__1(allocate(sizeof(system__console__Console__0)));
	return 0;
}
