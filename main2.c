 #include <stdio.h>
// #include <unistd.h>
#include "ft_printf.h"

int	main(void)
{
	int		a;
	int		b;
	//char	c[5]= "hello";
	int c = 0;
	char *printf_;

	printf_ = " %u ";
	a = printf(printf_, c);//"%.*u", -1
	printf("\n");
	b = ft_printf(printf_, c);
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
