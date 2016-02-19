#include <stdio.h>


int stack[10001];
int stkptr = -1;

int pop()
{
	int ret = -1;
	
	if (stkptr >= 0){
		ret = stack[stkptr];
		stkptr--;
	}
	return ret;

}

void push(int n)
{
	stkptr++;
	stack[stkptr] = n;
}

char command[10];

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){



		scanf("%s", command);

		if (command[0] == 'p' && command[1] == 'u'){

			int tmp;
			scanf("%d", &tmp);
			push(tmp);

		}
		else if (command[0] == 'p' && command[1] == 'o'){

			int tmp = pop();

			printf("%d\n", tmp);

		}
		else if (command[0] == 't'){
			//top
			if(stkptr>=0)printf("%d\n", stack[stkptr]);
			else printf("-1\n");
		}
		else if (command[0] == 's'){
			//size
			printf("%d\n", stkptr + 1);
		}
		else if (command[0] == 'e'){
			//empty
			if (stkptr == -1)printf("1\n");
			else printf("0\n");
		}

	}

	return 0;
}