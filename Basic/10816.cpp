#include <stdio.h>


int count[20000001];


int bsearch(int n, int * arr, int s, int e)
{
	
	if (e < s)return 0;

	

	int mid = (s + e) / 2;

	//printf("%d %d\n", n, arr[mid]);

	if (arr[mid] < n){

		bsearch(n, arr, mid + 1, e);

	}
	else if (arr[mid] > n){
		bsearch(n, arr, s, mid - 1);
	}
	else if (arr[mid] == n)return 1;


}


int main()
{
	int N;
	int M;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int tmp;
		scanf("%d", &tmp);
		
		count[tmp + 10000000]++;
		
	}

	

	scanf("%d", &M);

	for (int i = 0; i < M; i++){
		int tmp;
		scanf("%d", &tmp);

		printf("%d ", count[tmp + 10000000]);

	}
	printf("\n");
	

	return 0;
}