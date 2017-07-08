#include "kernel.h"
#include "../interruption/interruption.h" //access the function keyboard() 
#include "../drivers/inline_func.h"

IDT_DESCRIPTOR idt[256]; 
unsigned long idt_address;
unsigned long idt_keyboard_address;
unsigned long idt_offset=0x8;
DESCRIPTOR_REGISTER idt_descriptor;
void idt_init(){
//init the 8289A  --begin
	outb(0x20,0x11);
	outb(0xa0,0x11);

	outb(0x21,0x20);
	outb(0xa1,0x28);

	outb(0x21,0x4);
	outb(0xa1,0x2);

	outb(0x21,0x1);
	outb(0xa1,0x1);
//init the 8289A  --end
//set the mask bit --begin
	outb(0x21,0xfd);//only keyboard interrupt allowed
	outb(0xa1,0xff);
//set the mask bit --end
//init the 32th idt --begin 
//which presents the keyboard interrupt, and make it point to keyboard handler 	
	idt_keyboard_address=(unsigned long)keyboard;//get the keybard handler address
		
	idt[0x21].offset_low=idt_keyboard_address&0xffff;
	idt[0x21].segment_selector=idt_offset; //to find the code segment
	idt[0x21].reserved=0;
	idt[0x21].type=0x8e;
	idt[0x21].offset_high=idt_keyboard_address>>16;
//init the 32th idt --end 
//init the idt descriptor --begin
	idt_address=(unsigned long)idt;
	idt_descriptor.size_low=0x0;
	idt_descriptor.size_high=0x8;
	idt_descriptor.address_1=idt_address&0xff;
	idt_descriptor.address_2=(idt_address&0xff00)>>8;
	idt_descriptor.address_3=(idt_address&0xff0000)>>16;
	idt_descriptor.address_4=(idt_address&0xff000000)>>24;
//init the idt descriptor --end
//load idt descriptor --begin	
	asm("lidt %0\n\t"
		"sti"
		:"=m"(idt_descriptor)
	   );
//load idt descriptor --end
}


