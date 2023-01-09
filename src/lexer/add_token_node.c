#include "../minishell.h"

t_token *ft_add_new_token(char *str, int type)
{
    t_token *node;
    int i;

    node = NULL;
    if (!str)
        return (NULL);

    i = ft_strlen(str);
    node = malloc(sizeof(t_token));
    if (!node)
        exit(1);

    node->value = malloc(i + 1);
    if (!node->value)
        exit(1);
    
    i = -1;
    while (str[++i])
        node->value[i] = str[i];
    node->value[i] = '\0';
    node->type = type;
    node->next = NULL;
    node->prev = NULL;

    return (node);
}

t_token *ft_add_token_back(t_token *token, char *str, int type)
{
    t_token *node;
    t_token *token_duplicate;

    if (!str)
        return (NULL);

    node = ft_add_new_token(str, type);
    if (!node)
        exit(1);

    if (token == NULL)
        return (node);
        
    token_duplicate = token;
    while (token_duplicate->next != NULL)
        token_duplicate = token_duplicate->next;
    token_duplicate->next = node;
    node->prev = token_duplicate;
    return (token);
}