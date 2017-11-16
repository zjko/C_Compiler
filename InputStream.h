#ifndef __INPUTSTREAM_H__
#define __INPUTSTREAM_H__
#include "Error.h"
struct InputStream{
	FILE * fp = NULL;
	
	int readFile(char * path) {
		
		fp = fopen(path,"r");
		if(fp == NULL)
	//	error(ERR_FILE_READ_FAILED);
		
		puts("文件读取成功");
	};
	
	int closeFile(){
		fclose(fp);
		puts("文件关闭成功");
	};
	
//	int inputCode(char *str){
//	
//	};
//	
	char next(){
		char c;
		if(fp==NULL)puts("尚未打开文件");
		return fgetc(fp);

	};
	
}InputStream;

#endif
