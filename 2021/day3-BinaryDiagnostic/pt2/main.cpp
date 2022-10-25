#include <bits/stdc++.h>

using namespace std;

string rating(list<string>& misurazioni, char comune, char non_comune){
    int pos_bit=0;
    while (misurazioni.size()>1) {
        int sum = 0;
        for (string s: misurazioni)
            if (s.at(pos_bit) == '1') sum++;


        char bit = (sum*2 >= misurazioni.size()) ? comune : non_comune;

        for (auto listIterator = misurazioni.begin(); listIterator != misurazioni.end() ;) {
            if((*listIterator).at(pos_bit)!=bit){
                listIterator = misurazioni.erase(listIterator);
            }
            else ++listIterator;
        }

        ++pos_bit;
    }
    return misurazioni.front();
}

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");

    list<string> oxigen, CO2;

    string temp;
    while (in >> temp){
        oxigen.push_back(temp);
        CO2.push_back(temp);
    }


    out << stoi( rating(oxigen, '1', '0'), nullptr, 2) *
           stoi(rating(CO2, '0', '1'), nullptr, 2);

    in.close();
    out.close();
    return 0;
}

/*
    string oxygen, CO2;
    for (int somma: quanti){
        oxygen += somma >= N/2 ? '1' : '0';
        CO2 += somma < N/2 ? '1' : '0';
    }

    auto Oinizio=misurazioni.begin(), CO2inizio=misurazioni.begin();
    string Orisultato, CO2risultato;
    ricorsiva(Oinizio, misurazioni.end(), 0, oxygen, Orisultato);
    ricorsiva(CO2inizio, misurazioni.end(), 0, CO2, CO2risultato);

    long long risposta = stoi(*Oinizio, nullptr, 2) * stoi(*CO2inizio, nullptr, 2);
    out << risposta;
    cout << oxygen << " " << CO2 << "\n";
    cout << *Oinizio << " " << *CO2inizio;
*/

/*
void ricorsiva(set<string>::iterator& inizio, set<string>::iterator fine, int pos_bit, const string& gas, string& risultato){

    if(inizio == fine || pos_bit >= tot_bit){
        risultato = *inizio;
        return;
    }

    if (gas.at(pos_bit) == '1') {
        inizio = misurazioni.lower_bound(risultato+'0');
        risultato += gas.at(pos_bit);
        ricorsiva(inizio, fine, pos_bit+1, gas, risultato);
        return;
    }

    fine = misurazioni.upper_bound(risultato + '1');
    risultato += gas.at(pos_bit);
    ricorsiva(inizio, fine, pos_bit+1, gas, risultato);
}





int pos_bit = 0;
while (misurazioni.size()>1) {
    for (auto listIterator = misurazioni.begin(); listIterator != misurazioni.end();) {
        if (*listIterator.) {
            listIterator = L.erase(listIterator);
            trovata = true;
            quanti -= temp;
        } else
            ++listIterator;
    }
    ++pos_bit;
}
*/




/*
    string risultato_oxygen, risultato_CO2;
    auto Oinizio=misurazioni.begin(), Ofine=misurazioni.end();

    int pos_bit = 0;
    while (Oinizio != Ofine && pos_bit < 12) {
        if (oxygen.at(pos_bit) == '1') {
            Oinizio = misurazioni.lower_bound(risultato_oxygen+'0');
            risultato_oxygen += oxygen.at(pos_bit);
        } else {
            Ofine = misurazioni.upper_bound(risultato_oxygen + '1');
            risultato_oxygen += oxygen.at(pos_bit);
        }

        ++pos_bit;
    }


    auto CO2inizio=misurazioni.begin(), CO2fine=misurazioni.end();
    pos_bit = 0;
    while (CO2inizio != CO2fine && pos_bit < 12) {
        if (CO2.at(pos_bit) == '1') {
            CO2inizio = misurazioni.lower_bound(risultato_CO2+'0');
            risultato_CO2 += CO2.at(pos_bit);
        } else {
            CO2fine = misurazioni.upper_bound(risultato_CO2 + '1');
            risultato_CO2 += CO2.at(pos_bit);
        }

        ++pos_bit;
    }

    cout << oxygen << " " << CO2 << "\n";
    cout << *Oinizio << " " << *Ofine << " " << *CO2inizio << " " << *CO2fine << " ";
    out << (stoi(*Oinizio, nullptr, 2)) * (stoi(*CO2inizio, nullptr, 2));

    */
