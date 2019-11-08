#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h" 
# include <math.h>
# include<float.h>
# include <limits.h>
# include <stdarg.h>
#include <time.h>

void test_binary()
{
	int my,yo;
	// print binary with flags
	my = ft_printf("mine |%8b|%.8b|%#-8B|%#08b|\n", 42,42,42,42);
	yo =    printf("their|%8b|%.8b|%#-8B|%#08b|\n", 42,42,42,42);
	printf("return:->%i<-\n", my);
	printf("return:->%i<-\n", yo);
	printf("%s\n\n", "oh right, printf dont have b =D");
	fflush(stdout);
}

void test_apostrophe()
{
	int my,yo;
	// apostrophe
	my = ft_printf("mine |d:%8.3'd|u:%'8.3u|i:%8'.3i|p:%-'10p|x:%'x|o:%'010-o|s:%'s|\n", 424242,424242,424242,424242,424242,424242,"424242");
	yo =    printf("their|d:%8.3'd|u:%'8.3u|i:%8'.3i|p:%-'10p|x:%'x|o:%'010-o|s:%'s|\n", 424242,424242,424242,424242,424242,424242,"424242");
	printf("return:->%i<-\n", my);
	printf("return:->%i<-\n\n", yo);
	fflush(stdout);
}

void test_money()
{
	int my,yo;
	// $
	my = ft_printf("mine |%3$d|%d|%3$d|%2$d|%d|\n", 1,2,3,4,5);
	yo =    printf("their|%3$d|%d|%3$d|%2$d|%d|\n", 1,2,3,4,5);
	printf("return:->%i<-\n", my);
	printf("return:->%i<-\n\n", yo);
	fflush(stdout);

	// $ eaten
	my = ft_printf("mine |.12$|\n", 1,2,3,4,5,6,7,8,9,10,11,12,13);
	yo =    printf("their|.12$|\n", 1,2,3,4,5,6,7,8,9,10,11,12,13);
	printf("return:->%i<-\n", my);
	printf("return:->%i<-\n\n", yo);
	fflush(stdout);
}

void test_color()
{
//	printf("%sTheir red\n", KRED);
//    printf("%sTheir green\n", KGRN);
//    printf("%sTheir yellow\n", KYEL);
//    printf("%sTheir blue\n", KBLU);
//    printf("%sTheir magenta\n", KMAG);
//    printf("%sTheir cyan\n", KCYN);
//    printf("%sTheir white\n", KWHT);
//    printf("%sTheir normal\n", KNRM);
//	printf("\n");

	ft_printf("{red}Mine red\n");
    ft_printf("{green}Mine green\n");
    ft_printf("{yellow}Mine yellow\n");
    ft_printf("{blue}Mine blue\n");
    ft_printf("{magenta}Mine magenta\n");
    ft_printf("{cyan}Mine cyan\n");
    ft_printf("{white}Mine white\n");
    ft_printf("{noc}Mine normal\n");
	printf("\n");

	ft_printf("{Invalid}\n");
	ft_printf("Not complete { : {red\n");
	ft_printf("Not complete } : red}\n");
	ft_printf("Multiple layer : {{cyan}}\n");
	ft_printf("Multiple layer incomplete : {{blue/}\n");
	ft_printf("Multiple layer complicated : {{blue}}{cyan}}}}\n\n");
	fflush(stdout);
}

void test_star()
{
	int my,yo;
	my = ft_printf("mine |%.*d|%*d|%#*.*X|\n", 5,42,3,42,5,8,42);
	yo =    printf("their|%.*d|%*d|%#*.*X|\n", 5,42,3,42,5,8,42);
	printf("return:->%i<-\n", my);
	printf("return:->%i<-\n\n", yo);
	fflush(stdout);
}


void	pft_failed()
{
//	Test 1989 (f_L_limits_dblmin_prec0) : FAILED.
//    First line of code: {return test("%.0Lf", LDBL_MIN);}
//    Timed out
//
//Test 1990 (f_L_limits_dblmin_prec3) : FAILED.
//    First line of code: {return test("%.3Lf", LDBL_MIN);}
//    Timed out
//
//Test 1991 (f_L_limits_dblmin_precd) : FAILED.
//    First line of code: {return test("%Lf", LDBL_MIN);}
//    Timed out
//
//Test 1992 (f_L_limits_dblmin_prec8) : FAILED.
//    First line of code: {return test("%.8Lf", LDBL_MIN);}
//    Timed out
//
//Test 1996 (f_L_limits_ndblmin_prec0) : FAILED.
//    First line of code: {return test("%.0Lf", -LDBL_MIN);}
//    Timed out
//
//Test 1997 (f_L_limits_ndblmin_prec3) : FAILED.
//    First line of code: {return test("%.3Lf", -LDBL_MIN);}
//    Timed out
//
//Test 1998 (f_L_limits_ndblmin_precd) : FAILED.
//    First line of code: {return test("%Lf", -LDBL_MIN);}
//    Timed out
//
//Test 1999 (f_L_limits_ndblmin_prec8) : FAILED.
//    First line of code: {return test("%.8Lf", -LDBL_MIN);}
//    Timed out
//
//Test 2340 (nocrash_nullarg_22) : FAILED.
//    (nocrash test: automatically passes provided no unexpected failure)
//    First line of code: {return test("%f", NULL); }
//    SEGFAULT
//
//Test 2485 (nocrash_mandatory_f_size_LL) : FAILED.
//    (nocrash test: automatically passes provided no unexpected failure)
//    First line of code: {return test("%LLf", 42.5);}
//    Timed out
//
//Test 2486 (nocrash_mandatory_f_size_Ll) : FAILED.
//    (nocrash test: automatically passes provided no unexpected failure)
//    First line of code: {return test("%Llf", 42.5);}
//    Timed out
//
//Test 2487 (nocrash_mandatory_f_size_lL) : FAILED.
//    (nocrash test: automatically passes provided no unexpected failure)
//    First line of code: {return test("%lLf", 42.5);}
//    Timed out
}

void	test_time()
{
	time_t now;
	struct tm *ts;
	now = time(NULL);
	ts = localtime(&now);
	ft_printf("%k\n", ts);
	
	char       buf[80];
	strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", ts);
    puts(buf);
}


int	main()
{
	ft_printf("%f\n", 42.00000);
}
