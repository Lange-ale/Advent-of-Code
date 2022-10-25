#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream out("../output.txt");
    ifstream in("../../input.txt");
    int result = 0;
    string signal, output, pipe;
    while (in >> signal) {
        for (int i = 0; i < 9; ++i)
            in >> signal;
        in >> pipe;
        for (int i = 0; i < 4; ++i) {
            in >> output;
            if (output.size() == 2 || output.size() == 3 || output.size() == 4 || output.size() == 7)
                result++;
        }
    }
    out << result;

    return 0;
}
