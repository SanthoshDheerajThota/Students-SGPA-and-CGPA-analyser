// this is completely written by  T.Santhosh Dheeraj
#include <iostream>
using namespace std;
class Student {
    protected : 
        string name;
        string rollNo;
        string mobileNumber;
    public :
        void setData(){
            cout<<" enter the name of the student :"<<endl;
            cin>>this->name;
            cout<<"enter the roll number :"<<endl;
            cin>>this->rollNo;
            cout<<"enter the mobile number of the student :"<<endl;
            cin>>this->mobileNumber;
        }
        void printData(){
            cout<<"the name of the student is "<<this->name<<endl;
            cout<<"the roll no of the student is "<<this->rollNo<<endl;
            cout<<"the mobile number of the student is "<<this->mobileNumber<<endl;
        }
};
class CIE_1 : virtual public Student{
    protected :
        int internal1;
        int internal2;
        float percentage;
    public :
        void setData1(){
            cout<<"enter the internal -1 marks :"<<endl;
            cin>>this->internal1;
            cout<<"enter the internal -2 marks :"<<endl;
            cin>>this->internal2;
            percentage=((internal1+internal2)*(5/3.0));
        }
        void printData1(){
            cout<<"the internal-1 marks of the student are :"<<this->internal1<<endl;
            cout<<"the internal-2 marks of the student are :"<<this->internal2<<endl;
            cout<<"the internal percentage marks of the student are :"<<this->percentage<<endl;
        }
};
class CIE_2:virtual public Student{
    protected :
        int Q[3],A[3];
        float percentageQuiz;
        float percentageAssignment;
    public :
        void setData2(){
            cout<<"enter the three assignmenents and three quix marks respectively :"<<endl;
            cin>>A[0]>>A[1]>>A[2]>>Q[0]>>Q[1]>>Q[2];
            percentageQuiz=(Q[0]+Q[1]+Q[2])*(20/3.0);
            percentageAssignment=(A[0]+A[1]+A[2])*(20/3.0);
        }
        void printData2(){
            cout<<endl;
            cout<<"the three quiz marks are :"<<endl;
            cout<<"Quiz - 1 = "<<Q[0]<<endl;
            cout<<"Quiz - 2 = "<<Q[3]<<endl;
            cout<<"Quiz - 3 = "<<Q[3]<<endl;
            cout<<endl;
            cout<<"the Assignment marks are :"<<endl;
            cout<<"Asiignment - 1 = "<<A[0]<<endl;
            cout<<"Asiignment - 2 = "<<A[1]<<endl;
            cout<<"Asiignment - 3 = "<<A[2]<<endl;
            cout<<endl;
            cout<<"the quiz marks percentage is :"<<this->percentageQuiz<<endl;
            cout<<"the quiz marks percentage is :"<<this->percentageAssignment<<endl;
        }
};
class SEE:public CIE_1,public CIE_2{
    private :
        int finalTotal;
        int finalPercentage;
    public:
        void setData(){
            CIE_1::setData();
            CIE_1::setData1();
            CIE_2::setData2();
            cout<<"enter the final marks of 60 :"<<endl;
            cin>>finalTotal;
            finalPercentage=((internal1+internal2)/2.0)+((Q[0]+Q[1]+Q[2]+A[1]+A[2]+A[0])/3.0)+finalTotal;
        }
        void printData(){
            CIE_1::printData();
            CIE_1::printData1();
            CIE_2::printData2();
            cout<<"the final total marks are :"<<this->finalTotal<<endl;
            cout<<"the final percentage in the course is "<<this->finalPercentage<<endl;
        }
};
int main(){
    SEE santhosh;
    santhosh.setData();
    cout<<endl;
    santhosh.printData();
    return 0;
}
