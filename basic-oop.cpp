// encapsulation
// polymorphism
// inheritance

#include<bits/stdc++.h>
using namespace std;

class Teacher{
    // encapsulation
    private:
        list<string> SubjectTitle;  //only accessed by the f(n) of this class

    protected:                     // accessed by this class and derived class
        string Name;
        int Age;
        int StudentCount;
        int Rating;
    
    public:
    // constructor
        Teacher(string name, int age){
            Name = name;
            Age = age;
            StudentCount=0;
            Rating=0;
        }
    // class-methods
        void showInfo(){
            cout<<Name<<endl;
            cout<<Age<<endl;
            cout<<StudentCount<<endl;
            cout<<"subjects: "<<endl; 
            for (string subject : SubjectTitle){
            cout<<subject<<endl;
            }
        }
        void addSubjects(string title){
            SubjectTitle.push_back(title);
        }
        void studentSub(){
            StudentCount++;
        }
        void studentUnsub(){
            StudentCount--;
        }
        void ratingAnalysis(){
            if(Rating>3){
                cout<<"Excellent performance!"<<endl;
            }
            else{
                cout<<"Poor performance!"<<endl;
            }
        }
        // virtual checks if any latest definition of this method is available in derived class (redeefined in derived class)-runtime polymorphism
        // when a pointer reference to object of derived class invokes that method, then the redefined version of the method is being called
        virtual void practice(){
            cout<<Name<<" is teaching students."<<endl;
            Rating++;
        }

};

// inheritance : Teacher-base_class/parent_class, TA-derived_class/child_class
class TA : public Teacher{
    private:
        int Id;
        string Country;
    public:
        TA(string name, int age, int id, string country):Teacher( name,  age){
            Id = id;
            Country = country;
        }
        void showInfo(){
            cout<<Name<<endl;
            cout<<Age<<endl;
            cout<<Id<<endl;
            cout<<Country<<endl;
            cout<<StudentCount<<endl;
            cout<<"rating: "<<Rating<<endl;
        }
        void practice(){
            cout<<Name<<" is assisting as a TA and teaching sudents"<<endl;
            Rating++;
        }
};


// inheritance-polymorphism
// the most common use of polymorphism is when a parent class reference is used
// to refer a child class object
class RA : public Teacher{
    private:
        string ResSub;    // research_subject
    public:
        RA(string name, int age, string resSub ):Teacher(name, age){
            ResSub = resSub;
        }
        void practice(){
            cout<<Name<<" is assisting as a RA and doing research & teaching sudents"<<endl;
            Rating++;
        }   
        void showInfo(){
            cout<<Name<<endl;
            cout<<Age<<endl;
            cout<<ResSub<<endl;
            cout<<"rating: "<<Rating<<endl;
        }
};

int main(){
    // Teacher obj1("john",35);
    // obj1.addSubjects("Math");
    // obj1.addSubjects("Physics");
    // obj1.addSubjects("Chemistry");
    // obj1.studentSub();
    // obj1.studentSub();
    // obj1.studentSub();
    // obj1.studentUnsub();
    // obj1.showInfo();

    // TA obj2("sam", 24, 1703092, "England");
    // obj2.addSubjects("Chem");
    // obj2.addSubjects("English");
    // obj2.studentSub();
    // obj2.studentSub();
    // obj2.studentSub();
    // obj2.showInfo();
    
    // RA obj3("ron", 29, "Literature");
    // obj3.showInfo();
    
    //***********
    // the most common use of polymorphism is when a parent class reference is used
    // to refer a child class object
    // approach with virtual function
    TA obj4 = TA("rick", 33, 1703069, "England");
    RA obj5 = RA("pam", 29, "Philosophy");
    
    // Teacher* obj6 = &obj4;
    // Teacher* obj7 = &obj5;
    
    // obj6->practice();
    // obj7->practice();


    // different polymorphism approach
    obj4.practice();
    obj4.practice();
    obj4.practice();
    obj4.practice();
    obj5.practice();
    // obj4.showInfo();
    // obj5.showInfo();

    Teacher* obj6 = &obj4;
    Teacher* obj7 = &obj5;

    obj6->ratingAnalysis();
    obj7->ratingAnalysis();

}