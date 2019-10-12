#include "../arb_pre.h"
# include <stdio.h>

//char	*calc_two_pow(void)
//{
//	char cur[len + 1];
//	int i;
//
//	i = 0;
//	ft_memset(cur, (int)'0', len);
//	cur[len] = '\0';
//	while (i >= pow)
//	{
//		printf("%s\n", cur);
//		div(cur, 2);
//		i--;
//	}
//	return (cur);
//}


int	main(void)
{
	char s1[6];
	char s2[6];
	
	clear_str(s1, 5);
	clear_str(s2, 5);
	s1[0] = '0';
	s1[1] = '0';
	s1[2] = '0';
	s1[3] = '4';
	s1[4] = '5';
	
	s2[0] = '0';
	s2[1] = '0';
	s2[2] = '0';
	s2[3] = '1';
	s2[4] = '9';
	
//	printf("%s\n%s\n", s1,s2);
//	add(s1,s2);
//	printf("%s\n%s\n", s1,s2);
//	sub(s1,s2);
//	printf("%s\n%s\n", s1,s2);
	printf("%s\n%s\n", s1,s2);
	mult(s1,s2);
	printf("%s\n%s\n", s1,s2);
	
	return 0;
	
}