#include "arb_pre.h"

void	clear_str(char *n, int length)
{
	int	i;
	
	i = 0;
	while (i < length)
		n[i++] = '0';
	n[i] = '\0';
}

void	add_layer(char *n1, char* n2, int s)
{
	int	i;
	int	p;
	
	i = ft_strlen(n2) - 1; // len
	p = 0;
	while (i - s>= 0)
	{
		n1[i - s] += p / 10;
		p = n1[i - s] + n2[i] - '0' * 2;
		n1[i - s] = p % 10 + '0';
		i--;
	}	
}

void	mult(char *n1, char *n2)
{
	char	to_ret[ft_strlen(n1) + 1]; // len + 1
	char	res[ft_strlen(n1) + 1]; // len + 1
	int		p;
	int		i;
	int		j;
	
	clear_str(to_ret, ft_strlen(n1)); // len
	i = ft_strlen(n2) - 1;
	while (i >= 0)
	{
		clear_str(res, ft_strlen(n1)); // len
		j = ft_strlen(n1) - 1; // len
		p = 0;
		while (j >= 0)
		{
			p = (n2[i] - '0') * (n1[j] - '0') + p / 10;
			res[j] = p % 10 + '0';
			j--;
		}
		add_layer(to_ret, res, ft_strlen(n2) - 1 - i); // len - i
		i--;
	}
	i = 0;
	while (i < ft_strlen(n1)) // len
	{
		n1[i] = to_ret[i];
		i++;
	}
}

void	divi(char *n1, char *n2)
{
	
}