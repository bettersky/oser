static inline void outb(unsigned short port, unsigned char value){
	asm volatile("movw %1,%%dx\n\t"
			"outb %0, %%dx"
			: 
			:"a"(value), "d"(port) 
			);
}

static inline char inb(unsigned short port){
	unsigned char ret;
	asm volatile("movw %1,%%dx\n\t" 
			"inb %%dx, %0"
			:"=a"(ret) 
			: "r"(port)
			);
	return ret;
}
static inline void outl(unsigned short port, unsigned long value){
	asm volatile("movw %1,%%dx\n\t"
			"outl %0, %%dx"
			: 
			:"a"(value), "r"(port) 
			);
}
static inline unsigned long inl(unsigned short port){
	unsigned long value;
	asm volatile("movw %1,%%dx\n\t"
			"inl  %%dx,%0"
			:"=a"(value)
			:"r"(port) 
			);
	return value;
}

static inline unsigned short inw(unsigned short port){
	unsigned short value;
	asm volatile("movw %1,%%dx\n\t"
			"inw  %%dx,%0"
			:"=a"(value)
			:"r"(port) 
			);
	return value;
}
