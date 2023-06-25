NAME = philo

SRC = philo.c\
	philo_utils.c\
	main.c

OBJ = ${SRC : .c == .o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean :
	rm -rf ${OBJ}

fclean :clean
	rm -rf${NAME}

re : fclean all 

git:
	git add . && git commit -m "philo" && git push
