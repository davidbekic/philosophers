TARGET_EXEC := philo

BUILD_DIR := ./build
SRC_DIRS := ./src

NAME :=	$(TARGET_EXEC)

all:	$(NAME)

SRCS := $(shell find $(SRC_DIRS) -name '*.c')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $../$(NAME) 
	@echo "\033[92m${bold}COMPILED!🧽\033[0m"	

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

fclean:		clean
	rm -f $(NAME)
	@echo "\033[92m${bold}CLEAN!🧽\033[0m"	

re:	fclean all

.PHONY: all re clean fclean

-include $(DEPS)
