/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:48:50 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/22 15:48:05 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

//include

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h> // a enlever !!!!!!

// structure

typedef struct s_ret{
    char			tag;
    int				content;
    struct s_ret	*next;
}                   t_ret;

typedef struct s_info {
    int *tab;
    int size_tab;
    int med;
    int tier1;
    int tier2;
    int argc;
	t_list	*list_a;
    t_list	*list_b;
	int		last;
    int     first;
    int		second;
	int		third;
    t_list  *count;
    int     count_a;
    int     count2;
    t_list  *temp;
    t_list  *temp2;
    int     head;
    t_ret   *ret;
    int     end_count;
    int		lock;
}	t_info;

//fonction

void	crea_lst(t_list **list,char *argv);
void	print_list(t_list *list);
void    ft_sa(t_info *i, t_list **list, char tag);
void    ft_ra(t_info *i, t_list **list, char tag);
void    ft_rra(t_info *i, t_list **list, char tag);
void    ft_pa(t_info *i, t_list **list_a, t_list **list_b, char tag);
// char	**crea_tabs(t_list **list);
int     *crea_tabi(t_list **list);
void	sort_tab(int *tab, int size);
int     find_med(t_list *list, t_info *i);
int		find_dup(int *tab, int size);
int     ft_deter_int( const char *theString);
void	verif(t_list **list,char **argv);
void	ft_erreur();
void	ft_exit(int	*tab);
void	ft_brain(t_info *i);
void	print_tab(int *tab, int size);
void	sort_three(t_info *i, t_list **list);
void	sort_three_up(t_info *i, t_list **list);
int	    ft_lstmove_i(t_list *lst, int indice);
t_list	*ft_lstmove(t_list *lst, int indice);
int     ft_if_sort(t_list *lst);
void	ft_firtsort(t_info *i, int tete);
void	ft_second_step(t_info *i, int tete);
void	crea_lst_inter(t_info *i,t_list *lst, int count);
int     ft_amoreb(t_info *i);
void	ft_third_step(t_info *i, int tete);
t_ret	*ft_lstnew_ret(int content, char tag);
void	ft_lstadd_back_ret(t_ret **alst, t_ret *new);
void	print_lst_move(t_ret *list, char *a, char *b);
void	ft_ra_rra_same_tag(t_ret **list, int t);
void	ft_ra_rra_diff_tag(t_ret **list, int t);
void	lst_change_rt_under(t_ret **list);
int		ft_lstsize_ret(t_ret *lst);
void	ft_ss_diff_tag(t_ret **list, int t, int content);
void	print_list_rt(t_ret *list);
void	find_dbl_med(t_info *i, t_list *list);
void	sort_dbl_med(t_info *i, int tete, int *count, int *step);
void	swap_tete(t_info *i, t_list **tete);
void	declar_step_2_up(t_info *i);
void	declar_step_2_down(t_info *i);
void	sort_step_2_up(t_info *i, int *count, int tete);
void	sort_step_2_down(t_info *i, int *count, int tete);
int     add_content_lst(t_list *list);
void	declar_step_3(t_info *i);
void	last_1(t_info *i, int *count1, int *count_pa, int *step);
void	free_count(t_info *i);
void	lock_tete(t_info *i, t_list **tete);
int     make_count_a(t_info *i);
void	ft_lstclear_ret(t_ret **lst);
void	init(t_info *i);

#endif