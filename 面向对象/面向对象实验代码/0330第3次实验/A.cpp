#include "iostream"
#include <string>
#include <valarray>
#define maxn 10000
using namespace std;

//测试函数，以sinx为例
//实际上testFun可以根据需求，输入x返回任意的值
double testFun(double x){
    return sin(x);
}
class Integral{
    double leftPoint;
    double rightPoint;
    double (*fun) (double x);
public:
    Integral(){
        leftPoint = 0;
        rightPoint = 0;
        fun = testFun;
    }
    Integral(double left,double right){
        leftPoint = left;
        rightPoint = right;
        fun = testFun;
    }

    //计算数值积分的方法有很多，牛顿柯斯特、梯形、辛不森等等
    //在这里我选用的是自认为比较好的龙贝格法
    double calc(){
        double T[maxn],S[maxn],C[maxn],R[maxn];
        double len = rightPoint - leftPoint;
        T[0] = len*(testFun(leftPoint)+ testFun(rightPoint))/2;
        double sum = 0;
        for(int i =1;i<maxn;i++){
            sum = 0;
            for(int j = 1;j < pow(2,i-1)+0.1;j++){
                sum+= testFun(leftPoint+(2*j-1)*len/pow(2,i));
            }
            T[i] = 0.5*T[i-1] + len*sum/pow(2,i);
            S[i-1] = 4*T[i]/3 - T[i-1]/3;
            if(T[i]==S[i-1])    return S[i-1];
            if(i>=2){
                C[i-2] = 16*S[i-1]/15-S[i-2]/15;
                if(C[i-2]==S[i-1]){
                    return C[i-2];
                }
            }
            if(i>=3){
                R[i-3] = 64*C[i-2]/63-C[i-3]/63;
                if(R[i-3]==C[i-2]){
                    return R[i-3];
                }
            }
        }

    }
};


int main(){
    Integral test = Integral(0,1);

    cout<<test.calc()<<endl;   //output:0.459698
    cout<<1-cos(1)<<endl;   //output:0.459698
    return 0;
}