#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, s;
	cin >> n >> s;
	vector<int> seq(n);

	for (int i = 0; i < n; ++i)
		cin >> seq[i];

	sort(seq.begin(), seq.end());

	int l = 0, r = n - 1, ans = 0;

	while (l <= r) {
		int sum = seq[l] + seq[r];
		if (sum > s) --r;
		else if (sum < s) ++l;
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