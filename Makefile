NAME = philo

SRC = philo.c \
      philo_utils.c \
      main.c\
	  check_death.c\
	  mini_functions.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 
#  CFLAGS +=  -fsanitize=thread -g3
 #CFLAGS+= -g3 -fsanitize=address
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

push:
	git add . && git commit -m "philo" && git push
