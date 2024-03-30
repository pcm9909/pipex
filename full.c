#include "pipex.h"

void	check_argc(int argc)
{
	if (argc != 5)
	{
		perror("wrong number of arguments");
		exit(1);
	}
}

void	check_file(char *file1, char *file2)
{
	if (access(file1, F_OK) == -1)
	{
		perror("infile does not exist");
		exit(1);
	}
	if (access(file2, F_OK) == -1)
	{
		perror("outfile does not exist\n");
		exit(1);
	}
}

void	check_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		perror("pipe() failed\n");
		exit(1);
	}
}

void	check_fork(pid_t pid)
{
	if (pid == -1)
	{
		perror("fork() failed\n");
		exit(1);
	}
}

void	ensure_preconditions(int argc, char *f1, char *f2, int *fd)
{
	check_argc(argc);
	check_file(f1, f2);
	check_pipe(fd);
}

void	execute_child(int *fd, int *file, char *command, char **envp)
{
	char	**cmd;

	cmd = ft_split(command, ' ');
	dup2(file[1], 1);
	close(fd[1]);
	dup2(fd[0], 0);
	execve(get_cmd_path(cmd[0], get_path(envp)), cmd, NULL);
	perror("execve failed");
	exit(1);
}

void	execute_parent(int *fd, int *file, char *command, char **envp)
{
	char	**cmd;

	cmd = ft_split(command, ' ');
	dup2(file[0], 0);
	close(fd[0]);
	dup2(fd[1], 1);
	execve(get_cmd_path(cmd[0], get_path(envp)), cmd, NULL);
	perror("execve failed");
	exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	int		file[2];
	pid_t	pid;

	file[0] = open(argv[1], O_RDONLY);
	file[1] = open(argv[4], O_WRONLY | O_TRUNC);
	ensure_preconditions(argc, argv[1], argv[4], fd);
	pid = fork();
	printf("%d\n", pid);
	if (pid == 0)
	{
		execute_child(fd, file, argv[3], envp);
	}
	else if (pid > 0)
		execute_parent(fd, file, argv[2], envp);
	else
		check_fork(pid);
}
