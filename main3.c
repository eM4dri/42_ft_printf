 #include <stdio.h>
// #include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
    int     resA;
    int     resB;   
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	char *printf_;

	printf_ = "%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d";
	resA = printf(printf_, i, j, k, l, m, c, e, d);//"%.*u", -1
	printf("\n");
	resB = ft_printf(printf_, i, j, k, l, m, c, e, d);
	printf("\nsizeof(printf) = %d",a);
	printf("\nsizeof(ft_printf) = %d",b);
	printf("\n");
	return (0);
}
//print(" %01d ", 10)
//("%.*s", 0, "hello")
//"%*s", 32, "abc"
//printf_ = "A%3dA";
//cspdiuxX
//-0.*
//printf_ = "A%-10.30xA";
//.*s -3 0
//https://github.com/gavinfielder/pft
//https://github.com/Tripouille/printfTester
//https://github.com/Mazoise/42TESTERS-PRINTF
