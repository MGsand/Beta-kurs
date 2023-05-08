#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
char **A;
int j=0;
typedef char *pint;
   
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

int main () {
	int w,n=20;
	 A= (char **) malloc(n*sizeof(char *));
     A = new  pint[n];
    char ch, sl[200];
    char text[]="one two three four\n";
	FILE *pf,*pu; 
	pf=fopen("A.txt","r"); 
//fprintf(pf,"%d",5);
fscanf(pf,"%d",&w);
 for(int i=0;i<6;i++)
 {
 //fputs(text,pf);
 }
fclose(pf);
 
pf=fopen("A.txt","r"); //otkritie faila
printf(" %s\n"," From FILE:  ");

while ((ch=getc(pf))!=EOF)
   {
   fgets(sl, 200, pf);
   char temp[2];
   temp[0] = ch;
   temp[1]='\0';
   
   strcpy(temp,  strcat(temp,sl));
   
   //printf("%s", temp);
    pars(temp,n);
}

printf("\n This is result array \n");
    
	//for(int i=0;i<10;i++){
	
     for(int i=0;i<j;i++)  //j - kolvo slov
     	{
		  printf("%s \n", A[i]);
     }
   //  printf("\n");
   Shellsort(A,j);
   

printf("\n This is result array \n");
    
	//for(int i=0;i<10;i++){
	
     for(int i=0;i<j;i++)  //j - kolvo slov
     	{
		  printf("%s \n", A[i]);
     }
	    
 for(int i=0; i<n; i++) {
       free(A[i]);
       }
     free(A);

//printf(" %d",w);
fclose(pf);
return 0;
}
