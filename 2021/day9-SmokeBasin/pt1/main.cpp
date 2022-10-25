#include <bits/stdc++.h>

using namespace std;

vector<string> heights;

char height(int row, int column) {
    if (row >= heights.size() || row < 0 || column >= heights.at(row).size() || column < 0)
        return '9';
    return heights.at(row).at(column);
}

int main() {
    ofstream out("../output.txt");

    ifstream in("../../input.txt");
    string temp;
    while (in >> temp) {
        heights.push_back(temp);
    }

    vector<int> basins;
    int sum = 0;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights.at(i).size(); ++j) {
            if (heights.at(i).at(j) < height(i - 1, j) && heights.at(i).at(j) < height(i, j - 1) &&
                heights.at(i).at(j) < height(i + 1, j) && heights.at(i).at(j) < height(i, j + 1)) {
                sum += 1 + heights.at(i).at(j) - '0';
            }
        }
    }
    out << sum;

    return 0;
}

