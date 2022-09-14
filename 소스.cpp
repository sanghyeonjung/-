#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int arr[101][101];
int visit[101][101];
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
queue<pair<int, int>> q;
void bfs(int m, int n) {
	while (!q.empty())
	{
		int nowx = q.front().first;
		int nowy = q.front().second;
		q.pop();
		for (int k = 0; k < 8; k++)
		{
			int nx = nowx + dx[k];
			int ny = nowy + dy[k];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n)
			{
				if (arr[nx][ny] == 1)
				{
					arr[nx][ny] = 0;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}
int search(int m, int n, int cnt) {
	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[k][i] == 1)
			{
				q.push(make_pair(k, i));
				bfs(m, n);
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	while (true)
	{
		int m, n, a;
		cin >> m >> n;
		if (m == 0 && n == 0)
			return 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}
		cout << search(n, m, 0) << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
}