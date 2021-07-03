    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
  
    int main(int argc, char *argv[])
    {
      int count=0;
      float v,inter;
      unsigned int start_time =  clock();
	  unsigned int end_time;
      inter=atoi(argv[1]);
      v=atof(argv[2]); 
      do{
          end_time=clock()/1000;
		  printf("%u\n",end_time);
		  printf("%f\n",difftime(start_time,end_time));
		  if (difftime(start_time,end_time)<v)
          {
             count++;
             switch ((count-1)%4){
                  case 0: printf("|"); break;
                  case 1: printf("/"); break;
                  case 2: printf("-"); break;
                  case 3: printf("\\"); break;
                    }              
      }
      return 0;
    }while (end_time<inter);
}
