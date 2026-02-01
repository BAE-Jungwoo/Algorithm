#include <iostream>
using namespace std;

void recursiveCount(int** paper, int& white, int& blue, int size) {
	bool allWhite = true, allBlue = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[i][j] == 0)	// 전부 하얀색일 때
				allBlue = false;
			else					// 전부 파란색일 때
				allWhite = false;
		}
	}

	if (allWhite) {
		white++;
		return;
	}
	if (allBlue) {
		blue++;
		return;
	}

	// 4 분할 동적 할당
	int newSize = size / 2;
	int** topLeft = new int* [newSize];
	int** topRight = new int* [newSize];
	int** bottomLeft = new int* [newSize];
	int** bottomRight = new int* [newSize];

	for (int i = 0; i < newSize; i++) {
		topLeft[i] = new int[newSize];
		topRight[i] = new int[newSize];
		bottomLeft[i] = new int[newSize];
		bottomRight[i] = new int[newSize];

		for (int j = 0; j < newSize; j++) {
			topLeft[i][j] = paper[i][j];
			topRight[i][j] = paper[i][j + newSize];
			bottomLeft[i][j] = paper[i + newSize][j];
			bottomRight[i][j] = paper[i + newSize][j + newSize];
		}
	}

	// 각 분할마다 재귀 호출
	recursiveCount(topLeft, white, blue, newSize);
	recursiveCount(topRight, white, blue, newSize);
	recursiveCount(bottomLeft, white, blue, newSize);
	recursiveCount(bottomRight, white, blue, newSize);
	
	for (int i = 0; i < newSize; i++) {
		delete[] topLeft[i];
		delete[] topRight[i];
		delete[] bottomLeft[i];
		delete[] bottomRight[i];
	}
	delete[] topLeft;
	delete[] topRight;
	delete[] bottomLeft;
	delete[] bottomRight;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int white = 0, blue = 0;		
	int** paper = new int* [n];		// 행 포인터 배열 생성
	for (int i = 0; i < n; i++) {
		paper[i] = new int[n];		// 각 행에 대한 열 배열 생성
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];		// 흰색: 0, 파란색: 1
		}
	}

	recursiveCount(paper, white, blue, n);
	cout << white << "\n" << blue << "\n";

	for (int i = 0; i < n; i++) {
		delete[] paper[i];
	}
	delete[] paper;
	return 0;
}