#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
struct segtree{
 
	int size;
	vector<ll> mins;
 
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		mins.assign(2*size, 1e9);
	}
 
	void build(vector<int> &a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				mins[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		mins[x] = min(mins[2*x+1], mins[2*x+2]);
 
	}
 
	void build(vector<int> &a){
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			mins[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
 
		if(i < m){
			set(i, v, 2*x+1, lx, m);
		}
		else{
			set(i, v, 2*x+2, m, rx);
		}
		mins[x] = min(mins[2*x+1], mins[2*x+2]);
	}
 
	void set(int i, int v){
		set(i, v, 0, 0, size);
	}
 
	ll mn(int l, int r, int x, int lx, int rx){
		if(lx >= r or rx <= l) return 1e9;
		if(lx >= l and rx <= r) return mins[x];
		int m = (lx+rx)/2;
		ll s1 = mn(l, r, 2*x+1, lx, m);
		ll s2 = mn(l, r, 2*x+2, m, rx);
		return min(s1, s2);
	}
 
	ll mn(int l, int r){
		return mn(l, r, 0, 0, size);
	}
 
};
 
int main()
{
	int n, m;
	segtree st;
 
	cin >> n >> m;
	vector<int> a(n);
	st.init(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	st.build(a);
 
	while(m--){
		int opt;
		cin >> opt;
		if(opt==1){
			int i, v;
			cin >> i >> v;
			st.set(i, v);
			// for(int i=0;i<2*st.size;i++){
			// 	cout << st.mins[i] << " ";
			// }
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << st.mn(l, r) << endl;
		}
	}
}