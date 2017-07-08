;print a byte in bl
print_hex:
	;pusha
	mov ah,0xe
	mov al,bl	  
     	shr al,4  ;get first four bits
    	call do_print_hex_print_hex 
    	mov al,bl   ;get 2nd four bits
     	and al,0xf
     	call do_print_hex_print_hex 
	;popa
ret

	do_print_hex_print_hex :  
	   cmp al,10
	   jnb notBelowTen_print_hex 
	   add al,48
	   jmp do_print_print_hex 
	   notBelowTen_print_hex :
		    add al,55   
	   do_print_print_hex :		
		int 0x10
	ret


