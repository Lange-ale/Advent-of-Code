#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");
    int num0, num1, num2, prec=477;
    in >> num0 >> num1;
    int SOLUZ=0;
    while (in >> num2){
        int sum=num0+num1+num2;
        if(sum>prec) SOLUZ++;

        prec=sum;
        num0=num1;
        num1=num2;
    }
    out << SOLUZ;
    in.close();
    out.close();
    return 0;
}
