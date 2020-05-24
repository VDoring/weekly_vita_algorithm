//2020 05 24

/*
1. 팀원들이 선택한 영웅번호 4개를 배열에 입력받는다.
2. 내가 선택하고자 하는 영웅번호 5개를 배열에 입력받는다.
3. 두 배열을 서로 비교한다. 이떄 같으면 -1한다.
4. 팀원이 선택한 영웅이 아닌 수 를 출력한다.
*/

#include <iostream>
int main() {
	int teamchar[4];
	int mychar[5];
	int samechar_num = 5;

	std::cin >> teamchar[0] >> teamchar[1] >> teamchar[2] >> teamchar[3];
	std::cin >> mychar[0] >> mychar[1] >> mychar[2] >> mychar[3] >> mychar[4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			if (teamchar[i] == mychar[j]) samechar_num--;
		}
	}

	std::cout << samechar_num << std::endl;

	return 0;
}

/* 풀이 예시 코드

#include<iostream>
using namespace std;
int chk[100], num, ans;
int main() {
	for (int i = 0; i < 4; ++i) {
		scanf("%d", &num);
		chk[num] = 1;
	}
	for (int i = 0; i < 5; ++i) {
		scanf("%d", &num);
		if (chk[num] == 0) ++ans;
	}
	cout << ans;
}
*/