#include <stdio.h>

int arr[1001][2];

int my_absdiff(int a, int b)
{
	if (a > b)return a - b;
	else return b - a;
}

int main()
{
	int W, H, N;

	scanf("%d %d %d", &W, &H, &N);

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	
	for (int i = 0; i < N - 1; i++) {

		int a, b, c, d;

		a = arr[i][0]; b = arr[i][1];
		c = arr[i + 1][0]; d = arr[i + 1][1];

		int tmp_a, tmp_b; int tmp;

		tmp_a = my_absdiff(a, c);
		tmp_b = my_absdiff(b, d);

		if (a > c&&b > d) {
			if (tmp_a > tmp_b)tmp = tmp_b;
			else tmp = tmp_a;

			cnt += tmp;
			a -= tmp; b -= tmp;
		}
		else if (a < c&&b < d) {
			if (tmp_a > tmp_b)tmp = tmp_b;
			else tmp = tmp_a;

			cnt += tmp;
			c -= tmp; d -= tmp;
		}

		cnt += my_absdiff(a, c);
		cnt += my_absdiff(b, d);

	}

	printf("%d\n", cnt);
	
	
	return 0;
}