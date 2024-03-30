#include "pipex.h"

char *get_path(char **envp)
{
    int i;
    char *path;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_strdup(envp[i] + 5);
            return (path);
        }
        i++;
    }
    return (NULL);
}

char *get_cmd_path(char *cmd, char *path_env_var)
{
    char **paths = ft_split(path_env_var, ':');
    char *cmd_path = NULL;
    int i = 0;

    while (paths[i])
    {
        char *tmp = ft_strjoin(paths[i], "/");
        cmd_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(cmd_path, F_OK) != -1)
            break;
        free(cmd_path);
        cmd_path = NULL;
        i++;
    }
    if (!cmd_path)
    {
        perror("command not found");
        exit(1);
    }
    else
        return (cmd_path);
}