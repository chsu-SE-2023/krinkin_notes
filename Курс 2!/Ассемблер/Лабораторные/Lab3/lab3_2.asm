;f=4*a+b/c-6, если a>=b
;f=6-c*(a+b), если  b>=c
;f=3/a-(7+b)*5, если c>=a 

code SEGMENT

        ASSUME   CS:code,   DS:code
        ORG      100h
        
        JMP start
        
AB:     
        MOV    AX, 4
        IMUL   a       ;4*a
        MOV    CX, AX
        MOV    AX, b
        IDIV   c       ;b/c
        ADD    CX, AX  ;4*a+b/c
        SUB    CX, 6   ;4*a+b/c-6
        MOV    f, CX
        RET 
        
BC:                 
        MOV    AX, a
        ADD    AX, b   ;(a+b)
        IMUL   c       ;c*(a+b)
        MOV    BX, 6   
        SUB    BX, AX  ;6-c*(a+b)
        MOV    f, BX
        RET 
        
CA:     
        MOV    AX, b
        ADD    AX, 7   ;(7+b)
        MOV    BX, 5
        IMUL   BX      ;(7+b)*5
        MOV    BX, AX
        MOV    AX, 3
        IDIV   a       ;3/a
        SUB    AX, BX  ;3/a-(7+b)*5
        MOV    f, BX
        RET
        
start:     
        MOV    AX, a
        CMP    AX, b
        JAE    AB  
        
        MOV    AX, b
        CMP    AX, c
        JAE    BC
        
        MOV    AX, c
        CMP    AX, a
        JAE    CA
     
        RET
          
        a      DW 3
        b      DW 4 
        c      DW 5
        f      DW ?

code ENDS
END start
