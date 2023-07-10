# NAME = philo

# SRC = philo.c\
# 	philo_utils.c\
# 	main.c

# OBJ = ${SRC : .c == .o}

# CC = cc

# CFLAGS = -Wall -Wextra -Werror -g3 fsanitize=address

# all : ${NAME}

# ${NAME} : ${SRC}
# 	${CC} ${CFLAGS} ${SRC} -o ${NAME}

# clean :
# 	rm -rf ${OBJ}

# fclean :clean
# 	rm -rf ${NAME}

# re : fclean all 

# push:
# 	git add . && git commit -m "philo" && git push

NAME = philo

SRC = philo.c \
      philo_utils.c \
      main.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g3

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
#