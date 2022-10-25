#include <bits/stdc++.h>

using namespace std;

const int N=799;

int main() {
    ofstream out("../output.txt");
    ifstream in("../../input.txt");
    int x, y;
    string riga;
    queue<pair<int, int>> not_processed;
    for (int i = 0; i < N; ++i) {
        getline(in, riga);
        x = stoi(riga.substr(0, riga.find(',')));
        y = stoi(riga.substr(riga.find(',') + 1));
        not_processed.push(make_pair(x,y));
    }
    set<pair<int, int>> sol;

    getline(in, riga);
    getline(in, riga);
    int fold_along = stoi(riga.substr(riga.find('=') + 1));
    if(riga.find('x')!=string::npos){
        while (!not_processed.empty()) {
            pair<int, int> point = not_processed.front();
            not_processed.pop();
            if (point.first > fold_along)
                point.first = fold_along - (point.first - fold_along);
            sol.insert(point);
        }
    }
    else{
        while (!not_processed.empty()) {
            pair<int, int> point = not_processed.front();
            not_processed.pop();
            if (point.second > fold_along)
                point.second = fold_along - (point.second - fold_along);
            sol.insert(point);
        }
    }

    out << sol.size();

    return 0;
}
