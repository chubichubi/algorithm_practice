#include <stdio.h>

int arr[500001];
int find[500001];

void my_qsort(int * arr, int lo, int hi)
{
	int i = lo; int j = hi;
	int mid = arr[(lo + hi) / 2];

	do{

		while (arr[i] < mid)i++;
		while (arr[j] > mid)j--;

		if (i <= j){
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}

	} while (i <= j);

	if (i < hi)my_qsort(arr, i, hi);
	if (j > lo)my_qsort(arr, lo, j);

}

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
		scanf("%d", &arr[i]);
	}

	my_qsort(arr, 0, N - 1);

	scanf("%d", &M);

	for (int i = 0; i < M; i++){

		scanf("%d", &find[i]);
	}

	for (int i = 0; i < M;i++){
		int ret;
		ret = bsearch(find[i], arr, 0, N - 1);

		printf("%d ", ret);
	}
	printf("\n");

	return 0;
}