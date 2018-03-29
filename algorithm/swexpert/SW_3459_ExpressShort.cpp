#include <stdio.h>
#pragma warning(disable:4996)

char output[100001];
int firstNum = 0;
int rest[100001];


void init() {
	for (int i = 0; i < 100001; ++i) {
		rest[i] = 0;
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	int tc = 0;
	while (tc++ < T) {
		init();
		int p, q;
		scanf("%d %d", &p, &q);
		
		int w = 0;
		int isCycle = 0;
		int start = 0;
		int cur = p;
		while (cur) {
			if (w == 0) {
				firstNum = cur / q;
				if(cur % q) output[w++] = '.';
			}
			else {
				output[w++] = (cur / q) + 48;
			}

			cur = cur % q;
			if (rest[cur]) {
				isCycle = 1;
				start = rest[cur];
			}

			if (isCycle) {
				break;
			}
			else {
				rest[cur] = w;
			}
			 
			cur *= 10;		
		}

		printf("#%d %d", tc, firstNum);
		if (isCycle) {
			for (int i = 0; i < w; ++i) {
				if (i == start) {
					printf("(");
					for (int j = start; j < w; ++j) {
						printf("%c", output[j]);
					}
					printf(")");
					break;
				}
				else {
					printf("%c", output[i]);
				}			
			}
		}
		else {
			for (int i = 0; i < w; ++i) {
				printf("%c", output[i]);
			}
		}
		
		printf("\n");
	}

	

    return 0;
}

