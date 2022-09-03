#include<iostream>
#include<iomanip>
#include<limits>

using namespace std;

float average_of_students(int sum, int student_no){
    if(sum==0)return 0;
    float average = (float) sum/student_no;
    return average;
}

int main(){
    int score,sum=0,student_no=0;

    do{
        cout<< "Please enter the integer(-1 to stop) ";
        cin >> score;
        //exit case
        if(score==-1)break;

        if(score<0 || score>100 || cin.fail()){
            // exception if user enters other datatypes char, str
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            // prints invalid
            cout << "Invalid Score\n";
        }
        else{
            student_no++;
            sum+=score;
        }

    }while(true);

    float average = average_of_students(sum, student_no);
    
    cout << "Number of students: "<<student_no<<"\n";
    cout << "Total points: "<<sum<<"\n";
    cout << setprecision(2) << fixed << "The average is: "<<average<<"\n";
    return 0;
}