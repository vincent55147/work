#include <stdio.h>

void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

int heap[1000001], size;
void init() {
	size = 1;
}
bool empty() {
	return size == 1;
}
void push(int n) {
	heap[size++] = n;
	int now = size - 1;
	while (now>1 && heap[now] < heap[now / 2]) {
		swap(heap[now], heap[now / 2]);
		now /= 2;
	}
}
int top() {
	return heap[1];
}
void pop() {
	heap[1] = heap[--size];
	int now = 1, next;
	while (now * 2 < size) {
		next = now * 2;
		if (now * 2 + 1 < size && heap[now * 2 + 1] < heap[now * 2])
			next = now * 2 + 1;
		if (heap[now] > heap[next]) {
			swap(heap[now], heap[next]);
			now = next;
		}
		else break;
	}
}

int main() {
	int T, ins, n;
	scanf("%d", &T);
	init();
	while (T--) {
		scanf("%d", &ins);
		if (ins == 1) {
			scanf("%d", &n);
			push(n);
		}
		else {
			if (empty()) printf("empty!\n");
			else {
				printf("%d\n", top());
				pop();
			}
		}
	}
	return 0;
}
