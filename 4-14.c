//4-14 reverse by dominicm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char reverse(char* str,int i){		//reverse函数，输入字符串变量，开始倒转的字符下标
	int k,j,len;
	len=strlen(str);
	char temp;
	for(k=0;str[k]!='\0';k++){j=k;}	//用来计算有效的字符
	if(i<j-i){
	temp=str[i];
	str[i]=str[j-i];
	str[j-i]=temp;
	i++;
	reverse(str,i);}
	return str[len];	
}

int main(void){
	char reverse(char*str,int i);
	static	char m[255];
	fgets(m,255,stdin);
	m[255]=reverse(m,0);	
	printf("%s\n",m);
}
/*总结的话,缺点很明显,就是字符串长度要提前规定好,
*而且需要输入开始倒转字符的下标才能开始.*/
