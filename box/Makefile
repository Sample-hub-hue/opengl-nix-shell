CC=/nix/store/4krab2h0hd4wvxxmscxrw21pl77j4i7j-gcc-13.3.0/bin/g++
CFLAGS=-I/nix/store/lw21wr626v5sdcaxxkv2k4zf1121hfc9-glibc-2.40-36-dev/include \
       -I/nix/store/4krab2h0hd4wvxxmscxrw21pl77j4i7j-gcc-13.3.0/include/c++/13.3.0 \
       -I./include
LDFLAGS=-L/nix/store/lw21wr626v5sdcaxxkv2k4zf1121hfc9-glibc-2.40-36-dev/lib \
        -L/nix/store/4krab2h0hd4wvxxmscxrw21pl77j4i7j-gcc-13.3.0/lib
SRC=src/main.cpp src/glad.c
EXEC=OpenGLProject

all:
	$(CC) $(SRC) -o $(EXEC) $(CFLAGS) $(LDFLAGS) -lglfw -lGL -ldl -lX11 -pthread

