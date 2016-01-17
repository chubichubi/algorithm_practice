#include <stdio.h>

int arr[1001];
int ans[1001];

int main()
{


	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
		ans[i] = 1;
	}

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j < i; j++) {

			if (arr[i] > arr[j] && ans[i] < ans[j] + 1) {

				ans[i] = ans[j] + 1;
			}


		}

	}

	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (ans[i] > max)max = ans[i];
	}

	printf("%d\n", max);
	
	return 0;
}