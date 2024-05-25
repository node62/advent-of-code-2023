#include<iostream>
using namespace std;

int is_number(char temp_var){
    if(temp_var>='0' && temp_var<='9') 
        return 1; 
    else 
        return 0;
}

int to_num(string s, int f){
    int a=f, b=f;
    int ka=0, kb=0;
    while(ka==0 || kb==0){
        if(is_number(s[a-1])) a--; else ka=1;
        if(is_number(s[b+1])) b++; else kb=1;
    }
    int res= 0;
    for(int i=a; i<=b; i++){
        res= res*10 + s[i]-'0';
    }
    return res;
}

int star(string s, int ptr, int l){
    int a[8] = {ptr-l-1, ptr-l, ptr-l+1,
                ptr-1  , ptr+1,
                ptr+l-1, ptr+l, ptr+l+1}; 
    int count=0;
    int f[2] = {0, 0};
    for(int i=0; i<8; i++){
        if(!(s[a[i]]=='\n' || s[a[i]]=='\0' || a[i]<0 || a[i]>s.size())){
            if(i==0 || i==3 || i==5){
                if(is_number(s[a[i]])){
                    f[count++]=a[i];
                }
            }
            else{
                if(is_number(s[a[i]-1])==0 && is_number(s[a[i]])==1){
                    f[count++]=a[i];
                }
            }
        }
        if(count>2) 
            return 0;
    }
    if(count!=2) return 0;

    int v0 = to_num(s, f[0]);
    int v1 = to_num(s, f[1]);
    return v0*v1; 
}

int main(){
    string s;
    getline(cin, s, 'F');
    int lineLen = 0;
    for(int i = 0; s[i]!='\n' ; i++)
        lineLen++;
    lineLen++;
    int sum=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='*'){
            sum+= star(s, i, lineLen);
        }
    }
    cout<<"Sum: "<<sum;
return 0;
}