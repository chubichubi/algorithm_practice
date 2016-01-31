#include <stdio.h>

int arr[101];
int sequence[101];

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; i++) {

		for (int j = i - 1; j >= arr[i]; j--) {
			sequence[j + 1] = sequence[j];
		}

		sequence[arr[i]] = i;

	}
	for (int i = N-1; i >= 0; i--)
		printf("%d ", sequence[i]);
	printf("\n");
	return 0;
}