
#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <sys/wait.h>

// Main
char    *ft_get_final_path(char *av, char *env[]);

// Utils
void ft_free_double_pointer(char **str);
void ft_error(char *message);

#endif