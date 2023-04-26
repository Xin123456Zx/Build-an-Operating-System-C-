#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

char **manipulate_args(int argc, const char *const *argv, int (*const manip)(int))
{
	char **p;
	p=(char **)malloc((argc+1)*sizeof(char*));
	for(int i=0;i<argc;i++)
	{
		p[i]=(char *)malloc((strlen(argv[i])+1)*sizeof(char));
		for(int j=0;j<=(int)strlen(argv[i]);j++)
		{
			p[i][j]=manip(argv[i][j]);
		//	printf("i is %d,j is %d,%c\n",i,j,p[i][j]);
		}
	}
	p[argc]=NULL;
	return p;
}

void free_copied_args(char **args, ...)
{
	va_list x;
	va_start (x,args);

	while(args!=NULL)
	{
		int i=0;
		while(args[i]!=NULL)
		{
			free(args[i]);
			args[i]=NULL;
			++i;
		}
		if(args!=NULL)
		{
			free(args);
		}

		args=va_arg(x,char **);

	}
	va_end(x);

}




