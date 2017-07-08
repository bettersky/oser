#include "kernel.h"

GDT_DESCRIPTOR gdt[3]; 
DESCRIPTOR_REGISTER gdt_descriptor;
unsigned long gdt_address;
void gdt_init(){
//reserved seg --begin
	gdt[0].segment_limit_low=0;
	gdt[0].base_address_low=0;
	gdt[0].base_address_middle=0;
	gdt[0].uname1=0;
	gdt[0].uname2=0;
	gdt[0].base_address_hight=0;
//reserved seg --end
//code seg --begin
	gdt[1].segment_limit_low=0xffff;
	gdt[1].base_address_low=0x0;
	gdt[1].base_address_middle=0;
	gdt[1].uname1=0x9A;
	gdt[1].uname2=0xCF;
	gdt[1].base_address_hight=0;
//code seg --end
//data seg --begin
	gdt[2].segment_limit_low=0xffff;
	gdt[2].base_address_low=0;
	gdt[2].base_address_middle=0;
	gdt[2].uname1=0x92;
	gdt[2].uname2=0xCF;
	gdt[2].base_address_hight=0;
//data seg --end
//set the gdt descriptor --begin
	gdt_address=(unsigned long)gdt;
	gdt_descriptor.size_low=0x17;
	gdt_descriptor.size_high=0x0;
	gdt_descriptor.address_1=gdt_address&0xff;
	gdt_descriptor.address_2=(gdt_address&0xff00)>>8;
	gdt_descriptor.address_3=(gdt_address&0xff0000)>>16;
	gdt_descriptor.address_4=(gdt_address&0xff000000)>>24;
//set the gdt descriptor --end
//
//load the gdt --begin	
asm("cli");
asm("lgdt %0\n\t"
	:"=m"(gdt_descriptor));
//load the gdt --end	
}
