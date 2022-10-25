#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");
    int num, prec=149;
    int SOLUZ=0;
    while (in >> num){
        if(num>prec) SOLUZ++;
        prec=num;
    }
    out << SOLUZ;
    in.close();
    out.close();
    return 0;
}
