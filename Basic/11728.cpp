#include <stdio.h>
#define N_MAX 1000000
#define INFI 1234567890
int arr1[N_MAX + 1];
int arr2[N_MAX + 1];

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);


	for (int i = 0; i < N; i++){
		scanf("%d", &arr1[i]);
	}

	for (int i = 0; i < M; i++){
		scanf("%d", &arr2[i]);
	}

	for (int i = N; i < N_MAX; i++){
		arr1[i] = INFI;
	}

	for (int i = M; i < N_MAX; i++){
		arr2[i] = INFI;
	}


	int ai, bi;
	int cnt = 0;
	ai = bi = 0;

	while (ai < N && bi<M){

		if (arr1[ai] < arr2[bi]){
			printf("%d ", arr1[ai++]);
			cnt++;
		}
		else{
			printf("%d ", arr2[bi++]);
			cnt++;
		}

	}

	for (int i = ai; i < N; i++)
		printf("%d ", arr1[i]);

	for (int i = bi; i < M; i++)
		printf("%d ", arr2[i]);

	printf("\n");
	
		
	return 0;
}