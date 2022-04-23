#include "iostream"
class Date{
    int day;
    int month;
    int year;
public:
    Date(int y,int m,int d){
        day = d;
        month = m;
        year = y;
    }
    int getDateRank(){
        int rank = day;
        if((year%400==0||(year%4==0&&year%100!=0)&&month>2)) rank++;
        switch (month) {
            case 12:
                rank+=30;
            case 11:
                rank+=31;
            case 10:
                rank+=30;
            case 9:
                rank+=31;
            case 8:
                rank+=31;
            case 7:
                rank+=30;
            case 6:
                rank+=31;
            case 5:
                rank+=30;
            case 4:
                rank+=31;
            case 3:
                rank+=28;
            case 2:
                rank+=31;
                break;
        }
        return rank;
    }
};

int main(){
    Date a = Date(2020,3,1);
    std::cout<<a.getDateRank();
    return 0;
}
