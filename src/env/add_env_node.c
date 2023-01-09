#include "../minishell.h"

t_env *ft_add_new_env(char *value)
{
	t_env	*node;
	int		i;

	i = 0;
	node = NULL;
	node = malloc(sizeof(t_env));
	if (!node)
		exit (1);
	while (value[i] != '=')
		i++;
	node->name = ft_substr(value, 0, i);
	i++;
	if (value[i])
		node->value = ft_substr(value, i, ft_strlen(value) - i);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_env *ft_add_env_back(t_env *env_list, char *value)
{
	t_env	*node;
	t_env	*env_list_clone;

	if (!value)
		return (NULL);
	node = ft_add_new_env(value);
	if (env_list == NULL)
		return (node);
	env_list_clone = env_list;
	while (env_list_clone->next != NULL)
		env_list_clone = env_list_clone->next;
	env_list_clone->next = node;
	node->prev = env_list_clone;
	return (env_list);
}