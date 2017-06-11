#include "karl.h"

int karl_init(int argc, char** argv)
{
	return karl_shell("mkdir .karl");
}
