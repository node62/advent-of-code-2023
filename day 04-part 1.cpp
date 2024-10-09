#include<iostream>
#include<fstream>
using namespace std;

void clear(int arr[], int size){
    for(int i=0; i<size; i++){
        arr[i]=-1;
    }
}

bool is_num(char c){
    if(c>='0' && c<='9') return true;
    return false;
}

int to_num(string s, int& i){
    int num=0;
    while(is_num(s[i])){
        num=num*10+(s[i]-'0');
        i++;
    }
    return num;
}

int sol(int arr[], int alen, int brr[], int blen){
    int count=0;
    for(int i=0; i<blen; i++){
        for(int j=0; j<alen; j++){
            if(arr[j]==brr[i]){
                count++;
                break;
            }
        }
    }
    auto pow = [](int a, int b){
        int res=1;
        for(int i=0; i<b; i++){
            res*=a;
        }
        return res;
    };
    if (count==0) return 0;
    else return pow(2, count-1);
}

int main(){
    cout<<"Enter the string: \n";
    string s;
    string filename = "C:\\Users\\Theodore Regimon\\Desktop\\fcode\\advent of code 2023\\input.txt";
    
    ifstream file(filename);

    if(file.is_open()){
        string line;
        while(getline(file, line)){
            s+=line;
            s+='\n';
        }
        file.close();
    }
    else{
        cout<<"File not found!";
        return 0;
    }

     cout<<s;
    int alen=-1, blen=0;
    int key=0;
    for(int i=0; s[i]!='\n'; i++){
        if(s[i]==':') key=1;
        else if(s[i]=='|') key=2;

        if(s[i]==' ' && s[i+1]==' ') continue;

        if(key==1 && s[i]==' ') alen++;
        else if(key==2 && s[i]==' ') blen++;
    }
    int arr[alen], brr[blen];
    clear(arr, alen); clear(brr, blen);
    int sum=0;
    key=-1; 

    for(int i=0; s[i]!='\0'; i++){

        int temp=0;
        if(s[i]=='\n'){
            i=i+7;
            key=-1;
            sum+=sol(arr, alen, brr, blen);
            clear(arr, alen); clear(brr, blen);
        }
        else if(s[i]==':') key=0;
        else if(s[i]=='|') key=1;

        if(key==-1) continue;

        if(is_num(s[i])){
            temp=to_num(s,i); i--;
            auto fun = [](int arr[], int alen, int temp){
            for(int j=0; j<alen; j++){
                if(arr[j]==-1){
                    arr[j]=temp;
                    break;
                }
            }
            };
            if(key==0) fun(arr, alen, temp);
            else fun(brr, blen, temp);
        }
    }
    cout<<"Sum: "<<sum;
return 0;
}