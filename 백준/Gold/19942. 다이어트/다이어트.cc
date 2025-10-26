#include <iostream>
#include <vector>

using namespace std;

int N;
int mp, mf, ms, mv;
struct Food{
    int p, f, s, v, c;
};

vector<Food> foods;

int mc = 1e9;
vector<int> ans;

void input(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    foods.resize(N + 1);
    
    for(int i = 1; i <= N; i++){
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        foods[i] = {p, f, s, v, c};
    }
}

void DFS(int idx, vector<int> v){

    // 탐색할 필요없는 가지
    int np = 0, nf = 0, ns = 0, nv = 0, nc = 0;

    for(int i : v){
        Food food = foods[i];
        np += food.p;
        nf += food.f;
        ns += food.s;
        nv += food.v;
        nc += food.c;
    }

    // 필요없는 가지
    if(nc > mc) return;
    
    if(np >= mp && nf >= mf && ns >= ms && nv >= mv && nc < mc){
        ans = v;
        mc = nc;
        return;
    }

    // 종료
    if(idx > N) return;

    // idx번을 포함
    v.push_back(idx);
    DFS(idx + 1, v);
    v.pop_back(); // 백트래킹

    // idx번을 포함x
    DFS(idx + 1, v);

    return;
}

void solve(){
    vector<int> v;
    DFS(1, v);
}

int main(){
    input();
    solve();
    
    if(mc == 1e9) cout << -1 << "\n";
    else{
        cout << mc << "\n";
        for(int n : ans) cout << n << " ";
        cout << "\n";
    } 

    return 0;
}