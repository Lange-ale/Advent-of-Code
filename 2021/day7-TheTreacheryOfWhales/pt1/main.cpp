#include <bits/stdc++.h>

using namespace std;

vector<int> posizioni (1000);

int main() {
    ofstream out("../output.txt");

    int max_n = 0, min_n = 2000;
    FILE *f = fopen("../../input.txt", "r");
    for (auto &pos: posizioni) {
        fscanf(f, "%d,", &pos);
        max_n = max(max_n, pos);
        min_n = min(min_n, pos);
    }

    int min_fuel = 0xfffffff;
    for (int raggiungi = min_n; raggiungi <= max_n; ++raggiungi) {
        int fuel = 0;
        for (const auto &i: posizioni) {
            fuel += ((i > raggiungi) ? (i - raggiungi) : (raggiungi - i));
        }
        min_fuel = min(min_fuel, fuel);
    }

    out << min_fuel;

    return 0;
}

