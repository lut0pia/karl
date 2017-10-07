#include "karl.h"

const char* karl_require_root()
{
	const char* root = karl_root();
	if(!root)
	{
		fprintf(stderr, "Could not find karl root\n");
		exit(1);
	}
	return root;
}

