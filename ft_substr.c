/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagoumi <ayagoumi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:52:15 by eagoumi           #+#    #+#             */
/*   Updated: 2022/11/07 22:39:07 by ayagoumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s || len == 0)
		return (ft_strdup(""));
	j = ft_strlen(s);
	if (j <= start)
		return (ft_strdup(""));
	if (len > j)
		len = j;
	st = (char *)malloc((len + 1) * sizeof(char));
	if (st == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		st[i] = s[start + i];
		i++;
	}
	st[i] = '\0';
	return (st);
}

/*int	main(void)
{
	unsigned int r1;
	char *r = ft_substr("hola", 5, 2);
	r1 = substr("ABCDEFGH", 9, 9);
	printf("mine :|%s| \n", r);
	printf("sys : |%s| \n", r1);
	printf("mine :|%u| \n", r1);
}*/
