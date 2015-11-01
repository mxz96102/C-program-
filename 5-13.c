#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
#define MAXLENTH 1000
char *lineptr[MAXLINE];
void qsorts(char *v[],int left,int right);

int getlines(char line[],int max);

main(int argc,char *argv[]){
	int readlines(char *lineptr[],int max);
	void writelines(char *lineptr[],int nlines,int tailnum);
	int nlines,tailnum=10;
	
	int i;
/*	for(i=1;i<argc;i++)
		printf("%s%s",argv[i],(i<argc-1)?" " :"");*/
	if(argc<=1)
		tailnum=10;
	else if(argc==2&&(*++argv)[0]=='-') {
		tailnum=atoi(argv[0]+1);
	}else {
		printf("usage error");
	}
		printf("%d",tailnum);
	nlines=readlines(lineptr,MAXLINE);
	writelines(lineptr,nlines,tailnum);
	

}

int readlines(char *lineptr[],int max){
	int len,nlines=0,i;
	char *p;
	char line[MAXLENTH];
	p=calloc(MAXLINE,MAXLENTH);
	for(i=0;i<=MAXLINE;i++)
		lineptr[i]=NULL;
		i=0;
	while((len=getlines(line,MAXLENTH))>0){
		lineptr[i]=p;
		strcpy(lineptr[i],line);
		p+=1+len;
		nlines++;	
		i++;
	}
	return nlines;
}
			
void writelines(char *lineptr[],int nlines,int tailnum){
	int i;
	for(i=nlines-tailnum;tailnum-->0;i++)
		printf("%s",lineptr[i]);
}




void swap(char *v[],int i ,int j){
	char *temp;
	temp=v[i];
	v[i]=v[j];
	v[j]=temp;

}

int getlines(char s[], int lim){
        int c,i;
        i=0;
        while(--lim>0&&(c=getchar())!=EOF&&c!='\n')
                s[i++]=c;
        if(c=='\n')
                s[i++]=c;
        s[i]='\0';
        return i;
}	
