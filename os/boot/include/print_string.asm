print_string:
	print_string_begin:
		mov ah,0xe
		mov al,[bx]
		cmp al,0x0
		jz print_string_end
		int 0x10
		inc bx
		jmp print_string_begin
	print_string_end:
ret	
