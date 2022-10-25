#include <bits/stdc++.h>

using namespace std;

const int N=10;
vector<int> octopus [N];

//row, column
void next(int i, int j) {
    if (i < 0 || i >= N || j < 0 || j >= N) return;

    octopus[i].at(j)++;

    if (octopus[i].at(j) == 10) {
        next(i - 1, j - 1);
        next(i - 1, j);
        next(i - 1, j + 1);
        next(i, j - 1);
        next(i, j + 1);
        next(i + 1, j - 1);
        next(i + 1, j);
        next(i + 1, j + 1);
    }
}


int main() {
    ofstream out("../output.txt");
    ifstream in("../../input.txt");
    string temp;
    for (int i = 0; i < N; ++i) {
        in >> temp;
        for (int j = 0; j < N; ++j)
            octopus[i].push_back(temp.at(j) - '0');
    }

    int steps = 0;
    bool trovato = false;
    while (!trovato) {
        trovato = true;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                next(i, j);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j) {
                if (octopus[i][j] > 9)
                    octopus[i][j] = 0;
                else
                    trovato = false;
            }
        steps++;
    }

    out << steps;

    return 0;
}
