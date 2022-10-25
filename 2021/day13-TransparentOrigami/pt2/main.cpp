#include <bits/stdc++.h>

using namespace std;

const int N=799;

int main() {
    ofstream out("../output.txt");
    ifstream in("../../input.txt");
    int x, y;
    string riga;
    vector<pair<int, int>> points;
    for (int i = 0; i < N; ++i) {
        getline(in, riga);
        x = stoi(riga.substr(0, riga.find(',')));
        y = stoi(riga.substr(riga.find(',') + 1));
        points.emplace_back(x, y);
    }

    getline(in, riga);
    while (getline(in, riga)) {
        int fold_along = stoi(riga.substr(riga.find('=') + 1));
        if (riga.find('x') != string::npos) {
            for (auto &point: points)
                if (point.first > fold_along)
                    point.first = fold_along - (point.first - fold_along);
        } else
            for (auto &point: points)
                if (point.second > fold_along)
                    point.second = fold_along - (point.second - fold_along);
    }

    bool result[10][50];

    for (auto &i: result)
        for (bool &j: i)
            j = false;

    for (const auto &point: points)
        result[point.second][point.first] = true;

    for (const auto &i: result) {
        for (const auto &j: i) {
            if (j) out << "#";
            else out << " ";
        }
        out << endl;
    }


    return 0;
}
