#include <stdio.h>

int arr[41];

int main()
{
	int N, M;
	
	scanf("%d", &N);

	scanf("%d", &M);

	int ans = 1;

	int tmp_before = 0;
	int tmp;
	arr[0] = 1;
	arr[1] = 1; arr[2] = 2;
	for (int i = 3; i <= N; i++){
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	for (int i = 0; i < M; i++){
		
		scanf("%d", &tmp);

		int plus = tmp - tmp_before - 1;

		ans *= arr[plus];

		tmp_before = tmp;

	}

	if(M!=0)ans *= arr[N - tmp];
	else ans = arr[N];

	printf("%d\n", ans);

	return 0;
}