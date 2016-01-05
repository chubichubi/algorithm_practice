#include <stdio.h>

int arr[1000005];
char str[333335];

int my_strlen(char * str)
{
	int cnt = 0;
	char * tmp = str;
	while (*tmp != NULL){
		tmp++;
		cnt++;
	}

	return cnt;
}

int main()
{
	int length;
	int index = 0;
	int end;
	scanf("%s", str);

	length = my_strlen(str);
	end = length - 1;

	for (;;){
		int tmp = str[end]-'0';

		int cnt = 0;
		while (cnt<3){

			int a = tmp / 2;
			int b = tmp % 2;
			cnt++;
			tmp = tmp / 2;

			arr[index++] = b;
		}

		end--;
		if (end == -1)break;
	}
	int flag = 0;
	for (int i = index - 1; i >= 0; i--){
		if (flag == 0 && arr[i] == 0)continue;
		if (arr[i] == 1)flag = 1;
		printf("%d", arr[i]);
	}
	printf("\n");

	return 0;
}