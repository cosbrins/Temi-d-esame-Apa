#include <stdio.h>
#include <stdlib.h>
int check(int *v, int *sol, int n){
    int sum=0,i,k=0;
    if(!sol[0])
        return 0;
    for(i=0;i<n;i++){
        if(i==0) {
                sum = sum + v[i];
                k++;
                i = i + v[i]-1;
        }
        else{
            if(sol[i]==0){
                return 0;
            }
            else{
                sum=sum+v[i];
                i=sum;
                k++;
            }
        }
    }
    if(sum>=n){
        return k;
    } else{
        return 0;
    }
}
void powerset(int *v, int pos, int *sol, int *bestsol, int n, int *bestnum_salti, int *num_salti){
    int i;
    if(pos>=n){
        if(check(v,sol,n)>0 && check(v,sol,n)<*num_salti){
            *bestnum_salti=check(v,sol,n);
            *num_salti=*bestnum_salti;
            for(i=0;i<n;i++){
                bestsol[i]=sol[i];
            }
        }
        return;
    }
    sol[pos]=0;
    powerset(v,pos+1,sol,bestsol,n,bestnum_salti,num_salti);
    sol[pos]=1;
    powerset(v,pos+1,sol,bestsol,n,bestnum_salti,num_salti);
    return;

}
int main() {
    int *v,*sol,*bestsol;
    int n=5;
    int nsalti=4,ns=4,best_salti=0,i,count=0;
    v=malloc(n*sizeof(int));
    sol=calloc(nsalti,sizeof(int));
    bestsol=calloc(nsalti,sizeof(int));
    v[0]=2;
    v[1]=2;
    v[2]=3;
    v[3]=2;
    v[4]=1;
    powerset(v,0,sol,bestsol,nsalti,&best_salti,&ns);
    for(i=0;i<nsalti;i++){
        if(bestsol[i]){
            printf("Salto di %d dalla posizione %d\n",v[i],i);
        }
        else{
            count++;
        }
    }
    if(count==nsalti)
        printf("Non ci sono soluzioni possibili");
    return 0;
}
