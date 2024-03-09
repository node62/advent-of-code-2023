#include<stdio.h>

int check(char temp[], int r, int g, int b){
    int index = 0;
    for(;temp[index]!=':'; index++); 
    index++;
    int a=0;
    for(;temp[index]!='\0'; index++){
        // printf("%d", index);
        if(temp[index]==';'||temp[index]==','){
            a=0;
        }

        if(temp[index]>='0'&&temp[index]<='9'){
            // printf("\n<%d>", a);
            a=10*a+(temp[index]-'0');
            // printf("\n[%d]\n", a);
        }

        if(temp[index-1]==' '&&temp[index]=='b'){
            if(a>b){
                return 0;
            }
        }
        if(temp[index-1]==' '&&temp[index]=='g'){
            if(a>g){
                return 0;
            }
        }
        if(temp[index-1]==' '&&temp[index]=='r'){
            if(a>r){
                return 0;
            }
        }
    }
return 1;
}

void blank(char temp[]){
    for(int i=0; temp[i]!='\0'; i++)
        temp[i]='\0';
}

int main(){
    int games=100;
    int r=12, g=13, b=14;
    printf("Enter the strings: \n");
    char temp[200];
    int ans=0;
    for(int i=1; i<=games; i++){
        blank(temp);
        fgets(temp, sizeof(temp), stdin);
        if(check(temp, r, g, b))
        ans+=i;
    }
    printf("\nans: %d", ans);
return 0;
}