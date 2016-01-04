#pragma warning(disable:4996)
#include <stdio.h>
#define N_MAX 200
#define C_MAX 300000
#define INFI 1234567890

int acc[N_MAX + 1];
int tri[N_MAX + 1];
int map[C_MAX + 1];

int recursive(int n)
{
	if (n == 0)return 0;
	if (map[n] != 0)return map[n];
	else{

		int min = INFI;
		int tmp = 0;
		for (int i = 1; i <= N_MAX; i++){
			if (tri[i] > n)continue;

			if (tri[i] <= n){
				tmp =  recursive(n - tri[i]) + 1;
			}

			if (min > tmp)min = tmp;
			
		}

		map[n] = min;

		return min;

	}
}


int main()
{
	
	int sum = 0;
	int sum2 = 0;
	
	for (int i = 1; i <= N_MAX; i++){
		sum += i;
		acc[i] = sum;

		sum2 += acc[i];
		tri[i] = sum2;
	}
	/*for (int i = N_MAX-100; i <= N_MAX; i++)
					printf("%d\n", tri[i]);*/
	//////debug
	//for (int i = 1; i < 10; i++)
	//	printf("%d ", tri[i]);

	int n;
	map[1] = 1;
	scanf("%d", &n);
	
	recursive(n);

	//for (int i = 1; i <= 40; i++)
	//	printf("[%d] %d\n", i, map[i]);

	printf("%d\n", map[n]);

	return 0;
}
