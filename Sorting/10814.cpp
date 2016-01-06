#include <stdio.h>

typedef struct st{

	int age;
	char str[105];
	int orig_index;
} P;

P arr[100005];
int N;

void my_qsort(P* arr, int lo, int hi, int flag)
{
	int i = lo; int j = hi;
	P mid = arr[(lo + hi) / 2];
	do{

		if (flag == 1){
			while (arr[i].age < mid.age)i++;
			while (arr[j].age > mid.age)j--;
		}
		else if (flag == 2){
			while (arr[i].orig_index < mid.orig_index)i++;
			while (arr[j].orig_index > mid.orig_index)j--;
		}

		if (i <= j){
			
			P tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;

		}

	} while (i <= j);

	if (i < hi)my_qsort(arr, i, hi, flag);
	if (j > lo)my_qsort(arr, lo, j, flag);

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		
		scanf("%d %s", &arr[i].age, &arr[i].str);
		arr[i].orig_index = i;
		
	}
	
	my_qsort(arr, 0, N - 1, 1);

	int cnt = 0;
	int start, end;
	int flag = 0;
	for (int i = 0; i < N; i++){

		if (i!=N-1&&arr[i].age == arr[i + 1].age && flag==0){
			flag = 1;
			cnt++;
			start = i;
			end = i + 1;
		}
		else if (i!=N-1&&arr[i].age == arr[i + 1].age){
			cnt++;
			end = i + 1;
		}
		else{

			if (cnt > 0){
				my_qsort(arr, start, end, 2);
				cnt = 0;
				flag = 0;
			}

		}
	}

	for (int i = 0; i < N; i++){
		
		printf("%d %s\n", arr[i].age, arr[i].str);
	}


	return 0;
}