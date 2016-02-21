#include <stdio.h>

char str[105];

int main()
{

	int ret;
	
	for (int i = 0; i < 100;i++){
		
		gets(str);
	
		if (str[0] == NULL)
		{
			break;
		}

		int a_cnt = 0;
		int A_cnt = 0;
		int num_cnt = 0;
		int space_cnt = 0;

		char * tmp = str;

		while (*tmp != NULL){

			if (*tmp >= 'a'&&*tmp <= 'z')a_cnt++;
			if (*tmp >= 'A' &&*tmp <= 'Z')A_cnt++;
			if (*tmp >= '0'&&*tmp <= '9')num_cnt++;
			if (*tmp == ' ')space_cnt++;

			tmp++;


		}

		printf("%d %d %d %d\n", a_cnt, A_cnt, num_cnt, space_cnt);

		for (int i = 0; i < 105; i++)
			str[i] = 0;

	}
	
	

	return 0;
}