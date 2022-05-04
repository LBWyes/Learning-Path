#include "iostream"
//用来管理年月日的类
class DayTimeManager{
    int year;
    int month;
    int day;
public:
    DayTimeManager(){
        year = 0;
        month = 0;
        day = 0;
    }
    DayTimeManager(int _year,int _month,int _day){
        year = _year;
        month = _month;
        day = _day;
    }
    int operator-(DayTimeManager minus){
        int days = 0;
        int a = getDateRank();
        int b = minus.getDateRank();
        if(year<minus.year||(year==minus.year&&a<b)){
            days += 365-a+b;
            if(isRun()) days++;
        }else{
            days += 365-b+a;
            if(minus.isRun())   days++;
        }
        for(int i=year+1;i<minus.year;i++){
            days+=365;
            if(isRun(i))    days++;
        }
        return days;
    }
    bool isRun(){
        if(year%400==0||(year%4==0&&year%100!=0))   return true;
        else return false;
    }
    bool isRun(int _year){
        if(_year%400==0||(_year%4==0&&_year%100!=0))   return true;
        else return false;
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
//用来管理时分秒的类
class SecondTimeManager{
    int hour;
    int minute;
    int second;
public:
    SecondTimeManager(){
        hour = 0;
        minute = 0;
        second = 0;
    }
    SecondTimeManager(int _hour,int _minute,int _second){
        hour = _hour;
        minute = _minute;
        second = _second;
    }
    int operator-(SecondTimeManager minus){
        int seconds = 0;
        seconds += second - minus.second;
        seconds += (minute - minus.minute)*60;
        seconds += (hour - minus.hour)*3600;
        if(seconds<0)   return -seconds;
        else return seconds;
    }
};
//用来管理时间的类
class TimeManager{
    DayTimeManager days;
    SecondTimeManager seconds;
public:
    TimeManager(){
        days = DayTimeManager();
        seconds = SecondTimeManager();
    }
    TimeManager(int _year,int _month,int _day,int _hour,int _minute,int _second){
        days = DayTimeManager(_year,_month,_day);
        seconds = SecondTimeManager(_hour,_minute,_second);
    }
    DayTimeManager getDayTimeManager(){
        return days;
    }
    SecondTimeManager getSecondTimeManager(){
        return seconds;
    }
};
int main(){
    TimeManager a = TimeManager(2019,12,19,0,0,0);
    TimeManager b = TimeManager(2022,4,11,11,1,1);
    std::cout<<a.getDayTimeManager()-b.getDayTimeManager()<<"d  "<<a.getSecondTimeManager()-b.getSecondTimeManager()<<"s"<<std::endl;
}
