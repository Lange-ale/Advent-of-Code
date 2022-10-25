#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream in("../../input.txt");
    ofstream out("../output.txt");
    long long position=0, depth=0, aim=0;
    string azione;
    long long n;
    while (in >> azione >> n){
        if(azione=="forward"){
            position += n;
            depth += n*aim;
            if(depth<0) depth=0;
        }
        else if(azione=="down"){
            aim+=n;
        }
        else{
            aim-=n;
        }

    }
    out << position*depth;
    in.close();
    out.close();
    return 0;
}
