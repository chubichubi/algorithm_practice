#include <stdio.h>
#define N_MAX 10001


typedef struct {
	int x;
	int y;
}POINT;

typedef struct st {
	int front;
	int rear;
	POINT queue[N_MAX];
} Q;


Q qu;
Q cheese;
int map[101][101];
int visit[101][101];
int H, W;

void enqueue(POINT n, Q* qu)
{
	if ((qu->rear + 1) % N_MAX == qu->front) {
		//full
	}
	else {
		qu->queue[qu->rear] = n;
		qu->rear++;
		qu->rear %= N_MAX;

	}
}

POINT dequeue(Q * qu)
{
	POINT ret = { -1,-1 };
	if (qu->front == qu->rear) {
		//empty
		return ret;
	}
	else {
		ret = qu->queue[qu->front];
		qu->front++;
		qu->front %= N_MAX;
		
		return ret;
	}
}


int main()
{

	freopen("input.txt", "r", stdin);

	int phase;
	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	POINT start = { 0,0 };

	enqueue(start, &qu);

	int past_cnt = 0;
	int cnt = 0;
	for (phase = 0;; phase++) {

		past_cnt = cnt;
		cnt = 0;

		for (;;) {

			POINT tmp = dequeue(&qu);

			if (tmp.x == -1)break;

			int x = tmp.x; int y = tmp.y;

			visit[x][y] = 1;
			POINT tmpq;

			if (x > 0 && visit[x - 1][y] == 0 && map[x - 1][y] == 0) {
				tmpq.x = x - 1;
				tmpq.y = y;
				enqueue(tmpq, &qu);
				visit[x - 1][y] = 1;
			}
			else if (x > 0 && visit[x - 1][y] == 0 && map[x - 1][y] == 1) {
				tmpq.x = x - 1;
				tmpq.y = y;
				enqueue(tmpq, &cheese);
				cnt++;
				visit[x - 1][y] = 1;
			}

			if (x < H - 1 && visit[x + 1][y] == 0 && map[x + 1][y] == 0) {
				tmpq.x = x + 1;
				tmpq.y = y;
				enqueue(tmpq, &qu);
				visit[x + 1][y] = 1;
			}
			else if (x < H - 1 && visit[x + 1][y] == 0 && map[x + 1][y] == 1) {
				tmpq.x = x + 1;
				tmpq.y = y;
				enqueue(tmpq, &cheese);
				cnt++;
				visit[x + 1][y] = 1;
			}

			if (y > 0 && visit[x][y - 1] == 0 && map[x][y - 1] == 0) {
				tmpq.x = x;
				tmpq.y = y - 1;
				enqueue(tmpq, &qu);
				visit[x][y - 1] = 1;
			}
			else if (y > 0 && visit[x][y - 1] == 0 && map[x][y - 1] == 1) {
				tmpq.x = x;
				tmpq.y = y - 1;
				enqueue(tmpq, &cheese);
				cnt++;
				visit[x][y - 1] = 1;
			}

			if (y < W - 1 && visit[x][y + 1] == 0 && map[x][y + 1] == 0) {
				tmpq.x = x;
				tmpq.y = y + 1;
				enqueue(tmpq, &qu);
				visit[x][y + 1] = 1;
			}
			else if (y < W - 1 && visit[x][y + 1] == 0 && map[x][y + 1] == 1) {
				tmpq.x = x;
				tmpq.y = y + 1;
				enqueue(tmpq, &cheese);
				cnt++;
				visit[x][y + 1] = 1;
			}

		}

		if (cnt == 0)break;

		for (;;) {
			POINT tmp = dequeue(&cheese);
			if (tmp.x == -1)break;
			visit[tmp.x][tmp.y] = 0;
			map[tmp.x][tmp.y] = 0;
			enqueue(tmp, &qu);
		}

	}

	printf("%d\n%d\n", phase, past_cnt);

	
	return 0;
}