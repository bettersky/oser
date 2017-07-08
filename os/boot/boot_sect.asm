[org 0x7c00]
mov ch,16;make the cursor invisible
mov ah,1
int 10h
read:    
	mov cx,3
	try_read:
		mov ah,0x42
		mov dl,0x80

		mov si,0x0
		mov ds,si
		mov si,0x8000
		mov byte [si],0x10  ;size of packet (10h or 18h)
		mov word [si+2],0x30  ;number of blocks to transfer (max 007Fh for Phoenix EDD)
		mov dword[si+4],0x9c00  ;transfer buffer
		mov dword[si+8],0x1 ;starting absolute block number
		mov dword[si+12],0x0
		int 0x13  
		jnc read_end 
		
		
		dec cx
		cmp cx,0
		jz disk_error
		jmp try_read	
read_end:




mov bp,0x9000 ;set the stack
mov sp,bp
mov bx,MSG_REAL_MODE
;call print_string


call switch_to_pm
jmp $

disk_error:
	mov bx,ERR
	call print_string

jmp $
%include "./boot/include/print_string.asm"

%include "./boot/include/gdt.asm"
	
%include "./boot/include/switch_to_pm.asm"

%include "./boot/include/print_memory.asm"
	
MSG_REAL_MODE:
	db "Start in 16-bit real mode",0

ERR:
db "Disk Eroor:",0

%include "./boot/include/print_hex.asm"

times 0200h - 2 - ($ - $$)  db 0    ; NASM directive: zerofill up to 510 bytes
dw 0AA55h
