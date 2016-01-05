#include <stdio.h>
#define N_MAX 100000

int arr1[N_MAX + 1];
int arr2[N_MAX + 1];
int index[N_MAX + 1];
int ans[N_MAX + 1];

void my_qsort(int *arr, int lo, int hi)
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

void my_qsort_index(int *arr, int lo, int hi)
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

			int tmp2 = index[i];
			index[i] = index[j];
			index[j] = tmp2;

			i++;
			j--;

			

		}


	} while (i <= j);

	if (i < hi)my_qsort_index(arr, i, hi);
	if (j > lo)my_qsort_index(arr, lo, j);
}


int main()
{

	freopen("input.txt", "r", stdin);

	int N,M;
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		scanf("%d", &arr1[i]);
	}

	scanf("%d", &M);

	for (int i = 0; i < M; i++){
		scanf("%d", &arr2[i]);
		index[i] = i;
	}

	my_qsort(arr1, 0, N - 1);
	my_qsort_index(arr2, 0, M - 1);

	/*for (int i = 0; i < N; i++)
		printf("%d ", arr1[i]);
	printf("\n");
	for (int i = 0; i < M; i++)
		printf("%d ", arr2[i]);
	printf("\n");*/

	for (int k = 0; k < M; k++){

		int tmp = arr2[k];//ans[index[k]];

		int s = 0, e = N - 1;
		int flag = 0;
		for (int i = 0; i < 30; i++){
			
			int mid = arr1[(s + e) / 2];

			if (mid > tmp){
				e = (s + e) / 2 - 1;
			}
			else if (mid < tmp){
				s = (s + e) / 2 + 1;
			}
			else if (mid == tmp){
				flag = 1;
				break;
			}
		}
		if (flag == 1){
			ans[index[k]] = 1;
		}
		else{
			ans[index[k]] = 0;
		}
		

	}
	
	for (int i = 0; i < M; i++)
		printf("%d\n", ans[i]);


	return 0;
}