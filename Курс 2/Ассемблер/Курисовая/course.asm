; 3.7 (swap lines in file)

code SEGMENT

        ORG      100h
        JMP      main
        
fnew: ;(DX: filename) -> AX: file_id 
        MOV      CX, 00h
        MOV      AH, 3Ch
        INT      21h
        RET                     
        
fclose: ;(BX: file_id) -> None
        MOV      AH, 3Eh
        INT      21h
        RET
        
fopen: ;(DX: filename, AL: access) -> AX: file_id
        MOV      AH, 3Dh
        INT      21h
        RET
        
fread: ;(BX: file_id, CX: size) -> AX: readed bytes count
        MOV      AH, 3Fh
        MOV      DX, OFFSET fbuff
        INT      21h
        RET
        
fwrite: ;(BX: file_id, SI: offset, CX: size) -> AX: err
        MOV      AH, 40h
        MOV      DX, SI
        INT      21h
        RET
        
process: ;() -> None      
        MOV      SI, OFFSET fbuff
        MOV      sline_t, 0
        MOV      fline_t, 0
        ADD      SI, foffset
        
     L1:MOV      BX, [SI]
        INC      SI
        INC      fline_t ;first line size
        CMP      BL, 0Ah
        JE       L2
        JMP      L1
        
     L2:MOV      BX, [SI]
        CMP      BL, 0
        JE       WRT
        INC      SI
        INC      sline_t ;second line size
        CMP      BL, 0Ah
        JE       WRT
        JMP      L2
        
    WRT:MOV      BX, out_id
        MOV      SI, OFFSET fbuff
        ADD      SI, foffset
        ADD      SI, fline_t
        MOV      CX, sline_t
        CALL     fwrite ;write second line
        
        MOV      SI, OFFSET fbuff
        ADD      SI, foffset
        MOV      CX, fline_t
        CALL     fwrite ;write first line
        
        ADD      SI, fline_t
        ADD      SI, sline_t
        SUB      SI, OFFSET fbuff
        
        MOV      AX, fline_t
        ADD      AX, sline_t
        ADD      foffset, AX
        
        CMP      SI, fbuff_t ;end of file?
        JNE      process      
        RET        

main:   
        ;opening input file
        MOV      DX, OFFSET input
        MOV      AL, 000
        CALL     fopen
        MOV      in_id, AX
        
        ;creating output file
        MOV      DX, OFFSET output
        CALL     fnew
        MOV      BX, AX
        CALL     fclose
        
        ;read opened file
        MOV      BX, in_id
        MOV      CX, 512
        CALL     fread
        MOV      fbuff_t, AX
        MOV      BX, in_id
        CALL     fclose
        
        ;open output file
        MOV      DX, OFFSET output
        MOV      AL, 001
        CALL     fopen
        
        ;write to output file
        MOV      out_id, AX
        CALL     process
        
        ;close output file
        CALL     fclose
           
        RET
        
        fbuff    DB 512 DUP (?)     ;file buffer
        fbuff_t  DW ?               ;fbuffer usage
        foffset  DW ?               ;process offset
        fline_t  DW ?               ;first line size
        sline_t  DW ?               ;second line size
        in_id    DW ?               ;input file id
        out_id   DW ?               ;output file id
        input    DB 'input.txt',0   ;input filename
        output   DB 'output.txt',0  ;output filename 
        
code ENDS
END start
