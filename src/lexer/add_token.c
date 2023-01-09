#include "../minishell.h"

int ft_add_word(t_data *data, int i)
{
	char *command;

	command = ft_substr(data->command, i, ft_word_len(data->command, i));
	i += ft_word_len(data->command, i);
	data->token_list = ft_add_token_back(data->token_list, command, WORD);
	return (i);
}

int ft_add_field(t_data *data, int i)
{
	char	*command;
	int		len;
	int		begin;
	char	c;

	begin = i;
	len = 0;	
	if (data->command[i] == '"' || data->command[i] == '\'')
	{
		c = data->command[i];
		begin++;
		i++;
		len++;
		while (data->command[i] && data->command[i] != c)
		{
			i++;
			len++;
		}
	}
	if(data->command[i] == c)
	{
		i++;
		command = ft_substr(data->command, begin, len - 1);
		if (c == '"')
			data->token_list = ft_add_token_back(data->token_list, command, FIELD);
		else if (c == '\'')
			data->token_list = ft_add_token_back(data->token_list, command, EXP_FIELD);
	}
	else
		ft_print_error(data, "Invalid chakert");
	return (i);
}

int ft_add_redirection_in(t_data *data, int i)
{
	char *command;
	int len;
	int begin;

	begin = i;
	len = 0;
	command = NULL;
	while (data->command[i] && ft_is_redirection_in(data->command[i]))
	{
		i++;
		len++;
	}

	command = ft_substr(data->command, begin, len);

	if (len == 1)
	{
		data->token_list = ft_add_token_back(data->token_list, command, REDIRECT_IN);
	}
	else if (len == 2)
	{   
		data->token_list = ft_add_token_back(data->token_list, command, REDIRECT_INSOURCE);
	}
	else
		ft_print_error(data, "Invalid redirections");
	return (i);
}

int ft_add_redirection_out(t_data *data, int i)
{
	char *command;
	int len;
	int begin;

	begin = i;
	len = 0;
	command = NULL;
	while (data->command[i] && ft_is_redirection_out(data->command[i]))
	{
		i++;
		len++;
	}
	command = ft_substr(data->command, begin, len);

	if (len == 1)
	{
		data->token_list = ft_add_token_back(data->token_list, command, REDIRECT_OUT);
	}
	else if (len == 2)
	{
		data->token_list = ft_add_token_back(data->token_list, command, REDIRECT_APPEND);
	}
	else
		ft_print_error(data, "Invalid redirects");
	return (i);
}

int ft_add_pipe(t_data *data, int i)
{
	int begin;
	char *command;
	int len;

	begin = i;
	command = NULL;
	len = 0;
	while (data->command[i] && data->command[i] == '|')
	{
		i++;
		len++;
	}
	command = ft_substr(data->command, begin, len);
	if (len == 1)
		data->token_list = ft_add_token_back(data->token_list, command, PIPE);
	else
		ft_print_error(data, "Invalid pipes");
	return (i);
}
