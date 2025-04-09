;f=4*a+b/c-6, если a>=b
;f=6-c*(a+b), если  b>=c
;f=3/a-(7+b)*5, если c>=a 

code SEGMENT

        ASSUME CS:code,   DS:code
        ORG    100h
      
      JMP start
        
      C:INC CH
        JMP R
        
start:     
        MOV    BH, 10    ;Начальное число
        MOV    BL, 10    ;Делитель
        
      F:MOV    AL, BH
        CBW    
        DIV    BL
        ADD    AL, AH
        CMP    AL,k
        JE     C
        
      R:INC    BH
        CMP    BH, 99    ;Условие перехода
        JLE    F
        
        MOV AL, CH
        RET
          
        k      DB 7

code ENDS
END start
