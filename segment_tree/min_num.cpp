#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pll pair<ll, ll>
struct segtree{
 
	int size;
	vector<ll> mins, minno;
 
	void init(int n){
		size = 1;
		while(size < n) size *= 2;
		mins.assign(2*size, 1e9);
		minno.assign(2*size, 0);
	}
 
	void build(vector<int> &a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				mins[x] = a[lx];
				minno[x] = 1;
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		if(mins[2*x+1] == mins[2*x+2]){
			mins[x] = mins[2*x+1];
			minno[x] = minno[2*x+1] + minno[2*x+2];
		}
		else if(mins[2*x+1] > mins[2*x+2]){
			mins[x] = mins[2*x+2];
			minno[x] = minno[2*x+2];
		}
		else{
			mins[x] = mins[2*x+1];
			minno[x] = minno[2*x+1];	
		}
	}
 
	void build(vector<int> &a){
		build(a, 0, 0, size);
	}
 
	void set(int i, int v, int x, int lx, int rx){
		if(rx - lx == 1){
			mins[x] = v;
			minno[x] = 1;
			return;
		}
		int m = (lx + rx) / 2;
 
		if(i < m){
			set(i, v, 2*x+1, lx, m);
		}
		else{
			set(i, v, 2*x+2, m, rx);
		}
		if(mins[2*x+1] == mins[2*x+2]){
			mins[x] = mins[2*x+1];
			minno[x] = minno[2*x+1] + minno[2*x+2];
		}
		else if(mins[2*x+1] > mins[2*x+2]){
			mins[x] = mins[2*x+2];
			minno[x] = minno[2*x+2];
		}
		else{
			mins[x] = mins[2*x+1];
			minno[x] = minno[2*x+1];	
		}
	}
 
	void set(int i, int v){
		set(i, v, 0, 0, size);
	}
 
	pll mn(int l, int r, int x, int lx, int rx){
		if(lx >= r or rx <= l) return make_pair(1e9 ,0);
		if(lx >= l and rx <= r) return make_pair(mins[x], minno[x]);
		int m = (lx+rx)/2;
		pll p1 = mn(l, r, 2*x+1, lx, m);
		pll p2 = mn(l, r, 2*x+2, m, rx);
		if(p1.first == p2.first)
			return make_pair(p1.first, p1.second + p2.second);
		else if(p1.first > p2.first)
			return p2;
		else return p1;
	}
 
	pll mn(int l, int r){
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
			pll v = st.mn(l, r);
			cout << v.first << " " << v.second << endl;
		}
	}
}