#include <stdio.h>
#include <locale.h>
#include "includes/ft_printf.h"

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

union u_double
{
    double  dbl;
    char    data[sizeof(double)];
};

union u_float
{
    float   flt;
    char    data[sizeof(float)];
};

static void dump_float(union u_float f)
{
    int exp;
    long mant;

    printf("32-bit float: sign: %d, ", (f.data[0] & 0x80) >> 7);
    exp = ((f.data[0] & 0x7F) << 1) | ((f.data[1] & 0x80) >> 7);
    printf("expt: %4d (unbiassed %5d), ", exp, exp - 127);
    mant = ((((f.data[1] & 0x7F) << 8) | (f.data[2] & 0xFF)) << 8) | (f.data[3] & 0xFF);
    ft_printf("mant: %b %16ld (0x%06lX)\n", mant, mant, mant);
}

static void dump_double(union u_double d)
{
    int exp;
    long long mant;

    printf("64-bit float: sign: %d, ", (d.data[0] & 0x80) >> 7);
    exp = ((d.data[0] & 0x7F) << 4) | ((d.data[1] & 0xF0) >> 4);
    printf("expt: %4d (unbiassed %5d), ", exp, exp - 1023);
    mant = ((((d.data[1] & 0x0F) << 8) | (d.data[2] & 0xFF)) << 8) | (d.data[3] & 0xFF);
    mant = (mant << 32) | ((((((d.data[4] & 0xFF) << 8) | (d.data[5] & 0xFF)) << 8) | (d.data[6] & 0xFF)) << 8) | (d.data[7] & 0xFF);
    ft_printf("mant: %b %16lld (0x%013llX)\n", mant, mant, mant);
}

static void print_value(double v)
{
    union u_double d;
    union u_float  f;

    f.flt = v;
    d.dbl = v;

    printf("SPARC: float/double of %g\n", v);
//    image_print(stdout, 0, f.data, sizeof(f.data));
//    image_print(stdout, 0, d.data, sizeof(d.data));
    dump_float(f);
    dump_double(d);
}

int	main()
{
	print_value(0.5);
//	print_value(0.25654);
//	print_value(-3.244456);
}