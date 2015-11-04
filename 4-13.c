//4-13 itoa  by dominicMing 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char myitoa(int intnum,char*str ,int radix,int i){			//定义新函数来完成itoa功能
	int m,n;							
	char index[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";  		//索引数组，来转换数字
	n=strlen(str);							
	if(intnum>0){							//判断是否递归
		m=intnum%radix;						
		intnum=intnum-m;					
		intnum=intnum/radix;					
		str[n-1-i]=index[m];					
		i++;							
		myitoa(intnum,str,radix,i);				
	}else							
	return  *str;							
}

int count(int num,int radix){						//定义函数来估计字符数组大小
	int co=0;							
	do								
	{
		num=num/radix;
		co++;
	}while(num<=radix);
	return co;
} 

int main(void){
	char myitoa(int intnum,char* ,int radix,int i);
	int count(int num,int radix);
	int intnum=12345,y,radix;
	printf("input radix");
	scanf("%d",&radix);
	printf("input number");
	scanf("%d",&intnum);
	y=count(intnum,radix);
     	char str[y];
	myitoa(intnum,str,radix,0);
	printf("%s\n",str);
} 
/*这一次感觉好像是不是有些编写的错误，但是又不知道在哪里，因为linux下运行只能运行6位整数，学长能帮忙看看是什么问题吗。。。*/
