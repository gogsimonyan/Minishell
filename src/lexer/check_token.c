#include "../minishell.h"

int ft_is_space(char c)
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
	return (c != '|' && !ft_is_redirection_in(c) &&
		!ft_is_redirection_out(c) && !ft_is_space(c) &&
		c != '"' && c != '\'');
}