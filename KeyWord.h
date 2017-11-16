#ifndef __KEYWORD_H__
#define __KEYWORD_H__


struct KeyWord{
	const char *instructions[12] = {
	"include","define","error","if","else","elif","endif","ifdef","ifndef","undef","line","pragma"
	};
	
	const  char *datatype[12] = {
	"int","float","double","char","short","long","signed","void","struct","union","enum","const"
	};
	
	const char *control[12] = {
	"if","else","switch","do","while","for","case","goto","default","continue","break","return"
	};
	
	const char *other[6] = {
	"typede","sizeof","volatile","extern","auto","register"
	};
}KeyWord;

#endif
