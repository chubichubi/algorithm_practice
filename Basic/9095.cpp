#include <stdio.h>

int map[4][11];

int ans = 0;
int N;
int cnt;
int dfs(int sum)
{
	int cnt = 0;

	if (sum == N) {
		cnt++;
		return cnt;
	}
	else if (sum > N)return cnt;

	cnt+=dfs(sum + 1);
	cnt+=dfs(sum + 2);
	cnt+=dfs(sum + 3);

	return cnt;
}


int main()
{
	int T;

	scanf("%d", &T);

	for (int t = 0; t < T; t++) {

	
		scanf("%d", &N);

		int ret = dfs(0);

		printf("%d\n", ret);

	}



	return 0;

}