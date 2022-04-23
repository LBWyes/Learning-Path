#include <iostream>
class circle {
    double radius;
public:
    double getArea();

    circle(double r);

    circle(const circle &c);

};

double circle::getArea() {
    return 3.14*radius*radius;
}

circle::circle(double r) {
    radius = r;
}

circle::circle(const circle &c){
    radius = c.radius;
}


int main() {
    circle circleA = circle(5.3);
    circle circleB = circle(circleA);
    std::cout<<circleA.getArea()<<std::endl;
    std::cout<<circleB.getArea()<<std::endl;
    return 0;
}
