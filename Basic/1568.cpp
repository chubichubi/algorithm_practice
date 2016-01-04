#include <stdio.h>
#define N_MAX 1000000000

int arr[50001];

int main()
{
	int N;
	int time = 0;
	for (int i = 1; i <= 50000; i++){
		arr[i] += arr[i - 1] + i;
	}

	scanf("%d", &N);

	for (int i = 50000; i >= 1; i--){
		if (arr[i] > N)continue;

		while (N >= arr[i]){
			N = N - arr[i];
			time += i;
			//printf("%d %d\n", N, time);
		}
		if (N == 0)break;
	}

	printf("%d\n", time);

	return 0;
}