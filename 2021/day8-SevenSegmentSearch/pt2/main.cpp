#include <bits/stdc++.h>

using namespace std;

bool lunghezza(const string& s1, const string& s2){
    return s1.size()<s2.size();
}

int main() {
    ofstream out("../output.txt");
    ifstream in("../../input.txt");
    int sum = 0;
    string temp;
    vector<string> signals, outputs;
    map<string, int> sol;
    while (in >> temp) {
        signals.clear();
        outputs.clear();
        signals.push_back(temp);
        for (int i = 0; i < 9; ++i) {
            in >> temp;
            signals.push_back(temp);
        }
        in >> temp;
        for (int i = 0; i < 4; ++i) {
            in >> temp;
            outputs.push_back(temp);
        }

        //segnali di input in ordine di lunghezza
        sort(signals.begin(), signals.end(), lunghezza);
        //ordino in ordine alfabetico tutti i segnali (perche' afdcg e' ugauale a acdfg)
        for (auto &s: signals)
            sort(s.begin(), s.end());
        for (auto &s: outputs)
            sort(s.begin(), s.end());

        //valori gia' conosciti perche' di lunghezze univoche
        sol.clear();
        sol[signals.at(0)] = 1;
        sol[signals.at(1)] = 7;
        sol[signals.at(2)] = 4;
        sol[signals.at(signals.size() - 1)] = 8;


        //trovo la c, la f e il 6 notando che tra i numeri con 6 segmenti (0,6,9)
        // hanno tutti la f e solo al 6 manca la c
        char c, f;
        for (int i = 0; i < signals.at(0).size(); ++i)
            for (int j = 6; j <= 8; ++j)
                if (signals.at(j).find(signals.at(0).at(i)) == string::npos) {
                    sol[signals.at(j)] = 6;
                    c = signals.at(0).at(i);
                    if (i == 0)
                        f = signals.at(0).at(1);
                    else
                        f = signals.at(0).at(0);
                    signals.erase(signals.begin() + j);
                }

        //trovo il 5 notando che tra i numeri con 5 segmenti (2,3,5)
        //e' l'unico a cui manca la c
        for (int i = 3; i <= 5; ++i)
            if (signals.at(i).find(c) == string::npos) {
                sol[signals.at(i)] = 5;
                signals.erase(signals.begin() + i);
            }

        //trovo il 2, il 3 e notando che il 2 non ha la f e il 3 non ha la e
        char e;
        for (int i = 3; i <= 4; ++i)
            if (signals.at(i).find(f) == string::npos) {
                sol[signals.at(i)] = 2;
                int pos = (i == 3 ? 4 : 3);
                sol[signals.at(pos)] = 3;
                for (int j = 0; j < signals.at(pos).size(); ++j)
                    if (signals.at(pos).find(signals.at(i).at(j)) == string::npos)
                        e = signals.at(i).at(j);

                signals.erase(signals.begin() + i);
                signals.erase(signals.begin() + 3);
            }


        // trovo lo 0 e il 9
        for (int i = 3; i <= 4; ++i)
            if (signals.at(i).find(e) == string::npos) {
                sol[signals.at(i)] = 9;
                if (i == 3) sol[signals.at((4))] = 0;
                else sol[signals.at((3))] = 0;
            }


        int actual_sum = 0;
        for (const auto &s: outputs)
            actual_sum = actual_sum * 10 + sol[s];
        sum += actual_sum;
    }

    out << sum;

    return 0;
}
