# **************************************************************************** #
# VARIABLES

NAME		= form
CC			= c++
FLAGS		= -Wall -Wextra -Werror -I. -std=c++98 -g3
RM			= rm -rf

OBJS_DIR	= bin
 
SRCS		= Bureaucrat.cpp AForm.cpp main.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp ShrubberyCreationForm.cpp
OBJS		= $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

# **************************************************************************** #
# COLORS

GREEN		= \033[0;32m
GREY		= \033[1;30m
PURPLE		= \033[0;35m
BLUE		= \033[0;94m
CYAN		= \033[0;36m
PINK		= \033[1;35m
RED			= \033[0;31m
END_COLOR	= \033[0;39m


# **************************************************************************** #
# RULES

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)[Success]$(END_COLOR) Form is ready !"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR) "Shrubbery Creation_shrubbery"
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted"

fclean:
	@$(RM) $(OBJS_DIR) $(NAME) a.out "Shrubbery Creation_shrubbery"
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and objects have been deleted"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done."

.PHONY: all clean fclean re