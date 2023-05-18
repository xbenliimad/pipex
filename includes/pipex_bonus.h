
#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <sys/wait.h>

typedef struct s_info
{
    int ac;
    int fd[2];
    char **av;
    char **env;
}   t_info;

// Bonus
char    *ft_get_final_path(char *av, char *env[]);
void	ft_child_process(t_info main_info, int file[2]);

// Utils
void ft_free_double_pointer(char **str);
void ft_error(char *message);
t_info	ft_get_info(int ac, char *av[], char *env[]);

#endif