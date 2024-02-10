#include<iostream>
using namespace std;

int first_digit(string s){
    string num[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=0; i<s.length();i++){
                for(int j=0; j<10;j++){
        if (s[i] >= '0' && s[i] <= '9')
            return s[i]-'0';
          else if(s.compare(i,num[j].length(),num[j])==0)
            return j;
    }}
    return 0;
}

int last_digit(string s){
    string num[10]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i=s.length()-1; i>=0;i--){
                for(int j=0; j<10;j++){
        if (s[i] >= '0' && s[i] <= '9')
            return s[i]-'0';
        else if(s.compare(i,num[j].length(),num[j])==0)
            return j;
    }}
    return 0;
}

int main() {
    cout << "Enter: ";
    string str = "";
    int sum = 0;

    while (str != "$"){
        cin>>str;
        int k = first_digit(str);
        int m = last_digit(str);
        sum = sum + k*10 + m;
        cout<<"        sum: "<<sum<<endl;
    }

    cout << "\nSum is: " << sum;
}
