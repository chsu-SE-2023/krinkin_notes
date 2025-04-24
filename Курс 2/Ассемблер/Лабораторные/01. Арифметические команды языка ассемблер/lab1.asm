; -a * b + (c - 1) / d + 1

code SEGMENT

        ASSUME   CS:code,   DS:code
        ORG      100h

start:     
        
        MOV      AX, c
        SUB      AX, 1       ; (c - 1)
        MOV      BX, d
        IDIV     BX          ; (c - 1) / d
        MOV      ost, DX
        ADD      AX, 1       ; (c - 1) / d + 1
        MOV      CX, AX
        MOV      AX, a      
        NEG      AX         ; -a
        MOV      BX, b
        IMUL     b           ; -a * b
        ADD      AX, CX      ; -a * b + (c - 1) / d + 1
        MOV      result, AX
        
        RET
          
        a        DW 5
        b        DW 7 
        c        DW -6
        d        DW 2
        result   DW ?
        ost      DW ?

code ENDS
END start