#include "karl.h"

const char* karl_root()
{
	static char buffer[1024] = {0};
	static char* path = buffer+1023;
	if(!*path)
	{
		*--path = 'l';
		*--path = 'r';
		*--path = 'a';
		*--path = 'k';
		*--path = '.';

		int found = 0;
		while(path>buffer+3 && !(found = karl_file_exists(path)))
		{
			*--path = '/';
			*--path = '.';
			*--path = '.';
		}
		if(path<=buffer+3)
		{
			fprintf(stderr, "Couldn't find root directory .karl\n");
			exit(1);
		}
		printf("Root is \"%s\"\n", path);
	}
	return path;
}
