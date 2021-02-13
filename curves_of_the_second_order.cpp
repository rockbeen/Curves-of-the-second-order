#include <iostream>
#include <cmath>
#include <string>
using namespace std;
enum curve{circle,ellipse,parabola};
class Curve{					//common abstract ancestor
protected:
	double x,y,t;
public:	

	virtual void calculating_coordinates()=0;
	virtual void calculation_of_the_tangent()=0;
	virtual void closed_line()=0;
	
	};
class Circle: public Curve {
private:
	double r,x0,y0;
public:
	Circle(double R,double x,double y)
	{
		r=R;
		x0=x;
		y0=y;
		cout<<"Circle created!"<<endl;
		cout<<"The equation:\n"<<"x = "<<r<<"cos(t) + "<<x0<<"\n"<<"y = "<<r<<"sin(t) + "<<y0<<endl;
		}
	void calculation_of_the_tangent()//method for calculating the tangent vector to a curve for a given parameter
	{
		double t;
		cout<<"Please enter the parameter: ";
		cin>>t;
		x=r*cos(t)+x0;
		y=r*sin(t)+y0;
		cout<<"The tangent: x*"<<x/pow(r,2)<<" + y*"<<y/pow(r,2)<<"= 1"<<endl;
		}
	void calculating_coordinates()//method for calculating the coordinates of a point on a curve by a given parameter
	{
		double t;
		cout<<"Please enter the parameter: ";
		cin>>t;
		x=r*cos(t)+x0;
		y=r*sin(t)+y0;
		cout<<"x= "<<x<<"\n"<<"y= "<<y<<endl;
		}
	void closed_line()//outputs information about whether a given curve is closed.
	{
		cout<<"The curve is closed"<<endl;
		}
	};
class Ellipse: public Curve {
private:
	double a,b;
public:
	Ellipse(double A,double B)
	{
		a=A;
		b=B;
		cout<<"Ellipse created!"<<endl;
		cout<<"The equation:\n"<<"x = "<<a<<"cos(t)\n"<<"y = "<<b<<"sin(t)"<<endl;
		}
	void calculation_of_the_tangent()//method for calculating the tangent vector to a curve for a given parameter
	{
		double t;
		cout<<"Please enter the parameter: ";
		cin>>t;
		x=a*cos(t);
		y=b*sin(t);
		cout<<"The tangent: x*"<<x/pow(a,2)<<" + y*"<<y/pow(b,2)<<"= 1"<<endl;
		}
	void calculating_coordinates()//method for calculating the coordinates of a point on a curve by a given parameter
	{
		double t;
		cout<<"Please enter the parameter: ";
		cin>>t;
		x=a*cos(t);
		y=b*sin(t);
		cout<<"x= "<<x<<"\n"<<"y= "<<y<<endl;
		}
	void closed_line()//outputs information about whether a given curve is closed.
	{
		cout<<"The curve is closed"<<endl;
		}
	}; 
class Parabola: public Curve {
private:
	double a,b,c;
public:
	Parabola(double A,double B,double C)
	{
		a=A;
		b=B;
		c=C;
		cout<<"Parabola created!"<<endl;
		cout<<"The equation:\n"<<"y= "<<a<<"*x^2 + "<<b<<"*x + "<<c<<endl;
		}
	void calculation_of_the_tangent()//method for calculating the tangent vector to a curve for a given parameter
	{
		double t;
		cout<<"Please enter the parameter: ";
		cin>>t;
		double k,d;
		x=t-b/(2*a);
		y=a*x*x-(b*b-4*a*c)/(4*a);
		k=2*a*x+b;
		d=c-a*x*x;
		cout<<"The tangent: y="<<k<<"*x + "<<d<<endl;
		
		}
	void calculating_coordinates()//method for calculating the coordinates of a point on a curve by a given parameter
	{
		double t;
		cout<<"Please enter the parameter: ";
		cin>>t;
		x=t-b/(2*a);
		y=a*x*x-(b*b-4*a*c)/(4*a);
		
		cout<<"x= "<<x<<"\n"<<"y= "<<y<<endl;
		}
		void closed_line()//outputs information about whether a given curve is closed.
	{
		cout<<"The curve is not closed"<<endl;
		}
	
	
	};

