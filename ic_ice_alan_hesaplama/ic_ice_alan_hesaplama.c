#include <stdio.h>
#include <math.h>
#define PI 3.14

double circle_area(double radius)
{
	double area;
	area=PI*pow(radius,2);				/*Çemberin alan formülü*/
	return area;
}
double calc_area_of_square(int side)
{
	double area;
	area=pow(side,2);				/*Karenin alani*/
	return area;
}
double calc_hypotenuse(int side1, int side2)
{
	double side3;
	side3=sqrt(pow(side1,2)+pow(side2,2));		/*Hipotenüsü (köşegeni) side3 değişkeni olarak tanımladım ve üçgende pisagor teoremi kullanarak hesapladım*/
	return side3;
}
double calc_radius_of_smallest_circle(int side1,int side2)
{
	double radius;
	radius=calc_hypotenuse(side1,side2)/2.0;	/*Dikdörtgeni saran en küçük çemberin çapı, köşegenin yarısı oluyor*/
	return radius;
}
double calc_radius_of_largest_circle(int side1,int side2)
{
	double radius;
	if(side2>side1)					/*Hangi kenarın büyük olduğu belli olmadığı için if ile karışıklığı önledim.*/
	{
		radius=side1/2.0;
	}
	else
	{
		radius=side2/2.0;
	}
	return radius;
}
double calc_area_of_smallest_circle(int side1,int side2)
{
	double radius;					/*Çemberi yarıçapını bularak alanını hesapladım.*/
	double area;
	radius=calc_radius_of_smallest_circle(side1,side2);
	area=circle_area(radius);
	return area;
}
double calc_area_of_largest_circle(int side1,int side2)
{
	double radius;					/*Üstteki olayın aynısı sadece yarıçapı değiştirdim.*/
	double area;
	radius=calc_radius_of_largest_circle(side1,side2);
	area=circle_area(radius);
	return area;
}
double calc_area_of_smallest_square(int side1,int side2)
{
	double area;					/*Hangi kenarın büyük olduğu belli olmadığı için karışıklığı önlemek için if kullandım*/
	if(side2>side1)
	{
		area=calc_area_of_square(side2);
	}
	else
	{
		area=calc_area_of_square(side1);
	}
	return area;
}
double calc_area_of_largest_square(int side1,int side2)
{
	double area;					/*Üstteki olayın aynısı sadece kenarlar farklı*/
	if(side2>side1)
	{
		area=calc_area_of_square(side1);
	}
	else
	{
		area=calc_area_of_square(side2);
	}
	return area;
}
void display_results(
	double largest_circle,				/*Değerleri printf komutuyla yazdırdım.*/
	double largest_square,
	double smallest_circle,
	double smallest_square
)
{
	printf("The area of the largest circle that fits inside a rectangle:%.2lf\n",largest_circle);
	printf("The area of the largest square that fits inside a rectangle:%.2lf\n",largest_square);
	printf("The area of the smallest circle that surrounds the same rectangle:%.2lf\n",smallest_circle);
	printf("The area of the smallest square that surrounds the same rectangle:%.2lf\n",smallest_square);
}
int main(void)
{
	int side1;
	int side2;
	double smallest_circle;
	double largest_circle;
	double smallest_square;
	double largest_square;
	
	printf("Enter first side for rectangle:");	/*Kenarları kullanıcıdan istedim*/
	scanf("%d",&side1);
	printf("Enter second side for rectangle:");
	scanf("%d",&side2);
	
	smallest_circle=calc_area_of_smallest_circle(side1,side2);
	largest_circle=calc_area_of_largest_circle(side1,side2);
	smallest_square=calc_area_of_smallest_square(side1,side2);
	largest_square=calc_area_of_largest_square(side1,side2);
	
	display_results(largest_circle,largest_square,smallest_circle,smallest_square);
	return 0;
}
	
	
	
	
	
	
	
	
