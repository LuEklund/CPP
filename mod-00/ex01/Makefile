NAME = phonebook

FLAGS = -Wall -Werror -Wextra -I Includes -std=c++98

SRC = main.cpp ContactClass.cpp PhoneBookClass.cpp

SRC_DIR = src/
OBJ_DIR = obj/

HEADER = Includes/Contact.hpp Includes/PhoneBook.hpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))


all : $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	c++ $(FLAGS) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $@ 

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all