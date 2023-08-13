#include<bits/stdc++.h>
using namespace std;
class student{
    private:
    string Name;
    int Rollno,Age;
    public:
    student(string name,int roll,int age){
        Name=name;
        Rollno=roll;
        Age=age;
    }
    void setname(string name){
        Name=name;
    }
    string name(){
        return Name;
    }
    void setage(int age){
        Age=age;
    }
    int age(){
        return Age;
    }
    void setroll(int roll){
        Rollno=roll;
    }
    int roll(){
        return Rollno;
    }
    void display(student s){
        cout<<"Name:"<<s.name()<<endl;
        cout<<"Roll number:"<<s.roll()<<endl;
        cout<<"Age:"<<s.age()<<endl;
    }
    
};
void addstudent(vector<student>&s){
                int a,r;
                string n;
                cout<<"Enter Name:";
                cin>>n;
                cout<<"Enter Roll Number:";
                cin>>r;
                cout<<"Enter Age:";
                cin>>a;
                int temp=1;
                for(int i=0;i<s.size();i++){
                    if(s[i].roll()==r){
                        cout<<"Error!..A student with this roll number already exits.."<<endl;
                        return;
                    } 
                }
                student New(n,r,a);
                s.push_back(New);
                cout<<"Enrolled successfully.."<<endl;
                return;
}
void updatedata(vector<student>&s){
    string na;
    cout<<"Enter name to be updated:";
    cin>>na;
    int op;
    int tem=0;
    for(int i=0;i<s.size();i++){
        if(s[i].name()==na){
            int tem=1;
            cout<<"Student found..."<<endl;
            do{
                cout<<"1-Update Name"<<endl;
                cout<<"2-Update Rollno"<<endl;
                cout<<"3-Update Age"<<endl;
                cout<<"4-Exit"<<endl;
                cout<<"Enter Your choice:";
                cin>>op;
                string nam;
                int rn;
                int ag;
                switch(op){
                    case 1:
                    cout<<"Enter new Name:";
                    cin>>na;
                    s[i].setname(na);
                    break;
                    case 2:
                    
                    cout<<"Enter new Roll number:";
                    cin>>rn;
                    s[i].setroll(rn);
                    break;
                    case 3:
                    cout<<"Enter new age:";
                    cin>>ag;
                    s[i].setage(ag);
                    break;
                }
            }while(op!=4);
        }
    }
    if(op==4){
        return;
    }
    if(tem==0){
        cout<<"Student not found.."<<endl;
    }
    return;
}
void deletestudent(vector<student>&s){
    string na;
    cout<<"Enter name to be deleted:";
    cin>>na;
    int tem=0;
    for(int i=0;i<s.size();i++){
        if(s[i].name()==na){
            int tem=1;
            s.erase((s.begin()+i));
            cout<<"student removed successfully.."<<endl;
            return;
        }
    }
    if(tem==0){
        cout<<"student not found.."<<endl;
    }
    return;
}
int main(){
    vector<student> s;
    int choice=0;
    do{
        system("cls");
        cout<<"----------------------"<<endl;
        cout<<"1-Add student"<<endl;
        cout<<"2-Edit student data"<<endl;
        cout<<"3-Search student"<<endl;
        cout<<"4-Remove student"<<endl;
        cout<<"5-Display all students"<<endl;
        cout<<"6-Exit"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"enter your choice:";
        cin>>choice;
        string n;
        int temp;
        switch(choice){
            case 1:
                addstudent(s);
                system("pause");
                break;
            case 2:
                updatedata(s);
                system("pause");
                break;
            case 3:
                
                temp=1;
                cout<<"Enter the name of the student"<<endl;
                cin>>n;
                for(int i=0;i<s.size();i++){
                    if(s[i].name()==n){
                        cout<<"student found.."<<endl;
                        s[i].display(s[i]);
                        cout<<"-----------------"<<endl;
                        break;
                    }
                    else if(s[i].name()!=n&&i==s.size()-1){
                        temp=0;
                        break;
                    }
                }
                if(temp==0){
                    cout<<"No student found..."<<endl;
                }
                system("pause");
                break;
            case 4:
                deletestudent(s);
                system("pause");
                break;
            case 5:
                if(s.empty()){
                    cout<<"Error!...There are no students"<<endl;
                }
                for(int i=0;i<s.size();i++){
                    s[i].display(s[i]);
                    cout<<"-----------------"<<endl;
                }
                system("pause");
                break;
            case 6:
                exit(1);
        }
    } while(choice!=6); 
    return 0;
}