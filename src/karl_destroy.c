#include "karl.h"

int karl_destroy(int argc, char** argv)
{
	char cmd[4096];
	sprintf(cmd, "rm -r \"%s\"", karl_root());
	karl_shell(cmd);
	return 0;
}
