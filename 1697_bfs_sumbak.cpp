#include <iostream>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main() 
{
	int n, m;
	const int max_size = 200000;
	bool check[max_size];
	int dist[max_size];

	fill_n(check, max_size, 0);
	fill_n(dist, max_size, -1);

	scanf("%d %d", &n, &m);
	
	check[n] = true;
	dist[n] = 0;
	queue<int> q;
	q.push(n);

	while(!q.empty()) {
		int now = q.front();
		q.pop();

		if(now - 1 >= 0) {
			if(check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;
			}
		}
		if(now + 1 < max_size) {
			if(check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;
			}
		}
		if(now * 2 < max_size) {
			if(check[now * 2] == false) {
				q.push(now * 2);
				check[now * 2] = true;
				dist[now * 2] = dist[now] + 1;
			}
		}
		printf("now = %d\n", now);
		if(now == m)
			break;

	}
	printf("%d\n", dist[m]);
	return 0;
}


