NAME = miniRT

INC = -Iinc -Iinc/input

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	main.c					\
		exit.c					\
		init_camera.c			\
		init_img.c				\
		render_img.c			\
		transformation.c		\
		utilities.c				\
		get_color.c				\
		get_color1.c

S_INPUT =	parse.c				\
			read_infile.c		\
			create_nodes.c		\
			create_nodes_1.c	\
			create_nodes_2.c	\
			ft_atod_check.c		\
			check_nodes.c		\
			check_nodes_1.c

S_INTER =	inter_cy.c			\
			inter_pl.c			\
			inter_sp.c			\
			get_intersection.c	\


S_WINDOW =	interaction.c

S_MATRIX =	operations.c		\
			operations1.c		\
			utils.c				\
			defines.c			\
			debug.c

S_VECTOR =	vec_utils.c			\
			vec_utils1.c


SDIR = src
S_INPUTDIR = input
S_INTERDIR = inter
S_WINDOWDIR = window
S_VECTORDIR = vector
S_MATRIXDIR = matrix

FAST_SRC = $(addprefix $(SDIR)/, $(SRC))						\
			$(addprefix $(SDIR)/$(S_WINDOWDIR)/, $(S_WINDOW))	\
			$(addprefix $(SDIR)/$(S_INTERDIR)/, $(S_INTER))		\
			$(addprefix $(SDIR)/$(S_MATRIXDIR)/, $(S_MATRIX))	\
			$(addprefix $(SDIR)/$(S_VECTORDIR)/, $(S_VECTOR))

INPUT_SRC = $(addprefix $(SDIR)/$(S_INPUTDIR)/, $(S_INPUT))

HDIR = inc
HEADER = exit.h		\
		inter.h		\
		matrix.h	\
		mini_rt.h	\
		object.h	\
		vector.h	\
		window.h	\
		input/check_nodes.h		\
		input/create_nodes.h	\
		input/parse.h

ODIR = obj
OBJ =	$(patsubst %.c, %.o, $(SRC))		\
		$(patsubst %.c, %.o, $(S_INTER))	\
		$(patsubst %.c, %.o, $(S_WINDOW))	\
		$(patsubst %.c, %.o, $(S_MATRIX))	\
		$(patsubst %.c, %.o, $(S_VECTOR))	\
		$(patsubst %.c, %.o, $(S_INPUT))

LIBFT = -Llib -lft

LDFLAGS = -lft -lmlx -framework OpenGL -framework AppKit
LDLIBS = -Imlx

all: $(NAME)

$(NAME):	$(FAST_SRC) $(INPUT_SRC) $(addprefix $(HDIR)/, $(HEADER))
			make -C ./lib/minilibx
			make -C ./lib/libft
			cp -f ./lib/minilibx/libmlx.a lib
			cp -f ./lib/libft/libft.a lib
			mkdir -p $(ODIR)
			$(CC) $(CFLAGS) -Ofast $(INC) -c $(FAST_SRC)
			$(CC) $(CFLAGS) -Ofast $(INC) -c $(INPUT_SRC)
			mv $(OBJ) $(ODIR)
			$(CC) $(CFLAGS) $(LDFLAGS) $(INC) $(addprefix $(ODIR)/, $(OBJ)) $(LIBFT) -o $(NAME)

clean:
		rm -rf $(ODIR)
		rm -f ./lib/libmlx.a
		rm -f ./lib/libft.a
		make clean -C ./lib/minilibx
		make clean -C ./lib/libft

fclean:	clean
		make fclean -C ./lib/libft
		rm -rf $(NAME)

re: fclean all
