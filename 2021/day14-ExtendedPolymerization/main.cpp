#include <bits/stdc++.h>

using namespace std;

map<string, string> rules;
const int steps = 40;
map <string, map <char, long long>> sol[steps+10];

map <char, long long> react(string polymer, int step) {
    map<char, long long> result;
    if (polymer.size() == 3) result[polymer.at(1)] = 1;
    if (step == steps) return result;

    if (sol[step].find(polymer) != sol[step].end())
        return sol[step][polymer];

    map<char, long long> temp;
    for (int i = 0; i < polymer.size() - 1; ++i)
        if (rules.find(polymer.substr(i, 2)) != rules.end()) {
            temp = react(polymer.at(i) + rules[polymer.substr(i, 2)] + polymer.at(i + 1), step + 1);
            for (auto character: temp)
                result[character.first] += character.second;
        }

    sol[step][polymer] = result;
    return result;
}


int main() {
    ofstream out("../output.txt");
    ifstream in("../input.txt");
    string polymer, input_trash, reagents, produced;
    in >> polymer;
    while (in >> reagents >> input_trash >> produced)
        rules[reagents] = produced;

    map<char, long long> how_many = react(polymer, 0);
    for (char c: polymer)
        how_many[c]++;

    long long maximum = how_many[polymer.at(0)], minimum = how_many[polymer.at(0)];
    for (auto character: how_many) {
        maximum = max(character.second, maximum);
        minimum = min(character.second, minimum);
    }

    out << maximum - minimum;

    return 0;
}
