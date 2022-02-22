/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:42:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/22 16:26:51 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_firtsort(t_info *i, int tete)
{
	static int count = 0;

	// printf("\nfirst\n");
	// printf("liste A\n");
	// print_list(i->list_a);
	// printf("liste B\n");
	// print_list(i->list_b);
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
	if (i->first == 1)
	{
		i->med = find_med(i->list_a, i);
		find_dbl_med(i, i->list_a);
		i->last = ft_lstmove_i(i->list_a, ft_lstsize(i->list_a));
		i->first = 2;
		if (ft_lstsize(i->list_a) > 6)
			i->first = 3;
		if ((ft_lstsize(i->list_a) <= 3) && ft_amoreb(i) == 0)
		{
			sort_three(i, &i->list_a);
			i->first = 0;
		}
	}
	else if (i->first == 3)
		sort_dbl_med(i, tete, &count, &i->first);
	else if (tete < i->med)
	{
		// printf("inf med pb\n");
		count++;
		ft_pa(i, &i->list_a, &i->list_b, 'b');
	}
	else if (tete >= i->med)
	{
		// printf("sup ou eg med ra\n");
		ft_ra(i, &i->list_a, 'a');
	}
	if (tete == i->last)
	{
		if (count > 0)
			ft_lstadd_front(&i->count, ft_lstnew(count));
		count = 0;
		i->first = 1;
	}
}

void	last_1(t_info *i, int *count1, int *count_pa, int *step)
{
	if ((*step) == 3)
	{
		ft_lstadd_back(&i->count, ft_lstnew(*count1));
		ft_lstadd_front(&i->count, ft_lstnew(*count_pa));
		(*count1) = 0;
		(*count_pa) = 0;
		i->count_a = 0;
		while (i->count2 > 0)
		{
			// printf("rra du last | ");
			ft_rra(i, &i->list_a, 'a');
			i->count2--;
			if (i->third == 3)
			{
				i->count_a++;
			}
		}
		// printf("i.first = %i ", i->first);
		// printf("\n");
		(*step) = 1;
	}
}

void	sort_dbl_med(t_info *i, int tete, int *count, int *step)
{
	static int count_pa = 0;

	if (tete <= i->tier1)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		if(ft_lstsize(i->list_b) > 1)
			ft_ra(i, &i->list_b, 'b');
		(*count)++;
	}
	else if(tete <= i->tier2)
	{
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		count_pa++;
	}
	else if (tete > i->tier2)
	{
		ft_ra(i, &i->list_a, 'a');
		i->count2++;
	}
	if (tete == i->last)
	{
		last_1(i, count, &count_pa, step);
	}
}

void	ft_second_step(t_info *i, int tete)
{
	static int count = 0;

	// printf("\ndebut step 2\n");
	// printf("i.end_count = %i\n", i->end_count);
	// printf("tete = %i\n", tete);
	// printf("med = %i\n", i->med);
	// printf("liste A\n");
	// print_list(i->list_a);
	// printf("liste B\n");
	// print_list(i->list_b);
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n\n");
	if (i->second == 1)
	{
		if (i->head == 0)
			declar_step_2_up(i);
		else
		{
			declar_step_2_down(i);
		}
	}
	if (i->second > 1)
	{
		if (i->head == 0)
			sort_step_2_up(i, &count, tete);
		else
		{
			sort_step_2_down(i, &count, tete);
		}
	}
	// printf("end step 2\n");
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
}

void	sort_step_2_up(t_info *i, int *count, int tete)
{
	// printf("sort up step 2\n");
	if(i->count->content == 0 )
	{
		if (ft_lstsize(i->count) == 1)
		{
			i->count->content = (*count);
			(*count) = 0;
		}
		while ((*count) > 0)
		{
			ft_rra(i, &i->list_b, 'b');
			(*count)--;
			i->count->content++;
		}
		i->second = 0;
		i->third = 1;
		i->lock = 0;
	}
	else if (tete >= i->med)
	{
		// printf("sort up step 2 sup eg med ft_pa\n");
		ft_pa(i, &i->list_b, &i->list_a, 'a');
		i->count->content--;
        i->count_a++;
	}
	else if(tete < i->med)
	{
		// printf("sort up step 2 inf med ft_ra\n");
		ft_ra(i, &i->list_b, 'b');
		i->count->content--;
		(*count)++;
	}
}

void	sort_step_2_down(t_info *i, int *count, int tete)
{
	// printf("sort down\n");
	if(ft_lstmove_i(i->count, ft_lstsize(i->count)) == 0)
	{
		if((*count) > 0)
		{
			ft_lstadd_front(&i->count, ft_lstnew((*count)));
		}
		(*count) = 0;
		free_count(i);
		i->second = 0;
		i->third = 1;
		i->lock = 0;
	}
	else if (tete >= i->med)
	{
		// printf("sort down step 2 sup eg med ft_rra + pa\n");
		ft_rra(i, &i->list_b, 'b');
		ft_pa(i, &i->list_b, &i->list_a, 'a');
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
        i->count_a++;
	}
	else if(tete < i->med)
	{
		// printf("sort down step 2 inf med ft_rra\n");
		ft_rra(i, &i->list_b, 'b');
		ft_lstmove(i->count, ft_lstsize(i->count))->content--;
		(*count)++;
	}
}

