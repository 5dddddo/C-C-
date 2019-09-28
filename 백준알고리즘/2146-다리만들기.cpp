//#include <iostream>
//#include <queue>
//#include <cstring>
//using namespace std;
//int map[100][100], n;
//bool visited[100][100];
//struct info {
//	int x, y, cnt;
//};
//void color(int, int, int);
//int bfs(int);
//int dir[4][2] = { {-1,0},{1,0},{0,-1},{0, 1} };
//int sec, res = 987654321;
//int main() {
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			cin >> map[i][j];
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			if (map[i][j] == 1 && !visited[i][j])
//				color(i, j, ++sec);
//
//	for (int i = 1; i <= sec; i++) {
//		memset(visited, false, sizeof(visited));
//		int ans = bfs(i);
//		if (ans < res) res = ans;
//	}
//	cout << res << endl;
//	return 0;
//}
//
//void color(int x, int y, int col) {
//	queue <info> que;
//	que.push({ x,y,col });
//	visited[x][y] = true;
//	map[x][y] = col;
//	while (!que.empty()) {
//		info tmp = que.front();
//		int x = tmp.x;
//		int y = tmp.y;
//		int cnt = tmp.cnt;
//		que.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dir[i][0];
//			int ny = y + dir[i][1];
//			if (nx >= 0 && ny >= 0 && nx < n &&ny < n) {
//				if (map[nx][ny] == 1 && !visited[nx][ny]) {
//					visited[nx][ny] = true;
//					map[nx][ny] = cnt;
//					que.push({ nx,ny,cnt });
//				}
//			}
//		}
//	}
//}
//
//int bfs(int num) {
//	queue <info> que;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			if (map[i][j] == num) {
//				visited[i][j] = true;
//				que.push({ i,j,0 });
//			}
//		}
//	}
//	while (!que.empty()) {
//		info tmp = que.front();
//		int x = tmp.x;
//		int y = tmp.y;
//		int cnt = tmp.cnt;
//		que.pop();
//		for (int i = 0; i < 4; i++) {
//			int nx = x + dir[i][0];
//			int ny = y + dir[i][1];
//			if (nx >= 0 && ny >= 0 && nx < n &&ny < n &&!visited[nx][ny]) {
//				if (map[nx][ny] != 0 && map[nx][ny] != num) return cnt;
//				visited[nx][ny] = true;
//				que.push({ nx,ny,cnt + 1 });
//			}
//		}
//	}
//
//
//}

#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include <string.h>
#define MAX_SIZE 100
#define INF 0x7fffffff

using namespace std;


//input
int n;//��ũ��
int map[MAX_SIZE][MAX_SIZE];//��

							//process
int visit[MAX_SIZE][MAX_SIZE];//�湮üũ
vector<pair<int, int> > land;//���� ������ ����
int land_number;//������ �ѹ� ���̱�
int visit_number;//�湮üũ �ѹ�

				 //direct
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

//������ �ѹ����̱� �Լ�
void land_mark(int x, int y)
{
	if (visit[x][y] == 1) return;
	visit[x][y] = 1;

	queue<pair<int, int> > q;
	q.push(make_pair(x, y));

	while (!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();

		map[x][y] = land_number;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny]) continue;
			if (!map[nx][ny]) continue;
			visit[nx][ny] = 1;

			q.push(make_pair(nx, ny));

		}
	}

	land_number++;
}

//�Ÿ��� �����ϴ� bfs�Լ� ln�� ���� �ѹ�
int dist(int x, int y, int ln)
{
	bool flag = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map[nx][ny] == 0)
		{
			flag = 1;
			break;
		}
	}

	if (!flag) return INF;//�� ���⿡ �ٴٰ� ������ ����
	visit_number++;

	queue<pair<pair<int, int>, int> > q;
	q.push(make_pair(make_pair(x, y), 0));

	while (!q.empty())
	{
		x = q.front().first.first;
		y = q.front().first.second;
		int weight = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n || visit[nx][ny] == visit_number) continue;

			if (map[nx][ny] == ln) continue;
			else if (map[nx][ny] != ln && map[nx][ny] != 0) return weight;

			visit[nx][ny] = visit_number;
			q.push(make_pair(make_pair(nx, ny), weight + 1));
		}
	}

	return INF;
}


int main()
{

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) land.push_back(make_pair(i, j));
		}
	}

	land_number = 1;

	for (int i = 0; i < land.size(); i++) land_mark(land[i].first, land[i].second);

	memset(visit, 0, sizeof(visit));
	int ret = INF;

	for (int i = 0; i < land.size(); i++)
	{
		int x = land[i].first;
		int y = land[i].second;
		ret = min(ret, dist(x, y, map[x][y]));
	}

	printf("%d\n", ret);


	return 0;

}
