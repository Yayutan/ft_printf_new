#include "arb_pre.h"

int		cmp_size(char *n1, char *n2, int leng)
{
	int		i;
	int		j;

	i = 0;
	while (n1[i] && n1[i] == '0' && i < leng - (int)ft_strlen(n2))
		i++;
	if (leng - i > (int)ft_strlen(n2))
		return (1);
	else
	{
		j = 0;
		while (j < (int)ft_strlen(n2))
		{
			if (n1[i] > n2[j])
				return (1);
			else if (n1[i] < n2[j])
				return (-1);
			i++;
			j++;
		}
		return (0);	
	}
}

void	add_layer(char *n1, char* n2, int s)
{
	int	i;
	int	p;
	
	i = ft_strlen(n2) - 1;
	p = 0;
	while (i - s >= 0)
	{
		n1[i - s] += p / 10;
		p = n1[i - s] + n2[i] - '0' * 2;
		n1[i - s] = p % 10 + '0';
		i--;
	}	
}

void	mult(char *n1, char *n2)
{
	char	to_ret[LEN + 1];
	char	res[9][LEN + 1];
	int		p;
	int		i;
	int		j;

	
	clear_str(to_ret, LEN);
	i = 0;
	while (i < 9)
		res[i++][0] = '\0';		
	i = ft_strlen(n2) - 1;
	while (i >= 0)
	{
		if (n2[i] == '0')
		{
			i--;
			continue;
		}
		if (res[n2[i] - '0' - 1][0] == '\0')
		{
			clear_str(res[n2[i] - '0' - 1], LEN);
			j = LEN - 1;
			p = 0;
			while (j >= 0)
			{
				p = (n2[i] - '0') * (n1[j] - '0') + p / 10;
				res[n2[i] - '0' - 1][j] = p % 10 + '0';
				j--;
			}	
		}
		add_layer(to_ret, res[n2[i] - '0' - 1], ft_strlen(n2) - 1 - i);
		i--;
	}
	i = -1;
	while (++i < LEN)
		n1[i] = to_ret[i];
}

int		basic_divi(char *n1, char *n2, int leng)
{
	int		to_ret;
	int		i;
	int		j;

	to_ret = 0;
	while (cmp_size(n1 ,n2, leng) >= 0)
	{
		i = leng - 1;
		j = ft_strlen(n2) - 1;
		while (j >= 0 && i >= 0)
		{
			if (n1[i] >= n2[j])
				n1[i] = '0' + (n1[i] - n2[j]);
			else
			{
				n1[i] = '0' + (n1[i] - n2[j]) + 10;
				n1[i - 1]--;
			}				
			i--;
			j--;
		}
		to_ret++;
	}
	return (to_ret);
}

void	divi(char *n1, const char *n2)
{
	char	cp[LEN + 1];
	int		leng;
	
	ft_strcpy(cp, n1);
	clear_str(n1, LEN);
	leng = ft_strlen(n2);
	while (leng <= LEN)
	{
		n1[leng - 1] = basic_divi(cp, (char*)n2, leng) + '0'; 
		leng++;
	}
	
	
}