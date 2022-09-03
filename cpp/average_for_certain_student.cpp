#include<bits/stdc++.h>
using namespace std;

float average_of_students(int sum, int student_no){
    if(sum==0)return 0;
    float average = (float) sum/student_no;
    return average;
}

int main(){
    int arr[10],sum=0;
    for(int i=0;i<10;i++){
        arr[i] = rand()%100+1;
        sum+=arr[i];
    }
    float average = average_of_students(sum, 10);
    cout<< "The score of students are: ";
    for(int i: arr){
        cout << i<<" ";
    }
    cout << "\nTotal points: "<<sum<<"\n";
    cout << setprecision(2) << fixed << "The average is: "<<average<<"\n";
    return 0;
}