TARGET_EXEC := philo

BUILD_DIR := ./build
SRC_DIRS := ./src

NAME :=	$(TARGET_EXEC)

all:	$(NAME)


# Find all the C and C++ files we want to compile
# Note the single quotes around the * expressions. Make will incorrectly expand these otherwise.
SRCS := $(shell find $(SRC_DIRS) -name '*.c')

# String substitution for every C/C++ file.
# As an example, hello.cpp turns into ./build/hello.cpp.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# String substitution (suffix version without %).
DEPS := $(OBJS:.o=.d)

# Every folder in ./src will need to be passed to GCC so that it can find header files
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
# Add a prefix to INC_DIRS. So moduleA would become -ImoduleA. GCC understands this -I flag
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CFLAGS := $(INC_FLAGS) -MMD -MP -Wall -Wextra -Werror


# The final build step.
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $../$(NAME) $(LDFLAGS)
	@echo "\033[92m${bold}COMPILED!🧽\033[0m"	

# Build step for C source
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

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)
