#include <stdio.h>
#include <stdlib.h>

#include "chset.h"
extern struct bnode charset[];
extern struct charattr rootset[];

int __breakdown(int i)
{
	static int deep = 0;
	static int limit = 100;
	int id;
	char *p = NULL;
	
	int b = 0;

	deep++;
	if(deep > 8) {
		printf("ERR: data too deep or error.\n");
		deep--;
		return -1;
	}

	if(i<0) {
		printf("[%s%d]\n", rootset[-i].c, rootset[-i].strk);
	} else if(i>limit) {
		printf("Out of range.");
	} else if(i==0) {
		printf("\n");
	} else {

		p = charset[i].c;
		printf("%s", p);

		b = charset[i].left;
		if(b!=i) __breakdown(b);
		b = charset[i].right;
		if(b!=i) __breakdown(b);
	}
	deep--;
	return 0;
}

int breakdown(char *c)
{
	int i = 1;
	int id;
	char *p = NULL;
	const int limit = 100;

	while(i < limit) {
		id = charset[i].id;
		if(id == -1) {
			printf("\tNot Found.\n");
			break;
		}
		putchar('.');
		p = charset[i].c;
		if(p[0]==c[0] && p[1]==c[1]){
			printf("Found [%s]\n", p);
			__breakdown(i);
			return i;	/* 找到的下标 */
		}
		i++;
	}
}


int main(int argc, const char *argv[])
{
	int i;

	i = 1;
	while(i<100){
		char *p;
		int id;
		
		id = charset[i].id;
		if(id == -1) break;

		printf("--------------------------\n");
		p = charset[i].c;
		puts("Forest\n");
		printf("Looking for: %s\n", p);

		breakdown(p);
		putchar('\n');
		i++;
	}
	system("pause");
	return 0;
}

