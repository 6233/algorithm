#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

class tomato
{
	int first;
	int second;
	int count;
public:
	tomato()
	{
		first;
		second;
		count;
	}
	tomato(int x, int y, int cnt)
	{
		first = x;
		second = y;
		count=cnt;
	}
	int get_first()
	{
		return first;
	}

	int get_second()
	{
		return second;
	}
	int get_count()
	{
		return count;
	}
};

queue<tomato> q;
int a[1002][1002];

int main()
{
	int result = 0;
	
	memset(a, 2, sizeof(a));
	int n, m;
  int count  = 0;

	cin >> m >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
      if (a[i][j] > 0) {
        notAllzero = true;
      }
    }

  if (!notAllzero) {
    cout << -1 << '\n';
    return 0;
  }
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == 1)
			{
				q.push(tomato(i,j,0));
			}

	if (q.empty())
	{
		cout << result << '\n';
		return 0;
	}
	while (!q.empty())
	{
			if (a[q.front().get_first() - 1][q.front().get_second()] == 0)
			{
				q.push(tomato(q.front().get_first() - 1, q.front().get_second(), q.front().get_count()+1));
				a[q.front().get_first() - 1][q.front().get_second()] = 1;
			}
			if (a[q.front().get_first() +1][q.front().get_second()] == 0)
			{
				q.push(tomato(q.front().get_first() + 1, q.front().get_second(), q.front().get_count()+1));
				a[q.front().get_first() + 1][q.front().get_second()] = 1;
			}
			if (a[q.front().get_first()][q.front().get_second()-1] == 0)
			{
				q.push(tomato(q.front().get_first(), q.front().get_second()-1, q.front().get_count()+1));
				a[q.front().get_first() ][q.front().get_second()-1] = 1;
			}
			if (a[q.front().get_first()][q.front().get_second() + 1] == 0)
			{
				q.push(tomato(q.front().get_first(), q.front().get_second() + 1, q.front().get_count()+1));
				a[q.front().get_first()][q.front().get_second()+1] = 1;
			}

			if (q.front().get_count() >= result)
				result = q.front().get_count();
			q.pop();
	}

	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			if (a[i][j] == 0) {
				cout << "-1" << '\n';
				return 0;
			}

	cout << result << '\n';

	return 0;
}
