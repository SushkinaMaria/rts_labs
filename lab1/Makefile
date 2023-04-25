src_dir = src
debug_dir = debug
release_dir = release
build_dir = $(release_dir)/build
group = I993
name = Sushkina Mariya

CC = gcc
MD = mkdir

build_dir_guard = @$(MD) -p $(build_dir)

CFLAGS = \
	-fpic \
	-DGROUP='"$(group)"' -DNAME='"$(name)"' \
	$(NULL)

CFLAGS_LIB = -shared

SOURCES = \
	author.c \
	$(NULL) 

ifeq ($(MAKECMDGOALS), debug)
	CFLAGS += -g
	build_dir = $(debug_dir)/build
endif

OBJECTS = $(patsubst %.o, $(build_dir)/%.o, $(SOURCES:.c=.o))

all: libauthor

debug: libauthor

libauthor: $(OBJECTS)
	$(CC) $(CFLAGS) $(CFLAGS_LIB) $(OBJECTS) -o $(release_dir)/$@.so

$(build_dir)/%.o: $(src_dir)/%.c
	$(build_dir_guard)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(release_dir) $(debug_dir) libauthor
