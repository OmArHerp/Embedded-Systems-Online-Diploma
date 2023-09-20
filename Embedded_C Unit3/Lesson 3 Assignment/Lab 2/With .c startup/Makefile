#@copyright : OmArHerp
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3  -gdwarf-2
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=Lab2_Cortex_M3

all: $(Project_name).bin
	@echo "======Build is Done======"

%.o: %.c 
	$(CC)gcc.exe -c -mthumb $(CFLAGS) $(INCS)   $< -o $@

$(Project_name).elf : $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS)  $(AsOBJ) $(OBJ) -o $@ -Map=Map_file.map 

$(Project_name).bin: $(Project_name).elf 
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin
	
clean:
	rm *.elf *.bin