#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
//Geometry functions
//https://cp-algorithms.com/geometry/check-segments-intersection.html
struct pt {
  ll x, y;
  pt() {}
  pt(ll _x, ll _y) : x(_x), y(_y) {}
  pt operator-(const pt& p) const { return pt(x - p.x, y - p.y); }
  ll cross(const pt& p) const { return x * p.y - y * p.x; }
  ll cross(const pt& a, const pt& b) const { return (a - *this).cross(b - *this); }
};
ll d2(pt a, pt b){
  ll dx = a.x - b.x;
  ll dy = a.y - b.y;
  return dx * dx + dy * dy;
}
int sgn(const ll& x) { return x >= 0 ? x ? 1 : 0 : -1; }

bool inter1(ll a, ll b, ll c, ll d) {
  if (a > b)
    swap(a, b);
  if (c > d)
    swap(c, d);
  return max(a, c) <= min(b, d);
}

bool check_inter(const pt& a, const pt& b, const pt& c, const pt& d) {
  if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
    return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
  return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
    sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}
//End Geometry functions

const ll mxc = 1000000;
const int mxn = 2e4 + 10;
const int mxm = 5e3 + 10;

int n, m;
//wire i is positive if sgn[i] = 1
//wire i is negative if sgn[i] = -1
int sign[mxm];
int get_score(vector<pt> cities, vector<vector<pt>> wires, vector<int> h, vector<int> v){
    for(int i = 0; i < mxm; i++) {
        sign[i] = 0;
    }
  //positive plate
  sign[m] = 1;
  //negative plate
  sign[m + 1] = -1;

  //move wires 
  ll P = 0;
  for (int i = 0; i < m; i++){
    ll di = h[i], vi = v[i];
    if(-mxc > di || di > mxc) {
        return 1e18;
    }
    if(-mxc > vi || vi > mxc) {
        return 1e18;
    }
    for (int j = 0; j < 2; j++){
      wires[i][j].x += di;
      wires[i][j].y += vi;
    }
    P += (di*di + vi*vi);
  }

  //pn[0] = all positive wires, pn[1] = all negative wires
  vector<int> pn[2];
  for (int it = 0; it < 2; it++){
    queue<int> q;
    //bfs starting from the plate
    q.push(m + it);
    while (!q.empty()){
      int u = q.front();
      q.pop();
      if (u < m) pn[it].push_back(u);
      pt a = wires[u][0];
      pt b = wires[u][1];
      for (int v = 0; v < m; v++){
        //sgn[v]=0 or there is short-circuit
        if (sign[v] != sign[u]){
          pt c = wires[v][0];
          pt d = wires[v][1];
          if (check_inter(a, b, c, d)){
            //no short-circuits
            if(sign[v] == -sign[u]) return 1e18;
            if(sign[v] != 0) 1e18;
            sign[v] = sign[u];
            q.push(v);
          }
        }
      }
    }
  }
  //at least one positive/negative wire
  if(pn[0].empty()) return 1e18;
  if(pn[1].empty()) return 1e18;

  ll Q = 0;
  for (int i = 0; i < n; i++){
    pt city = cities[i];
    for(int it = 0; it < 2; it++){
      ll best = -1;
      for (int j : pn[it]){        
        ll better = min(d2(wires[j][0], city), d2(wires[j][1], city));
        if (best == -1 || better < best){
          best = better;
        }
      }
      Q += best;
    }
  }
  ll score = P + Q;
  // cerr << "score = " << score / 1e15 << endl;
  return score;
}


struct PT {
    int x1, y1, x2, y2, idx;
    long double slope;

    void read() {
        cin >> x1 >> y1 >> x2 >> y2;
        slope = (long double) (y2 - y1) / (x2 - x1);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<pt> cities(n);
    vector<vector<pt>> wires(m);

    vector<int> X(n), Y(n);
    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
        cities[i].x = X[i];
        cities[i].y = Y[i];
    }

    vector<PT> pts[2];
    for(int i = 0; i < m; i++) {
        PT p;
        p.idx = i;
        p.read();
        wires[i].push_back({p.x1, p.y1});
        wires[i].push_back({p.x2, p.y2});
        pts[p.slope > 0].push_back(p);
    }
    wires.push_back({{-1, 0}, {0, -1}});
    wires.push_back({{mxc + 1, mxc},{mxc, mxc+1}});

    vector<int> H(m), V(m);
    int best_score = 1e18;
    int best_per = -1;
    int best_divisions = -1;

