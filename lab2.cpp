#include <stdlib.h>
#include <stdio.h>
class Magic {    
  private:
    unsigned** tab; 
    int row;      
    int col;       
    int degree;     
  public:
    Magic(int);               
    ~Magic();                 
    void print();            
    void horse3();          
    int reflect(int);      
 }; 


Magic::Magic(int n) 
{   
	degree = n;               
	tab = new unsigned* [degree];              
	for(row=0; row < degree; row++)      
  		tab[row] = new unsigned [degree];           
	for(row=0; row < degree; row++)                  
  		for(col=0; col < degree; col++)                        
   			 tab[row][col] = 0;                      
}  


Magic::~Magic(){									
	for(row=0; row < degree; row++)                
		  delete [] tab[row];                   
	delete [] tab; 								
} 


void Magic::print() {                
	int degree2;   						
	int len = 0;   					
	degree2 = (degree * degree);
	while(degree2 > 0) {
  		degree2 /= 10;
 		len++;
	} 
	for(row=0; row < degree; row++) {		
  		for(col=0; col < degree; col++)							
    		printf("%0*d  ", len, tab[row][col]); 			
  	putchar('\n');
	} 
putchar('\n');
return;					
} 						

int Magic::reflect(int k) {				
if(k < 0) 							
  return reflect(k + degree); 							 
return(k);					
} 



void Magic::horse3() {
int i;             
int j; 							
int degree2 = (degree*degree); 							
int z = 1;					
row = (degree - 1); 							
col = (degree / 2); 							
tab[row][col] = z; 								
while(z < degree2) {							
  i = reflect(row - 2); 					
  j = reflect(col - 1); 						
  if(tab[i][j] > 0) { 							
    	i = reflect(row - 4);					
    	j = reflect(col); 							
  } 
  row = i;  col = j; 					
  ++z; 								
  tab[row][col] = z; 						
} 
return;											
} 

int main(int argc, char* argv[]) {					
	if(argc != 2)							 
 	 	return(puts("Usage: magic degree"));
	int n = atoi(argv[1]); 							
	if((n % 2) == 0) 						
 	{
 		puts("Введите нечетное число");
 		return(n);
	} 
	Magic mag(n); 			
	mag.horse3();		
	mag.print();		
	return(n);
} 
