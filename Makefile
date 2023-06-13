CC = cc
NAME = minishell
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I$(HEADERS_DIRECTORY) -I /goinfre/$(USER)/.brew/Cellar/readline/8.2.1/include
LIBRARIES =-lreadline  -L /goinfre/$(USER)/.brew/Cellar/readline/8.2.1/lib 

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = minishell.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./
SOURCES_LIST =	add_x.c \
				ambiguis.c \
				builtins.c \
				cd.c \
				change_pwd.c \
				change_x.c \
				charloc.c \
				check_error.c \
				check_pipe.c \
				check_q_nb.c \
				check_q.c \
				check_red.c \
				childs_utils.c \
				childs.c \
				clean_q.c \
				clean.c \
				close.c \
				echo.c \
				env.c \
				exit_print.c \
				exit.c \
				expand_creat.c \
				expand_join.c \
				expand_q.c \
				exp_bf_af.c \
				expand.c \
				export.c \
				fill_check.c \
				fill_lin.c \
				fill_sp.c \
				forking.c \
				free.c \
				ft_atoi.c \
				ft_cmp.c \
				ft_free.c \
				ft_is_2.c \
				ft_is.c \
				ft_itoa.c \
				ft_lstadd_back.c \
				ft_lstadd_back2.c \
				ft_lstclear.c \
				ft_lstlast.c \
				ft_lstlast2.c \
				ft_lstnew.c \
				ft_lstnew2.c \
				ft_lstsize.c \
				ft_put_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_substr.c \
				get_env.c \
				here_exp.c \
				heredoc.c \
				lin_type.c \
				minishell.c \
				open.c \
				pipes.c \
				print_error.c \
				pwd.c \
				rdy_to_exp.c \
				set_arg.c \
				set_cmd.c \
				set_env.c \
				set_ex.c \
				set_file.c \
				sig_handel.c \
				trim_space.c \
				unset.c \
				wait.c \

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS) -o $(NAME) $(LIBRARIES)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

bonus: all

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all
