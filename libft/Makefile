NAME	=	libft.a

SRCS    =   ft_atoi.c       ft_isalpha.c        ft_itoa.c\
            ft_memcpy.c     ft_putendl_fd.c     ft_strdup.c\
            ft_strmapi.c    ft_tolower.c        ft_bzero.c\
            ft_isascii.c    ft_memmove.c        ft_putnbr_fd.c\
            ft_strlcat.c    ft_strncmp.c        ft_toupper.c\
            ft_memset.c     ft_putstr_fd.c      ft_strlcpy.c\
            ft_strnstr.c    ft_isalnum.c        ft_isprint.c\
            ft_putchar_fd.c     ft_strchr.c \
            ft_strlen.c     ft_strrchr.c        ft_substr.c\
            ft_split.c      ft_strtrim.c        ft_striteri.c\
            ft_strjoin.c    get_next_line.c get_next_line_utils.c\
            ft_calloc.c     ft_isdigit.c\

SRCS_B  =   ft_lstnew_bonus.c       ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c      ft_lstadd_back_bonus.c\

HEADER	=	libft.h

OBJ		=	$(SRCS:.c=.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror #-I $(HEADER)

.PHONY	:	all clean fclan re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
		ar rcs $(NAME) $?

%.o :	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus :
	@make OBJ="$(OBJ) $(OBJ_B)" all

clean	:
		rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
		rm -f $(NAME)

re		:	fclean all