    for(int divisions = 9; divisions <= 15; divisions++) {
        for(int per : {5, 7, 9, 12}) {
            for(int pos : {0, 1}) {
                for(auto& p: pts[pos]) {
                    if(p.x1 > p.x2) {
                        swap(p.x1, p.x2);
                        swap(p.y1, p.y2);
                    }
                }
            }
            vector<int> h(m), v(m);
            int pvx = -1, pvy = 0;
            int pos = 1;
            vector<bool> taken(m, 0);

            const int MAX = 1e6;
            int B1 = MAX * per / 100;
            int B2 = (100 - per) * MAX / 100;


            int border[divisions + 1];
            int pos_x[2][divisions + 1], pos_y[2][divisions + 1];

            for(int i = 0; i <= divisions; i++) {
                border[i] = i * MAX / divisions;
            }



            vector<int> cnt(3, 0);

            for(int rep = 0; rep < 2; rep++) {

                int cont = 0;

                for(int it = 0; it < m; it++) {
                    int best = 1e18;
                    PT chosen;
                    chosen.idx = -1;
                    bool found = false;
                    for(auto p: pts[pos]) {
                        if(taken[p.idx]) continue;
                        int x = p.x1, y = p.y1;
                        int dist = (x - pvx) * (x - pvx) + (y - pvy) * (y - pvy);
                        int dx = pvx - x, dy = pvy - y;
                        if(dist < best && abs(dx) <= 1e6 && abs(dy) <= 1e6) {
                            if(rep == 0 && p.y2 + dy <= B1 && p.y2 + dy >= 0) {
                                best = dist;
                                chosen = p;
                                found = true;
                            }
                            if(rep == 1 && p.y2 + dy <= 1e6 && p.y2 + dy >= B2) {
                                best = dist;
                                chosen = p;
                                found = true;
                            }
                        }
                    }
                    if(!found) {
                        if(cont == 1) {
                            break;
                        }
                        it--;
                        cont = 1;
                        pos ^= 1;
                        continue;
                    }
                    if(chosen.x2 + pvx - chosen.x1 > 1e6 || chosen.x2 + pvx - chosen.x1 < 0) break;
                    cnt[rep]++;
                    taken[chosen.idx] = true;
                    h[chosen.idx] = pvx - chosen.x1, v[chosen.idx] = pvy - chosen.y1;
                    pvx = chosen.x2 + h[chosen.idx], pvy = chosen.y2 + v[chosen.idx];
                    cont = 0;
                    for(int i = 0; i < divisions; i++) {
                        if(pvx > border[i] && pvx < border[i + 1]) {
                            pos_x[rep][i] = pvx;
                            pos_y[rep][i] = pvy;
                        }
                    }
                }


                if(rep == 0) {
                    pvx = 1e6 + 1, pvy = 1e6;
                    pos = 1;
                    for(int pos : {0, 1}) {
                        for(auto& p: pts[pos]) {
                            swap(p.x1, p.x2);
                            swap(p.y1, p.y2);
                        }
                    }
                }
            }

            // cout << cnt[0] << " " << cnt[1] << '\n';

            for(int pos : {0, 1}) {
                for(auto& p: pts[pos]) {
                    if(p.y1 > p.y2) {
                        swap(p.x1, p.x2);
                        swap(p.y1, p.y2);
                    }
                }
            }


            for(int rep = 0; rep < 2; rep++) {

                for(int w = rep; w < divisions; w += 2) {
                    int cont = 0;

                    pvx = pos_x[rep][w], pvy = pos_y[rep][w];


                    for(int it = 0; it < m; it++) {
                        int best = 1e18;
                        PT chosen;
                        chosen.idx = -1;
                        bool found = false;
                        for(auto p: pts[pos]) {
                            if(taken[p.idx]) continue;
                            int x = p.x1, y = p.y1;
                            int dist = (x - pvx) * (x - pvx) + (y - pvy) * (y - pvy);
                            int dx = pvx - x, dy = pvy - y;
                            if(dist < best && abs(dx) <= 1e6 && abs(dy) <= 1e6) {
                                if(p.x2 + dx >= border[w] && p.x2 + dx < border[w + 1]) {
                                    best = dist;
                                    chosen = p;
                                    found = true;
                                }
                            }
                        }
                        if(!found) {
                            if(cont == 1) {
                                break;
                            }
                            it--;
                            cont = 1;
                            pos ^= 1;
                            continue;
                        }
                        if(rep == 0 && chosen.y2 + pvy - chosen.y1 >= B2) {
                            break;
                        }
                        if(rep == 1 && chosen.y2 + pvy - chosen.y1 <= B1) {
                            break;
                        }
                        cnt[rep]++;
                        taken[chosen.idx] = true;
                        h[chosen.idx] = pvx - chosen.x1, v[chosen.idx] = pvy - chosen.y1;
                        pvx = chosen.x2 + h[chosen.idx], pvy = chosen.y2 + v[chosen.idx];
                        cont = 0;
                    }

                }
                if(rep == 0) {
                    pos = 1;
                    for(int pos : {0, 1}) {
                        for(auto& p: pts[pos]) {
                            swap(p.x1, p.x2);
                            swap(p.y1, p.y2);
                        }
                    }
                }
            }

            int cur_score = get_score(cities, wires, h, v);
            // cout << divisions << " " << cur_score << '\n';
            if(cur_score < best_score) {
                best_score = cur_score;
                best_per = per;
                best_divisions = divisions;
                H = h;
                V = v;
            }
        }
    }

    cerr << "best_score = " << best_score << " " << " best_per = " << best_per << " best_divisions = " << best_divisions << '\n';

    // cout << cnt[0] << " " << cnt[1] << '\n';

    for(int i = 0; i < m; i++) {
        cout << H[i] << " " << V[i] << '\n';
    }

    return 0;
}