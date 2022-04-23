#include <iostream>
#include "stdio.h"
using namespace  std;

 template <typename T>
 class Link {
    struct linkNode{
        T data;
        linkNode* next;
        linkNode(){
            data = 0;
            next = nullptr;
        }
        linkNode(T d){
            data = d;
            next = nullptr;
        }
    };
    linkNode* head;
    linkNode* end;
    int length;

public:
    Link(){                 //没有参数的构造
         head = new linkNode();
         end = head;
         length = 0;
     }
    Link(T d) {              //有参数的构造
        head = new linkNode();
        end = new linkNode(d);
        head->next = end;
        length = 1;
    }
    ~Link(){
        linkNode* temp;
        for(int i=0;i<length;i++){
            temp = head;
            head = head->next;
            delete temp;
        }
        length = 0;
        end = nullptr;
    }
    Link add(T d){         //末尾直接添加
        linkNode* temp = new linkNode(d);
        end->next = temp;
        end = temp;
        length++;
    }
    Link add(T d,int n){   //选任意位置添加
        if(n>length+1){
            cout<<"该位置在链表之外"<<endl;
        }else{
            if(n==length+1){
                linkNode* temp = new linkNode(d);
                end->next = temp;
                end = next;
                length++;
            }else{
                linkNode* temp = head;
                for (int i = 0; i < n-1; ++i) {
                    temp = temp->next;
                }
                linkNode* temp2 = temp->next;
                linkNode* a = new linkNode(d);
                temp->next = a;
                a->next = temp2;
                length++;
            }
        }

    }
    Link del(){              //末尾删除
        length--;
        linkNode* temp = head;
        for(int i=0;i<length;i++){
            temp = temp->next;
        }
        delete end;
        end = temp;

    }
    Link del(int n){        //选任意位置删除
        if(n>length){
            cout<<"该位置在链表之外"<<endl;
        }else{
            linkNode* temp=head;
            for(int i=0;i<n-1;i++){
                temp = temp->next;
            }
            linkNode* a = temp->next;
            temp->next = a->next;
            delete a;
            if(n==length){
                end = temp;
            }
            length--;
        }
    }
    Link update(T d,int n){ //更新选定位置的数据
        if(n>length){
            cout<<"该位置在链表之外"<<endl;
        }else{
            linkNode* temp=head;
            for(int i=0;i<n;i++){
                temp = temp->next;
            }
            temp->data = d;
        }
    }
     bool isempty(){
         if(head==end)   return true;
         return false;
     }

    Link operator+(Link b){
        end->next = b.head->next;
        end = b.end;
        length+=b.length;
        return this;
    }
    Link operator-(int n){
        del(n);
        return this;
    }
    T operator[](int n){          //返回查询位置的节点
        if(n>length){
            cout<<"该位置在链表之外"<<endl;
        }else{
            linkNode* a=head;
            for(int i=0;i<n;i++){
                a = a->next;
            }
            return a->data;
        }
    }

 };



int main() {
    Link<int> *link = new Link<int>(5);
    if(!link->isempty()){
        cout<<"成功创建"<<endl;
    }
    link->add(2);
    link->del(2);
    link->del(1);
    if(link->isempty()){
        cout<<"全部删除"<<endl;
    }
    return 0;
}
