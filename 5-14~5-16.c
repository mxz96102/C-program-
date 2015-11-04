#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#define MAXLINE 500
#define MAXLENTH 500
void qsorts(void *v[],int left ,int right,int (*comp)(void *,void *));
int numcmp( char *s1, char *s2);
int fccmp(char *s1,char *s2);
int dcmp(char *s1,char *s2);
int fdcmp(char *s1,char *s2);
int getlines(char line[],int max);
int readlines(char *lineptr[],int max);
void writelines(char *lineptr[],int nlines);
int option;

main(int argc,char *argv[]){
	char *lineptr[MAXLINE];
	int nlines;
	int stal,endl;
	int i,numeric=1;
	char c;
	
	if((argc>=2||argc<=4)&&(*argv[1])=='-'){
			c=*(argv[1]+1);
			 if(argc==3){
                                stal=atoi(argv[2]);
                                endl=0;}
                         if(argc==4){
                                stal=atoi(argv[2]);
                                endl=atoi(argv[3]);}

			switch(c){
				case 'n':
					if(*(argv[1]+2)=='r'){
						option=2;
						break;}
					option=1;
					break;
				case 'r':
					if(*(argv[1]+2)=='n'){
						option=2;
						break;}
					option=5;
					break;
				case 'f':
					if(*(argv[1]+2)=='d'){
						option=6;
						break;}
					option=3;
					break;
				case 'd':
					if(*(argv[1]+2)=='f'){
						option=6;
						break;}
					option=4;
					break;		
			
				default:
					printf("option error\n");
					return 1;
					break;
				}
		}else { if(argc==1)
			option=0;
			else {	
			printf("usage error\n");
			return 1;
				}
		}
		printf("%d",option);
		if(endl<=stal){
			printf("start line end line illigal");
			return 1;}
	
		if((nlines = readlines(lineptr,MAXLINE))>0){
			if(endl>nlines-1)
				endl=nlines-1;
			switch(option){
				case 0:
					qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))strcmp);
					break;
				case 1:
					qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))numcmp);
					break;
				case 2:
					qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))numcmp);
					break;
				case 3:
					qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))fccmp);
					break;
				case 4:
					qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))dcmp);
					break;
				case 5:
                    qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))strcmp);
                    break;
				case 6:
					qsorts((void **) lineptr,stal,endl,(int (*)(void*,void*))fdcmp);
					break;
				default:
					break;
			}
			writelines(lineptr,nlines);
		}else 
			printf("too big to sort\n");		
 		return 0;	
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

void writelines(char *lineptr[],int nlines){
	int i;
	if(option==2||option==5)
		for(i=nlines-1;nlines-->0;i--)
                        printf("%s",lineptr[i]);

	else
		for(i=0;nlines-->0;i++)
			printf("%s",lineptr[i]);
}

int numcmp( char *s1, char *s2){
	double v1,v2;

	v1 = atof(s1);
	v2=atof(s2);
	if (v1<v2)
		return -1;
	else if(v1>v2)
		return 1;
	else 
		return 0;
}

int fccmp(char *s1,char *s2){
	char t1,t2;
		t1=*s1;
		t2=*s2;
		if(isupper(t1))
			t1=tolower(t1);
		if(isupper(t2))
                        t2=tolower(t2);
                return t1-t2;

}

int dcmp(char *s1,char *s2){
        char t1,t2;
	t1=*s1;
	t2=*s2;
	if(ispunct(t1)){
		s1++;
		return;	}
	if(ispunct(t2)){
                s2++;
                return;}
		
        if (t1<t2)
                return -1;
        else if(t1>t2)
                return 1;
        else
                return 0;

}

int fdcmp(char *s1,char *s2){
        char t1,t2;
        t1=*s1;
        t2=*s2;
	if(isupper(t1))
        t1=tolower(t1);
    if(isupper(t2))
        t2=tolower(t2);

    if(ispunct(t1)){
        s1++;
        return; }
    if(ispunct(t2)){
        s2++;
        return;}

    if (t1<t2)
        return -1;
    else if(t1>t2)
        return 1;
    else
        return 0;

}


		

void qsorts(void *v[],int left ,int right,int (*comp)(void *,void *)){
	int i,last;
	void swap(void *v[],int,int);

	if(left>=right)
		return;
	swap(v,left,(left+right)/2);
	last=left;
	for (i = left+1;i<= right;i++)
		if ((*comp)(v[i],v[left]) < 0)
			swap(v, ++last, i);
	swap(v,left,last);
	qsorts(v,left,last-1,comp);
	qsorts(v,last+1,right,comp);
}

void swap(void *v[],int i,int j){
	void *temp;

	temp=v[i];
	v[i]=v[j];
	v[j]=temp;
}
