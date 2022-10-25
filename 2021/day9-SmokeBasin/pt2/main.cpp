#include <bits/stdc++.h>

using namespace std;

vector<string> heights;

char height(int row, int column) {
    if (row >= heights.size() || row < 0 || column >= heights.at(row).size() || column < 0)
        return '9';
    return heights.at(row).at(column);
}

int dim_basin(int row, int column) {
    if (height(row, column) == '9') return 0;
    heights.at(row).at(column) = '9';
    int quanti = 1;
    if (height(row - 1, column) != '9') quanti += dim_basin(row - 1, column);
    if (height(row + 1, column) != '9') quanti += dim_basin(row + 1, column);
    if (height(row, column - 1) != '9') quanti += dim_basin(row, column - 1);
    if (height(row, column + 1) != '9') quanti += dim_basin(row, column + 1);
    return quanti;
}

int main() {
    ofstream out("../output.txt");

    ifstream in("../../input.txt");
    string temp;
    while (in >> temp) {
        heights.push_back(temp);
    }

    vector<int> basins;
    for (int i = 0; i < heights.size(); ++i) {
        for (int j = 0; j < heights.at(i).size(); ++j) {
            if (heights.at(i).at(j) != '9') {
                basins.push_back(dim_basin(i, j));
            }
        }
    }

    int maximum[3] = {0,0,0};
    for (const auto &basin: basins) {
        if (basin > maximum[0]) maximum[0] = basin;
        sort(maximum, maximum+3);
    }
    out << maximum[0] * maximum[1] * maximum[2];

    return 0;
}

