//习题4-2 atof 的 扩充 by dominicMing 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//新建函数atofplus来扩充功能 
double atofplus(char input[50] ){  
	double num;                   //用num作为容器收纳结果   
	int i;
	for(i=0;i<strlen(input);i++) {     //遍历input字符数组 
		if((*(input+i)=='e')||(*(input+i)=='E')){    //通过指向数组的指针，找到字符e或者E来区分输入的数组 
			sscanf(input,"%d",&num);                 //sscanf函数来输出科学计数法数字（c语言本身支持科学计数法 
				return num;
		}else
		num=atof(input);                             //一般情况调用atof函数 
			return num;
	}

} 

int main(void){
    double atofplus(char* );      //声明函数atofplus的使用，输入的是input数组的指针 
    double result; 
    char input[50];
    printf("please input your number:\n"); 
    gets(input);
	printf("%g",atofplus(input));
}
/*总结：写的时候一直因为没有搞对输出形式，
*所以一直输出错了的我，改了好久的程序，真是好蠢，
*这次使用了学过的指针还是挺高兴的，
*希望下一个程序我也有时间来写这些吧*/ 
