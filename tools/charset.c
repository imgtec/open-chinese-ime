#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int col, row;
	int count = 0;

	/* 先打印 GB2312 再说 */
	
	for(row = 16; row <= 55; row++){
		/* 一级汉字 3755 个 */
		for(col = 1; col <= 94; col++) {
			int r, c;
			r = row + 0xa0;
			c = col + 0xa0;

			count++;
#if 1
			/* EXCEL 格式 */
			printf("%d,%c%c,\n", count, r, c);
#else
			putchar(r);
			putchar(c);
#endif
			if(count >= 3755) break;
		}
	}

	putchar('\n');

	/* 二级汉字 3008 个 */
	for(row = 56; row <= 87; row++) {
		for(col=1; col <= 94; col++) {
			count++;
			printf("%d,%c%c,\n", count, row+0xa0, col+0xa0);
			if(count >= 6763) break;
		}
	}

	printf("%d\n", count);

	return 0;
}

