#include <stdio.h>

long long arr[25];
long long mul[25];
int main()
{
	long long N;
	long long sum = 0;
	scanf("%lld", &N);

	mul[0] = 1;
	for (int i = 1; i < 25; i++){
		mul[i] = mul[i - 1] * 2;
	}

	for (int i = 0; i < N; i++){
		long long tmp;
		scanf("%lld", &tmp);

		int index = 0;
		for (;;){
			long long a = tmp % 2;
			arr[index] += a;
			index++;
			tmp = tmp / 2;
			if (tmp == 0)break;
		}
	}

	for (int i = 0; i < 25; i++){
		if (arr[i] == 0)continue;
		else{
			sum += mul[i] * arr[i] * (N - arr[i]);
		}
	}

	printf("%lld\n", sum);
	
	
}