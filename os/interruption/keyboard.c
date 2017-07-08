#include "interruption.h"
#include "../drivers/inline_func.h"
#include "../drivers/drivers.h"
static char key_map[0xff]={'n'};
void keyboard(){
//asm("hlt");
	asm("pushal");
//scan code mapping to ascii--begin
	key_map[0x1e]='a';
	key_map[0x30]='b';
	key_map[0x2e]='c';
	key_map[0x20]='d';
	key_map[0x12]='e';
	key_map[0x21]='f';
	key_map[0x22]='g';
	key_map[0x23]='h';
	key_map[0x17]='i';
	key_map[0x24]='j';
	key_map[0x25]='k';
	key_map[0x26]='l';
	key_map[0x32]='m';
	key_map[0x31]='n';
	key_map[0x18]='o';
	key_map[0x19]='p';
	key_map[0x10]='q';
	key_map[0x13]='r';
	key_map[0x1f]='s';
	key_map[0x14]='t';
	key_map[0x16]='u';
	key_map[0x2f]='v';
	key_map[0x11]='w';
	key_map[0x2d]='x';
	key_map[0x15]='y';
	key_map[0x2c]='z';
	key_map[0x0b]='0';
	key_map[0x2]='1';
	key_map[0x3]='2';
	key_map[0x4]='3';
	key_map[0x5]='4';
	key_map[0x6]='5';
	key_map[0x7]='6';
	key_map[0x8]='7';
	key_map[0x9]='8';
	key_map[0xa]='9';
	key_map[0x33]=',';
	key_map[0x39]='$';
	key_map[0xe]=0x8;  //Backspace key
	key_map[0x1c]=0xd; //Enter key
//scan code mapping to ascii --end

//read the keyboard buffer --begin
	unsigned char key;
	key=inb(0x60);
//read the keyboard buffer --end

//print the character --begin	
	if(key<0x80){
		print_char(key_map[key]);
	}
//print the character --end

//interrupt return --begin
//asm("hlt");
	outb(0x20,0x20);//turn on interrupt
	asm("popal");
	asm("leave");
	asm("iret");
//interrupt return --end	
}
