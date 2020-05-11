#include <stdio.h>

int count_down(int second) {
	if (second == 0) { //기저사례 (제귀함수의 끝)
		return 0;
	}
	else {
		printf("%d조 ", second);
		count_down(second - 1); //함수 안의 함수 사용: 재귀함수
	}
}

int main() {
	count_down(5);

	return 0;
}

/*
완전탐색 : 발생 가능한 모든 경우의 수를 확인하는 방법
- 입력으로 주어지는 수가 작은 경우 쉽게 사용할 수 있다.
- 단, 시간이 오래 걸리는 경우가 많으니 완전 탐색으로 구현하기 전 시간복잡도를 먼저 계산해보는게 좋다.

방법은 크게 두가지로 나뉜다.
1. for문과 if문 사용
2. 재귀 함수

재귀함수를 사용할 떄는 기저 사례를 설정해야하며, 재귀 함수의 깊이가 너무 깊어지지 않도록 주의해야한다.

*/