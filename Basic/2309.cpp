#include <stdio.h>

int arr[10];

int result[8];
int flag;
void findSum(int sum, int n, int cnt, int * ans)
{
	if (flag==1 || n>=9 || cnt>7)return;

	
	sum += arr[n];
	ans[cnt] = arr[n];
	
	if (cnt == 7 && sum == 100) {
		flag = 1;
		for (int i = 1; i <= cnt; i++)
			result[i] = ans[i];
		return;
	}

	for (int i = n + 1; i < n + 4; i++)
		if(i<9)findSum(sum, i, cnt + 1, ans);
}


int main()
{

	int ans[10] = { 0, };

	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}

	

		
	findSum(0, 0, 1, ans);
	if (flag != 1)findSum(0, 1, 1, ans);
	if (flag != 1)findSum(0, 2, 1, ans);
	
	
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 6; j++) {
			if (result[j] > result[j + 1]) {
				int tmp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = tmp;
			}
		}
	}

	for (int i = 1; i <= 7; i++)
		printf("%d\n", result[i]);

	return 0;
}