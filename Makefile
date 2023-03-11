NAME = philo

SRC = 

OBJ = ${SRC : .c == .o}

all : ${NAME}

${NAME} : ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}
clean :
	rm -rf ${OBJ}

fclean :clean
	rm -rf${NAME}

re : fclean all 

git:
	git add . && git commit -m "again" && git push