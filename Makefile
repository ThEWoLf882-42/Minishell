CC = cc
NAME = minishell
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g

INCLUDES = -I$(HEADERS_DIRECTORY)

HEADERS_LIST = minishell.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./
SOURCES_LIST =	charloc.c \
				check_error.c \
				check_pipe.c \
				check_quote.c \
				check_red.c \
				childs.c \
				clean_lin.c \
				clean.c \
				copy.c \
				expand.c \
				fill_lin.c \
				fill_sp.c \
				forking.c \
				free_env.c \
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
				ft_strncmp.c \
				ft_substr.c \
				lin_type.c \
				minishell.c \
				open_fin.c \
				open_fout.c \
				print_error.c \
				set_arg.c \
				set_cmd.c \
				set_env.c \
				set_file.c \
				trim_space.c \

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) -lreadline $(OBJECTS) $(INCLUDES) -o $(NAME)
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

re:
	@$(MAKE) fclean
	@$(MAKE) all