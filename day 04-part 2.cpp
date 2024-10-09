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
                // break;
            }
        }
    }
    return count;
}


void deck_operation(int deck[], int freq[], int len){
    for(int i=0; i<len; i++){
        for(int k=0; k<freq[i]; k++){
            for(int j=i+1; j<(deck[i]+i+1); j++){
                freq[j]++;
            }
        }
    }
}

int main(){
    string s;
    string filename = "C:\\Users\\Theodore Regimon\\Desktop\\fcode\\advent of code 2023\\input.txt";
    
    ifstream file(filename);
    int lines=0;
    if(file.is_open()){
        cout<<"File opened successfully!\n";
        string line;
        while(getline(file, line)){
            s+=line;
            s+='\n';
            lines++;
        }
        file.close();
    }
    else{
        cout<<"File not found!";
        return 0;
    }

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
    int deck[lines];
    int card=1;
    for(int i=0; s[i]!='\0'; i++){

        int temp=0;
        if(s[i]=='\n'){
            while(s[i]!=':' && s[i]!='\0')
                i++;
            key=-1;
            deck[card-1]=sol(arr, alen, brr, blen);
            card++;
            clear(arr, alen); clear(brr, blen);
        }
        if(s[i]==':') key=0;
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
    int freq[lines];
    for(int i=0; i<lines; i++) freq[i]=1;

    deck_operation(deck, freq, lines);

    for(int i=0; i<lines; i++)
        sum+=freq[i];
     cout<<"Sum: "<<sum;
return 0;
}