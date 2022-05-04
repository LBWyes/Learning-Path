#include <fstream>
#include "iostream"
#include "vector"
#include <cmath>
#include "filesystem"
using namespace std;
class Point{
public:
    int y;
    int x;
public:
    Point(int x,int y);
};

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

class Rectangle:Point{
    int X;  //rectangle's length
    int Y;  //rectangle's height

public:
    Point getRightUpPoint();
    Rectangle(int a,int b,int x,int y);
    Rectangle(const Rectangle &a,int x,int y);
};

class path;

Point Rectangle::getRightUpPoint() {
    return Point(x+X,y+Y );
}

Rectangle::Rectangle(int a, int b,int x,int y) : Point(x, y) {
    X = a;
    Y = b;
}

Rectangle::Rectangle(const Rectangle &a,int x,int y) : Point(x, y) {
    X = a.X;
    Y = a.Y;
}

int VecToInt(vector<char> a){
    int result=0;
    int i = 0;
    while(!a.empty()){
        result += (a.back()-48)*pow(10,i);
        a.pop_back();
        i++;
    }
    return result;
}
int main(){
    //TODO:按绝对路径更改相应path
    string path = "D:\\Projects\\ClionProjects\\0323\\input.txt";

    ifstream input(path);
    if(!input.is_open()){
        cout<<"文件打开失败！"<<endl;
        return 1;
    }
    string temp;
    while(getline(input,temp)){
        vector<char> num[4];
        int j=0;
        for(int i=0;i<temp.length();i++){
            if(temp[i]==' '){
                j++;
            }else{
                num[j].push_back(temp[i]);
            }
        }
        Rectangle A = Rectangle(VecToInt(num[0]),VecToInt(num[1]),VecToInt(num[2]),VecToInt(num[3]));
        Point B = A.getRightUpPoint();
        cout<<"("<<B.x<<","<<B.y<<")"<<endl;
    }

}