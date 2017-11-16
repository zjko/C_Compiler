#ifndef __TOOLS_H__
#define __TOOLS_H__

#include<string.h>
struct Tools{

	int classification(char c) {
		if( c== '#')return 1;//第一类 指令类
		if( c>='A'&&c<='Z' || c>='a'&&c<='z'||c == '_') return 2;//第二类 字母类 
		if( c>='0'&&c<='9')return 3;	//第三类 数字类
		switch(c){	//使用switch可以通过编译器优化 提高运行速度 
			case '+':case '-':case '*':case '/':case '%':
			case '&':case '|':case '!':case '^':case '~':
			case '<':case '>':case '=':
			case '?':case ':':
			case ',':case '(':case ')':case '[':case ']':
			return 4;			//	第四类操作符 
			case '\'':case '\"':
			return 5;	// 第五类 字符 字符串 常量 标识符
			case ';':	
			return 6;	//	第六类 语句结束符 
			case '{':case '}':
			return 7; 
			default:    ;
//			error(0);  puts("非法符号");
			/* WAR 暂未编号   */
		}
	}; 
	
	int lookupStr(const char **str1,const char *str2){
		for(int i=0;str1[i];i++){
			if(strcmp(str1[i],str2)==0)return 1;
		}
		return 0;
	}
	
	
	}Tools; 
	
	#endif
