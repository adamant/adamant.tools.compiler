#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type_ID = 0,
};
typedef enum Type_ID Type_ID;

// Type Declarations

// Function Declarations
void mut main__0();

// Class Declarations

// Global Definitions

// Definitions

void mut main__0()
{
	string__0new__1(((string){{3},(uint8_t*)u8"foo"}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}
