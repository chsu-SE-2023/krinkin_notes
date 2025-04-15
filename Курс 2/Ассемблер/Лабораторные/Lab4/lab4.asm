; i=1 П i^j-1

code SEGMENT

        ASSUME   CS:code, DS:code
        ORG      100h

start: 
        MOV CX, N       ;Настрока цикла (N раз)
        MOV BL, 1       ;i=1
        
        F: JCXZ end
           MOV AL, BL   ;i
           CBW
           MOV BH, CL
           MOV CX, j
           DEC CX
           MOV tmp, AX
           MOV AX, 1      
           A: IMUL tmp   ;i**(j-1)
              LOOP A                            
           MOV CL, BH
           IMUL result 
           MOV result, AX
           INC BL
           LOOP F
           
   end: RET
        
        N        DW 0  
        j        DW 2
        result   DW 1
        tmp      DW ?

code ENDS
END start
