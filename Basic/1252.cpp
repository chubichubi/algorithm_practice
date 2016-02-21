#include <stdio.h>

char a[85];
char b[85];
int ans[85];
int my_strlen(char * a)
{
	char * tmp = a;

	int cnt = 0;

	while (*tmp != NULL) {
		cnt++;
		tmp++;
	}

	return cnt;
}


int main()
{
	freopen("input.txt", "r", stdin);

	scanf("%s %s", &a, &b);
	
	int alength = my_strlen(a);
	int blength = my_strlen(b);
	int start = 0;
	int i = alength - 1;
	int j = blength - 1;
	int index = 0;

	while (i >= 0) {
		ans[index] += a[i] - '0';
		i--;
		index++;
	}

	start = index;
	index = 0;
	while (j >= 0) {
		ans[index] += b[j] - '0';
		j--;
		index++;
	}
	
	if (index <= start)index = start;
	start = 0;

	for (int i = 0; i <= index; i++) {
		if (ans[i] >= 2) {
			ans[i + 1] += ans[i] / 2;
			ans[i] %= 2;
			
		}
	}


	for (int i = index; i >= 0; i--) {
		if (ans[i] != 0) {
			start = i;
			break;
		}
	}

	for (int i = start; i >= 0; i--) {
		printf("%d", ans[i]);
	}
	printf("\n");

	return 0;
}