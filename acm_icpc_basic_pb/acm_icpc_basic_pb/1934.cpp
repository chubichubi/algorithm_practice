//1934

#include <stdio.h>
#pragma warning(disable:4996)

int euclid(int a, int b)
{
	if (b == 0)return a;

	return euclid(b, a%b);
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {

		int a, b;
		int ret;

		scanf("%d %d", &a, &b);

		ret = euclid(a, b);
		
		printf("%d\n", a*b / ret);

	}

	return 0;
}