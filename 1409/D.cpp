#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define pb push_back
#define mp make_pair
typedef long long int ll;
typedef long double ld;
#define pii pair<int,int>
#define pll pair<ll,ll>

int main()
{
	ll t, n, s;
	ll p[20] = {0};
	p[0] = 1ll;
	p[1] = 1ll;
	for(ll i=2;i<20;i++)
		p[i] = 10ll*p[i-1];
	cin >> t;
	while(t--){
		cin >> n >> s;
		ll nn = n;
		vector<ll> v;
		while(nn > 0){
			v.pb(nn%10);
			nn/=10;
		}
		// for(int k: v) cout << k << " ";
		// 	cout << endl;
		ll ans = 0, sm = 0, i;
		ll V = (ll) v.size();
		for(i=V-1;i>=0;i--){
			if(sm + v[i] <= s){
				sm += v[i];
				ans += (v[i]*p[i+1]);
				// cout << ans << endl;
				if(n == ans) break;
				if(sm == s and n > ans){
					ans -= (v[i]*p[i+1]);
					break;
				}
			}
			else break;
		}
		if(n - ans > 0 and ans == 0){
			ans = p[V+1];
		}
		else if(ans != n){
			ans += p[i+2];
		}
		cout << ans-n << endl;

	}
	return 0;
}