
unsigned int timer(){
	unsigned int low,high;
	asm("rdtscp"
		:"=a"(low),"=d"(high)
		);
	return low;
	
}
unsigned int sleep(unsigned long ms){ //base 400000 for about 1ms(>1ms)
	int i;
	int base=40000;
	for(i=0;i<ms*base;i++){
	}	
}
