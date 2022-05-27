NAME = fractol

SRCS		= 	main.c \
				src/draw.c \
				src/model.c \
				src/init.c \
				src/init_2.c \
				src/complex.c \
				src/parsing_1.c \
				src/parsing_2.c \
				src/color.c \
				src/hook.c \
				src/zoom.c \
				src/plan.c \
				src/math_utils.c \
				src/detect.c \
				src/free.c



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 		= -Wall -Werror -Wextra
# FLAGS		    = -lmlx -lXext -lX11 -lm
SANITIZE		= -g3 -fsanitize=address

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(OBJS) $(FLAGS) libft/libft.a -o $(NAME)		

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