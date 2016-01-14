#include <stdio.h>

char str_a[10005];
char str_b[10005];
char buf[10005];

int my_strlen(char* str)
{
	char *tmp = str;
	int cnt = 0;

	while (*tmp != NULL) {
		tmp++;
		cnt++;
	}

	return cnt;
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%s", str_a);
	scanf("%s", str_b);

	int length_a = my_strlen(str_a);
	int length_b = my_strlen(str_b);

	int diff = 0;
	int flag = 0;
	char *buf2;
	int length = 0;

	if (length_a > length_b) {
		diff = length_a - length_b;
		flag = 1;
	}
	else diff = length_b - length_a;

	if (flag == 1) {

		//a is bigger
		for (int i = length_b - 1; i >= 0; i--) {
			buf[i+diff]=str_b[i];
		}
		for (int i = 0; i < diff; i++)
			buf[i] = '0';
		
		buf2 = str_a;
		length = length_a;
	}
	else {
		//b can be bigger
		for (int i = length_a - 1; i >= 0; i--) {
			buf[i + diff] = str_a[i];
		}
		for (int i = 0; i < diff; i++)
			buf[i] = '0';

		buf2 = str_b;
		length = length_b;

	}

	

	int carry = 0;
	for (int i = length - 1; i >= 0; i--) {

		if (buf[i] + buf2[i]-'0'-'0' >= 10) {

			int tmp = (buf[i] + buf2[i] - '0' - '0') % 10;
			int tmp2 = (buf[i] + buf2[i] - '0' - '0') / 10;

			if (i >= 1)buf[i - 1] += tmp2;
			else if (i == 0)carry = 1;

			buf[i] = tmp+'0';

		}
		else buf[i] = buf[i] + buf2[i]-'0';

	}

	if (carry) {
		printf("1%s\n", buf);
	}
	else printf("%s\n", buf);
	
	return 0;

}

