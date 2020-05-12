#include <iostream>
#include <vector>
#include <string>

using namespace std;

int findSum(int arr[], int len){
    cout << "arr " << arr << endl;
    int sum = 0;
    for(int i =0; i<len; i++){
        sum+=arr[i];
    }
return sum;
}

class temp{
public:
    int a;
};

int dummy(string& s){
cout << "&s: " << &s << endl;
}

int main(void) {
    vector<int> vec1{1, 2, 3, 4};
    vector<int> vec2 = vec1;
    cout << "&vec1" << &vec1<<endl;
    cout << "&vec2" << &vec2<<endl;

    int A[] = {1, 2, 3};
    string str1 = "dummy";
    cout << "A " <<A << endl;
    cout << findSum(A, 3) <<endl;
    string str = str1;
    cout << "&str1 "<<&str1 << endl;
    cout << "&str "<<&str << endl;
    str[0] = 'v';
    cout << "str: "<<str<<endl;
    cout << "str1: "<<str1<<endl;
    dummy(str);

    cout <<endl;
    cout <<endl;

    temp t1;
    t1.a = 5;
    temp t2 = t1;
    cout << "&t1: "<< &t1 <<endl;
    cout << "&t2: "<< &t2 <<endl;

    t2.a = 7;
    cout << "t1.a: "<<t1.a<<endl;
    cout << "t2.a: " << t2.a <<endl;

   return 0;
}
