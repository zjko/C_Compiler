#include"Error.h"
#include"RFA.h"
#include"Tools.h"
#include<stdio.h>
#include"InputStream.h"
struct Analyzer{
	
	
	int analyzer(){
//		putchar(c);
	char c;
		while((c=InputStream.next())!=EOF){
//			putchar(c);
			if(c!=' '&&c!='\n'&&c!='\t')RFA.Model(c);
			
//			else putchar(c);
			
		}
	
		
	};
}Analyzer;
