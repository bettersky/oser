;ds:起始段地址
;bx:起始偏移地址
;cx:长度，单位是字节
;即，从DS:BX处开始打印，打印长度为CX个字节
print_memory:
pusha	
	mov ah,0xe
	print_memory_begin:
		cmp cx,0
		jz print_memory_end
		

		mov dl,[bx]

		mov al,dl

		shr al,4
			   cmp al,10
			   jnb notBelowTen 
			   add al,48
			   jmp do_print
			   notBelowTen:
				    add al,55   
			   do_print:		
				int 0x10
			 
		mov al,dl
		and al,0xf
			   cmp al,10
			   jnb notBelowTen2 
			   add al,48
			   jmp do_print2
			   notBelowTen2:
				    add al,55   
			   do_print2:		
				int 0x10
			   mov al,' '
			   int 10h
	     	
		dec cx
		inc bx
		jmp print_memory_begin
	print_memory_end:
	
popa
ret

