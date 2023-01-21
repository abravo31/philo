SOURCES_FILES	=	main.c \
					philo.c philo_poutine.c time.c tools.c

SOURCES_DIR		=	srcs

HEADER			=	$(SOURCES_DIR)/philo.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

MAKE			=	make

NAME			=	philo

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g3 -Wall -Wextra -Werror -pthread #-fsanitize=address

all:	$(NAME)

.c.o:		
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)  
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

clean:
	@$(RM) $(OBJECTS) 
	@echo "\033[32mClean !\033[0m   \033[0;38;5;44mObjects are removed\033[0m"

fclean:		clean
	@$(RM) $(NAME)
	@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mPhilo is removed\033[0m"

re:			fclean all

.PHONY:		all clean fclean re 
