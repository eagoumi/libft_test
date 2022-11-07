/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:44:57 by eagoumi           #+#    #+#             */
/*   Updated: 2022/11/07 16:50:58 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_checkstart(char const *realstr, char const *sh, int count)
{
	int		i;
	size_t	j;
	size_t	len;

	i = 0;
	len = ft_strlen(sh);
	while (realstr[i])
	{
		j = 0;
		while (sh[j])
		{
			if (realstr[i] == sh[j])
			{
				count++;
				break ;
			}
			else
				j++;
			if (j == len)
				return (count);
		}
		i++;
	}
	return (count);
}

int	ft_checkend(char const *lasstr, char const *seh, int cont)
{
	int		i;
	size_t	j;
	int		lendx;

	i = ft_strlen(lasstr) - 1;
	lendx = ft_strlen(lasstr);
	while (i >= 0)
	{
		j = 0;
		while (seh[j])
		{
			if (lasstr[i] == seh[j])
			{
				cont++;
				break ;
			}
			else
				j++;
			if (j == ft_strlen(seh))
				return (lendx - cont);
		}
		i--;
	}
	return (lendx - cont);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	char	*temp;
	int		n;

	n = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	i = ft_checkstart(s1, set, 0);
	j = ft_checkend(s1, set, 0);
	temp = ft_substr(s1, i, (j - i));
	if (temp == NULL)
		return (NULL);
	str = ft_strdup(temp);
	if (str == NULL)
		return (NULL);
	free(temp);
	return (str);
}

// int	main(void)
// {
// 	char	*result1;
// 	char	*s1 = "   \t  \n\n \t\t  \n\n\nHe";

// 	result1 = ft_strtrim(NULL, "NULL");
// 	printf("string are : %s\n", result1);
// }