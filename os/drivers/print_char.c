
int row=0;
int column=0;
void print_char(unsigned char x){
	
	char* const video_base=(char *)0xb8000;
	//row=0;column=0;
	if(x==0xd){  //x is enter key
		*(video_base+row*160+column*2)=0;  //clear current cur
		*(video_base+row*160+column*2+1)=0x0;
		column=0;
		row++;
	}
	else if(x==0x8){  //x is backspace key
		*(video_base+row*160+column*2)=0;  //clear current cur
		*(video_base+row*160+column*2+1)=0x0;
		//make the cur back
		if(column==0){
			if(row>0){
				column=79;
				row--;
			}
			
		}
		else{
			column--;
		}
		//clear the current char
		*(video_base+row*160+column*2)=0;
		*(video_base+row*160+column*2+1)=0x0;
		

	}
	else{ //x is a character to be dispalayed				
		*(video_base+row*160+column*2)=x;
		*(video_base+row*160+column*2+1)=0x0a;


		column++;
	}

	if(column==80){// new line
		column=0;
		row++;
	}
	if(row==25){ //screen scroll
			int i,j;
			for(i=0;i<24;i++){//change every line's content to it's next line's
				for(j=0;j<80;j++){
					*(video_base+i*160+j*2)=*(video_base+(i+1)*160+j*2);
					*(video_base+i*160+j*2+1)=*(video_base+(i+1)*160+j*2+1);
				}
			}
			for(j=0;j<80;j++){//clean the 25th line
				*(video_base+24*160+j*2)=0;
			}
				
			row--;
	
	}


	*(video_base+row*160+column*2)=95;//print the bottom line(cur)
	*(video_base+row*160+column*2+1)=0xda;

}

void print_hex(unsigned char x){
	
	unsigned char a=x>>4;
	if(a<10){
		a=a+48;
	}
	else{
		a=a+55;
	}
	print_char(a);
	
	a=x&0xf;
	if(a<10){
		a=a+48;
	}
	else{
		a=a+55;
	}
	print_char(a);
}

void print_string(unsigned char *str){
	while(*str!=0){
		print_char(*str);
		str++;
	}
}

void print_int_as_hex(unsigned int x){
	print_string("0x\0");
	unsigned char a=x>>24;
	print_hex(a);
	a=(x&0xff0000)>>16;
	print_hex(a);
	a=(x&0xff00)>>8;
	print_hex(a);
	a=x&0xff;
	print_hex(a);

}
void print_int(unsigned int x){
	if(x==0){
		 print_char('0');
		 return;
	}
	unsigned char arr[32]={0};
	int remainder;
	int i=31;	
	while(x!=0){
		remainder=x%10;
		x=x/10;
		arr[i]=remainder+48;
		i--;		
	}
	int begin;
	for(i=0;i<32;i++){
		if( arr[i]!='0'){
			begin=i;	
		}
	}
	for(i=begin;i<32;i++){
		print_char(arr[i]);
	}


}
void clear_screen(){
	int i;
	for(i=0;i<80*25;i++){

	}


}
