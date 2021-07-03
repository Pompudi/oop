#include <stdlib.h>
#include <iostream>
using namespace std;
class Alpha
{
private:
	unsigned bin[2]; 
public:
	Alpha () { bin[0]=(1<<26)-1;
			   bin[1]=(1<<26)-1;
}; 
	Alpha (char*);
	int operator, ( Alpha& ); 
	int count( unsigned ); 
	operator char*(); 
};


Alpha::Alpha(char* s )
{
	bin[0]=0;
	bin[1]=0;
	while(*s)
	{
		if ((*s)>='a' && (*s)<='z')		
		{
			bin[1] |=(1 << (*s-'a'));
		}
		if (*s>='A' && *s<='Z')
		{
			bin[0] |=(1<<(tolower(*s)-'a'));
		}
	s++;
	}
}

Alpha::operator char* (){
static char s[53];
	unsigned b1=bin[0];
	unsigned b2=bin[1];
	int i=0;
	int j=0,k=count(b1);
	while(b1>0 || b2>0 )
	{
		if (b1 & 1)
			s[j++] = 'A' + i;
		if (b2 & 1)
			s[k++]= 'a' + i;
		i++;
		b1 >>= 1;
		b2 >>= 1;
	}
	s[k] = 0;
	return (s);
}
int Alpha::operator , (Alpha& y)
{
return count( bin[1] & y.bin[1]); 
}

int Alpha::count(unsigned b) 
{
	int i=0; 
	while ( b != 0)
	{
		b = b & ( b - 1); 
		i++; 
	}
	return ( i ); 
}

int main (int argc,char* argv[])
{
	if (argc<2)
		return (-1);
	Alpha A(argv[1]); 
	Alpha B; 
	int d = (B,A);  
	cout  << ( char* ) A<<" количество строчных букв: "<<d<<endl;
	return (0);
}
