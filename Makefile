NAME = fractol

SRCS		= 	main.c \
				julia.c \
				mandelbrot.c \
				imag.c \
				init.c \
				complex.c \
				parsing.c \
				color.c \
				hook.c \
				plan.c \
				math_utils.c



OBJS			= $(SRCS:.c=.o)
CC				= clang
# FLAGS 			= -Wall -Werror -Wextra
FLAGS		    = -lmlx -lXext -lX11 -lm
SANITIZE		= -g3 -fsanitize=address

%.o : %.c
			$(CC) -c $(CFLAGS) $< -o $@
	
$(NAME) : 		$(OBJS)
				make -C libft
				$(CC) $(OBJS) $(FLAGS) libft/libft.a -o $(NAME)		

all : 			$(NAME)


# UNAME = $(shell uname -s)
# ifeq ($(UNAME), Linux)
# 	NPROC := $(shell nproc)
# 	LIBS += -lmlx -lXext -lX11 -lm
# else
# 	NPROC := $(shell sysctl -n hw.ncpu)
# 	INC_FLAGS += -Ilibs/mlx
#     	LIBS += -Llibs/mlx -framework OpenGL -framework Appkit
# endif

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