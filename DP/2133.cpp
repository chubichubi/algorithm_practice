#include <stdio.h>

int map[31];

int main()
{
	int N;
	scanf("%d", &N);

	if (N % 2){
		printf("0\n");
	}
	else{

		map[0] = 1;
		map[2] = 3;

		for (int i = 4; i <= N; i += 2){

			map[i] = map[i - 2] * 3;

			for (int j = 4; j <= i; j += 2){

				map[i] += 2 * map[i - j];

			}

			

		}


		printf("%d\n", map[N]);
	}


	return 0;
}