#include "RuntimeLibrary.h"

// Type ID Declarations
enum Type_ID
{
	never__0Type__ID = 0,
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
	int32 mut x__ = int32__0op__mul(((int32){1}), ((int32){2}));
}

// Entry Point Adapter
int32_t main(int argc, char const ptr const ptr argv)
{
	main__0();
	return 0;
}