void	declar_step_2_up(t_info *i)
{
	crea_lst_inter(i, i->list_b, i->count->content);
	i->med = find_med(i->temp, i);
	ft_lstclear(&i->temp);
	i->second = 2;
	i->lock = 1;
    i->last = ft_lstmove_i(i->list_b, i->count->content);
	if (i->count->content <= 3)
	{
		while (i->count->content > 0)
        {
            ft_pa(i, &i->list_b, &i->list_a, 'a');
            i->count->content--;
			i->count_a++;
		}
		// printf("before free step 2 up\n");
		free_count(i);
		// printf("after free step 2 up\n");
		i->second = 0;
		i->third = 1;
		i->lock = 0;
	}
}

void	help_crea_lst_2(t_info *i)
{
	t_list	*tete;
	int		size_b;
	int		end_count_b;

	size_b = ft_lstsize(i->list_b);
	end_count_b = ft_lstmove_i(i->count, ft_lstsize(i->count));
	tete = ft_lstmove(i->list_b, (size_b - end_count_b));
	// printf("size = %i | indice %i | count end %i | tete = %i\n", size_b, (size_b - end_count_b), end_count_b, tete->content);
	crea_lst_inter(i, tete->next, end_count_b);
}

void	declar_step_2_down(t_info *i)
{
	// printf("decla_2_down\n");
	// crea_lst_inter(i, ft_lstmove(i->list_b, ft_lstsize(i->list_b) - ft_lstmove_i(i->count, ft_lstsize(i->count))),ft_lstmove_i(i->count, ft_lstsize(i->count)));
	// printf("size = %i | indice %i | count end %i\n", ft_lstsize(i->list_b), (ft_lstmove(i->list_b, ft_lstsize(i->list_b) - ft_lstmove_i(i->count, ft_lstsize(i->count)))), ft_lstmove_i(i->count, ft_lstsize(i->count)));
	help_crea_lst_2(i);
	i->med = find_med(i->temp, i);
	ft_lstclear(&i->temp);
	i->second = 2;
	i->lock = 2;
    i->last = ft_lstmove_i(i->list_b, ft_lstmove_i(i->count, ft_lstsize(i->count)));
	if (ft_lstmove_i(i->count, ft_lstsize(i->count)) <= 3)
	{
		while (ft_lstmove_i(i->count, ft_lstsize(i->count)) > 0)
        {
			// printf("decla_2_down rra + pa\n");
			ft_rra(i, &i->list_b, 'b');
            ft_pa(i, &i->list_b, &i->list_a, 'a');
            ft_lstmove(i->count, ft_lstsize(i->count))->content--;
			i->count_a++;
		}
		free_count(i);
		i->second = 0;
		i->third = 1;
		i->lock = 0;
	}
}

void	ft_third_step(t_info *i, int tete)
{
	static int count = 0;
    static int count_b = 0;

	// printf("liste A\n");
	// print_list(i->list_a);
	// printf("liste B\n");
	// print_list(i->list_b);
	// printf("liste count\n");
	// print_list(i->count);
	// printf("end count\n");
	if (i->third == 1)
	{
		// printf("decla 3\n");
		// printf("i.count_a = %i\n", i->count_a);
		declar_step_3(i);
		// printf("i.last = %i\n", i->last);
	}
	else if (i->third == 3)
	{
		sort_dbl_med(i, tete, &count_b, &i->third);
		// printf("count = %i\n", count);
		// printf("count_a = %i\n", i->count_a);
		// printf("etat i-third = %i\n", i->third);
	}
	// else if(i->count_a == 0)
	// {
	// 	printf("sort 3 i->count_a == 0\n");
	// 	while (count > 0)
	// 	{
	// 		ft_rra(i, &i->list_a, 'a');
	// 		count--;
	// 		i->count_a++;
	// 	}
	// 	i->third = 1;
	// }
	else if (tete >= i->med)
	{
		// printf("sort 3 tete >= i->med\n");
		ft_ra(i, &i->list_a, 'a');
		i->count_a--;
		count++;
	}
	else if(tete < i->med)
	{
		// printf("sort 3 tete < i->med\n");
		ft_pa(i, &i->list_a, &i->list_b, 'b');
		count_b++;
		i->count_a--;
	}
	if (tete == i->last && i->third != 3)
	{
		// printf("last 3\n");
		if (count_b > 0)
			ft_lstadd_front(&i->count, ft_lstnew(count_b));
		count_b = 0;
		while (count > 0)
		{
			// printf("ft_rra last\n");
			ft_rra(i, &i->list_a, 'a');
			count--;
			i->count_a++;
		}
		i->third = 1;
	}
}

void	declar_step_3(t_info *i)
{
	i->count_a = make_count_a(i);
	crea_lst_inter(i, i->list_a,i->count_a);
	i->med = find_med(i->temp, i);
	ft_lstclear(&i->temp);
	crea_lst_inter(i, i->list_a,i->count_a);
	find_dbl_med(i, i->temp);
	ft_lstclear(&i->temp);
	i->third = 2;
	if (i->count_a > 6)
		i->third = 3;
	i->last = ft_lstmove_i(i->list_a, i->count_a);
	if (i->count_a <= 3)
	{
		// printf("step 3 sort_three_up\n");
		sort_three_up(i, &i->list_a);
		i->count_a = 0;
		// count_b = 0;
		i->second = 1;
	}
}
