NAME = fractol

SRCS		= 	main.c \
				draw.c \
				model.c \
				init.c \
				init_2.c \
				complex.c \
				parsing_1.c \
				parsing_2.c \
				color.c \
				hook.c \
				zoom.c \
				plan.c \
				math_utils.c \
				detect.c \
				free.c



OBJS			= $(SRCS:.c=.o)
CC				= gcc
# FLAGS 		= -Wall -Werror -Wextra
# FLAGS		    = -lmlx -lXext -lX11 -lm
SANITIZE		= -g3 -fsanitize=address -fsanitize=leak

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(SANITIZE)  $(OBJS) $(FLAGS) libft/libft.a -o $(NAME)		

all : 			$(NAME)


UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	FLAGS += -lmlx -lXext -lX11 -lm
else
	NPROC := $(shell sysctl -n hw.ncpu)
	FLAGS += -lmlx
    FLAGS += -Lminilibx -framework OpenGL -framework Appkit
endif

clean :
				make clean -C libft
				/bin/rm -rf $(OBJS)

fclean : clean
				make fclean -C libft
				/bin/rm -rf $(NAME)

debug : 		$(OBJS)
				$(CC) $(OBJS) $(FLAGS) $(SANITIZE) libft/libft.a  -o $(NAME)
				# lldb ./$(NAME)


re : fclean all
.PHONY			: all clean fclean re