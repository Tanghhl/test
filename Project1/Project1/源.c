#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
int countc(char *file) //返回文件的字符数 
{
	int cchar = 0;
	FILE *f;
	f = fopen(file, "r");
	char a;
	if (NULL == (f = fopen(file, "r")))
	{
		printf("file is NULL");
	}
	else
		while (!feof(f))
		{
			a = fgetc(f);
			if (a != ' '&&a != '\n'&&a != '\t')
				cchar++;
		}
	fclose(f); printf("charnum:%d ", cchar);
	return 0;
}
int countw(char *file)//返回文件词的数目 
{
	int aword = 0;
	int cword = 0;
	FILE *f;
	f = fopen(file, "r");
	char ch;
	if (NULL == (f = fopen(file, "r")))
	{
		printf("file is NULL");
	}
	else
		while (!feof(f))
		{
			ch = fgetc(f);
			if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || ch == '_')
				aword = 1;
			else if (aword)
			{
				cword++;
				aword = 0;
			}
		}
	fclose(f); printf("wordnum:%d ", cword); return 0;
}
int main(int argc, char* argv[])
{
	
	FILE *fp;
	while (1)
	{
		if ((fp = fopen(argv[2], "r")) == NULL)
		{
			printf("FileNull\n\n\n");
			scanf("%s%s%s", argv[0], argv[1], argv[2]);
			continue;
		}
		else if (!strcmp(argv[1], "-w"))
			countw(argv[2]);
		else if (!strcmp(argv[1], "-c"))
			countc(argv[2]);
		
	
		else
			printf("NullPoint\n");
		printf("\n\n");
		scanf("%s%s%s", argv[0], argv[1], argv[2]);
	}
	
	
	
	return 0;
}

