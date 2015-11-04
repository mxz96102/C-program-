#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 1000
#define MAXLENTH 1000
char *lineptr[MAXLINE];
char *p;
void qsorts(char *v[],int left,int right);

int getlines(char line[],int max);

void main(int argc,char *argv[]){
	int readlines(char *lineptr[],int max);
	void writelines(char *lineptr[],int nlines,int tailnum);
	int nlines,tailnum=10;
	
	int i;
	if(argc<=1)						//判断输入参数
		tailnum=10;
	else if(argc==2&&(*++argv)[0]=='-') {
		tailnum=atoi(argv[0]+1);
	}else {
		printf("usage error");
	}
	nlines=readlines(lineptr,MAXLINE);
	if(nlines<tailnum)					//使参数变得合法
		tailnum=nlines;
	if(tailnum>MAXLINE)
		tailnum=MAXLINE;
	writelines(lineptr,nlines,tailnum);

}

int readlines(char *lineptr[],int max){				//新建readline来读取输入内容
	int len,nlines=0,i;
	char line[MAXLENTH];
	p=calloc(MAXLINE,MAXLENTH);				//分配一片内存来容纳输入内容
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

/*删除了之前多次修改所遗留的测试函数以及没有用到的功能函数,
 *加入了参数合法性的判断*/	
