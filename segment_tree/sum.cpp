#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
 
struct segtree{
 
	int size;
	vector<ll> sums;
 
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		sums.assign(2*size, 0LL);
	}
 
	void build(vector<int> &a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		sums[x] = sums[2*x+1] + sums[2*x+2];
 
	}
 
	void build(vector<int> &a){
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
 
		if(i < m){
			set(i, v, 2*x+1, lx, m);
		}
		else{
			set(i, v, 2*x+2, m, rx);
		}
		sums[x] = sums[2*x+1] + sums[2*x+2];
	}
 
	void set(int i, int v){
		set(i, v, 0, 0, size);
	}
 
	ll sum(int l, int r, int x, int lx, int rx){
		if(lx >= r or rx <= l) return 0;
		if(lx >= l and rx <= r) return sums[x];
		int m = (lx+rx)/2;
		ll s1 = sum(l, r, 2*x+1, lx, m);
		ll s2 = sum(l, r, 2*x+2, m, rx);
		return s1+s2;
	}
 
	ll sum(int l, int r){
		return sum(l, r, 0, 0, size);
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
	// for(int i=0;i<2*st.size;i++){
	// 	cout << st.sums[i] << " ";
	// }
	// cout << endl;
	while(m--){
		int opt;
		cin >> opt;
		if(opt==1){
			int i, v;
			cin >> i >> v;
			st.set(i, v);
			// for(int i=0;i<2*st.size;i++){
			// 	cout << st.sums[i] << " ";
			// }
		}
		else{
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << endl;
		}
	}
}
