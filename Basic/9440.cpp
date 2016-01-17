#include <stdio.h>

int arr[14];
int a[14];
int b[14];

int main()
{

	int N;

	freopen("input.txt", "r", stdin);

	for (;;) {

		scanf("%d", &N);

		if (N == 0)break;

		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 0; i < N; i++) {

			for (int j = 0; j < N - 1; j++) {


				if (arr[j] > arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}

		}
		int zero = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] == 0)zero++;
		}

		int a_index = 0;
		int b_index = 0;
		
		int flag = 1;
		for (int i = N - 1; i > zero + 1; i--) {
			if (flag == 1) {
				a[a_index++] = arr[i];
			}
			else {
				b[b_index++] = arr[i];
			}
			flag *= -1;
		}

		for (int i = 0; i < zero; i++) {

			if (flag == 1) {
				a[a_index++] = 0;
			}
			else {
				b[b_index++] = 0;
			}
			flag *= -1;

		}

		a[a_index] = arr[zero];
		b[b_index] = arr[zero + 1];
		int cal_a, cal_b;
		cal_a = cal_b = 0;

		for (int i = a_index; i >= 0; i--) {
			cal_a *= 10;
			cal_a += a[i];
		}

		for (int i = b_index; i >= 0; i--) {
			cal_b *= 10;
			cal_b += b[i];
		}

		
		printf("%d\n", cal_a + cal_b);
		for (int i = 0; i < 14; i++) {
			a[i] = b[i] = arr[i] = 0;
		}

	

	}

	return 0;
}