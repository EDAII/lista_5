#include<stdio.h>
#include <stdlib.h>

int achahead( int* vet, int n){
    int head,i;
    head=vet[0]; 

    for(i=0;i<n;i++){
     if(head>vet[i]){
      head=vet[i];
        }  
    }
     
    return head;  
}

int* montavet(int* vet,int  n){
	
    int head;
    int i2,n2;
    i2=0;
    n2=n-1;
    int* vet2=(int*)malloc(n*sizeof(int));
    int i;
    head=achahead(vet,n);
    
    printf("passo 2\n");
    for(i=0;i<=n;i++){
       if(vet[i]!=head){
         vet2[i2]=vet[i];     
         i2++;  
       }
    } 
    return vet2;
}
int achaelementodomeio(int* vet, int n){
    int* vet2;    
    vet2=montavet(montavet(vet,5),4);
    return achahead(vet2,3);
}
int achaelementodomeio2(int* vet, int n){
    int i;
    int* vet2;
    int quant;  
    for(i=0;i<3;i++){
      quant=n-i;
      vet2=montavet(vet,quant);
    }
    return achahead(vet2,quant);   
}                 
int** divide(int* vet, int n){
      int i,i2,icont=0;
      int** vetpoint;
      vetpoint=(int**)malloc(2*sizeof(int*));
      for(i2=0;i2<n;i2++){
         vetpoint[i2]=(int*)malloc(5*sizeof(int));
      }
           
      for(i2=0;i2<n;i2++){ 
        for(i=0;i<5;i++){
           vetpoint[i2][i]=vet[icont];
           printf("%d\n",vet[icont]); 
           icont++;   
        }
      }
      return vetpoint;          
} 
int* dividepivo(int* vet, int n, int mom){
      int** vetpoint;
      int i,contmenor, contmaior,i2; 
      contmenor=0;
      contmaior=0;      
      vetpoint=(int**)malloc(2*sizeof(int*));
      for(i2=0;i2<n;i2++){
         vetpoint[i2]=(int*)malloc(n*sizeof(int));
      }  
      for(i=0;i<n;i++){
         if(vet[i]>mom){
           vetpoint[1][contmaior]=vet[i];
           contmaior++;
           printf(" é maior do que : %d ,%d\n",mom,vet[i]);
          }else{
            vetpoint[0][contmenor]=vet[i];
            contmenor++;
            printf(" é menor do que : %d ,%d\n",mom,vet[i]); 
              
          }
     }
     if(contmaior>contmenor){
       vetpoint[1];
       vetpoint[1][contmaior+1]=-1;
       return vetpoint[1];         
     }else{
       vetpoint[0];
       vetpoint[0][contmenor+1]=-1;
       return vetpoint[0];  
     }     
} 
int* selecionamediana(int* vet, int n){  
     int ndivide;
     int** vetpoint;
     ndivide=n/5;
     vetpoint=divide(vet,ndivide);
     int i2;
     int meio[ndivide];
     i2=0;
     int* vet2;
     printf("passo 1\n");
     for(i2=0;i2<ndivide;i2++){
      meio[i2]=achaelementodomeio(vetpoint[i2],5);
      printf(" o elemnto do meio é :%d\n ",meio[i2]);
     }
     int meioele;
     meioele=achaelementodomeio2(meio,3); 
     printf("a mediana das medianas é %d\n:",meioele); 
     vet=dividepivo(vet,n,meioele);
     return vet;  
      
  
}                                    
int main(){
int i;
int* vet;
int ndivide, n;
printf("digite a quantidade de numeros");
scanf("%d",&n);
printf("passo inicio");
vet=(int*)malloc(n*sizeof(int));   
for(i=0;i<n;i++){ 
   printf("digite o numero %d", i);
   scanf("%d", &vet[i]);
}

vet=selecionamediana(vet,n);
i=0;
while(vet[i]!=-1){
  printf("%d\n",vet[i]);
  i++;
}

  
}



