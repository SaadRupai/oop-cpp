// a class that has at least one pure virtual funtion, is called an abstract class
// pure virtual function is virtual function but the base class tells that every derived class must have their own version 
// of the specific virtual method 
// pure virtual function: virtual practice()=0 (eg.)

#include<bits/stdc++.h>
using namespace std;

class Ball{
    public:
        //virtual function
        // virtual void jump(){
        //     cout<< "The ball is jumping"<<endl;
        // }

        //pure virtual functoin
        virtual void jump()=0;
};

class Football : public Ball{
    public:
        void jump(){
            cout<<"The football is jumping"<<endl;
        }
};
class Baseball : public Ball{
    public:
        void jump(){
            cout<<"The baseball is jumping"<<endl;
        }
};

int main(){
    Ball* obj = new Football();
    // obj->jump();
    Ball* obj1 = new Baseball();
    // obj1->jump();

    // polymorphic behaviours of virtual functions
    Ball* balls[2]={obj, obj1};
    for(int i=0; i<2; i++){
        balls[i]->jump();
    }
}