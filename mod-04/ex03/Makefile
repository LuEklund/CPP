NAME = run

FLAGS = -Wall -Werror -Wextra -I Includes -std=c++98 
DEBUG = 
# -g -fsanitize=address
SRC = main.cpp \
		AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		Character.cpp \
		MateriaSource.cpp \
		Trash.cpp
		

OBJ_DIR = obj/
SRC_DIR = src/

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

all : $(NAME) 

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	c++ $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJ_DIR) $(OBJ)
	c++ $(FLAGS) $(DEBUG) $(OBJ) -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all