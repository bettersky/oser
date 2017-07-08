[bits 32]
global asmbegin
global outICW
global asm_iret

asmbegin:
	mov ecx,600000
	delay:	
		nop
	loop delay	
ret

;print begin
print:
mov al,'I'
mov ah,0xda
mov [0xb8004],ax
ret
;print end



	
