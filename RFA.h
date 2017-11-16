#ifndef __RFA_H__
#define __RFA_H__

#include "Keyword.h"
#include "Error.h"
#include "Tools.h"
#include "InputStream.h"

#define BUFFERSIZE	512
struct RFA{
	char Buffer[BUFFERSIZE];		//解析缓存 
	int Model (char first){
		char c;
		int i;
		clean();
		switch(Tools.classification(first)){
			case 1://第一类 命令类
				for(i=0;(c=InputStream.next())!=EOF&&1<BUFFERSIZE;i++){
						if(Tools.classification(c)!=2&&Tools.classification(c)!=3)break;
						Buffer[i]=c;
						//只接受字符和数字 
					}
					if(Tools.lookupStr(KeyWord.instructions,Buffer)){
						printf("关键字：%s 代号1\n",Buffer);
						clean();	
					}else {
						printf("%s",Buffer) ;
						Error.No(ERR_STR_FAIL);
					} 
					
					return 1;
					
			
			case 2://第二类 字母类
			i = 0;
			Buffer[i++]=first;
			while((c=InputStream.next())!=EOF&&i<BUFFERSIZE){
						if(Tools.classification(c)!=2&&Tools.classification(c)!=3)break;
						Buffer[i++]=c;
						//只接受字符和数字 
					}
					if(Tools.lookupStr(KeyWord.datatype,Buffer)){
						printf("关键字：%s 代号2\n",Buffer);
						clean();
					}else{
						printf("标识符：%s 代号3\n",Buffer);
						
					}
					return 1;
			
			case 3://第三类 数字类 
			i = 0;
			Buffer[i++]=first;
			while((c=InputStream.next())!=EOF&&i<BUFFERSIZE){
						if(Tools.classification(c)!=2&&Tools.classification(c)!=3)break;
						Buffer[i++]=c;
						//只接受字符和数字 
			}
//			if(checkNum(Buffer))			 没写
			 if(Buffer[0]=='0')
			 		if(Buffer[1]=='x'||Buffer[1]=='X')printf("数字常量 十六进制：%s\n",Buffer) ;
					else printf("数字常量 八进制：%s\n",Buffer);
				else printf("数字常量 十进制：%s\n",Buffer);
				clean();
				return 1;
			
			case 4://第四类 操作符 
				printf("运算符：%c \n",first) ;
				clean();
				return 1;
			case 5://第五类 字符（串）常量 
			
				
				i=0;
				while((c=InputStream.next())!=EOF&&i<BUFFERSIZE){
					if(c=='\"')break;
					Buffer[i++]=c;
				}
				printf("字符串常量：%s\n",Buffer);
				
				return 1;
			
			case 6://第六类 ；分号结束符 
			
			clean();
			return 1;
			
			
			case 7:
//				printf("界符 ：%c\n",first);
//				clean();
				return 1;
			default : 
			printf("%c 无法识别") ;
			Error.No(ERR_LLLEGAL_CHAR) ;
			
			
			; 
		}
	};
	
	
	
	int clean(){
		for(int i=0;Buffer[i];i++)Buffer[i]=0;
	}
	

}RFA;



#endif
