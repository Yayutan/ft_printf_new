#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"
//#include "includes/pow_of_two.h"
#include "includes/arb_pre.h"


//void test_binary()
//{
//	int my,yo;
//	// print binary with flags
//	my = ft_printf("mine |%8b|%.8b|%#-8B|%#08b|\n", 42,42,42,42);
//	yo =    printf("their|%8b|%.8b|%#-8B|%#08b|\n", 42,42,42,42);
//	printf("return:->%i<-\n", my);
//	printf("return:->%i<-\n", yo);
//	printf("%s\n\n", "oh right, printf dont have b =D");
//	fflush(stdout);
//}
//
//void test_apostrophe()
//{
//	int my,yo;
//	// apostrophe
//	my = ft_printf("mine |d:%8.3'd|u:%'8.3u|i:%8'.3i|p:%-'10p|x:%'x|o:%'010-o|s:%'s|\n", 424242,424242,424242,424242,424242,424242,"424242");
//	yo =    printf("their|d:%8.3'd|u:%'8.3u|i:%8'.3i|p:%-'10p|x:%'x|o:%'010-o|s:%'s|\n", 424242,424242,424242,424242,424242,424242,"424242");
//	printf("return:->%i<-\n", my);
//	printf("return:->%i<-\n\n", yo);
//	fflush(stdout);
//}
//
//void test_money()
//{
//	int my,yo;
//	// $
//	my = ft_printf("mine |%3$d|%d|%3$d|%2$d|%d|\n", 1,2,3,4,5);
//	yo =    printf("their|%3$d|%d|%3$d|%2$d|%d|\n", 1,2,3,4,5);
//	printf("return:->%i<-\n", my);
//	printf("return:->%i<-\n\n", yo);
//	fflush(stdout);
//
//	// $ eaten
//	my = ft_printf("mine |.12$|\n", 1,2,3,4,5,6,7,8,9,10,11,12,13);
//	yo =    printf("their|.12$|\n", 1,2,3,4,5,6,7,8,9,10,11,12,13);
//	printf("return:->%i<-\n", my);
//	printf("return:->%i<-\n\n", yo);
//	fflush(stdout);
//}
//
////void test_color()
////{
////	printf("%sTheir red\n", KRED);
////    printf("%sTheir green\n", KGRN);
////    printf("%sTheir yellow\n", KYEL);
////    printf("%sTheir blue\n", KBLU);
////    printf("%sTheir magenta\n", KMAG);
////    printf("%sTheir cyan\n", KCYN);
////    printf("%sTheir white\n", KWHT);
////    printf("%sTheir normal\n", KNRM);
////	printf("\n");
////
////	ft_printf("{red}Mine red\n");
////    ft_printf("{green}Mine green\n");
////    ft_printf("{yellow}Mine yellow\n");
////    ft_printf("{blue}Mine blue\n");
////    ft_printf("{magenta}Mine magenta\n");
////    ft_printf("{cyan}Mine cyan\n");
////    ft_printf("{white}Mine white\n");
////    ft_printf("{noc}Mine normal\n");
////	printf("\n");
////
////	ft_printf("{Invalid}\n");
////	ft_printf("Not complete { : {red\n");
////	ft_printf("Not complete } : red}\n");
////	ft_printf("Multiple layer : {{cyan}}\n");
////	ft_printf("Multiple layer incomplete : {{blue/}\n");
////	ft_printf("Multiple layer complicated : {{blue}}{cyan}}}}\n\n");
////	fflush(stdout);
////}
//
//void test_star()
//{
//	int my,yo;
//	my = ft_printf("mine |%.*d|%*d|%#*.*X|\n", 5,42,3,42,5,8,42);
//	yo =    printf("their|%.*d|%*d|%#*.*X|\n", 5,42,3,42,5,8,42);
//	printf("return:->%i<-\n", my);
//	printf("return:->%i<-\n\n", yo);
//	fflush(stdout);
//}

void test_fail()
{
}

//int main(int argc, char** argv)
//{
//	/**
//	 *	New features include:
//	 *	1) %b to print binary
//	 *	2) ' to print apostrophe in duiop
//	 *	3) $ for indexing arguments
//	 *	4) Color
//	 *	5) star
//	 *	6) fd
//
//	 */
//
//	//setlocale(LC_ALL, "");
//	//wchar_t * str  = L"😀😃";
//	
////	printf("{%f}\n", 1444565444646.6465424242242);
////	ft_printf("{%f}\n", 1444565444646.6465424242242);
//	
////	printf("{%f}\n", 0.14445654446466465424242242);
////	ft_printf("{%f}\n", 0.14445654446466465424242242);
////	ft_printf("{%f}\n", 1.4445654446466465424242242);
////	ft_printf("{%f}\n", 14.445654446466465424242242);
////	ft_printf("{%f}\n", 144.45654446466465424242242);
////	ft_printf("{%f}\n", 1444.5654446466465424242242);
////	ft_printf("{%f}\n", 14445.654446466465424242242);
////	ft_printf("{%f}\n", 144456.54446466465424242242);
////	ft_printf("{%f}\n", 1444565.4446466465424242242);
////	ft_printf("{%f}\n", 14445654.446466465424242242);
////	ft_printf("{%f}\n", 144456544.46466465424242242);
////	ft_printf("{%f}\n", 1444565444.6466465424242242);
////	ft_printf("{%f}\n", 14445654446.466465424242242);
////	ft_printf("{%f}\n", 144456544464.66465424242242);
//	
//	double d = 3.4222;
//	
//	long long int temp = d;
//	
//	char sign = (d >> 63) & 1;
//	
//	
//	
//	
//	
//	
//	long long int mask = 0xffffffff;
//	
//	int a = (int)((temp >> 63) & 1);
////	test_binary();
////	test_apostrophe();
////	test_money();
//	//test_color();
////	test_star();
//	//test_fail();
//	return 0;
//}

