#include <stdio.h>
#define N_MAX 100000

typedef struct st{
	int heapSize = -1;
	int heap[N_MAX + 1];
} HEAP;

HEAP h;

void insertHeap(int num)
{
	int child, parent;

	h.heapSize++;

	h.heap[h.heapSize] = num;

	child = h.heapSize;

	while (child > 0){

		parent = (child - 1) / 2;

		if (h.heap[child] >= h.heap[parent]) break;
		else{
			int tmp = h.heap[child];
			h.heap[child] = h.heap[parent];
			h.heap[parent] = tmp;

			child = parent;
		}

	}

}

int getHeap(void)
{
	if (h.heapSize == -1)return 0;

	int ret = h.heap[0];
	int parent, child;

	h.heap[0] = h.heap[h.heapSize];

	h.heapSize--;

	parent = 0;
	
	while(parent<=(h.heapSize-1)/2){

		if (h.heapSize >= parent * 2 + 2){

			if (h.heap[parent * 2 + 1] > h.heap[parent * 2 + 2]){
				child = parent * 2 + 2;
			}
			else child = parent * 2 + 1;
		}
		else if (h.heapSize == parent * 2 + 1){
			child = parent * 2 + 1;
		}
		else break;

		if (h.heap[child] >= h.heap[parent]) break;
		else{
			int tmp = h.heap[child];
			h.heap[child] = h.heap[parent];
			h.heap[parent] = tmp;

			parent = child;
		}


	}

	return ret;
}

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
		int tmp;
		scanf("%d", &tmp);
		if(tmp!=0)insertHeap(tmp);
		else{
			printf("%d\n", getHeap());
		}
	}

	
	return 0;
}