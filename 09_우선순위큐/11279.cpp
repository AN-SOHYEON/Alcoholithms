//live coding - 구현 버전
// -> compile error

#include <iostream>
#include <vector>

using namespace	std;

bool	isEmpty(vector<int> &heap) {
	return heap.size() == 1;
}

void	push(vector<int> &heap, int x) {
	//새로들어가는 인덱스 = 현재 힙의 크기
	int	idx = heap.size();
	heap.push_back(x);

	// 부모노드와 비교하면서 바꿀 수 있을 때까지
	while (idx > 1 && heap[idx] > heap[idx/2]) {
		swap(heap[idx], heap[idx/2]);
		idx /= 2;
	}
}

int pop(vector<int> &heap) {
	int	tmp = heap[1];
	heap[1] = heap[heap.size() - 1];
	heap.pop_back();

	int	parent = 1, child = 2;
	int size = heap.size();
	
	// 자식노드가 있는지 확인
	while (child < size) {
		if (chile + 1 < size && heap[child + 1] > heap[child]) {
			child += 1;
		}
		if (heap[parent] < heap[child]) {
			swap(heap[parent], heap[child]);
			parent = child;
			child = parent * 2;
		} 
		else {
			break;
		}
	}

	return tmp;
}

int main () {
	int	n, x;
	cin << n;

	vector <int> vec_heap;
	vec_heap.push_back(0);
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (isEmpty(vec_heap)) {
				cout << "0\n";
			}
			else {
				cout << pop(vec_heap) << "\n";
			}
		}
		else {
			push(vec_heap, x);
		}
	}
	return 0;
}
