#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
void selectfail();
void Shellsort(char **AA,int N);
void pars (char stro[],int n);
char **A;
int j=0;
typedef char *pint;
	int w,n=20;
char fname[10];
FILE *f,*pu;
int main () {
//fname= fileselect();
	printf(" scan \n");
	f=fopen(fname,"r");
     printf(" fopen \n");
	getchar();
	
	fclose(f);
return 0;
}

void selectfail(){
     int flag=0;
      while (flag==0)
{     	printf(" Enter filename \n");
//       fgets(fname);  
//		fname=fgets( buffer, buffer_len, stdin ) ;
		scanf("%s",fname);
       if ((f=fopen(fname,"r")) == NULL) {
                              printf("Error open file not faund \n ");
                             } else { 
                                    printf("Open file \n");     
                                   flag=1;                                
                                  }
       }
}

void Shellsort(char **AA,int N){
	int h=2,i,jj,k;
	char t[20],temp[20];//slovo
	for(k=h;k>0;k--){
	 for(i=k;i<N;i++){
	 	strcpy(t,AA[i]);
	 	jj=i-k;
	 
	 	while(jj>=0 && strcmp(t,AA[jj]) < 0){ //sortirovka
	 	
	 		strcpy(temp,AA[jj+k]);
	 		strcpy(AA[jj+k],AA[jj]);
	 		strcpy(AA[jj],temp);
	 		jj=jj-k;
	 		
		}
	 	strcpy(t,AA[jj+k]);
	 }}
}
    void pars (char stro[],int n){
    	printf("\n%s\n",stro);
		int i=0;
    	char ch= stro[0]; //droblenie na slova
    	int k=0;
    	char slovo[20];
    	 
     //или a4=new char*[n]
    
    while (ch != '\0')
    {
    		while ( (stro[k-1]==' ') && (stro[k]==' ') && (stro[k] != '\0')&&(k<20)) 
    			k++;
	        ch= stro[k];k++;
			//printf("%c",ch);
	    	if ((ch != ' ') && (ch != '\0')) 
			{
    		slovo[i] = ch;
	    	i++;
			}
			else{
				if(ch!= '\0')
				{
				
			slovo[i+1] = '\0';	
			printf("RES %s \n",slovo);
			A[j]=(char *) calloc(i+1,sizeof(char));
           // A[j] = new char[i+1];
            strcpy(A[j], slovo);
			j++;
			i=0;
			for (int i=0; i<20; i++) 
				slovo[i]='\0';
			}}
			
	}
	slovo[1+i] = '\0';	
	printf("RES %s\n",slovo);
	A[j]=(char *) calloc(i+1,sizeof(char));
	strcpy(A[j], slovo);
	j++;
	i=0;
return;
}
