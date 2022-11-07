/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 04:04:51 by eagoumi           #+#    #+#             */
/*   Updated: 2022/11/07 22:06:44 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_count(char const *string, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i])
	{
		while (string[i] == c && string[i])
		{
			i++;
		}
		if (string[i])
		{
			count++;
		}
		while (string[i] && string[i] != c)
		{
			i++;
		}
	}
	return (count);
}

char	**free_str(char **string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		free(string[i]);
		i++;
	}
	free(string);
	return (NULL);
}

char	**check_if_empty_and_allocate(char const *s, char c)
{
	char	**one_case;

	if (!s)
		return (NULL);
	if (!*s)
	{
		one_case = (char **)malloc(sizeof(char *));
		if (one_case)
			one_case[0] = NULL;
		return (one_case);
	}
	else
		return ((char **)malloc((ft_count(s, c) + 1) * sizeof(char *)));
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		k;
	int		y;
	char	**big;

	i = 0;
	y = 0;
	big = check_if_empty_and_allocate(s, c);
	while (big && s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		k = 0;
		while (s[i + k] && s[i + k] != c)
			k++;
		if (k != 0)
			big[y++] = ft_substr(s, i, k);
		if (y > 0 && big[y - 1] == NULL)
			return (free_str(big));
		i = k + i;
		big[y] = NULL;
	}
	return (big);
}

/*int main(void)
{
	char **sp, **tab, *splitme, **sd;
	int i;

	sp = ft_split("Tripouille ", ' ');
	i = 0;
	while (sp[i])
	{
		printf(" loup |sp[%d]| =%s-l\n", i, sp[i]);
		i++;
	}
	printf("strcmp = %d\n", strcmp(sp[0], "Tripouille"));
	splitme = strdup("Tripouille ");
	tab = ft_split(splitme, ' ');
	printf("sp[|0|] =%s-l\n", sp[0]);
	printf("splitme =%s-l\n", splitme);
	printf("tab[|0|] =%s-l\n", tab[0]);
	printf("strcmp = %d\n", strcmp(tab[0], "Tripouille"));
	sd = "ssssssss";
	i = 0;
	printf(" loup |sp[%d]| =%s-l\n", i, sp[i]);
}*/
