#include <stdio.h>

int arr[4];



int main()
{
	for (int i = 0; i < 4; i++){
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){

			if (arr[j] > arr[j + 1]){
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}


		}
	}

	printf("%d\n", arr[0] * arr[2]);


	return 0;
}