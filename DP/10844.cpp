#include <stdio.h>
#define MODULUS 1000000000
int ans[101][10];


int main()
{
	int N;
	

	scanf("%d", &N);
	
	ans[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		ans[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {

		ans[i][0] = ans[i - 1][1];
		ans[i][9] = ans[i - 1][8];


		for (int j = 1; j < 9; j++) {

			ans[i][j] = (ans[i - 1][j - 1]%MODULUS + ans[i - 1][j + 1]%MODULUS);
			ans[i][j] %= MODULUS;
		}

	}

	int sum = 0;

	for (int i = 0; i <= 9; i++) {
		sum += ans[N][i];
		sum %= MODULUS;
	}

	printf("%d\n", sum);


	//ans[i+1] = ans[i]*2 - arr18[i-1];
	//ans[i+1] = ans[i]*2 - arr27[i-2];



	return 0;

}