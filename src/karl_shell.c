#include "karl.h"

int karl_shell(const char* cmd)
{
	return system(cmd);
}
