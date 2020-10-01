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
	int t, n, x, y;
	cin >> t;
	while(t--){
		cin >> n >> x >> y;
		vector<int> ans;
		ans.clear();
		ans.pb(x);ans.pb(y);
		int i, j, idx = -1, mx = -1;
		int diff = y-x;
		n -= 2;
		for(i=1;i<=diff;i++){
			if(diff % i == 0){
				int z = diff/i - 1;
				// cout << "i: " << i << endl;
				if(z <= n){
					if(z > mx){
						mx = z;
						idx = i;
					}
				}
			}
		}
		i = idx;
		for(j=x+i;j<y and n > 0;j+=i){
			ans.pb(j);
			n--;
		}
		j = x-i;
		while(n > 0 and j > 0){
			ans.pb(j);
			n--;
			j-=i;
		}
		j = y + i;
		while(n > 0){
			ans.pb(j);
			j+=i;
			n--;
		}
		for(auto k: ans) cout << k << " ";
		cout << endl;

	}
	return 0;
}