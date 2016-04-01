#include <cstdio>

const int Maxn = int(1e7) + 10;
int t, a, b, ans = 0;
int prime[664600], mu[Maxn];
bool vis[Maxn];

void get_prime()
{
	mu[1] = 1;
	for(int i = 2; i <= Maxn; ++i)
	{
		if(!vis[i])
		{
			prime[++prime[0]] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= prime[0] && i * prime[j] <= Maxn; ++j)
		{
			vis[prime[j] * i] = true;
			if(i % prime[j] == 0)
			{
				mu[i * prime[j]] = 0;
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
}

void swap(int& a, int& b)
{
	a ^= b; b ^= a; a ^= b;
	return;
}

int main()
{
    freopen("4491.txt", "r", stdin);
	get_prime();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		if(a > b) swap(a, b);
		for(int i = 1; i <= prime[0] && prime[i] <= a; ++i)
			for(int j = 1, la = 0; j <= a / prime[i]; j = la+1)
            {
                la = min(a / ())
				ans += mu[j] * (a / (j*prime[i]) * (b / (j*prime[i])));
            }
		printf("%d\n", ans);
		ans = 0;
	}
}
