#include <stdio.h>
#pragma warning(disable:4996)

int N;
int num[3000001];

void quicksort(int lo, int hi);

int main()
{
	int T;
	scanf("%d", &T);
	int tc = 0;
	while (tc++ < T) {
		scanf("%d", &N);
		
		for (int i = 0; i < N; ++i) {
			scanf("%d", &num[i]);
		}

		quicksort(0, N-1);
		
		int cnt = 1;
		int comp = num[0];

		int answer = 0;
		for (int i = 1; i < N; ++i) {
			if (comp == num[i]) cnt++;
			else {	
				if (cnt % 2 == 1) {
					answer = answer ^ comp;
				}
				cnt = 1;
				comp = num[i];
			}
		}

		if (cnt % 2 == 1) {
			answer = answer ^ comp;
		}

		printf("Case #%d\n", tc);
		printf("%d\n", answer);

	}

    return 0;
}

void quicksort(int lo, int hi) {
	int i = lo, j = hi;
	int pivot = num[(lo + hi) / 2];
	int temp;
	do{
		while (num[i] < pivot) i++;
		while (num[j] > pivot) j--;

		if (i <= j) {
			temp = num[i];
			num[i] = num[j];
			num[j] = temp;

			i++;
			j--;
		}
	} while (i <= j);

	if (lo < j) quicksort(lo, j);
	if (i < hi) quicksort(i, hi);
}
