#include <stdio.h>
#define INFI 1234567890
int arr[101];

int map[101][10001];

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <=n; i++){
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= k; i++){
		if (i%arr[1] == 0)map[1][i] = i / arr[1];
		else map[1][i] = INFI;

	}

	for (int i = 2; i <= n; i++){


		for (int j = 1; j <= k; j++){

			if (j>=arr[i] && map[i-1][j] > map[i][j-arr[i]] + 1){
				map[i][j] = map[i][j - arr[i]] + 1;
			}
			else map[i][j] = map[i - 1][j];

		}
	}

	if(map[n][k]!=INFI)printf("%d\n", map[n][k]);
	else printf("-1\n");

	return 0;
}