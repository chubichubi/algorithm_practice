#include <stdio.h>
#pragma warning(disable:4996)
#define N_MAX 100

int map[N_MAX + 1][N_MAX + 1];

int main()
{
	freopen("input.txt", "r", stdin);

	int N, M;

	scanf("%d %d", &N, &M);

	int x1, x2, y1, y2;

	for (int i = 0; i < N; i++){

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		for (int j = x1; j <= x2; j++){
			for (int k = y1; k <= y2; k++){
				map[j][k]++;
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= 100; i++){
		for (int j = 1; j <= 100; j++){
			if (map[i][j]>M)cnt++;
		}
	}
	
	printf("%d\n", cnt);

	return 0;
}