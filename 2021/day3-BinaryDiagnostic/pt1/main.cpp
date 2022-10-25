#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");
    long long N=0;
    int tot_bit=12;
    int quanti[tot_bit];
    for(auto& i: quanti)
        i=0;

    string temp;
    while (in >> temp){
        for (int i = 0; i < tot_bit; ++i)
            if(temp[i]=='1')
                quanti[i] += 1;

        ++N;
    }
    string gamma, epsilon;
    for(const auto& i: quanti){
        if(i>N/2){
            gamma+='1';
            epsilon+='0';
        }
        else{
            gamma+='0';
            epsilon+='1';
        }
    }

    long long risultato = stoi(gamma,nullptr,2) * stoi(epsilon,nullptr,2);
    out << risultato;

    in.close();
    out.close();
    return 0;
}
