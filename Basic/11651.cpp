#include <stdio.h>

typedef struct st {

	int x;
	int y;

} Point;

Point arr[100001];

void my_qsort(Point * arr, int lo, int hi, int flag)
{
	int i = lo;
	int j = hi;
	Point mid = arr[(i + j) / 2];

	do {

		if (flag == 0) {
			while (mid.y > arr[i].y)i++;
			while (mid.y < arr[j].y)j--;
		}
		else {
			while (mid.x > arr[i].x)i++;
			while (mid.x < arr[j].x)j--;
		}

		if (i <= j) {
			Point tmp = arr[i];
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
	int N;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		scanf("%d %d", &arr[i].x, &arr[i].y);

	}

	my_qsort(arr, 0, N - 1, 0);
	int s=0, e=0;
	int flag = 0;
	for (int i = 0; i < N; i++) {

		if (flag==0 && arr[i].y == arr[i + 1].y) {
			flag = 1;
			s = i;
			e = i + 1;
		}
		else if (arr[i].y == arr[i + 1].y) {
			e = i + 1;
		}
		else {

			if (flag == 1) {
				my_qsort(arr, s, e, 1);
				flag = 0; s = 0; e = 0;

			}

		}

	}

	for (int i = 0; i < N; i++) {

		printf("%d %d\n", arr[i].x, arr[i].y);

	}

	return 0;
}