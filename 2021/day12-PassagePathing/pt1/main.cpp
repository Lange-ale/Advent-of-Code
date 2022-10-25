#include <bits/stdc++.h>

using namespace std;

map<string, list<string>> nodi;

//nodi piccoli visitati, nodo attuale
long long quanti(set<string> visitati, string attuale) {
    if(attuale=="end") return 1;

    if((attuale).at(0)>='a' && (attuale).at(0)<='z') visitati.insert(attuale);

    long long tot=0;

    for (auto it = nodi[attuale].begin(); it!=nodi[attuale].end(); ++it) {
        if(visitati.find(*it)==visitati.end()){
            tot += quanti(visitati, *it);
        }
    }

    return tot;
}

int main() {
    ofstream out("../output.txt");
    ifstream in("../../input.txt");
    string a, b, riga;
    while (in >> riga) {
        a = riga.substr(0, riga.find('-'));
        b = riga.substr(riga.find('-') + 1);
        nodi[a].push_back(b);
        nodi[b].push_back(a);
    }

    set<string> visitati;
    out << quanti(visitati, "start");

    return 0;
}
