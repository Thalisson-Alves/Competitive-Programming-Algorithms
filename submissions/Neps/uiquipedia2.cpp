//iagorrr ;)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main(){
    fast
    int n;
    cin >> n;

    // lendo todas as strings  referências.
    vector <pair<string, string>> refs(n);

    map<string,bool> checkpaginas;
    vector <string> paginas;
    for(int i = 0; i < n; ++i){
        string a, b;
        cin >> a >> b;
        refs[i].first = a;
        refs[i].second = b;

        if(!checkpaginas[a]) paginas.push_back(a);
        if(!checkpaginas[b]) paginas.push_back(b);

        checkpaginas[a] = true;
        checkpaginas[b] = true;
    }

    // linha em branco.
    // char c;
    // cin >> c;

    // inicio e fim.
    string pinicial, pfinal;
    cin >> pinicial >> pfinal;

    // relacionar cada palavra a um indice do grafo.
    map <string, int> ipag;
    sort(paginas.begin(), paginas.end());
    int totalpag = paginas.size();
    for(int i = 0; i < totalpag; ++i) ipag[paginas[i]] = i;

    // construindo arestas do grafo, com as referências.
    vector <ll> grafo[totalpag];
    for(int i = 0 ; i < n; ++i){
        int pa = ipag[refs[i].first];
        int pb = ipag[refs[i].second];
        grafo[pa].push_back(pb);
    }

    // construindo arestas do grafo com os adjacentes.
    if(find(grafo[0].begin(), grafo[0].end(), 1) == grafo[0].end()) grafo[0].push_back(1);
    if(find(grafo[totalpag-1].begin(), grafo[totalpag-1].end(), totalpag-2) == grafo[totalpag-1].end()) grafo[totalpag-1].push_back(totalpag-2);
    for(int i = 1; i < totalpag-1; ++i){
        if(find(grafo[i].begin(), grafo[i].end(), i+1) == grafo[i].end()) grafo[i].push_back(i+1);
        if(find(grafo[i].begin(), grafo[i].end(), i-1) == grafo[i].end()) grafo[i].push_back(i-1);
    }
    
    // bfs.
    int pa = ipag[pinicial];
    int pb = ipag[pfinal];
    int ans = INT_MAX;
    queue <pair<int, int>> bfs;
    map<int, bool> check;
    bfs.push({pa, 0});
    while(!bfs.empty()){
        auto [atual, moves] = bfs.front();
        bfs.pop();
        check[atual] = true;

        if(atual == pb) ans = min(ans, moves);
        for(auto v : grafo[atual]){
            if(!check[v]){
                bfs.push({v, moves+1});
            }
        }
    }
    cout << ans << endl;
    return 0;
}

// Accepted.
