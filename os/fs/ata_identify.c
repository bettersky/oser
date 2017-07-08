#include "../drivers/inline_func.h"
extern unsigned char read_buf[];

void ata_identify(unsigned short base,unsigned short ctrl,unsigned char selector,unsigned char reg7,unsigned char reg6,unsigned char reg5,unsigned char reg4,unsigned char reg3,unsigned char reg2,unsigned char reg1,unsigned char reg0){

	unsigned char feed;//used to store byte read from port

//poll the status, if not BSY  --begin
	
	
	//poll the status, if not BSY  --begin
//command --begin
	outb(base+2,0);
	outb(base+3,0);
	outb(base+4,0);
	outb(base+5,0);

	outb(base+7,0xec);
	
	//sleep(4);//delay
	//command --end
//polling --begin
	while(1){
		feed=inb(base+7);
		if(feed&0x1){
			print_string(" er   \0");
			print_hex(feed);
			break;
		}
		if(!(feed&0x80)&&(feed&0x08)){
			//print_string(" ok   \0");
			//print_hex(feed);
			break;
		}
	}
	//polling --end
//read --begin
	int i;
	unsigned short read;
	for(i=0;i<256;i++){
		read=inw(base);//the byte 		
		read_buf[2*i]=*(char *)(&read);
		read_buf[2*i+1]=*((char *)(&read)+1);
	}
//read --end
}
