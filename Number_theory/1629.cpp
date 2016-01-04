#include <stdio.h>
#pragma warning(disable:4996)

unsigned long long arr[31];//2 squared 1, 2, 4, 8, 16, ...
unsigned long long arr_2[31];
int main()
{
	unsigned long long a, b, c;
	
	scanf("%llu %llu %llu", &a, &b, &c);

	arr_2[0] = 1; arr_2[1] = 2;
	arr[0] = a%c; arr[1] = (arr[0] * arr[0])%c;
	

	for (int i = 2; i <= 30; i++){
		arr[i] = (arr[i - 1] * arr[i - 1]) % c;
		arr_2[i] = arr_2[i - 1] * 2;
	}

	unsigned long long ans = a%c;
	b--;
	
	for (int i = 30; i >= 0; i--){
		if (arr_2[i] > b)continue;
		
		while (b >= arr_2[i]){
			b = b - arr_2[i];
			ans = (ans%c * arr[i]%c)%c;
			
		}
		if (b == 0)break;

	}

	printf("%llu\n", ans);

	return 0;
}