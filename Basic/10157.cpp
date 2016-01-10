#include <stdio.h>


int map[1001][1001];



int main()
{
	int C, R;
	int K;

	scanf("%d %d", &C, &R);
	scanf("%d", &K);

	if (K > C*R) {
		printf("%d\n", 0);
		return 0;
	}

	int iter_r, iter_c;
	int flip = -1;
	int x, y;
	int cnt = 1;

	iter_r = R; iter_c = C - 1;

	x = R+1; y = 1;

	//Row
	for (;;) {
		for (int i = 0; i < iter_r; i++) {
			x += flip;
			map[x][y] = cnt++;
		}
		if (cnt == R*C + 1)break;

		flip *= -1;

		//Column
		for (int i = 0; i < iter_c; i++) {
			y += flip;
			map[x][y] = cnt++;
		}
		if (cnt == R*C + 1)break;
		iter_r--; iter_c--;
		
	}
	
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == K) {
				printf("%d %d\n", j, R - i + 1);
				break;
			}
		}
	}

	return 0;
}