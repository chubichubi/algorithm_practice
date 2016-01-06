#include <stdio.h>

int index[51];
int arr[51];
int ans[51];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		index[i] = i;
	}

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N - 1; j++){

			if (arr[j] > arr[j + 1]){
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;

				tmp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = tmp;

			}
		}
	}
	
	for (int i = 0; i < N; i++){
		ans[index[i]] = i;
	}

	for (int i = 0; i < N-1; i++){
		printf("%d ", ans[i]);
	}
	printf("%d\n",ans[N-1]);


	return 0;
}