#include <stdio.h>
#pragma warning(disable:4996)

#define N_MAX 500

#define MAX(a,b)(((a)>(b))?(a):(b))

int arr[N_MAX + 1][N_MAX + 1];

int map[N_MAX + 1][N_MAX + 1];

int main()
{
	int N;

	freopen("input.txt", "r", stdin);
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= i; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	map[1][1] = arr[1][1];

	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= i; j++){
			map[i][j] = MAX(map[i - 1][j - 1] + arr[i][j], map[i - 1][j] + arr[i][j]);

		}
	}
	int max = 0;
	for (int i = 1; i <= N; i++){
		if (map[N][i] > max)max = map[N][i];
	}
	
	printf("%d\n", max);

	return 0;
}