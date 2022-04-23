#include <iostream>
#include <string.h>
#define max 1001
using namespace std;

//打印函数
void printPI(char * pi,int accuracy){
    printf("%c.",pi[0]+48);
    for(int i=1;i<=accuracy;i++){
        printf("%c",pi[i]+48);
    }
    cout<<endl;
}

//利用级数计算 π = 2 + 2/3 + 2/3*2/5 + 2/3*2/5*3/7 + ...
class PiCalculator{
    int accuracy;   //保留到小数点后几位
public:
    PiCalculator(){
        accuracy = 100;
    }
    PiCalculator(int Accuracy){
        accuracy = Accuracy;
    }
    char * calc(){
        static char pi[max];
        char delta[max];
        char result[max];
        memset(pi,0,max);
        pi[0] = 2;
        int i = 1;
        memset(result,0,max);
        result[0] = 2;
        while(true){
//            printPI(result,accuracy);
            memset(delta,0,max);
            highAccuracyDeluxe(i,2*i+1,delta);
//            printPI(delta,accuracy);
            highAccuracyMultiply(result,delta,result);
//            printPI(result,accuracy);
            if(calcAccuracy(result))    break;
            highAccuracyPlus(pi,result);
            i++;
            cout<<endl;
        }
        return pi;
    }
private:
    bool calcAccuracy(char * p){
        for(int i=accuracy;i>0;i--){
            if (p[i]!=0)    return false;
        }
        return true;
    }

    void highAccuracyDeluxe(int a,int b,char *result){
        int temp[max];
        temp[0] = a;
        int  c,d;
        for(int i=0;i<max;i++){
            c = temp[i]%b;
            d = temp[i]/b;
            result[i] = d;
            temp[i+1] = 10*c;
        }
    }
    void highAccuracyMultiply(char* a,char *b,char *result){
        //注意，为防止溢出，tempResult的第2位与第3位之间是小数点
        char tempResult[10][max+1];
        int temp=0;
        for(int i=0;i<10;i++){
            memset(tempResult[i],0,max);
            for(int j=max-1;j>=0;j--){
                temp = i*a[j];
                tempResult[i][j+1] += temp%10;
                tempResult[i][j] += temp/10;
            }
        }
        char Result[2*max];
        memset(Result,0,2*max);
        for(int i=max-1;i>0;i--){
            //小数点后max-1+i位
            for(int j = max-1+i ; j>=i ; j--){
                temp = Result[j] + tempResult[b[i]][j-i+1];
                Result[j] = temp%10;
                Result[j-1] += temp/10;
            }
        }
        for(int i=0;i<max;i++){
           result[i] = Result[i];
        }
    }
    void highAccuracyPlus(char* a,char *b){
        int temp;
        for(int i=max-1;i>=1;i--){
            temp = a[i] + b[i];
            a[i] = temp%10;
            a[i-1]+= temp/10;
        }
    }
};




int main() {
    int accuracy = 100;
    PiCalculator Pi = PiCalculator(accuracy);
    char *p = Pi.calc();
    printPI(p,accuracy);
    //output:3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170678
    return 0;
}


