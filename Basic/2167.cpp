#include <stdio.h>

int arr[301][301];
int sum[301][301];
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= M; j++){
			scanf("%d", &arr[i][j]);
			
		}
	}

	for (int j = 1; j <= M; j++){
		int tmp = 0;
		for (int i = 1; i <= N; i++){
			tmp += arr[i][j];
			sum[i][j] = tmp;
		}
	}


	int K;

	scanf("%d", &K);

	for (int i = 0; i < K; i++){
		int a, b, c, d;

		scanf("%d %d %d %d", &a, &b, &c, &d);

		int acc = 0;

		for (int j = b; j <= d; j++){
			acc += sum[c][j] - sum[a - 1][j];
		}

		printf("%d\n", acc);
	}


	return 0;
}