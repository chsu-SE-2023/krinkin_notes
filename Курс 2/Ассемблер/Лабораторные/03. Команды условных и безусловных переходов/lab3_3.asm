;f=4*a+b/c-6, ���� a>=b
;f=6-c*(a+b), ����  b>=c
;f=3/a-(7+b)*5, ���� c>=a 

code SEGMENT

        ASSUME CS:code,   DS:code
        ORG    100h
      
      JMP start
        
      C:INC CH
        JMP R
        
start:     
        MOV    BH, 10    ;��������� �����
        MOV    BL, 10    ;��������
        
      F:MOV    AL, BH
        CBW    
        DIV    BL
        ADD    AL, AH
        CMP    AL,k
        JE     C
        
      R:INC    BH
        CMP    BH, 99    ;������� ��������
        JLE    F
        
        MOV AL, CH
        RET
          
        k      DB 7

code ENDS
END start
