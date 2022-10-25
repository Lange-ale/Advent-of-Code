#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream out("../output.txt");

    map<char, int> points;
    points['('] = 1;
    points['['] = 2;
    points['{'] = 3;
    points['<'] = 4;

    map<char, char> match;
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';
    match['>'] = '<';


    ifstream in("../../input.txt");
    vector<long long> results;
    string line;
    while (in >> line) {
        bool corrupted = false;
        stack<char> opened;
        for (auto bracket: line) {
            if (match.find(bracket) != match.end()) {//se chiude
                if (match[bracket] != opened.top()) {
                    corrupted = true;
                    break;
                } else
                    opened.pop();
            } else
                opened.push(bracket);
        }

        long long result = 0;
        if (!corrupted) {
            while (!opened.empty()) {
                result = result * 5 + points[opened.top()];
                opened.pop();
            }
            results.push_back(result);
        }
    }

    sort(results.begin(), results.end());
    out << results.at(results.size() / 2);

    return 0;
}