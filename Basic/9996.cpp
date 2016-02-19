#include <stdio.h>

char pattern[101];
char str[101][101];
int visited[101][101];

int my_strlen(char * str)
{
	char * tmp = str;

	int cnt = 0;

	while (*tmp != NULL){
		tmp++;
		cnt++;
	}

	return cnt;
}

int match(int n, int length)
{

	char * tmp1;
	char * ptmp1;

	int tmplength = my_strlen(str[n]);

	tmp1 = str[n];
	
	ptmp1 = pattern; 

	int i, j;
	i = 0; j = 0;
	while (ptmp1[i] != '*'){

		if (ptmp1[i] == tmp1[j] && visited[n][j]==0){
		
			visited[n][j] = 1;
			i++;
			j++;
		}
		else{
			return -1;
		}

	}

	i = length - 1;
	j = tmplength - 1;

	while (ptmp1[i] != '*'){

		if (ptmp1[i] == tmp1[j] && visited[n][j] == 0){
	
			visited[n][j] = 1;
			i--;
			j--;
		}
		else{
			return -1;
		}

	}

	return 1;
}

int main()
{
	int T;


	scanf("%d", &T);

	scanf("%s", pattern);

	int length = my_strlen(pattern);

	for (int i = 0; i < T; i++){

		scanf("%s", str[i]);
		int ret;
		ret = match(i, length);

		if (ret == 1){
			printf("DA\n");
		}
		else if(ret==-1)printf("NE\n");

	}

	return 0;
}