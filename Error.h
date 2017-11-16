#include<stdio.h>

#ifndef __ERROR_H__
#define __ERROR_H__

#define ERR_FILE_READ_FAILED  0x01000001
#define ERR_LLLEGAL_CHAR			0x01000002
#define ERR_STR_FAIL					0x01000003
/*
错误码第一位保留
第二位为1代表 Analyzer的问题  2代表……
*/

////////
struct Error {
	int No(const int err){
		
		switch(err){
			case 0										:	return 0;
			
			case ERR_FILE_READ_FAILED :	puts("文件读取失败")	;
																	return 0;
			case ERR_LLLEGAL_CHAR			: puts("词法分析器出错，检测到非法字符") ;
																	return 0;
			case ERR_STR_FAIL					:	puts("非法字符");														
																																
		}
	
	};
	
}Error;

#endif
