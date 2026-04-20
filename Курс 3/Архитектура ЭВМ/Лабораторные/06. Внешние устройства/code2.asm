; init
RD #50
WR r1 ; Message1 - 109 101 115 115 097 103 101 049
RD #60
WR r2 ; Message2 - 109 101 115 115 097 103 101 050
RD #70
WR r3 ; Message3 - 109 101 115 115 097 103 101 051

; Enable keyboard
RD #11
OUT 01

EI ; Enable interruptions

JMP main

print:
    ; reinit disp
    ADD #101
    OUT 11
    RD #11
    OUT 11

    ; symbol
    p:
        RD @r4+
        OUT 10
        JNZ p
    RET

msg1: 
    RD r0
    SUB #49
    JNZ ret1
    MOV r4,r1
    CALL print
    ret1: RET

msg2: 
    RD r0
    SUB #50
    JNZ ret2
    MOV r4,r2
    CALL print
    ret2: RET

msg3: 
    RD r0
    SUB #51
    JNZ ret3
    MOV r4,r3
    CALL print
    ret3: RET

main:
    ; one-symbol mode
    RD #103
    OUT 01

    NOP

    JMP main

ikey:
    ; Read value
    IN 00
    WR r0

    ; Print msgs
    CALL msg1
    CALL msg2
    CALL msg3

    ; clear keyboard
    RD #101
    OUT 01

    IRET