bool input_circle(double& x1,double& x2,double& x3,double& y1,double& y2,double& y3,double& r,double& a,double& b)//method for calculating the coefficients of a circle
{
			double A,B,C,D,E,F,G;	//solving a system with three unknowns
			A= x2 - x1;
			B= y2 - y1;
			C= x3 - x1;
			D= y3 - y1;
			E= A * (x1 + x2) + B * (y1 + y2);
			F= C * (x1 + x3) + D * (y1 + y3);
			G= 2 * (A * (y3 - y2) - B * (x3 - x2));
			if (G == 0) return 0;
			a= (D * E - B * F) / G;
			b= (A * F - C * E) / G;
			r=sqrt(pow(x1-a,2)+pow(y1-b,2));		
			return 1;
			
			
};
bool input_ellipse(double& x1,double& x2,double& x3,double& y1,double& y2,double& y3,double& a,double& b)//the method for calculating coefficients of the ellipse
{
			if (x1 == 0)  b=abs(y1);//if the points lie on the main axes
			else if (x2 == 0)  b=abs(y2);
			else if (x3 == 0)  b=abs(y3);
			else if (y1!=0&& y2!=0&& x1!=x2) b=sqrt((pow(x2,2)*pow(y1,2)-pow(y2,2)*pow(x1,2))/(pow(x2,2)-pow(x1,2)));//if not then we solve the system
			else if (y2!=0&& y3!=0&& x2!=x3) b=sqrt((pow(x3,2)*pow(y2,2)-pow(y3,2)*pow(x2,2))/(pow(x3,2)-pow(x2,2)));
			else if (y3!=0&& y1!=0&& x3!=x1) b=sqrt((pow(x1,2)*pow(y3,2)-pow(y1,2)*pow(x3,2))/(pow(x1,2)-pow(x3,2)));
			if (y1 == 0)  a=abs(x1);//if the points lie on the main axes
			else if (y2 == 0)  a=abs(x2);
			else if (y3 == 0)  a=abs(x3);	
			else if (b!=y1&& x1!=0) a=sqrt((pow(b,2)*pow(x1,2))/(pow(b,2)-pow(y1,2)));//if not then we solve the system
			else if (b!=y2&& x2!=0) a=sqrt((pow(b,2)*pow(x2,2))/(pow(b,2)-pow(y2,2)));
			else if (b!=y3&& x3!=0) a=sqrt((pow(b,2)*pow(x3,2))/(pow(b,2)-pow(y3,2)));
			if (a==0 || b==0) return 0;
			else return 1;
			
			
			
};
bool input_parabola(double& x1,double& x2,double& x3,double& y1,double& y2,double& y3,double& a,double& b,double& c)//the method for calculating coefficients of a parabola
{

			a=(y3-((x3*(y2-y1)+x2*y1-x1*y2)/(x2-x1)))/(x3*(x3-x1-x2)+x1*x2);//solving a system with three unknowns
			b=(y2-y1)/(x2-x1)-a*(x1+x2);
			c=(x2*y1-x1*y2)/(x2-x1)+a*x1*x2;
			return 1;
			
			
};
void method(Curve* ptr)//method for convenient use by other 3 methods
{
	bool cycle=true;
	int method;
	do
	{
		cout<<"What method do you want to use?(enter 1, 2, 3 or 4)"<<endl;
		cout<<"1)calculating the coordinates of a point\n"<<"2)the calculation of the tangent vector\n"<<"3)outputs information about whether a given curve is closed\n"<<"4)exit"<<endl;
		cin>>method;
		
			if (method==1)	ptr->calculating_coordinates();//calculating the coordinates of a point(1)
			else if (method==2)	ptr->calculation_of_the_tangent();//the calculation of the tangent vector(2)
			else if (method==3)	ptr->closed_line();//outputs information about whether a given curve is closed(3)
			else if (method==4) cycle=false;
			else cout<<"Incorrect input"<<endl;
	}
	while(cycle);
	
	};
int main()
{
	;
	bool cycle=true;
	double x1,x2,x3,y1,y2,y3,a,b,c,r;
	string trajectory;
	do
	{
		cout<<"What curve do you want to build?\n"<<"Write a 'circle', 'ellipse', or 'parabola' (to exit enter 'exit')"<<endl;
		cin>>trajectory;
		if(trajectory=="circle"||trajectory=="ellipse"||trajectory=="parabola")
		{
			cout<<"Please enter 3 dots:\n"<<"x1= ";
			cin>>x1;
			cout<<"y1= ";
			cin>>y1;
			cout<<"x2= ";
			cin>>x2;
			cout<<"y2= ";
			cin>>y2;
			cout<<"x3= ";
			cin>>x3;
			cout<<"y3= ";
			cin>>y3;
			if (!((y3-y1)*(x2-x1)==(x3-x1)*(y2-y1)))//if the points are not collinear
			{
				a=0;
				b=0;
				c=0;
				if(trajectory=="circle" && input_circle(x1,x2,x3,y1,y2,y3,r,a,b)) //changing a, b and r to create the circle class(a=x0,b=y0)
					{
						Circle n(r,a,b);
						method(&n);
						
						}
				else if(trajectory=="ellipse" && input_ellipse(x1,x2,x3,y1,y2,y3,a,b)) //changing a and b to create the ellipse class
					{
						Ellipse n(a,b);
						method(&n);
					}

				else if(trajectory=="parabola" && input_parabola(x1,x2,x3,y1,y2,y3,a,b,c))  //changing a, b and c to create the parabola class
					{
						Parabola n(a,b,c);
						method(&n);
					}
				else cout<<"Incorrect input"<<endl;
					
			}
			else cout<<"All 3 points are on the same line"<<endl;
		}
		else if (trajectory=="exit") cycle=false;
		else cout<<"Incorrect input"<<endl;
		}
	while(cycle);
   
    return 0;
}
