#include "../inc/libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *new;

	if (!(new = malloc(sizeof(t_list))))
		return NULL;
	new->content = content;
	new->next = NULL;

	return new;
}

void ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst && *alst)
	{
		new->next = *alst;
		*alst = new;
	}
}

int ft_lstsize(t_list *lst)
{
	int i = 0;
	
	while (lst && ++i)
		lst = lst->next;
	return i;
}

t_list *ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return lst;
}

void ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!alst)
		return ;

	t_list *tmp = *alst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*alst = new;
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	if (!lst || !*lst)
		return ;
	while ((*lst))
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		ft_lstdelone(tmp, (*del));
	}
}

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list *tmp = lst;

	while (tmp && *f)
	{
		(*f)(tmp->content);
		tmp = tmp->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list *temp;
	t_list *start;

	if (!lst || !*del || !*f)
		return (NULL);
	if (!(temp = ft_lstnew((*f)(lst->content))))
		return (NULL);
	start = temp;
	while (lst)
	{
		if (!(temp = ft_lstnew((*f)(lst->content))))
			ft_lstclear(&temp, del);
		lst = lst->next;
		ft_lstadd_back(&start, temp);
	}
	start = start->next;
	return (start);
}
