CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

TARGET = sistempinjamalat
OBJS = main.c \
       admin/adminfunction.c \
       fileio/fileio.c \
       login/login.c \
       user/userfunction.c \
       utils/utils.c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)


clean:
	# Khusus Windows
	del /f /q $(TARGET).exe $(OBJS) 2>nul || (exit 0)

	# Khusus Linux
	# rm -f $(TARGET) $(OBJS)