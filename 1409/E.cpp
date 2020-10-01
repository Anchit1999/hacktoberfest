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
	int t, n, k, x, y;
	cin >> t;
	vector<int> v;
	while(t--){
		v.clear();
		cin >> n >> k;
		for(int i=0;i<n;i++){
			cin >> x;
			v.pb(x);
		}
		for(int i=0;i<n;i++){
			cin >> y;
		}
		sort(v.begin(), v.end());
		for(int i: v)
			cout << i << " ";
		cout << endl;
		for(int i=0;i<n;i++){
			int a = upper_bound(v.begin(), v.end(), v[i]+k) - v.begin();
			int b = lower_bound(v.begin(), v.end(), v[n-i-1]-k) - v.begin();
			cout << a - i << " " << n - i - b << endl;
		}
	}
	return 0;
}