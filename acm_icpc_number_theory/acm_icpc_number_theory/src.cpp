//1644


#include <stdio.h>
#define N_MAX 4000000
#pragma warning(disable:4996)

int arr[N_MAX + 1];
int prime[N_MAX / 4 + 1];

int che(int n)
{
	for (int i = 2; i <= n; i++) {
		arr[i] = n;
	}

	for (int i = 2; i <= n; i++) {
		if (arr[i] == 0)continue;

		for (int j = i + i; j <= n; j += i) {
			arr[j] = 0;
		}
	}

	int  cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] != 0)prime[cnt++] = i;
	}

	return cnt;
}

int worm(int n, int end)
{
	int ans = 0;
	long long sum = 0;
	int start = 0;

	/*for (int i = 0; i < end; i++)
	printf("prime..%d\n", prime[i]);
	*/
	for (int i = 0; i < end; i++) {

		sum += prime[i];

		if (sum > n) {
			for (int j = start; j <= i; j++) {
				if (sum > n) {
					sum -= prime[j];
				}
				else if (sum < n) {
					start = j;
					break;
				}
				else {
					start = j;
					ans++;
					break;
				}
			}
		}
		else if (sum < n) {
			continue;

		}
		else if (sum == n) {
			ans++;
			continue;

		}
	}

	return ans;
}

int main()
{
	//	freopen("input.txt", "r", stdin);
	int n;
	int ret = 0;
	scanf("%d", &n);
	int end = 0;
	end = che(n);

	ret = worm(n, end);

	printf("%d\n", ret);

	return 0;
}