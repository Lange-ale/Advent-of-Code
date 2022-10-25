#include <bits/stdc++.h>
using namespace std;

const long long infinito = 0xfffffffffffffff;

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");

    const int N = 100 * 5;
    vector<vector<int>> risks(N);

    string riga;
    vector<vector<int>> input_risks(N / 5);
    for (int i = 0; i < N / 5; ++i) {
        in >> riga;
        for (char j: riga)
            input_risks[i].push_back(j - '0');
    }
    for (int i = 0; i < N; ++i) risks[i].resize(N);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            for (int r = 0; r < input_risks.size(); ++r)
                for (int c = 0; c < input_risks[r].size(); ++c) {
                    risks[r + i * N / 5][c + j * N / 5] = input_risks[r][c] + i + j;
                    if (risks[r + i * N / 5][c + j * N / 5] > 9)
                        risks[r + i * N / 5][c + j * N / 5] = risks[r + i * N / 5][c + j * N / 5] % 9;
                }

    long long risultato = infinito;
    map<pair<int, int>, long long> minimi;
    multimap<long long, pair<int, int>> sorted_minimi;
    sorted_minimi.insert(make_pair(0, make_pair(0, 0)));
    minimi[make_pair(0, 0)] = 0;
    int r, c;
    for (long long n = 0; n < N * N; ++n) {
        auto minimo = sorted_minimi.begin();
        r = (*minimo).second.first;
        c = (*minimo).second.second;

        if ((r > 0 && risks[r - 1][c] != -1))
            if (minimi.find(make_pair(r - 1, c)) == minimi.end() ||
                minimi[make_pair(r, c)] + risks[r - 1][c] < minimi[make_pair(r - 1, c)]) {

                minimi[make_pair(r - 1, c)] = minimi[make_pair(r, c)] + risks[r - 1][c];
                sorted_minimi.insert(make_pair(minimi[make_pair(r, c)] + risks[r - 1][c], make_pair(r - 1, c)));
            }

        if ((c > 0 && risks[r][c - 1] != -1))
            if (minimi.find(make_pair(r, c - 1)) == minimi.end() ||
                minimi[make_pair(r, c)] + risks[r][c - 1] < minimi[make_pair(r, c - 1)]) {

                minimi[make_pair(r, c - 1)] = minimi[make_pair(r, c)] + risks[r][c - 1];
                sorted_minimi.insert(make_pair(minimi[make_pair(r, c)] + risks[r][c - 1], make_pair(r, c - 1)));
            }

        if ((r < N - 1 && risks[r + 1][c] != -1))
            if (minimi.find(make_pair(r + 1, c)) == minimi.end() ||
                minimi[make_pair(r, c)] + risks[r + 1][c] < minimi[make_pair(r + 1, c)]) {

                minimi[make_pair(r + 1, c)] = minimi[make_pair(r, c)] + risks[r + 1][c];
                sorted_minimi.insert(make_pair(minimi[make_pair(r, c)] + risks[r + 1][c], make_pair(r + 1, c)));
            }

        if ((c < N - 1 && risks[r][c + 1] != -1))
            if (minimi.find(make_pair(r, c + 1)) == minimi.end() ||
                minimi[make_pair(r, c)] + risks[r][c + 1] < minimi[make_pair(r, c + 1)]) {

                minimi[make_pair(r, c + 1)] = minimi[make_pair(r, c)] + risks[r][c + 1];
                sorted_minimi.insert(make_pair(minimi[make_pair(r, c)] + risks[r][c + 1], make_pair(r, c + 1)));
            }

        risks[r][c] = -1;
        if (r == N - 1 && c == N - 1) risultato = (*minimo).first;
        sorted_minimi.erase(minimo);
        minimi[make_pair(r, c)] = infinito;
    }

    out << risultato;

    return 0;
}
