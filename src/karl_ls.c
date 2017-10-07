#include "karl.h"

int karl_ls(int argc, char** argv)
{
	const char* root = karl_require_root();
	printf("Wow there are no files... *wink*\nRoot is %s\n", root);
	return 0;
}
