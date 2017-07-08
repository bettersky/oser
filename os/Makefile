C_SOURCES = $(wildcard kernel/*.c drivers/*.c interruption/*.c fs/*.c)
ASM_SOURCES = $(wildcard asm/*.asm)
#HEADERS = $(wildcard kernel/*.h drivers/*.h interruption/*.h)
OBJ = ${C_SOURCES:.c=.o}
OBJ1= ${ASM_SOURCES:.asm=.o}
os-image: boot/boot_sect.bin kernel.bin
	cat $^ > os-image
kernel.bin: kernel/kernel_entry.o ${OBJ} ${OBJ1}
	ld -o $@ -Ttext 0x9c00 $^ --oformat binary

%.o : %.c 
#${HEADERS}
	gcc -ffreestanding -c $< -o $@

#Assemble the kernel_entry
%.o : %.asm
	nasm $< -f elf -o $@

%.bin : %.asm
	nasm $< -f bin -I '../../16bit/' -o $@

clean:
	rm -fr *.bin *.dis *.o os-image
	rm -fr kernel/*.o boot/*.bin drivers/*.o fs/*.o
	rm -fr asm/*.o
	rm -rf interruption/*.o
	
