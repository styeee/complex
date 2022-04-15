#include <stdio.h>

class complex
{
	double real;
	double image;
public:
	complex(const double r,const double i=0)
		:real(r),image(i){}
	complex(const complex&a)
		:real(a.get_real()),image(a.get_image()){}

	const double get_real()const
	{return real;}

	const double get_image()const
	{return image;}

	const complex&operator+(const complex&a)const
	{
		return complex(real+a.get_real(),image+a.get_image());
	}

	const complex&operator*(const complex&a)const
	{
		//(ac-bd)+(ad+bc)
		return complex(real*a.get_real()-image*a.get_image(),
			real*a.get_image()+image*a.get_real());
	}

	const complex&operator+(const double a)const
	{
		return complex(real+a);
	}

	void out()const
	{printf("%f+%f*i\n",real,image);}
};

int main()
{
	complex w(3,5);
	complex z=complex(2,1)+2;
	z.out();

	z=z+w;
	z.out();

	(complex(1,1)*complex(1,1)).out();

	return 0;
}