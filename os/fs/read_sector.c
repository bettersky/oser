#include "../drivers/inline_func.h"
extern unsigned char read_buf[];
extern unsigned char arr[];
extern  int x;
void ata_read(unsigned short base,unsigned short ctrl,unsigned char selector,unsigned char reg7,unsigned char reg6,unsigned char reg5,unsigned char reg4,unsigned char reg3,unsigned char reg2,unsigned char reg1,unsigned char reg0){

	unsigned char feed;//used to store byte read from port

//poll the status, if not BSY  --begin
	
	//poll the status, if not BSY  --begin
//command --begin
	outb(base+6,reg6);
	outb(base+2,0);//sector count high byte
	outb(base+3,0);//LBA4
	outb(base+4,0);//LBA5
	outb(base+5,0);//LBA6
	outb(base+2,reg2);//sector count low byte
	outb(base+3,reg3);//LBA1
	outb(base+4,reg4);//LBA2
	outb(base+5,reg5);//LBA3

	outb(base+7,reg7);

	
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
