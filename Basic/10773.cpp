#include <stdio.h>

int arr[100001];
int stkptr = -1;

void push(int n)
{
	stkptr++;
	arr[stkptr] = n;
}

int pop()
{
	int ret;

	ret = arr[stkptr];
	stkptr--;

	return ret;
}



int main()
{
	int N;
	int index = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);

		if (tmp != 0)push(tmp);
		else pop();
		
	}
	int sum = 0;
	for (int i = 0; i < stkptr + 1; i++) {
		sum += arr[i];
	}
	printf("%d\n", sum);
	return 0;
}