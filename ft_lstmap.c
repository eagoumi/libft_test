/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagoumi <eagoumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:07:31 by eagoumi           #+#    #+#             */
/*   Updated: 2022/11/05 21:05:32 by eagoumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

typedef struct s_params
{
	void	*new_content;
	t_list	*new_node;
	t_list	*new_lst;
	t_list	*last_node;
}	t_params;

void	*del_free(t_list **lst, void (*del)(void *))
{
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_params	params;

	params.new_lst = NULL;
	while (f != NULL && del != NULL && lst != NULL)
	{
		params.new_content = f(lst->content);
		if (!params.new_content)
			return (del_free(&params.new_lst, del));
		params.new_node = ft_lstnew(params.new_content);
		if (!params.new_node)
			return (del_free(&params.new_lst, del));
		if (params.new_lst == NULL)
		{
			params.new_lst = params.new_node;
			params.last_node = params.new_lst;
		}
		else
		{
			params.last_node->next = params.new_node;
			params.last_node = params.last_node->next;
		}
		lst = lst->next;
	}
	return (params.new_lst);
}

// void    *del(void *i)
// {
// 	printf("leet");
// }

// int main()
// {
//   t_list  *test;
//   test = ft_lstnew("leet");
//   test->next = ft_lstnew("1337");
//   test->next->next = ft_lstnew("coding");
//   test->next->next->next = ft_lstnew("school");
//   t_list *result = ft_lstmap(test, &ft_strdup, del);
//   while (result)
//   {
//     printf("%s <---> ", result->content);
//     result = result->next;
//   }
//   return 0;
// }