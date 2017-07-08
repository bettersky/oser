
kernel.bin:kernel_entry.o kernel.o
	ld -o kernel.bin -Ttext 0x9c00  $^ --oformat binary

kernel_entry.o:kernel_entry.asm
	nasm kernel_entry.asm -f elf -o $@
kernel.o:kernel.c
	gcc -ffreestanding -c kernel.c -o kernel.o
clean:
	rm -rf *.bin *.o
