TARGET = prog

PREF_SRC = ./src/
PREF_OBJ = ./obj/
PREF_FILE = ./files/
DELF = .\obj\

SRC = $(wildcard $(PREF_SRC)*.c)
OBJ = $(patsubst $(PREF_SRC)%.c, $(PREF_OBJ)%.o, $(SRC))


$(TARGET) : $(OBJ)
	gcc $(OBJ) -o $(TARGET)

$(PREF_OBJ)%.o : $(PREF_SRC)%.c
	gcc -c $< -o $@


.PHONY : clean
clean :
	rm -f $(PREF_OBJ)*.o $(TARGET)