#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//정수형 n, s에 값 입력
	int n, s;
	cin >> n >> s;
	//배열과 비슷한 역할
	vector<int> seq(n);

	//i=0에서 n 미만까지 증가하며 seq 공간에 값 입력 
	for (int i = 0; i < n; ++i)
		cin >> seq[i];

	//seq 처음부터 끝까지 정렬
	sort(seq.begin(), seq.end());

	int l = 0, r = n - 1, ans = 0;

	//1이 r 이하인 동안
	while (l <= r) {
		//seq[l]값과 seq[r]값 더해서 sum에 저장
		int sum = seq[l] + seq[r];
		//만약 sum이 s보다 크다면 r 감소
		if (sum > s) --r;
		//만약 sum이 s보다 작다면 l 증가
		else if (sum < s) ++l;
		//둘 다 아니라면 l 증가, r 감소, ans 증가
		else {
			++l; --r; ++ans;
		}
	}
	cout << ans;
}

/*
배열 내 합이 S가 되는 순서쌍 찾기


두 개의 포인터를 이용해 양 끝 지점을 가리킨다.
(왼쪽 끝의 포인터를 l, 오른쪽 끝의 포인터를 r이라고 칭한다.)

이제 l <= r을 만족하는동안 이 작업을 반복한다.
- 두 개의 포인터가 가리키고 있는 원소의 합이 S보다 큰 경우 r을 감소시킨다.
- 두 개의 포인터가 가리키고 있는 원소의 합이 S보다 작은 경우 l을 증가시킨다.
- 두 개의 포인터가 가리카고 있는 원소의 합이 S와 같다면 l을 증가시키고 r을 감소시키거나 작업을 종료한다.
*/