//#include <stdio.h>

//union u_ldouble
//{
//    long double  ldbl;
//    char    data[sizeof(double)];
//};

//union u_float
//{
//    float   flt;
//    char    data[sizeof(float)];
//};

//int		get_exp(union u_double u_d)
//{
//	int		exp;
//	int		i;
//
//	exp = 0;
//	i = 0;
//	while (i <= 3)
//	{
//		exp += (((u_d.data[6] >> (i + 4)) & 1) << i);
//		i++;
//	}
//	while (i <= 10)
//	{
//		exp += (((u_d.data[7] >> (i - 4)) & 1) << i);
//		i++;
//	}	
//	return (exp - 1023);
//}
//
//void	get_mantissa(union u_double u_d, char *m)
//{
//	int	i;
//	int	sh;
//	int	p;
//
//	add(m, g_pow_two[0]);
//	p = 1;
//	i = 6;
//	sh = 3;
//	while (p <= 52)
//	{
//		while (sh >= 0)
//		{
//			if ((u_d.data[i] >> sh) & 1)
//				add(m, g_pow_two[p]);
//			p++;
//			sh--;
//		}
//		i--;
//		sh = 7;
//	}
//}
//
//char	*udtoa(double d)
//{
//	union u_double	u_d;
//	int				exp;
//	char			man[len + 1];
//	
//
//	u_d.dbl = d;
//	exp =  get_exp(u_d); // special case for 00000 and fffff ?
//	clear_str(man, len);
//	get_mantissa(u_d, man);
//	return "";
//}

# include <math.h>
# include<float.h>

int	main()
{
//	printf("e 1e300: %e\n", 1e300);
//	ft_printf("My e 1e300: %e\n", 1e300);
//	
//	printf("e 1e201: %e\n", 1e201);
//	ft_printf("My e 1e201: %e\n", 1e201);
//	
//	printf("e 1e200: %e\n", 1e200);
//	ft_printf("My e 1e200: %e\n", 1e200);
//	
//	printf("e 1e199: %e\n", 1e199);
//	ft_printf("My e 1e199: %e\n", 1e199);
//	
//	printf("e 1e100: %e\n", 1e100);
//	ft_printf("My e 1e100: %e\n", 1e100);
//	
//	printf("e 1e10: %e\n", 1e10);
//	ft_printf("My e 1e10: %e\n", 1e10);
//	
//	printf("e 1e1: %e\n", 1e1);
//	ft_printf("My e 1e1: %e\n", 1e1);
//	
//	printf("e 1e-50: %e\n", 1e-50);
//	ft_printf("My e 1e-50: %e\n", 1e-50);
//	
//	printf("e 1e-100: %e\n", 1e-100);
//	ft_printf("My e 1e-100: %e\n", 1e-100);
//	
//	printf("e 100: %e\n", 100.0);
//	ft_printf("My e 100: %e\n", 100.0);
//	
//	printf("e 1023: %e\n", 1023.0);
//	ft_printf("My e 1023: %e\n", 1023.0);
//	
//	printf("e 0.0000302: %e\n", 0.0000302);
//	ft_printf("My e 0.0000302: %e\n", 0.0000302);
	
//	printf("f_1e200: %f\n", 1e200);
//	ft_printf("My f_1e200: %f\n", 1e200);
//    printf("f_1e200: %.30f\n", 1e200);
//	ft_printf("My f_1e200: %.30f\n", 1e200);

//	ft_printf("%e\n", 128.0);
//	ft_printf("%e\n", 4.0);
//	ft_printf("%e\n", 2.0);
//	ft_printf("%e\n", 1.0);
	printf("%+f\n", 0.0/0.0);
//	ft_printf("%+f\n", 0.0/0.0);
//	ft_printf("%e\n", 0.2);
//	ft_printf("%e\n", 0.02);
//	printf("%e\n", 1e200);
//	printf("%e\n", 128.0);
//	printf("%e\n", 4.0);
//	printf("%e\n", 2.0);
//	printf("%e\n", 1.0);
//	printf("%e\n", 0.0);
//	printf("%e\n", 0.2);
//	printf("%e\n", 0.02);
//	printf("%e\n", 0.002);
//	printf("%e\n", 2e-11);
//	printf("%e\n", 2e-100);
//	printf("%.e\n", 20.0);
//	printf("%#.e\n", 20.0);
//	printf("%e\n", 20.3433);
//	printf("%.5e\n", 20.3433);
//	printf("%.e\n", 20.3433);
//	printf("%LLf\n", (long double)42.5);
//	ft_printf("%LLf\n", (long double)42.5);
//    printf("%.399Lf\n", (long double)DBL_MIN);
//    ft_printf("%.399Lf\n", (long double)DBL_MIN);
//    printf("%Lf\n", LDBL_MIN);
//    ft_printf("%Lf\n", LDBL_MIN);
//    printf("%.5000Lf\n", LDBL_MIN);
//    ft_printf("%.5000Lf\n", LDBL_MIN);
//    printf("%.0Lf\n", -LDBL_MIN);
//    ft_printf("%.0Lf\n", -LDBL_MIN);
//    printf("%.3Lf\n", -LDBL_MIN);
//    ft_printf("%.3Lf\n", -LDBL_MIN);
//    printf("%Lf\n", -LDBL_MIN);
//    ft_printf("%Lf\n", -LDBL_MIN);
//    printf("%.5000Lf\n", -LDBL_MIN);
//    ft_printf("%.5000Lf\n", -LDBL_MIN);
}