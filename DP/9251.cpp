#include <stdio.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

char str1[1001];
char str2[1001];
int map[1001][1001];

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

int main()
{
	
	scanf("%s", str1);
	scanf("%s", str2);

	int length1 = my_strlen(str1);
	int length2 = my_strlen(str2);

	for (int i = 1; i <= length1; i++){

		for (int j = 1; j <= length2; j++){

			if (str1[i - 1] == str2[j - 1]){
				map[i][j] = map[i-1][j-1] + 1;
			}
			else map[i][j] = MAX(map[i - 1][j], map[i][j - 1]);

		}


	}

	/*for (int i = 0; i <= length1; i++){
		for (int j = 0; j <= length2; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}*/
	
	printf("%d\n", map[length1][length2]);

	return 0;
}