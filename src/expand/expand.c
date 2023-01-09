#include "../minishell.h"

int ft_is_dollar(char c)
{
    if (c == '$')
        return (1);
    return (0);
}

char *ft_find_expand_string(t_data *data, char *token_value)
{
    int len;
    int begin;
    int i;
    char c;
    char *expand_string;

    i = 0;
    begin = i;
    len = 0;
    if (token_value[i] == '$')
    {
        c = token_value[i];
        begin++;
        i++;
        len++;
        while (token_value[i] && token_value[i] != c && !ft_isspace(token_value[i]))
        {
            i++;
            len++;
        }
    }
    if (token_value[i] == c && ft_isspace(token_value[i]))
    {
        i++;
        expand_string = ft_substr(token_value, begin, len);
        if(len == 1)
        {
            ft_print_error(data, "Invalid $");
            return (NULL);
        }
    }
    return (expand_string);
}

int ft_expanding(t_data *data)
{
    t_token *token_clone;
    int i;
    int len;
    char *expanded_string;

    i = 0;
    token_clone = data->token_list;
    while (token_clone)
    {
        if (token_clone->type == EXP_FIELD)
        {
            i = 0;
            while (token_clone->value[i])
            {
                if (ft_is_dollar(token_clone->value[i]))
                {
                    expanded_string = ft_find_expand_string(data, token_clone->value);
                    printf("expanded_string === %s\n", expanded_string);
                }
                i++;
            }
        }
    }
    return (0);
}
