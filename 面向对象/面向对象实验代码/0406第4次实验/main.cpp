#include <iostream>
using namespace std;

class calculator{
    long long int sNumber[10];
public:
    calculator(){
        srand(time(0));
        for(int i=0;i<10;i++){
            sNumber[i] = (2*rand())%100+2;
        }
        printsNumber();
    }
    void printsNumber(){
        for(int i=0;i<10;i++){
            std::cout<<sNumber[i]<<"  ";
        }
        std::cout<<std::endl;
    }
    void passSweet(){
        long long int pass[10] = {0};
        for(int i=0;i<10;i++){
            pass[i] = sNumber[i]/2;
            sNumber[i] -= pass[i];
        }
        for(int i=0;i<9;i++){
            sNumber[i+1] += pass[i];
        }
        sNumber[0] += pass[9];
        for (int i = 0; i < 10; ++i) {
            if(sNumber[i]%2==1) sNumber[i]++;
        }
    }
    bool check(){
        for (int i = 0; i < 9; ++i) {
            if(sNumber[i]!=sNumber[i+1])    return false;
        }
        return true;
    }
};


int main() {
    calculator a = calculator();
    int i=0;
    while(!a.check()){
        a.passSweet();
    }
    a.printsNumber();
    return 0;
}
