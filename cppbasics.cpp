#include<bits/stdc++.h>

using namespace std;

class Animals{
    private:
        string owner_name;
        int owner_id;
    public:
        static int total_count;

        Animals(){
            total_count++;
        }
        void set_owner_name(string o_name){
            owner_name = o_name;
        }
        void set_owner_id(int o_id){
            owner_id = o_id;
        }
        string get_owner_name(){
            return owner_name;
        }
        int get_owner_id(){
            return owner_id;
        }
        ~Animals(){
            cout << "gg" << endl;
        }
};

class Dog: public Animals{
    private:
        string dog_name;
    public:
        void set_dog_name(string name){
            dog_name = name;
        }
        string get_dog_name(){
            return dog_name;
        }
};

string adulthood(int& age){
    if(age<15)return "childhood";
    if(age>15 && age<25)return "teenage";
    if(age>25 && age<45)return "adult";
    if(age>45) return "grandparent";
}

float area_of_circle(int radius){
    return (float) 3.14*(radius*radius);
}
int Animals::total_count = 0;

int main(){
    
    cout << "Hello world"<<endl;
    
    int age=10;
    float money=20.01;
    double speed=3.1800000;
    bool is_it = false;
    char ch = 'a';
    char name[] = "Siva";
    string s = "kumar";
    
    cout << "Enter your age" << endl;
    cin >> age;
    
    if(age>=18){
        cout << "you can vote" << endl;
    }
    else{
        cout << "you cant vote" << endl;
    }

    while(is_it){
        if(money<10)break;
        cout << money;
        money--;
    }

    for(int i=10;i<100;i++){
        if(i==30)cout<<"hi";
        if(i==99)cout<<"end"<<endl;
    }

    int rad = 0;
    try
    {
        cout << "enter radii for area of circle: ";
        cin >> rad;
        cout << area_of_circle(rad) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Animals dog;
    dog.set_owner_id(1);
    dog.set_owner_name("siva");
    cout << dog.get_owner_name() << endl;

    int dog_age = 12;
    int *d_age = &dog_age;
    *d_age = 30;
    cout << dog_age << endl;

    cout << adulthood(*d_age) << endl;

    int* arr_ptr = new int[10];

    for(int i=0;i<10;i++){
        arr_ptr[i] = i;
    }
    for(int i=0;i<10;i++){
        cout << arr_ptr[i];
    }

    Dog chop;
    chop.set_dog_name("chop");
    cout << chop.get_dog_name();
    delete[] arr_ptr;

    ofstream MyFile("filename.txt");
    MyFile << "writing data in c++ is great!!";
    MyFile.close();
    return 0;
}

