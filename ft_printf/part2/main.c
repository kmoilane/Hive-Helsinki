#include "../includes/ft_printf.h"

int	main(void)
{
	char	c;
	char	n;
	char	str[] = "yapadapadoo";

	c = 'T';
	n = '\n';

	ft_printf("\n--------------------TESTS FOR %%---------------------\n\n");
	printf("printf\t\t%%<- Just a percent sign : D\n");
	ft_printf("ft_printf\t%%<- Just a percent sign : D\n");
	printf("printf\t\t%-4%<- Just a percent sign : D\n");
	ft_printf("ft_printf\t%-4%<- Just a percent sign : D\n");
	printf("printf\t\t%03%<- Just a percent sign : D\n");
	ft_printf("ft_printf\t%03%<- Just a percent sign : D\n");
	printf("printf\t\t%%%%<- Just 2 percent signs :_D\n");
	ft_printf("ft_printf\t%%%%<- Just 2 percent signs :_D\n");
	
	ft_printf("\n--------------------TESTS FOR %%c--------------------\n\n");
	printf("printf\t\tO K\n");
	ft_printf("ft_printf\tO K\n");
	printf("printf\t\t%c\n", 'L');
	ft_printf("ft_printf\t%c\n",'L');
	printf("printf\t\ttab%ctab\n", '\t');
	ft_printf("ft_printf\ttab%ctab\n", '\t');
	printf("printf\t\tnew line:%03lc\n", n);
	ft_printf("ft_printf\tnew line:%03lc\n",n);
	printf("printf\t\t%##03c\n", 'k');
	ft_printf("ft_printf\t%##03c\n",'k');
	printf("printf\t\t3 spaces after this:%4c\n", '3');
	ft_printf("ft_printf\t3 spaces after this:%4c\n",'3');
	printf("printf\t\t%-9c8 spaces before this\n", '8');
	ft_printf("ft_printf\t%-9c8 spaces before this\n", '8');
	printf("printf\t\t%c%c%c%c%c%c%c%c\n", 'M','u','l','t','i','p','l','e');
	ft_printf("ft_printf\t%c%c%c%c%c%c%c%c\n",'M','u','l','t','i','p','l','e');
	printf("printf\t\t%c\n", c);
	ft_printf("ft_printf\t%c\n",c);

	ft_printf("\n--------------------TESTS FOR %%s--------------------\n\n");
	printf("printf\t\tJust a reagular text here!\n");
	ft_printf("ft_printf\tJust a reagular text here!\n");
	printf("printf\t\t5 spaces between here%13s\n", "and here");
	ft_printf("ft_printf\t5 spaces between here%13s\n", "and here");
	printf("printf\t\t%s - 7 = %.3s\n", "Illuminati", "Illuminati");
	ft_printf("ft_printf\t%s - 7 = %.3s\n", "Illuminati", "Illuminati");
	printf("printf\t\t%-28s8 spaces before this\n", "8 spaces after this:");
	ft_printf("ft_printf\t%-28s8 spaces before this\n", "8 spaces after this:");
	printf("printf\t\t%s\n", str);
	ft_printf("ft_printf\t%s\n", str);

	ft_printf("\n--------------------TESTS FOR %%p--------------------\n\n");
	printf("printf\t\t%p\n", str);
	ft_printf("ft_printf\t%p\n", str);
	printf("printf\t\t%020p\n", str);
	ft_printf("ft_printf\t%020p\n", str);
	printf("printf\t\t%-20p Should be extra spaces\n", str);
	ft_printf("ft_printf\t%-20p Should be extra spaces\n", str);
	printf("printf\t\t%0.5p\n", str);
	ft_printf("ft_printf\t%0.5p\n", str);
	printf("printf\t\t%.25p\n", str);
	ft_printf("ft_printf\t%.25p\n", str);
	printf("printf\t\t%028.25p\n", str);
	ft_printf("ft_printf\t%028.25p\n", str);

	return (0);
}
