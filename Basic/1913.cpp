#include <stdio.h>


int map[1005][1005];


int main()
{
	int N;
	int find;
	scanf("%d", &N);
	int num = 1;
	scanf("%d", &find);


	int i = N / 2 + 1;
	int j = N / 2 + 1;
	int flip = 1;
	int cnt = 1;
	int ans_x, ans_y;
	while (num <= N*N){

		for (int k = 0; k < cnt;k++){
			map[i][j] = num;
			if (num == find){
				ans_x = i;
				ans_y = j;
			}
			num++; i-=flip;
			if (num == N*N+1)break;
		}
		if (num == N*N + 1)break;

		for (int k = 0; k < cnt; k++){
			map[i][j] = num;
			if (num == find){
				ans_x = i;
				ans_y = j;
			}
			num++; j += flip;
			if (num == N*N+1)break;
		}
		if (num == N*N + 1)break;
		flip *= -1;
		cnt++;

	}

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	printf("%d %d\n", ans_x, ans_y);
	



}