; -a | 7 * (b & 3) + ((c ^ 4) - 1) / !d + 1

code SEGMENT

        ASSUME   CS:code,   DS:code
        ORG      100h

start:     
        MOV      BL, b       
        MOV      BH, 3
        AND      BL, BH      ; (b & 3)
        MOV      AL, 7
        IMUL     BL          ; 7 * (b & 3)
        MOV      AH, a
        NEG      AH          ; -a
        OR       AH, AL      ; -a | 7 * (b & 3)
        MOV      CL, AH      ; -a | 7 * (b & 3) (in CL)
        MOV      BL, c
        MOV      BH, 4
        XOR      BL, BH      ; (c ^ 4)
        SUB      BL, 1       ; ((c ^ 4) - 1) (in BL)
        MOV      BH, d
        NOT      BH          ; !d
        MOV      AL, BL
        CBW                  ; ((c ^ 4) Ö 1) (in AX)
        IDIV     BH          ; ((c ^ 4) Ö 1) / !d
        ADD      AX, 1       ; ((c ^ 4) Ö 1) / !d + 1
        MOV      BX, AX      ; ((c ^ 4) Ö 1) / !d + 1 (in BX)
        MOV      AL, CL      
        CBW                  ; -a | 7 * (b & 3) (in AX)
        ADD      AX, BX

        MOV      result, AX
        
        RET
          
        a        DB -5
        b        DB 7 
        c        DB 5
        d        DB 2
        result   DW ?

code ENDS
END start
