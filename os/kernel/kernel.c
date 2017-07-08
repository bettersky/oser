#include "kernel.h"
#include "../drivers/drivers.h"
extern row,column;
void main(){
row=0;column=0;
	gdt_init();
	idt_init();

	test();

	while(1){
		asm("hlt");
	}

}
