CC = cc
NAME = minishell
FLAGS =#-fsanitize=address -g #-Wall -Wextra -Werror 

INCLUDES = -I$(HEADERS_DIRECTORY) #-I /goinfre/agimi/.brew/Cellar/readline/8.2.1/include
LIBRARIES = -L /goinfre/agimi/.brew/Cellar/readline/8.2.1/lib -lreadline 

HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = minishell.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./
SOURCES_LIST =	builtins.c \
				cd.c \
				charloc.c \
				check_error.c \
				check_pipe.c \
				check_quote.c \
				check_red.c \
				childs.c \
				clean_lin.c \
				clean.c \
				close.c \
				copy.c \
				echo.c \
				env.c \
				exit.c \
				expand.c \
				export.c \
				fill_lin.c \
				fill_sp.c \
				forking.c \
				free.c \
				ft_cmp.c \
				ft_free.c \
				ft_is_2.c \
				ft_is.c \
				ft_lstadd_back.c \
				ft_lstclear.c \
				ft_lstlast.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_strlen.c \
				ft_substr.c \
				lin_type.c \
				minishell.c \
				open.c \
				pipes.c \
				print_error.c \
				pwd.c \
				set_arg.c \
				set_cmd.c \
				set_env.c \
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
	@$(CC) $(FLAGS) $(OBJECTS) $(INCLUDES) -o $(NAME) $(LIBRARIES)
	@echo "\n$(NAME): $(GREEN)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all
