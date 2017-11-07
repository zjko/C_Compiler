#include"Error.h"
#include"RFA.h"
struct Analyzer{
	
	int readFile(char * path) {
		FILE * fp = NULL;
		fp = fopen(path,"r");
		if(fp == NULL)
//		error(ERR_FILE_READ_FAILED);
		
		while (feof(fp) == NULL)analyzer(fgetc(fp));
		fclose(fp);
	};
	
	int inputCode(char *str){
		while(*str){
			Analyzer(*str);
			str++;
		}
	};
	
	int analyzer(char c){
//		putchar(c);
		RFA.Model(classification(c)) ;
	};
	
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
			case ';':	return 6;	//	第六类 语句结束符 
			default:    ;
//			error(0);  puts("非法符号");
			/* WAR 暂未编号   */
		}
	}; 
	
}Analyzer;
