CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

TARGET = sistempinjamalat
OBJS = main.o \
       adminfunction.o \
       fileio.o \
       login.o \
       userfunction.o \
       utils.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

adminfunction.o: admin/adminfunction.c admin/adminfunction.h
	$(CC) $(CFLAGS) -c admin/adminfunction.c -o adminfunction.o

fileio.o: fileio/fileio.c fileio/fileio.h
	$(CC) $(CFLAGS) -c fileio/fileio.c -o fileio.o

login.o: login/login.c login/login.h
	$(CC) $(CFLAGS) -c login/login.c -o login.o

userfunction.o: user/userfunction.c user/userfunction.h
	$(CC) $(CFLAGS) -c user/userfunction.c -o userfunction.o

utils.o: utils/utils.c utils/utils.h
	$(CC) $(CFLAGS) -c utils/utils.c -o utils.o

clean:
	# Khusus Windows
	del /f /q $(TARGET).exe $(OBJS) 2>nul || (exit 0)

	# Khusus Linux
	# rm -f $(TARGET) $(OBJS)