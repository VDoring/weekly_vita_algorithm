int binary_search(vector<int>& seq, int data) {
	int l = 0, r = seq.size() - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (seq[mid] == data)
			return mid;
		else if (seq[mid] < data)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return -1;
}

/*
이분 탐색(binary search)
= 이미 정렬된 배열에서 특정한 원소가 포함되어 있는지 아닌지를 빠르게 판단할 수 있는 기법.
  답을 직접 구하기는 어렵지만, 답을 가정할 수 있고 해당 답이 맞는지 틀린지 확인하는 문제에서 자주 사용한다.

판단 순서)
값 A를 찾고자 할떄, 값이 포함된 것으로 예상되는 범위의 가운데 값을 먼저 확인한다.
그다음, A와 가운데 원소를 비교하며 A가 있을 수 없는 곳은 탐색하지 않고 지나간다.
*/