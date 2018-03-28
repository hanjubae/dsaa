#include <stdio.h>
#pragma warning(disable:4996)

long long N;

int main()
{
	int T;
	scanf("%d", &T);

	int tc = 0;
	while (tc++ < T) {
		scanf("%lld", &N);
		
		if (N <= 3) {
			if (N == 1) {
				printf("#%d Bob\n", tc);
			}
			else {
				printf("#%d Alice\n", tc);
			}
		}
		else {
			long long size = 4LL;
			int w = 2;
			while (1) {
				if (N >= size && N < (size << 1)) break;
				size = size << 1;
				w++;
			}
			
			long long x = 1LL;
			if (w % 2) { // A위치
				for (int i = 1; i <= w; ++i) {
					if (i % 2) {
						x = x << 1;
					}
					else {
						x = (x << 1) + 1;
					}
				}
				if (x <= N) {
					printf("#%d Alice\n", tc);
				}
				else {
					printf("#%d Bob\n", tc);
				}
			}
			else { // B위치
				for (int i = 1; i <= w; ++i) {
					if (i % 2) {
						x = (x << 1) + 1;
					}
					else {
						x = x << 1;
					}
				}

				if (x > N) {
					printf("#%d Alice\n", tc);
				}
				else {
					printf("#%d Bob\n", tc);
				}
			}
		}
	}
    return 0;
}
