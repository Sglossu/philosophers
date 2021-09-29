NAME			=	philo
DIR_HEAD		=	includes
CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
DIR_SRCS		=	srcs/

SRCS			=	$(DIR_SRCS)philo.c					$(DIR_SRCS)valid.c					$(DIR_SRCS)ft_atoi.c \
					$(DIR_SRCS)init_struct.c			$(DIR_SRCS)thread.c					$(DIR_SRCS)time.c

OBJS			=	$(SRCS:.c=.o)

HEAD			=	$(DIR_HEAD)/philo.h

.PHONY			:	all clean fclean re bonus

.c.o:	
	$(CC) $(CFLAGS) -c  -I$(DIR_HEAD) $< -o $(<:.c=.o)

all				:	$(NAME) 

$(NAME)			:	$(OBJS) $(HEAD)
	$(CC) -g $(CFLAGS)  -I$(DIR_HEAD) $(SRCS)  -o $(NAME) 

clean 			:
	$(RM) $(OBJS)

fclean			:	clean
	$(RM) $(OBJS) $(NAME)

re				:	fclean all
