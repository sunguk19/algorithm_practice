#include <iostream>
#include <stdio.h>

using namespace std;

int go(int cnt, int sum, int goal)
{
	if(sum > goal) return 0;
	if(sum == goal) return 1;
	int now = 0;
	for(int i = 1; i <= 3; i++) {
		now += go(cnt + 1, sum + i, goal);
	}
	return now;
}

int main()
{
	int t;
	scanf("%d", &t);
	
	while(t--) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		ans = go(0, 0, n);
		printf("%d\n", ans);
	}
	return 0;
}

