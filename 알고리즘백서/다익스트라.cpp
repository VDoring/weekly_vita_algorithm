/*
다익스트라(dijstra) 알고리즘
= 최단 경로를 찾기 위해 사용한다.
  하나의 출발점으로부터 모든 정점까지의 최단거리를 계산하는 알고리즘 기법이다.

순서)
1. 시작 정점을 결정한다.
2. 시작 정점을 제외한 모든 정점까지의 거리를 무한대(매우 큰 수)로 설정한다.
3. 현재 위치에서 갈 수 있는 모든 정점을 확인한다. 만약 해당 정점이 현재까지 기록한 거리보다 더 짧은 경로로 이동할 수 있다면 갱신하고, 그렇지 않다면 갱신하지 않고 넘어간다.
4. 아직 선택하지 않았던 정점들 중 가장 짧은 거리에 있는 정점을 현재 정점으로 선택한다.
5. 3~4과정을 반복한다.

*/

/* 다익스트라 알고리즘 간단 코드 구현 */
int minV = 0, minDist = 1e9;
for (int i = 1; i < v; ++i) {
	if (minDist > dist[i]) {
		minV = i;
		minDist = dist[i];
	}
}
//다음 정점과 연결된 간선 확인


/*
우선순위 큐(priority queue):
큐와 비슷한 성질을 갖지만 가장 먼저 들어온 데이터를 먼저 처리하는 것이 아닌, 각 데이터마다 가지고 있는 우선순위를 이용해 우선순위가 가장 높은 데이터를 먼저 처리하는 자료구조이다.

사용시 시작점으로부터 거리가 가장 짧은 지점을 매번 선택하는 것이 아니라, 전체 이동 거리를 우선순위 큐에 넣으며 항상 거리가 가장 짧은 지점을 선택하여 다음 정점까지의 거리를 갱신할 수 있다.
*/

/* 우선순위 큐를 통해 작성된 다익스트라 알고리즘 코드(C++14 기반) */
#define VMAX 101010	//정점의 최대 개수
const int inf = 1e9;
struct EDGE {	//간선의 정보를 저장하기 위한 구조체
	int to, w;
};
vector<EDGE> adj[VMAX];	//인접 리스트를 이용하여 그래프의 정보를 저장
bool operator < (EDGE e1, EDGE e2) {	//우선순위 큐를 이용하기 위해 연산자 '<'를 오버로딩(오름차순 정렬)
	return e1.w > e2.w;
}
vector<int> dijkstra(int s) {	//s = 시작점
	vector<int> ans(VMAX);	//시작점으로부터 최단 거리를 저장 할 배열
	for (int i = 0; i < ans.size(); ++i)
		ans[i] = inf;	//시작점으로부터의 거리를 매우 큰 수로 초기화
	priority_queue<EDGE> q;
	q.push({ s, 0 });	//우선순위 큐에 시작점과 그 거리를 저장
	ans[s] = 0;
	while (q.size()) {
		int cur = q.top().to, d = q.top().w;	//현재 위치에서 가장 가까운 곳에 있는 정점을 현재 정점으로 선택
		q.pop();
		for (int i = 0; i < adj[cur].size(); ++i) {	//현재 정점에서 방문할 수 있는 모든 정점 확인
			int nextV = adj[cur][i].to, nextD = adj[cur][i].w + d;
			if (ans[nextV] > nextD) {	//만약 다음 정점까지의 거리가, 기록해둔 거리보다 짧은 경우
				ans[nextV] = nextD;	//거리 갱신
				q.push({ nextV, nextD });
			}
		}
	}
	return ans;
}