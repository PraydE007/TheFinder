NAME = finder

# SOFTWARE CODE
INC = inc/header.h
FILES = main.c \
	mx_load_map.c \

SRCS = $(addprefix src/, $(FILES))

# FLAGS
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
SDL = `pkg-config --cflags --libs sdl2` -lSDL2_image
JSON = `pkg-config --cflags --libs json-c`

all: $(NAME)

$(NAME): install

install:
#	@echo $(SDL)
	@clang $(CFLAGS) $(SDL) $(JSON) -I inc $(SRCS) -o $(NAME)

uninstall:
	@rm -rf $(NAME)

# clean:
# 	@rm -rf header.h
# 	@rm -rf main.c

reinstall: all
