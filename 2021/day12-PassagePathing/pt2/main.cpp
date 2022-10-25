#include <bits/stdc++.h>

using namespace std;

map<string, list<string>> nodi;

//nodi piccoli visitati, nodo attuale, nodo piccolo su cui si puo' passare 2 volte
long long quanti(set<string> visitati, string attuale, bool ripetibile) {
    if (attuale == "end") return 1;

    if (attuale.at(0) >= 'a' && attuale.at(0) <= 'z') visitati.insert(attuale);

    long long tot = 0;

    for (auto it = nodi[attuale].begin(); it != nodi[attuale].end(); ++it) {
        if (visitati.find(*it) == visitati.end())
            tot += quanti(visitati, *it, ripetibile);
        else if (ripetibile && *it != "end" && *it != "start" && (*it).at(0) >= 'a' && (*it).at(0) <= 'z')
            tot += quanti(visitati, *it, false);
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
    long long tot = 0;
//    for (auto& ripetibile: nodi) {
//        if (ripetibile.first == "end" || ripetibile.first == "start" ||
//        ripetibile.first.at(0)<'a' || ripetibile.first.at(0)>'z') continue;
//        tot += quanti(visitati, "start", ripetibile.first);
//    }

    tot += quanti(visitati, "start", true);

    out << tot;

    return 0;
}
