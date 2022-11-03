#include<iostream>
#include<stdio.h>
using namespace std;

int parent[1000001];
int arr[1001][1001];
int findparent(int x) { // x����� �θ� ã�Ƽ� ��ȯ
	if (parent[x] == x) return x;
	return parent[x] = findparent(parent[x]);
}
void merge(int x, int y) {
	x = findparent(x);
	y = findparent(y);

	if (x == y) // �̹� ���� �����̹Ƿ� ��ȯ
	{
		return;
	}
	if (x < y)
	{
		parent[y] = x;
	}
	else
	{
		parent[x] = y;
	}
}
int islinked(int x, int y) { //���� �����̶�� 1 �ٸ��� -1 ��ȯ
	x = findparent(x);
	y = findparent(y);
	if (x == y)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[k][i];
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			if (arr[k][i] == 1 && islinked(k, i) == -1)
			{
				merge(k, i);
			}
		}
	}
	int flag = 1;
	int bx = 0;
	cin >> bx;
	for (int k = 1; k < m; k++)
	{
		int nx;
		cin >> nx;
		if (islinked(bx, nx) == -1)
		{
			flag = -1;
		}
		bx = nx;
	}
	if (flag == 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}