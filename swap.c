/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:25:54 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/01/31 14:33:03 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sa(t_info *i, t_list **list, char tag)
{
    t_list	*tmp;
    t_list	*tete;

    tete = *list;
    tmp = tete->next;
    tete->next = tete->next->next;
    tmp->next = *list;
    *list = tmp;
    ft_lstadd_back_ret(&i->ret, ft_lstnew_ret(1, tag));
}

void    ft_ra(t_info *i, t_list **list, char tag)
{
    t_list *tmp;
    t_list	*tete;
    int count;

    count = 0;
    tmp = *list;
    tete = *list;
    *list = tete->next;
    while (count < ft_lstsize(*list))
    {
        tete = tete->next;
        count++;
    }
    tete->next = tmp;
    tete->next->next = NULL;
    ft_lstadd_back_ret(&i->ret, ft_lstnew_ret(4, tag));
}

void    ft_rra(t_info *i, t_list **list, char tag)
{
    t_list	*tete;
    int count;

    count = 0;
    tete = *list;
    while (count < ft_lstsize(*list) - 2)
    {
        tete = tete->next;
        count++;
    }
    tete->next->next = *list;
    *list = tete->next;
    tete->next = NULL;
    ft_lstadd_back_ret(&i->ret, ft_lstnew_ret(6, tag));
}

void    ft_pa(t_info *i, t_list **list_a, t_list **list_b, char tag)
{
    t_list	*tmp;

    tmp = *list_a;
    *list_a = tmp->next;
    tmp->next = NULL;
    ft_lstadd_front(list_b, tmp);
    ft_lstadd_back_ret(&i->ret, ft_lstnew_ret(3, tag));
}
