#include <stdio.h>
#define N_MAX 101
int adj[101][101];
int visited[105];

typedef struct st {
	int front;
	int rear;
	int queue[101];
} Q;

Q q;

void enqueue(int n)
{
	if ((q.rear + 1) % N_MAX == q.front) {
		//full
	}
	else {
		q.queue[q.rear] = n;
		q.rear++;
		q.rear %= N_MAX;
	}
}

int dequeue(void)
{
	int ret = -1;
	if (q.front==q.rear) {
		//empty
		return ret;
	}
	else {
		ret = q.queue[q.front];
		q.front++;
		q.front %= N_MAX;
		return ret;
	}
}

int main()
{
	int N;
	int M;

	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	
	scanf("%d", &M);

	for (int i = 0; i < M; i++) {

		int a, b;
		scanf("%d %d", &a, &b);

		adj[a][b] = 1;
		adj[b][a] = 1;

	}

	
	for (int i = 2; i <= N; i++) {
		if (adj[1][i] == 1) {
			enqueue(i);
			visited[i] = 1;
			
		}
	}
	int tmp;
	while ((tmp = dequeue()) != -1) {

		for (int i = 1; i <= N; i++) {
			if (i == tmp)continue;
			else if (adj[tmp][i] == 1 && visited[i] != 1) {
				enqueue(i);
				visited[i] = 1;
				
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (visited[i] == 1)cnt++;
	}
	printf("%d\n", cnt);

	
	return 0;
}