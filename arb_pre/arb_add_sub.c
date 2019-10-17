#include "arb_pre.h"

void	increment(char *n1, int index)
{
	n1[index] = ((n1[index] - '0' + 1) % 10) + '0';
	if (n1[index] == '0')
		increment(n1, index - 1);
}

void	add(char *n1, const char *n2)
{
	int	i;
	int	p;
	
	i = ft_strlen(n1) - 1;
	p = 0;
	while (i >= 0)
	{
		n1[i] += p / 10;
		p = n1[i] + n2[i] - '0' * 2;
		n1[i] = p % 10 + '0';
		i--;
	}
}

void	sub(char *n1, const char *n2)
{
	int	i;
	int	p;
	
	i = ft_strlen(n1) - 1;
	p = 10;
	while (i >= 0)
	{
		n1[i] -= (p < 10);
		p = n1[i] - n2[i] + 10;
		n1[i] = p % 10 + '0';
		i--;
	}
}

void	clear_str(char *n, int length)
{
	int	i;
	
	i = 0;
	while (i < length)
		n[i++] = '0';
	n[i] = '\0';
}