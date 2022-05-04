#include <iostream>
#include <map>
#include "string"
#include "vector"
using namespace std;
//教师、学生人员类
enum MemberType{
    Teacher = 0,
    Student = 1,
    Other = 2
};
class Member{
    MemberType memberType;
    string name;
    long long number;
public:
    Member(){
        memberType = Other;
        string name = "";
        number = 7220200001;
    }

    Member(MemberType _memberType,string _name,long long _number){
        memberType = _memberType;
        name = _name;
        number = _number;
    }

    MemberType getMemberType() const {
        return memberType;
    }

    const string &getName() const {
        return name;
    }

    long long int getNumber() const {
        return number;
    }
};
//课程信息类
//包含开课学期、课程名、课程号、课程容量、课程时间与地点
class Course{
    string term;
    string courseName;
    long long courseNumber;
    float courseCredit;
    int capacity;
    string location;
    //TODO:这里有优化空间，可以把一个字符串细化成周数、周几、第几节课
    string time;
public:
    Course(){
        term = "";
        courseName = "";
        courseNumber = 100000000;
        courseCredit = 0;
        capacity = 0;
        location = "";
        time = "";
    }

    Course(string _term,string _courseName,long long _courseNumber,
           float _courseCredit,string _location,string _time){
        term = _term;
        courseName = _courseName;
        courseNumber = _courseNumber;
        courseCredit = _courseCredit;
        location = _location;
        time = _time;
    }

    const string &getTerm() const {
        return term;
    }

    const string &getCourseName() const {
        return courseName;
    }

    long long int getCourseNumber() const {
        return courseNumber;
    }

    float getCourseCredit() const {
        return courseCredit;
    }

    int getCapacity() const {
        return capacity;
    }

    const string &getLocation() const {
        return location;
    }

    const string &getTime() const {
        return time;
    }
};
//课程管理类
class SingleCourseManager{
    Course course;
    Member teacher;
    vector<Member> students;
    map<long long int,int> grades;
public:
    SingleCourseManager(){
        course = Course();
        teacher = Member();
    }

    SingleCourseManager(Course _course,Member _teacher){
        course = _course;
        teacher = _teacher;
    }

    SingleCourseManager operator+(Member student){
        students.push_back(student);
    }

    SingleCourseManager addStudent(Member student){
        students.push_back(student);
    }

    //删除学生操作
    SingleCourseManager deleteStudent(Member student){
        for(int i=0;i<students.size();i++){
            if(students[i].getNumber()==student.getNumber()){
                students.erase(students.begin()+i);
            }
        }

    }
    SingleCourseManager deleteStudent(long long studentNumber){
        for(int i=0;i<students.size();i++){
            if(students[i].getNumber()==studentNumber){
                students.erase(students.begin()+i);
            }
        }
    }

    //添加成绩
    SingleCourseManager addGrades(long long studentNumber,int grade){
        grades.insert(pair<long long,int>(studentNumber,grade));
    }
    //获得单个学生成绩
    int getGrade(Member student){
        int grade = grades.find(student.getNumber())->second;
        return grade;
    }
    int getGrade(long long studentNumber){
        int grade = grades.find(studentNumber)->second;
        return grade;
    }

    const map<long long int, int> &getGradesMap() const {
        return grades;
    }

    const Course &getCourse() const {
        return course;
    }

    const Member &getTeacher() const {
        return teacher;
    }

    const vector<Member> &getStudents() const {
        return students;
    }
};

int main() {
    Course oop = Course("2021-2022-2","OOP",100072107,
                        2.5,"理教楼305","1-8周,周一,3-5节,周三,6-7节，");
    Member lly = Member(Teacher,"刘来旸",6120150000);
    Member lbw = Member(Student,"刘博文",1120201883);
    SingleCourseManager CourseOOP = SingleCourseManager(oop,lly);
    return 0;
}



