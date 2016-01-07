#include <stdio.h>
#include <math.h>

int my_absdiff(int a, int b)
{
	if (a > b)return a - b;
	else return b - a;
}

double arr[28300];

double my_sqrt(int n)
{
	int pivot;

	for (int i = 1;; i++){
		if (arr[i] * arr[i] > (double)n){
			pivot = i;
			break;
		}
	}

	double end = arr[pivot];
	double start = arr[pivot - 1];
	double mid = (start+end)/2;

	for (int i = 0; i < 100; i++){

		if (mid*mid > n){

			end = mid;
			mid = (start + end) / 2;
		}
		else if (mid*mid == n){
			break;
		}
		else{
			start = mid;
			mid = (start + end) / 2;
		}

	}

	return mid;

}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i < 28300; i++){
		arr[i] = i;
	}

	for (int t = 0; t < T; t++){


		int x1, y1, r1, x2, y2, r2;

		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		
		int tmp1 = my_absdiff(x1, x2);
		int tmp2 = my_absdiff(y1, y2);
		int R, r;

		double distance = my_sqrt((tmp1*tmp1+tmp2*tmp2));

		if (r1>r2){
			R = r1;
			r = r2;
		}
		else{
			R = r2;
			r = r1;
		}

		if (x1 == x2&&y1 == y2&&r == R){
			printf("%d\n", -1);
		}
		else if (distance > r + R){
			printf("%d\n", 0);
		}
		else if (distance == r + R){
			printf("%d\n", 1);
		}
		else if (distance + r == R){
			printf("%d\n", 1);
		}
		else if (distance + r > R){
			printf("%d\n", 2);
		}
		else if (distance + r < R){
			printf("%d\n", 0);
		}
	}

	return 0;
}