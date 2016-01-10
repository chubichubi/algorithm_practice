#include <stdio.h>
#define N_MAX 100

int N, M;
int adj[101][101];
int adj2[101][101];
int ans[101][101];

typedef struct st {
	int front;
	int rear;
	int queue[101];
} queue;

queue q;
int queued[101];

void enqueue(int n)
{
	if ((q.rear + 1) % N_MAX == q.front) {
		//queue is full

	}
	else {
		q.queue[q.rear] = n;
		q.rear++;
		q.rear %= N_MAX;
	}
}

int dequeue(void)
{
	int ret;
	if (q.rear == q.front) {
		//queue is empty
		return -1;
	}
	else {
		ret = q.queue[q.front];
		q.front++;
		q.front %= N_MAX;
	}

	return ret;
}

void graph(int (*adj)[101])
{

	for (int s = 1; s <= N; s++) {

		//init
		q.front = q.rear = 0;
		for (int i = 1; i <= N; i++) {
			if (adj[s][i] != 0) {
				enqueue(i);
				ans[s][i] = 1;
				queued[i] = 1;
			}
		}
		
		for (;;) {

			int tmp = dequeue();
			if (tmp == -1)break;

			queued[tmp] = 0;

			for (int i = 1; i <= N; i++) {
				if (adj[tmp][i] != 0) {

					if (queued[i] != 1) {
						enqueue(i);
						queued[i] = 1;
						ans[s][i] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	

	scanf("%d", &N);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;//heavy
		adj2[b][a] = 1;//light
	}

	//bell
	graph(adj);
	graph(adj2);


	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)continue;
			if (ans[i][j] == 0)cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}