#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

long long readInt(long long l,long long r,char endd){
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true){
		char g=getchar();
		if(g=='-'){
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g && g<='9'){
			x*=10;
			x+=g-'0';
			if(cnt==0){
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);
 
			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd){
			if(is_neg){
				x= -x;
			}
			if(!(l<=x && x<=r))cerr<<l<<"<="<<x<<"<="<<r<<endl;
			assert(l<=x && x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l,int r,char endd){
	string ret="";
	int cnt=0;
	while(true){
		char g=getchar();
		assert(g!=-1);
		if(g==endd){
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt && cnt<=r);
	return ret;
}
long long readIntSp(long long l,long long r){
	return readInt(l,r,' ');
}
long long readIntLn(long long l,long long r){
	return readInt(l,r,'\n');
}
string readStringLn(int l,int r){
	return readString(l,r,'\n');
}
string readStringSp(int l,int r){
	return readString(l,r,' ');
}
template<class T>
vector<T> readVector(int n, long long l, long long r){
    vector<T> ret(n);
    for(int i = 0; i < n; i++){
	ret[i] = i == n - 1 ? readIntLn(l, r) : readIntSp(l, r);
    }
    return ret;
}

map<vector<int>, vector<vector<vector<int>>>> mp;
vector<vector<vector<int>>> gen_partitions(vector<int> v){
	if(mp.find(v) != mp.end()) return mp[v];
	int n = sz(v);
	if(n == 1) return {{{v[0]}}};
	vector<vector<vector<int>>> ret;
	for(int mask = 0; mask < (1 << (n - 1)); mask++){
		vector<int> curr;
		vector<int> V = v; V.pop_back();
		for(int j = 0; j < (n - 1); j++) if(mask >> j & 1){
			curr.push_back(v[j]);
			V.erase(find(all(V), v[j]));
		}
		curr.push_back(v.back());
		if(V.empty()){
			ret.push_back({curr});
			continue;
		}
		vector<vector<vector<int>>> parts = gen_partitions(V);
		for(auto & it : parts){
			it.push_back(curr);
		}
		copy(all(parts), back_inserter(ret));
	}
	return mp[v] = ret;
}
const int N = 1000006;
int factor[N];

int get(int n, int k){
    vector<int> PE;
    while(n != 1){
	int p = factor[n];
	int pe = 1;
	while(n % p == 0) n /= p, pe *= p;
	PE.push_back(pe);
    }
    vector<int> v(PE.size());
    iota(all(v), 0);
    mp.clear();
    vector<vector<vector<int>>> P = gen_partitions(PE);
    int ans = INT_MAX;
    for(auto it : P){
	int l = it.size();
	if(l > k) continue;
	int here = k - l;
	for(auto H : it){
	    int prod = 1;
	    for(int u : H){
	        prod *= u;
	    }
	    here += prod;
	}
	ans = min(ans, here);
    }
    return ans;
}
int main(){
    int t = readIntLn(1, 40);
    for(int i = 2; i < N; i++) if(!factor[i]){
	for(int j = i; j < N; j += i) factor[j] = i;
    }
    while(t--){
	int k = readIntSp(1, 1000000), n = readIntLn(1, 1000000);
	cout << get(n, k) << endl;
    }
}