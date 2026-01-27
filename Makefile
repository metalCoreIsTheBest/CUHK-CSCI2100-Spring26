CC := gcc
CFLAGS := -Wall -O2
LDFLAGS := -L./lib -lcsci2100
AR := ar
ARFLAGS := rcs

LIBSRC := $(wildcard src/*.c)
LIBOBJ := $(patsubst src/%.c, lib/%.o, $(LIBSRC))
LIBTARGET := lib/libcsci2100.a


lib: $(LIBTARGET)

$(LIBTARGET): $(LIBOBJ)
    $(AR) $(ARFLAGS) $@ $^

lib/%.o: src/%.c
    if ! [ -d lib ] then; mkdir lib; fi
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    -rm $(LIBOBJ) 2> /dev/null
    -rm $(LIBTARGET) 2> /dev/null


.PHONY: lib clean

