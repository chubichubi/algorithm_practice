#include <stdio.h>
#define INFI -1234567890
int arr[1001];

int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++){

		int N;

		scanf("%d", &N);

		for (int i = 0; i < N; i++){
			scanf("%d", &arr[i]);
		}

		int sum = 0;
		int max = INFI;
		for (int i = 0; i < N; i++){

			sum += arr[i];

			if (max < sum)max = sum;

			if (sum < 0){
				sum = 0;
			}

		}
		
		printf("%d\n", max);


	}
	
	
	return 0;
}