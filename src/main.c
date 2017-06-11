#include <stdio.h>
#include "karl.h"

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		karl_help(0, NULL);
		return 1;
	}
	else if(!strcmp(argv[1], "help"))
	{
		return karl_help(argc-2, argv+2);
	}
	else if(!strcmp(argv[1], "init"))
	{
		return karl_init(argc-2, argv+2);
	}
	else if(!strcmp(argv[1], "destroy"))
	{
		return karl_destroy(argc-2, argv+2);
	}
	else if(!strcmp(argv[1], "ls"))
	{
		return karl_ls(argc-2, argv+2);
	}
	return 1;
}
