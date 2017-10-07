#include "karl.h"

int karl_init(int argc, char** argv)
{
	const char* root = karl_root();
	if(root)
	{
		printf("Already in karl repository\n");
		return 1;
	}
	else
	{
		return karl_shell("mkdir .karl");
	}

}
