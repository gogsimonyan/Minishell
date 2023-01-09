#include "../minishell.h"

void ft_create_env_list(t_data *data, char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        data->env_list = ft_add_env_back(data->env_list, env[i]);
        i++;
    }
}
