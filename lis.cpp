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
const int N = 1010;
int n;
int arr[N];

void print_seq(int seq[], int idx){

	int i = idx;
	cout << arr[i] << " ";
	while(seq[i] != -1){
		cout << arr[seq[i]] << " ";
		i = seq[i];
	}
	cout << endl;
}

void lis_n2(){
	int length[n], seq[n];
	for(int i=0;i<n;i++){
		seq[i] = -1;
		length[i] = 1;
	}
	int lis = 0, idx = 0;
	for(int i=0;i<n;i++){
		for(int j=i-1;j >= 0; j--){
			if(arr[i] >= arr[j]){
				if(length[i] <= length[j] + 1){
					length[i] = length[j] + 1;
					lis = max(lis, length[i]);
					seq[i] = j;
				}
			}
		}
		if(length[i] > length[idx]){
			idx = i;
		}
	}
	cout << lis << endl;
	print_seq(seq, idx);
}

void lis_nlogn(){
	int length[n+1], seq[n+1];
	for(int i=0;i<n+1;i++){
		seq[i] = -1;
		length[i] = -1;
	}
	int lis = 0, max_idx = 1;
	length[1] = 0;
	for(int i=1;i<n;i++)
	{
		int l = 1, h = max_idx, mid;
		mid = (l+h) / 2;
		while(l <= h){
			mid = (l+h) / 2;
			int k = length[mid];
			if(arr[k] < arr[i]){
				l = mid + 1;
			}
			else
				h = mid - 1;
		}
		length[l] = i;
		seq[i] = length[l-1];
		max_idx = max(max_idx, l);
	}
	cout << max_idx << endl;
	print_seq(seq, length[max_idx]);
}

int main()
{
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	lis_n2();
	lis_nlogn();
	return 0;
}
