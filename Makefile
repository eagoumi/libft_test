NAME=libft.a
CC=cc -Wall -Wextra -Werror -c
INCLUDE=./
PATH_SRC=./
PATH_OBJ=./obj/

# fonction de la libft & Supplementaire 

FILES_SRC=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c

# fonction Bonus

FILES_BNS=	ft_lstadd_back.c\
			ft_lstadd_front.c\
			ft_lstclear.c\
			ft_lstdelone.c\
			ft_lstiter.c\
			ft_lstlast.c\
			ft_lstmap.c\
			ft_lstnew.c\
			ft_lstsize.c

OBJ=$(addprefix $(PATH_OBJ), $(FILES_SRC:.c=.o))
OBJ_BONUS=$(addprefix $(PATH_OBJ), $(FILES_BNS:.c=.o))

DEF 	= 	\x1B[1;0m
RED 	= 	\x1B[1;31m
PURPLE 	=	\x1B[1;34m
BLUE 	= 	\x1B[1;96m
GREEN 	= 	\x1B[1;32m
SILVER 	= 	\x1B[1;90m
YELLOW 	= 	\x1B[1;33m
WHITE	= 	\x1b[37m

all: $(NAME)

$(NAME):$(OBJ) ./libft.h
	@ar rcs $(NAME) $(OBJ)
	@printf "\n\t\t\t\t\t\t      $(RED)$(NAME) $(GREEN) 𝘾 𝙍 𝙀 𝘼 𝙏 𝙀 𝘿  ✅ \n"


bonus: $(OBJ_BONUS)  $(NAME) ./libft.h
	@ar rcs $(NAME) $(OBJ_BONUS)

$(PATH_OBJ)%.o:./%.c
	@mkdir -p $(PATH_OBJ)
	@$(CC) -c $< -o $@
	@printf "\t\t$(SILVER)[$(PURPLE)Object file of $(WHITE)$< $(BLUE)  ======>  $(WHITE)$(PATH_OBJ)$(notdir $@)   $(RED)>>>>$(GREEN)🅳 🅾 🅽 🅴 $(RED)<<<<$(SILVER)] $(GREEN)         🅲  🆁  🅴  🅰  🆃  🅴  🅳\n\n" 

clean:
	@rm -rf $(PATH_OBJ)
	@printf "\n\t$(BLUE)|🤧 - 🤧 - 🤧 - 🤧 - 🤧 - 🤧|\t$(RED)𝘾 𝙇 𝙀 𝘼 𝙉 𝙄 𝙉 𝙂   𝘼 𝙍 𝙀   𝘾 𝙊 𝙈 𝙋 𝙇 𝙀 𝙏 𝙀 𝘿\t$(YELLOW)|✅ - ✅ - ✅ - ✅ - ✅ - ✅|\n\n"

fclean: clean
	@rm -f $(NAME)
	@printf "\n\t$(YELLOW)|🚮 - 🚮 - 🚮 - 🚮 - 🚮 - 🚮|\t$(RED)𝙁 𝙊 𝙍 𝘾 𝙀   𝘾 𝙇 𝙀 𝘼 𝙉 𝙄 𝙉 𝙂   𝘼 𝙍 𝙀   𝘾 𝙊 𝙈 𝙋 𝙇 𝙀 𝙏 𝙀 𝘿    $(BLUE)|✅ - ✅ - ✅ - ✅ - ✅ - ✅|\n\n"; \


re: fclean bonus all
	@printf "\n\t\t\t$(YELLOW)               ==$(GREEN)---------------------------------------------------$(YELLOW)== $(BLUE)\n"
	@printf "\t\t\t$(YELLOW)               ||$(GREEN)---------------------------------------------------$(YELLOW)||\n"
	@printf "\t\t\t$(YELLOW)               ||$(GREEN) 𝙍 𝙀 - 𝙈 𝘼 𝙆 𝙄 𝙉 𝙂   𝘼 𝙍 𝙀   𝘾 𝙊 𝙈 𝙋 𝙇 𝙀 𝙏 𝙀 𝘿   ✅$(YELLOW)||\n"
	@printf "\t\t\t$(YELLOW)               ||$(GREEN) 𝙍 𝙀 - 𝙈 𝘼 𝙆 𝙄 𝙉 𝙂   𝘼 𝙍 𝙀   𝘾 𝙊 𝙈 𝙋 𝙇 𝙀 𝙏 𝙀 𝘿   ✅$(YELLOW)||\n"
	@printf "\t\t\t$(YELLOW)               ||$(GREEN) 𝙍 𝙀 - 𝙈 𝘼 𝙆 𝙄 𝙉 𝙂   𝘼 𝙍 𝙀   𝘾 𝙊 𝙈 𝙋 𝙇 𝙀 𝙏 𝙀 𝘿   ✅$(YELLOW)||"
	@printf "\n\t\t\t$(YELLOW)               ||$(GREEN)---------------------------------------------------$(YELLOW)||\n"
	@printf "\t\t\t$(YELLOW)               ==$(GREEN)---------------------------------------------------$(YELLOW)== $(BLUE)\n\n\n\n"


.PHONY: all clean fclean re bonus
