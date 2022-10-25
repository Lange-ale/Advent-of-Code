#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream out("../output.txt");

    map<char, int> points;
    points[')'] = 3;
    points[']'] = 57;
    points['}'] = 1197;
    points['>'] = 25137;

    map<char, char> match;
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';
    match['>'] = '<';


    ifstream in("../../input.txt");
    int result = 0;
    string line;
    while (in >> line) {
        stack<char> opened;
        for(auto bracket: line){
            if(match.find(bracket)!=match.end()){//se chiude
                if(match[bracket] != opened.top()){
                    result += points[bracket];
                    break;
                }
                else
                    opened.pop();
            }
            else
                opened.push(bracket);
        }

    }

    out << result;

    return 0;
}
