#include <stdio.h>

int arr[8];
int max;
int N;
int visited[8];

int my_abs(int a, int b)
{
	if (a > b)return a - b;
	else return b - a;
}

void recursive(int n, int sum, int *tmp)
{
	if (n == N) {
		
	/*	for (int i = 0; i < N; i++)
			printf("%d ", tmp[i]);

		printf("\n%d\n", sum);
		*/
		if (max < sum) {
			max = sum;
			return;
		}
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 0) {
			tmp[n] = arr[i];
			
			int sum_tmp;

			if(n>0)sum_tmp=my_abs(tmp[n - 1], tmp[n]);
			else sum_tmp = 0;
			//printf("%d\n", sum_tmp);
			visited[i] = 1;

			recursive(n + 1, sum + sum_tmp, tmp);

			visited[i] = 0;
		}
	}
}

int main()
{
	int tmp[8] = { 0, };

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	recursive(0, 0, tmp);

	printf("%d\n", max);
	
	return 0;
}