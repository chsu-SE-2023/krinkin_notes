; Записать в d наибольшее из a, b, c, d

code SEGMENT

        ASSUME   CS:code,   DS:code
        ORG      100h
        
CA:     MOV  d, AL
CB:     MOV  d, AL
CC:     MOV  d, AL

start:     
        MOV  AL, a
        CMP  AL, d
        JA   CA
     
        MOV  AL, b
        CMP  AL, d
        JA   CB
      
        MOV  AL, c
        CMP  AL, d
        JA   CC
     
        RET
          
        a        DB 3
        b        DB 1 
        c        DB 5
        d        DB 2

code ENDS
END start
