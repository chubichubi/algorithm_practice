#include <stdio.h>



int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int order[10] = { 10, 5, 9, 8, 3, 2, 7, 6, 1, 4 };

int ans[100];
int orig[100];
int main()
{
	int M, N;

	scanf("%d %d", &M, &N);

	for (int i = M; i <= N; i++){

		orig[i] = i;

		int a;

		if (i >= 10){
			a = i / 10;
		}
		else a = i;

		ans[i] = order[a] * 12;

		if (i >= 10){
			int b = i % 10;
			ans[i] += order[b];
		}
	
	}

	/*for (int i = M; i <= N; i++)
		printf("%d << %d\n", ans[i], orig[i]);*/


	for (int i = M; i <= N; i++){
		for (int j = M; j <= N - 1; j++){

			if (ans[j] > ans[j + 1]){
				int tmp = ans[j];
				ans[j] = ans[j + 1];
				ans[j + 1] = tmp;

				tmp = orig[j];
				orig[j] = orig[j + 1];
				orig[j + 1] = tmp;
			}
		}
	}

	int cnt = 0;
	for (int i = M; i <= N; i++){
		cnt++;
		if (cnt % 10)printf("%d ", orig[i]);
		else printf("%d\n", orig[i]);

	}


	return 0;
}