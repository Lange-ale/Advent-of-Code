#include <bits/stdc++.h>
using namespace std;

const long long infinito = 0xfffffffffffffff;

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");

    const int N = 100;
    vector<vector<int>> risks(N);
    vector<vector<long long>> minimi(N);
    long long risultato = infinito;
    string riga;
    for (int i = 0; i < N; ++i) {
        in >> riga;
        for (char j: riga)
            risks[i].push_back(j - '0');
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            minimi[i].push_back(infinito);
    minimi[0][0] = 0;

    int r, c;
    long long minimo;
    for (long long n = 0; n < N * N; ++n) {
        minimo = infinito;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (minimi[i][j] < minimo) {
                    minimo = minimi[i][j];
                    r = i;
                    c = j;
                }

        if (r > 0 && risks[r - 1][c]!=-1 && minimi[r][c] + risks[r - 1][c] < minimi[r - 1][c])
            minimi[r - 1][c] = minimi[r][c] + risks[r - 1][c];

        if (c > 0 && risks[r][c - 1]!=-1 && minimi[r][c] + risks[r][c - 1] < minimi[r][c - 1])
            minimi[r][c - 1] = minimi[r][c] + risks[r][c - 1];

        if (r < N - 1 && risks[r + 1][c]!=-1 && minimi[r][c] + risks[r + 1][c] < minimi[r + 1][c])
            minimi[r + 1][c] = minimi[r][c] + risks[r + 1][c];

        if (c < N - 1 && risks[r][c + 1]!=-1 && minimi[r][c] + risks[r][c + 1] < minimi[r][c + 1])
            minimi[r][c + 1] = minimi[r][c] + risks[r][c + 1];

        risks[r][c] = -1;
        if (r == N-1 && c == N-1) risultato = minimi[r][c];
        minimi[r][c] = infinito;
    }

    out << risultato;

    return 0;
}
