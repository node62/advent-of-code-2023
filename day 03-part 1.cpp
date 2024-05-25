#include<iostream>
using namespace std;

int* fun(string s, int i){
    int* ptr = new int[2];
    int j;
    int num=0;
    for(j = i; s[j]>='0'&&s[j]<='9'; j++){
        num = num*10 + (s[j]-'0');
    }
    ptr[0] = num;
    ptr[1] = j;
    return ptr;
}

int findCogs(string s, int a, int b, int len){
    a--; 

    if(a==-1 || s[a]=='\n')
        a++;

    if(s[b]=='\n' || s[b]=='\0')
        b--;

    if(!(s[a]=='.' || s[a]>='0' && s[a]<='9'))
        return 1;

    else if(!(s[b]=='.' || s[b]>='0' && s[b]<='9'))
        return 1;

    if(a-len>=0)
        for(int i = a-len; i<=b-len; i++){
            if(!(s[i]>='0' && s[i]<='9' || s[i]=='.')){
                return 1;
            }
        }

    if(a+len<s.size())
        for(int i = a+len; i<=b+len; i++){
            if(!(s[i]>='0' && s[i]<='9' || s[i]=='.')){
                return 1;
        }
    }
    return 0;
}

int main(){
    string s;
    getline(cin, s, 'F');
    int lineLen = 0;
    for(int i = 0; s[i]!='\n' ; i++)
        lineLen++;
    lineLen++;
    cout<<s[lineLen];
    int sum = 0;
    int temp;
    for(int i = 0; s[i]!='\0'; i++){
        int* ptr = new int[3];
        if(s[i] >= '0' && s[i]<= '9'){
            ptr = fun(s, i);
            temp=i;
            if(findCogs(s, temp, ptr[1], lineLen)){
                sum+=ptr[0];
            }
            i = ptr[1];
        }
    }
    cout<<"Sum: "<<sum<<endl;
return 0;
}