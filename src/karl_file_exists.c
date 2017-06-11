#include "karl.h"

int karl_file_exists(const char* path)
{
	char cmd[4096];
	sprintf(cmd, "test -e \"%s\"", path);
	return !karl_shell(cmd);
}
