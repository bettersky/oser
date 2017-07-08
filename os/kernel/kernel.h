typedef struct {	
	unsigned int offset_low:16;
	unsigned int segment_selector:16;
	unsigned int reserved:8;
	unsigned int type:8;
	unsigned int offset_high:16;
}IDT_DESCRIPTOR;
typedef struct {	
	unsigned int segment_limit_low:16;
	unsigned int base_address_low:16;
	unsigned int base_address_middle:8;
	unsigned int uname1:8;
	unsigned int uname2:8;
	unsigned int base_address_hight:8;
}GDT_DESCRIPTOR;
typedef struct{
	unsigned char size_low;
	unsigned char size_high;
	unsigned char address_1;
	unsigned char address_2;
	unsigned char address_3;
	unsigned char address_4;


}DESCRIPTOR_REGISTER;
void idt_init();
int test();

