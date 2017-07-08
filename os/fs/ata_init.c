#include "../drivers/inline_func.h"

void ata_init(unsigned short base,unsigned short ctrl,unsigned char selector){
	unsigned char feed;
//stop current drive from sending interrupts --beign
	feed=inb(ctrl+2);
	feed=feed|0x1;
	outb(ctrl+2,feed);
	//stop current drive from sending interrupts --end

//select drive --begin
	outb(base+6,selector);
	sleep(4);//delay
	//select drive --end
	



}
