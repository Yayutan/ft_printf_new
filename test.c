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

int main(int argc, char** argv)
{
	/**
	 *	New features include:
	 *	1) %b to print binary
	 *	2) ' to print apostrophe in duiop
	 *	3) $ for indexing arguments
	 *	4) Color
	 *	5) star
	 *	6) fd

	 */

	//setlocale(LC_ALL, "");
	//wchar_t * str  = L"😀😃";
//	printf("X: %X\n", 42);
//	ft_printf("X: %X\n", 42);
	char c = NULL;
//	printf("#8x: %#8x\n", 42);
//	ft_printf("#8x: %#8x\n", 42);
	
	//	test_binary();
//	test_apostrophe();
//	test_money();
	//test_color();
//	test_star();
	//test_fail();
	return 0;
}
