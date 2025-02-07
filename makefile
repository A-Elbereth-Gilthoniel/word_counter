TARGET = prog

PREF_SRC = ./src/
PREF_OBJ = ./obj/

CFLAGS = -O0 -g -Wall
CC = gcc

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))


$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(CFLAGS)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	$(CC) -c $< -o $@ $(CFLAGS)


.PHONY : clean
clean :
	rm -f $(PREF_OBJ)*.o $(TARGET)
