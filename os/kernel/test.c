#include "kernel.h"
#include "../drivers/inline_func.h"
#define ata1_bar0 0x1630
#define ata1_bar1 0x1624
#define ata1_bar2 0x1628
#define ata1_bar3 0x1620

#define ata2_bar0 0x1688
#define ata2_bar1 0x163c
#define ata2_bar2 0x1680
#define ata2_bar3 0x1638

#define master_drive 0xA0
#define slave_drive 0xB0
#define read_buf_size 512
unsigned char read_buf[read_buf_size];

int test(){

int i,j,k;
//a=checkAllBuses();

	modify_bar(0x0,0x1f,0x5,ata1_bar0,ata1_bar1,ata1_bar2,ata1_bar3);
	modify_bar(0x0,0x1f,0x2,ata2_bar0,ata2_bar1,ata2_bar2,ata2_bar3);//this one will work
	ata_init(ata2_bar0,ata2_bar1,master_drive);
	ata_identify(ata2_bar0,ata2_bar1,master_drive,0xec,0,0,0,0,0,0,0);//identify
	unsigned long  *disk_capacity_pointer;
	unsigned long disk_capacity;
	disk_capacity_pointer=&read_buf[200];
	disk_capacity=(*disk_capacity_pointer)/1024*512/1024/1024;
	print_string("Disk capacity:\0");
	print_int_as_hex(disk_capacity);
	print_string(" GB\0");

	ata_read(ata2_bar0,ata2_bar1,master_drive,0x20,0x40,0,0,0,1,0,0);//read mbr
	
	//print_char(0xd);
	char *disk_part[4];
	disk_part[0]=&read_buf[0x1be];
	disk_part[1]=&read_buf[0x1ce];
	disk_part[2]=&read_buf[0x1de];
	disk_part[3]=&read_buf[0x1ee];
	for(i=0;i<4;i++){
		print_char(0xd);
		print_string("Partition \0");print_int(i+1);print_char(':');
		for(k=0;k<16;k++){
			print_char(' ');
			print_hex(*(disk_part[i]+k));
		}

	}
	
	//print
	
	for(i=0;i<0;i++){
		if(i%4==0){
			print_char(0xd);
			print_int_as_hex(i*4);
			print_string("    \0");
		}
		print_hex(read_buf[4*i]);
		print_char(' ');
		print_hex(read_buf[4*i+1]);
		print_char(' ');
		print_hex(read_buf[4*i+2]);
		print_char(' ');
		print_hex(read_buf[4*i+3]);
		print_char(' ');
		print_char(' ');

	}

return 0;

}

/*

//ide_test(0x1688,0x163c,0xA0);//02  ,this is where my disk works

//ide_test(0x1630,0x1624,0xA0); //05
//ide_test(0x1630,0x1624,0xB0);

//ide_test(0x1628,0x1620,0xA0);
//ide_test(0x1628,0x1620,0xB0);
//ide_test(0x1688,0x163c,0xB0);
//ide_test(0x1680,0x1638,0xA0);
//ide_test(0x1680,0x1638,0xB0);

*/
