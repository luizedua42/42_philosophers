NAME := philo
CFLAGS := -Wextra -Wall -Werror -pthread
CFLAGS += -g3
JOBS := -j50
MAKEFLAGS += --no-print-directory
YELLOW := $(shell tput setaf 3)
GREEN := $(shell tput setaf 2)
RESET := $(shell tput sgr0)

CC := cc
RM := rm -rf

LIBS := 

OBJ_DIR := build

SRCS := philo.c philo_utils.c input_validation.c inits.c thread_creation.c
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

bonus: $(NAME)_bonus

print_start:
	@echo "$(YELLOW)Compiling philosophers...$(RESET)"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): print_start $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(INCLUDES) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)philosophers compiled!$(RESET)"

clean:
	@$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
