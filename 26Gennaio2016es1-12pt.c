#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6
#define LSTR 14

char *charErase (char *str, int *pos){
    char *nstr;
    int cont=0,i,k=0;
    for(i=0;i<N;i++){
        if(pos[i]>=0)
            cont++;
    }
    nstr=calloc(strlen(str)-cont, sizeof(char));
    for(i=0;i<N;i++){
        if(pos[i]>=0){
            str[pos[i]]=' ';
        }
    }
    for(i=0;i<strlen(str);i++){
        if(str[i]!=' '){
            nstr[k]=str[i];
            k++;
        }
    }
    nstr[k]='\0';
    return nstr;
}
int main() {
    char *str,*nstr;
    str=calloc(LSTR, sizeof(char));
    str=strdup("ThisIsAString");
    int *pos;
    pos=calloc(N, sizeof(int));

    pos[0]=7;
    pos[1]=4;
    pos[2]=2;
    pos[3]=0;
    pos[4]=11;
    pos[5]=-1;
    nstr=charErase(str,pos);
    printf("\nNuova stringa: %s ",nstr);
    return 0;
}
