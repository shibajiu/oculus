src = $(wildcard src/*.c)
obj = $(src:.c=.o)
bin = oculus2

CFLAGS = -pedantic -Wall -g `pkg-config --cflags sdl2`
LDFLAGS = $(libgl) `pkg-config --libs sdl2` -lOVR -ldl $(libsys)

ifeq ($(shell uname -s), Darwin)
	libgl = -framework OpenGL -lGLEW
else
	libgl = -lGL -lGLU -lGLEW
	libsys = -lX11
endif

$(bin): $(obj)
	$(CC) -o $@ $(obj) $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) $(bin)
