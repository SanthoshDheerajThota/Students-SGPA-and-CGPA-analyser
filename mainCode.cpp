#include <iostream>
#include <vector>
using namespace std;
class Student{
    private :
        string name;
        int rollNumber;
        float sgpa[8];
        float cgpa;
    public :
        void setData(){
            cout<<"enter the name of the student :"<<endl;
            cin>>name;
            cout<<"enter rollno :"<<endl;
            cin>>rollNumber;
            cout<<"enter the sgpa in 8 semesters :"<<endl;
            for(int i=0;i<8;i++){
                cin>>this->sgpa[i];
            }
            cout<<"enter the overall CGPA of the student :"<<endl;
            cin>>this->cgpa;
            cout<<"the data is successfuly stored "<<endl;
        }
        void printData(){
            cout<<"the name of the student is "<<this->name<<endl;
            cout<<"the rollNumber of the student is "<<this->rollNumber<<endl;
            cout<<"the semester wise sgpa of the student are "<<endl;
            for(int i=0;i<8;i++){
                cout<<"the sgpa of "<<i+1<<" semester is  "<<this->sgpa[i]<<endl;
            }
            cout<<"the overall CGPA of the student is "<<this->cgpa<<endl;
        }
        friend void getTheTopperSemesterWise(vector<Student> &allStudents);
        friend void getTheOverallTopper(vector<Student> &allStudents);
};

void  getTheTopperSemesterWise(vector<Student> &allStudents){
    for(int i=0;i<8;i++){
        int indexOfTopper=0;
        float topPercentage=allStudents.at(0).sgpa[i];
        for(int j=0;j<allStudents.size();j++){
            if(topPercentage<allStudents.at(j).sgpa[i]){
                indexOfTopper=j;
                topPercentage=allStudents.at(j).sgpa[i];
            }
        }
        cout<<"the topper int htne semester "<<i+1<<" is "<<allStudents.at(indexOfTopper).name<<endl;
        cout<<"the top percentage is "<<topPercentage<<endl<<endl;;
    }
}
void  getTheOverallTopper(vector<Student> &allStudents){
    int topperIndex=0;
    float topPercentage=allStudents.at(0).cgpa;
    for(int i=0;i<allStudents.size();i++){
        if(topPercentage<allStudents.at(i).cgpa){
            topperIndex=i;
            topPercentage=allStudents.at(i).cgpa;
        }
    }
    cout<<"the overall topper "<<allStudents.at(topperIndex).name<<endl;
    cout<<"the top percentage is "<<topPercentage<<endl<<endl;;
}
int main(){
    vector <Student> allStudents;
    int size;
    cout<<"enter the number of students you want :"<<endl;
    cin>>size;
    for(int i=0;i<size;i++){
        allStudents.push_back(Student());
        allStudents.at(i).setData();
    }
    for(int i=0;i<size;i++){
        allStudents.at(i).printData();
    }
    getTheTopperSemesterWise(allStudents);
    cout<<endl;
    getTheOverallTopper(allStudents);
    return 0;
}
