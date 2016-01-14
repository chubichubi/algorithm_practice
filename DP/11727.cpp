#include <stdio.h>
#define MODULUS 10007

unsigned long long arr[1001];

int main()
{
	int n;

	scanf("%d", &n);

	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 3;

	for (int i = 3; i <= n; i++) {

		int tmp = i / 2;
		int tmp2 = (i - 2);
		int tmp3 = tmp2 / 2;
		arr[i] = ((arr[tmp] * arr[i - tmp])%MODULUS + ((2 * arr[tmp3])%MODULUS * arr[tmp2 - tmp3])%MODULUS)%MODULUS;
		
	}

	

	printf("%llu\n", arr[n]);


	return 0;
}