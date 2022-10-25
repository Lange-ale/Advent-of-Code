#include <bits/stdc++.h>

using namespace std;

const int righe=500;
int grids[righe][5];
bool marked[righe][5];

void init_estrazione(queue<int>& estrazione, const string &s) {
    unsigned int pos_num=0, pos_virg=s.find(',', 1);
    while (pos_virg!=string::npos){
        estrazione.push(stoi(s.substr(pos_num, pos_virg-pos_num)));
        pos_num = pos_virg+1;
        pos_virg = s.find(',', pos_num);
    }
}

bool trovato(int riga, int colonna) {
    bool risultato = true;
    for (bool mark: marked[riga])
        if(!mark){
            risultato = false;
            break;
        }

    if(risultato) return true;

    risultato = true;
    int r0 = riga-riga%5;//prima riga del tabellone
    for (int i = 0; i<5; ++i)
        if(!marked[i+r0][colonna]){
            risultato = false;
            break;
        }

    return risultato;
}

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");

    queue<int> estrazione;
    string stringa_estrazione;
    in >> stringa_estrazione;
    init_estrazione(estrazione, stringa_estrazione);

    for(auto & riga: grids)
        in >> riga[0] >> riga[1] >> riga[2] >> riga[3] >> riga[4];

    for (auto &riga: marked) for(bool& el: riga) {el = false;}

    pair<int,int> winner = {-1,-1};
    while (winner.first==-1){
        int estratto = estrazione.front();
        estrazione.pop();
        for (int i=0; i<righe; ++i) {
            for(int j=0; j<5; ++j){
                if(grids[i][j]==estratto){
                    marked[i][j] = true;
                    if(trovato(i, j)) winner={i,j};
                }
            }
        }
    }

    int sum_non_estratti=0;
    int r0 = winner.first - winner.first%5;//prima riga del tabellone
    for (int i = 0; i<5; ++i)
        for (int j = 0; j<5; ++j)
            if(!marked[i+r0][j]) sum_non_estratti+=grids[i+r0][j];

    cout << grids[winner.first][winner.second] << " " << sum_non_estratti;
    out << grids[winner.first][winner.second] * sum_non_estratti;

    in.close();
    out.close();
    return 0;
}

/*
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << grids[i][j] << " ";
        }
        cout << "\n";
    }
*/

