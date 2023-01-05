#include "lexer.h"

int ft_isspace(char c)
{
    if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == ' ' || c == '\f')
        return (1);
    return (0);
}

int ft_is_redirection_in(char c)
{
    if (c == '<')
        return (1);
    return (0);
}

int ft_is_redirection_out(char c)
{
    if (c == '>')
        return (1);
    return (0);
}

int ft_is_word(char c)
{
    if (c != '|' && !ft_is_redirection_in(c) && !ft_is_redirection_out(c) && !ft_isspace(c) && c != ';' 
        && c != '"' && c != '\'')
        return (1);
    return (0);
}