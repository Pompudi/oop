#include <stdio.h>
#include <math.h>
using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int _x, int _y) : x(_x), y(_y) {};
	int getx() {return x;};
	int gety() {return y;};
	friend double distance(Point*);
};
double distance(Point* t){
	double d2=(t->x)*(t->x)+(t->y)*(t->y);
	return (sqrt(d2));
}

int main(int argc, char* argv[])
{
	double dis;
	double max=0.0;
	Point** p; 
	Point* t;	
	int x,y,kx,ky;
	int i=0;
	int j=0;
	if (argc<2)
		return (-1);
	p = new Point*[argc]; 
	while(++i<argc){
		sscanf(argv[i], "(%d%*c%d)",&x,&y);
		p[j]= new Point(x,y);
		j++;
	}
	p[j]=NULL;
	for (i=0;p[i] != NULL;i++)
	{
		t=p[i];
			dis=distance(t);
		if (dis>max)
		{
			max=dis;
			kx=t->getx();
			ky=t->gety();
		
	}
		printf("(%d;%d) %f\n",kx,ky,max);
	for(j=0;p[j]!=NULL;j++)
		delete p[j];
	delete []p;
	return 0;
}
}
