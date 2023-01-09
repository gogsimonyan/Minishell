#include "../minishell.h"

void ft_lexer(t_data *data)
{
	int i;

	i = 0;
	while (data->command[i])
	{
		while (ft_is_space(data->command[i]))
			i++;
		if (ft_is_word(data->command[i]))
			i = ft_add_word(data, i);
		if (data->command[i] == '"' || data->command[i] == '\'')
			 i = ft_add_field(data, i);
		if (ft_is_redirection_in(data->command[i]))
			 i = ft_add_redirection_in(data, i);
		if (ft_is_redirection_out(data->command[i]))
			 i = ft_add_redirection_out(data, i);
		if (data->command[i] == '|')
			 i = ft_add_pipe(data, i);
	}
}