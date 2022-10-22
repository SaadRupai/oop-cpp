// abstraction
// abstraction means showing important info hiding the unimportant and complex details
// eg.: coffee machine- how machine works, is hidden; add water, get coffee- simple procedure 
// hides complex details behind simple procedures

// to implement abstraction, we use abstract class
// we cannot create instances of abstract classes, but we can create pointers of abstract classes

#include<bits/stdc++.h>
using namespace std;

class SmartPhone{
    public:
        virtual void takeSelfie()=0;
        virtual void makeCall()=0;
};

class Android : public SmartPhone{
    // developer here doesn't have to know about how Iphone or main program works
    public:
        void takeSelfie(){
            cout<<"Android selfie.."<<endl;
        }
        void makeCall(){
            cout<<"Android call.."<<endl;
        }
};

class Iphone : public SmartPhone{
    // developer here doesn't have to know about how Android or main program works
    public:
        void takeSelfie(){
            cout<<"Iphone selfie.."<<endl;
        }
        void makeCall(){
            cout<<"Iphone call.."<<endl;
        }
};

int main(){
    // developer here doesn't have to know about how Iphone or Android works, rather have to know aboout what methods to use for smartphone
    SmartPhone* obj = new Android();
    obj->takeSelfie();
    obj->makeCall();
    SmartPhone* obj1 = new Iphone();
    obj1->takeSelfie();
    obj1->makeCall();

}