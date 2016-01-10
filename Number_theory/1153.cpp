#include <stdio.h>


int prime[1000005];


void che(void)
{

	for (int i = 2; i <= 1000000; i++) {

		if (prime[i] != i)continue;

		for (int j = i + i; j <= 1000000; j += i) {
			prime[j] = 1;
		}

	}


}

int ans[4];

int main()
{
	prime[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		prime[i] = i;
	}

	che();

	int N;

	scanf("%d", &N);

	if (N < 8) {
		printf("-1\n");
		return 0;
	}
	else if (N % 2==0) {

		ans[0] = 2;
		ans[1] = 2;
		N = N - 4;
	}
	else {
		ans[0] = 2;
		ans[1] = 3;
		N = N - 5;
	}

	//printf("%d\n", N);
	for (int i = 2; i < N; i++) {

		if (prime[i] == i && prime[N - i] == N-i) {
			ans[2] = i;
			ans[3] = N - i;
			break;
		}
	}

	printf("%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);




	return 0;
}