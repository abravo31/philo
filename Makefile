SOURCES_FILES	=	main.c \
					parsing.c tools.c

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

$(NAME): $(OBJECTS) $(HEADER) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(HEADER) 
	@echo "\033[32m$ ${NAME} compiled !"
	@echo "----------------------------\033[0m"

clean:
	@$(MAKE) -C clean
	@$(RM) $(OBJECTS) 
	@echo "\033[32mClean !\033[0m"

fclean:		clean
	@$(MAKE) -C fclean
	@$(RM) $(NAME) 

re:			fclean all

.PHONY:		all clean fclean re 
