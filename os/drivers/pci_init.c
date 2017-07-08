#include "../drivers/inline_func.h"
void modify_bar(unsigned char bus_number, unsigned char device_number,unsigned long function,unsigned long bar0,unsigned long bar1,unsigned long bar2,unsigned long bar3){
	unsigned long register_number; //2-7 bit		
	unsigned long addr;
//modify --begin
	register_number=4;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	outl(0xcfc,bar0);

	register_number=5;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	outl(0xcfc,bar1);

	register_number=6;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	outl(0xcfc,bar2);

	register_number=7;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	outl(0xcfc,bar3);
	
//modify --end

//print --begin
register_number=4;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	unsigned long bar00=inl(0xcfc);
	print_char(' ');
	print_int_as_hex(bar00);	

	register_number=5;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	unsigned long bar10=inl(0xcfc);
	print_char(' ');
	print_int_as_hex(bar10);	

	register_number=6;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	unsigned long bar20=inl(0xcfc);
	print_char(' ');
	print_int_as_hex(bar20);	

	register_number=7;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	unsigned long bar30=inl(0xcfc);
	print_char(' ');
	print_int_as_hex(bar30);	
	//print prog --begin
	register_number=2;
	addr=(bus_number<<16)|(device_number<<11)|(register_number<<2)
				|(function)<<8|((unsigned long)0x80000000);
	outl(0xcf8,addr);
	unsigned long prog=inl(0xcfc);
	print_char(' ');
	print_int_as_hex(prog);	
	//print prog --end
//print --end
	print_char(0xd);

}

