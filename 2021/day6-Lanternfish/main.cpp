#include <bits/stdc++.h>

using namespace std;

const int TOT_GIORNI = 256;

long long soluz[10][TOT_GIORNI + 20];

       //input, giorno creazione
stack<pair<int, int>> pesci;


long long quanti(pair<int, int> pesce) {
    if (pesce.second > TOT_GIORNI) return 0;
    if (pesce.first + pesce.second > TOT_GIORNI) {
        soluz[pesce.first][pesce.second] = 1;
        return 1;
    }
    if (soluz[pesce.first][pesce.second] != -1) return soluz[pesce.first][pesce.second];

    int rimanenti = TOT_GIORNI - pesce.first - pesce.second;

    long long counter = 1;
    int da_creare = 1 + rimanenti / 7;
    for (int i = 0; i < da_creare; ++i) {
        counter += quanti(make_pair(8, pesce.first + pesce.second + i * 7 + 1));
    }

    soluz[pesce.first][pesce.second] = counter;
    return counter;
}


int main() {
    ofstream out("../output.txt");

    for (auto &i: soluz) for (auto &j: i) j = -1;

    int temp;
    FILE *f = fopen("../input.txt", "r");
    while (fscanf(f, "%d,", &temp) != EOF) {
        pesci.push(make_pair(temp, 0));
    }

    long long counter = 0;

    while (!pesci.empty()) {
        pair<int, int> attuale = pesci.top();
        pesci.pop();
        counter += quanti(attuale);
    }

    out << counter;

    return 0;
}

