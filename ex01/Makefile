# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: jschott <jschott@student.42.fr>			+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2023/10/09 10:31:55 by jschott		   #+#	#+#			  #
#	Updated: 2024/02/20 16:08:29 by jschott		  ###   ########.fr		#
#																			  #
# **************************************************************************** #

NAME = Forms2Fill

# SOURCES
SRC_PATH =	src/
SRC_FILES =	main.cpp \
			Bureaucrat.cpp \
			Form.cpp
SRCS := $(addprefix $(SRC_PATH), $(SRC_FILES))

# OBJECTS
OBJ_PATH = obj/
OBJS = $(addprefix $(OBJ_PATH), $(SRC_FILES:.cpp=.o))

# INCLUDES
INCL_PATH =	include/
HDRS = 		Bureaucrat.hpp \
			Form.hpp
INCLDS := $(addprefix $(INCL_PATH), $(HDRS))

# COMPILATION CMNDS
CC = c++
FT_FLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address
INCLUDES = -I $(INCL_PATH)

all: $(NAME)
	@echo "\n\nCompilation finished successfully\nHave fun breaking things\n"

$(NAME): $(OBJS)
	@echo "\n\nCompiling Executable\n"
	$(CC) $(FT_FLAGS) $(INCLUDES) -o $(NAME) $(OBJS)
	@echo "\nExecutable compiled\n\n"

${OBJ_PATH}:
				@if [ ! -d "${OBJ_PATH}" ]; \
				then mkdir -p "${OBJ_PATH}"; \
				fi

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp $(INCLDS)
	@mkdir -p $(dir $@)
	$(CC) $(FT_FLAGS) $(INCLUDES) -c $< -o $@

clean: 
	@rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
