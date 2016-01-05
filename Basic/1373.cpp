#include <stdio.h>

int arr[1000005];
char str[1000005];

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
		
		int tmp = 0;
		int a, b, c;

		a = str[end] - '0';
		end--;

		tmp += a;
		if (end == -1){
			arr[index++] = tmp;
			break;
		}

		b = str[end] - '0';
		end--;

		tmp += b * 2;
		if (end == -1){
			arr[index++] = tmp;
			break;
		}

		c = str[end] - '0';
		end--;

		tmp += c * 4;
		if (end == -1){
			arr[index++] = tmp;
			break;

		}

		arr[index++] = tmp;
	}

	for (int i = index - 1; i >= 0; i--)
		printf("%d", arr[i]);
	printf("\n");

	return 0;
}