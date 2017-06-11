#include "karl.h"

int karl_help(int argc, char** argv)
{
	printf("Karl -- P2P file-sharing gone wrong\n");
	printf("\tkarl init: set root of karl directory\n");
	printf("\tkarl destroy: destroy karl directory\n");
	printf("\tkarl ls: list files in current karl directory\n");
	return 0;
}
