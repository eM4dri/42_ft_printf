#include "ft_printf.h"
#include <stdio.h>


void print_test(int size)
{
	printf("\tsize = %d\n", size);
}


int main(void)
{
	// print_test(printf("d\t%d", -2147483648));
	// print_test(ft_printf("d\t%d", -2147483648));

	// print_test(printf("i\t%i", -2147483648));
	// print_test(ft_printf("i\t%i", -2147483648));

	// print_test(printf("u\t%u", 4294967295));
	// print_test(ft_printf("u\t%u", 4294967295));

	// print_test(printf("x\t%x", 4294967295));
	// print_test(ft_printf("x\t%x", 4294967295));

	// print_test(printf("X\t%X", 4294967295));
	// print_test(ft_printf("X\t%X", 4294967295));
	int *p;
	int c;
	//c = ft_printf("\nHello World!00423\nHello World!\n\n");
	p = &c;
	c = ft_printf("\nHello World!\n%c\n%s\n%p\n%d\n%x\n%X\n%u\nJose->\t%u",'H', p, "Hello World!",-2147483648, -2147483648, 4294967295, 4294967295, 4294961111);
	printf("\nsizeof(c) = %d\n",c);

	// c = printf("\n%p",p);
	// printf("\nsizeof(c) = %d",c);
	// c = ft_printf("\n%p",p);
	// printf("\nsizeof(c) = %d",c);

	// printf("%n:%-15.10s:\n" , &c, "Hello, world");
	// printf("c = %d\n\n",c);
	// printf(":%-15.10s:\n%n" , "Hello, world", &c);
	// printf("AAA%04d",25);
	// printf("AAA%-04d",25);
	// printf("AAA%04d",5);
	// printf("\n%*s",5,"P");
	// printf("\n%*s",5,"Prendido a tu botella vacia esa que antes siempre tuvo gusto a nada",2,3,5,8,4);
	// printf("\n%*d",5 , 1);
	// printf("\n%*d",5 , 1234567890);
	// printf("\n%*d",10 , 1234567890);

	// printf("\n%.*s",5,"P");
	// printf("\n%.*s",5,"Prendido a tu botella vacia esa que antes siempre tuvo gusto a nada");
	// printf("\n%.*d",5 , 1);
	// printf("\n%.*d",5 , 1234567890);
	// printf("\n%.*d",10 , 1234567890);

	// printf("\n%*i",5 , 1);
	// printf("\n%*i",5 , 1234567890);
	// printf("\n%*i",10 , 1234567890);
	// printf("\n%.*i",5 , 1);
	// printf("\n%.*i",5 , 1234567890);
	// printf("\n%.*i",10 , 1234567890);

	// printf("\n%*X",5 , 15);
	// printf("\n%*X",5 , 1234567890);
	// printf("\n%*X",10 , 1234567890);
	// printf("\n%.*X",5 , 15);
	// printf("\n%.*X",5 , 1234567890);
	// printf("\n%.*X",10 , 1234567890);
	// printf("\n%*x",5 , 15);
	// printf("\n%*x",5 , 1234567890);
	// printf("\n%*x",10 , 1234567890);
	// printf("\n%.*x",5 , 15);
	// printf("\n%.*x",5 , 1234567890);
	// printf("\n%.*x",10 , 1234567890);
	// printf("\n%*c",5,'P');
	// printf("\n%.*c",5,'P');

	//printf("\n%.2s","ABCDEFG");
	//printf("\n%.2d",123456);

	//printf("\n%.10s","ABCDEFG");
	//printf("\n%.10d",123456);

	// printf("\n%.2s","ABCDEFG");
	// printf("\n%.2d",123456);

	// printf("\n%.010s","ABCDEFG");
	// printf("\n%.010d",123456);
	//printf("sdhbajkdfbha",1,2);

	//printf("%02.1%i",5);

	// printf("\n%20.2.20s","ABCDEF");
	// printf("\n%2.2.20d",12345);

	// printf("\n%2.20s","ABCDEF");
	// printf("\n%2.2d",12345);

	//printf("%-*sHELLO",10,"ABCDEFG");
	//printf("%-*10*sHELLO\n%-*sHELLO",5,5,"ABCDEFG",10,"ABCDEFG");
	//printf("%-10-5dHELLO",10,123456);
	return (0);
}

//c	s	p	di	u	xX
