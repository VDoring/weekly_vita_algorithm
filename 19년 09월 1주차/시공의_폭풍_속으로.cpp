//2020 05 24

/*
1. �������� ������ ������ȣ 4���� �迭�� �Է¹޴´�.
2. ���� �����ϰ��� �ϴ� ������ȣ 5���� �迭�� �Է¹޴´�.
3. �� �迭�� ���� ���Ѵ�. �̋� ������ -1�Ѵ�.
4. ������ ������ ������ �ƴ� �� �� ����Ѵ�.
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

/* Ǯ�� ���� �ڵ�

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