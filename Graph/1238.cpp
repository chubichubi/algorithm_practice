//1238
#include <stdio.h>
#pragma warning(disable:4996)
#define V_MAX 1000
#define E_MAX 10000
#define INFI 1000000000

typedef struct st {
	int front;
	int rear;
	int queue[V_MAX + 1];
}Q;

int adj[V_MAX + 1][V_MAX + 1];
int queued[V_MAX + 1];

int adj2[V_MAX + 1][V_MAX + 1];
int queued2[V_MAX + 1];

int V, E;
int S;
Q q;

void enqueue(int n)
{
	if ((q.rear + 1) % V_MAX == q.front) {
		//queue is full
	}
	else {
		q.queue[q.rear] = n;
		q.rear++;
		q.rear %= V_MAX;
	}
}

int dequeue(void)
{
	if (q.front == q.rear) {
		return -1;
		//empty
	}
	else {
		int tmp = q.queue[q.front];
		q.front++;
		q.front %= V_MAX;

		return tmp;
	}
}
//
//void print(int(*adj)[V_MAX + 1])
//{
//	for (int i = 1; i <= V; i++){
//		for (int j = 1; j <= V; j++){
//			printf("%10d ", adj[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

void dijkstra(int start, int(*a)[V_MAX + 1], int* queued)
{
	q.front = q.rear = 0;

	//init
	for (int i = 1; i <= V; i++) {
		if (a[start][i] != INFI) {
			enqueue(i);
			queued[i] = 1;
		}
	}

	int update = 1;

	while (update) {

		update = 0;

		int tmp = dequeue();
		if (tmp == -1)break;
		else {

			update = 1;
			queued[tmp] = 0;

			for (int i = 1; i <= V; i++) {
				if (i == start)continue;
				if (a[start][i] > a[start][tmp] + a[tmp][i]) {
					a[start][i] = a[start][tmp] + a[tmp][i];

					if (!queued[i])
					{
						enqueue(i);
						queued[i] = 1;
					}
				}
			}
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);

	scanf("%d %d %d", &V, &E, &S);

	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++) {
			adj[i][j] = INFI;
			adj2[i][j] = INFI;
		}

	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		adj[a][b] = c;
		adj2[b][a] = c;

	}

	dijkstra(S, adj, queued);

	dijkstra(S, adj2, queued2);


	int MAX = 0;
	for (int i = 1; i <= V; i++) {
		if (i == S)continue;
		else if (MAX < adj[S][i] + adj2[S][i]) {
			MAX = adj[S][i] + adj2[S][i];
		}
	}

	printf("%d\n", MAX);
}