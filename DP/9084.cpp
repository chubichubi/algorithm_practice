#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

int map[21][10001];
int coin[21];
int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		
		int N, M;

		scanf("%d", &N);

		for (int i = 1; i <= N; i++) {
			scanf("%d", &coin[i]);
		}

		scanf("%d", &M);

		for (int i = 1; i <= M; i++) {
			if (i%coin[1] == 0)map[1][i] = 1;
		}

		for (int i = 1; i <= N; i++) {
			map[i][0] = 1;
		}

		for (int i = 2; i <= N; i++) {

			for (int j = 1; j <= M; j++) {


				if (j >= coin[i])map[i][j] = map[i - 1][j] + map[i][j - coin[i]];
				else map[i][j] = map[i - 1][j];

			}

		}

		//for (int i = 1; i <= N; i++) {
		//	for (int j = 1; j <= M; j++) {
		//		printf("%d ", map[i][j]);
		//	}
		//	printf("\n");
		//}
		//
		printf("%d\n", map[N][M]);

		for (int i = 1; i <= N; i++) {
			coin[i] = 0;
			for (int j = 1; j <= M; j++)
				map[i][j] = 0;

		}


	}


	return 0;

}