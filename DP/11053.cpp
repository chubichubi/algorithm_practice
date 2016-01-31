#include <stdio.h>


int arr[1001];
int longest[1001];
int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}


	for (int i = 0; i < N; i++)
		longest[i] = 1;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {

			if (arr[i] > arr[j] && longest[i] < longest[j] + 1) {
				longest[i] = longest[j] + 1;
			}
		}
	}

	/*for (int i = 0; i < N; i++) {
		printf("%d ", longest[i]);
	}
	printf("\n");
*/
	int max = 0;
	for (int i = 0; i < N; i++) {
		if (longest[i] > max)max = longest[i];
	}

	printf("%d\n", max);

	return 0;
}