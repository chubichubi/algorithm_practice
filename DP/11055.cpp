#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int arr[1001];
int sum[1001];

int main()
{
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		sum[i] = arr[i];
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {	
				sum[i]=MAX(sum[i], sum[j] + arr[i]);
			}
		}

	}
	int max = 0;

	for (int i = 0; i < N; i++) {
		if (max < sum[i])max = sum[i];
	}

	printf("%d\n", max);

	
	return 0;
}