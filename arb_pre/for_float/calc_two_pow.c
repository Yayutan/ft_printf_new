#include "../arb_pre.h"
# include <stdio.h>

void	calc_two_pow(void)
{
	char	cur[len + 1];
	int		i;
	int		j;

	i = 0;
    clear_str(cur, len);
	printf("const\tchar *g_pow_two[113] = {\n");
    cur[wh] = '1';
	while (i >= pow) // 80 - 4 - 2 = 74
	{
		j = 0;
		while (cur[j])
		{
			if (j % 73 == 0)
				printf("\t\"");
			printf("%c", cur[j]);
			if (j % 73 == 72)
				printf("\"\n");
			j++;
		}
		if (j % 73 != 72)
			printf("\"\n");
		if (i != pow)
			printf("\t,\n");
		divi(cur, "2");
		i--;
	}
	printf("\n};\n\n#endif\n");
}

// "012.......73"
// "7475......147"


int	main(void)
{
//	char s1[6];
//	char s2[6];
//	
//	clear_str(s1, 5);
//	clear_str(s2, 5);
//	s1[0] = '1';
//	s1[1] = '0';
//	s1[2] = '0';
//	s1[3] = '\0';
//	s1[4] = '0';
//	
//	s2[0] = '1';
//	s2[1] = '0';
//	s2[2] = '\0';
//	s2[3] = '0';
//	s2[4] = '\0';
//	
//	printf("%s\n%s\n", s1,s2);
//	add(s1,s2);
//	printf("%s\n%s\n", s1,s2);
//	sub(s1,s2);
//	printf("%s\n%s\n", s1,s2);
//	printf("%s\n%s\n", s1,s2);
//	mult(s1,s2);
//	printf("%s\n%s\n", s1,s2);
//	printf("%s\n%s\n", s1,s2);
//	divi(s1, s2);
//	printf("%s\n%s\n", s1,s2);
	calc_two_pow();
	return (0);
	
}