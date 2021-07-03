#include <string.h>
#include <stdlib.h>

class Fraction{
	private:
		int num;
		int den;
	public:
		Fraction(char*);
		Fraction(int n=0;int m=1) : num(n),den(m){};	
		Fraction operator +(Fraction&);
		Fraction operator =();
		void reduce();
};

Fraction :: Fraction(char* s){
	char* p = strchr(s,'\');
	if (p != NULL){
		*p++ = '\0';
		den = atoi(p);
	}
	num = atoi(s);
}

 evklid(){
	r = 1;
	while (n != 0){
		r = m % n;
		m=n;
		n=r;
	}
	return m; 
}

void Fraction :: reduce(){
	int gcd; 
	gcd = evklid(abs(num), den); 
	num /= gcd; 
	den /= gcd; 
	return; 	
}	
//Fraction& Fraction :: operator= (Fraction &a)
   //     {
     //        num = a.num;
  //           den = a.den;
    ///         return *this;
       // }

Fraction Fraction :: operator+(Fraction d2){
	Fraction d3;
	d3.num = num * d2.den + d2.num * den;
	d3.dem = den * d2.den;
	d3.reduce();
	return d3;
}

int main (int argc,char* argv[]){
	if (argc<2){
		printf("Ошибка! Необходимо ввести 2 дроби в формате: чс/зн чс/зн \n ");
		return 0;
	Fraction dr1(argv[1]);
	Fraction dr2(argv[2]);
	Fraction res;
	dr1.reduce();
	dr2.reduce();
	res=dr1+dr2;
	printf("%d/%d \n",res.num,res.den)
}


