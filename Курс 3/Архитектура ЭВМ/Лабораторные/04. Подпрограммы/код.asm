
; Первый вызов
RD #51
WR R1
RD 50
WR R2

CALL ODD
RD R4
WR 80

; Второй вызов
RD #61
WR R1
RD 60
WR R2

CALL ODD
RD R4
WR 81

; Третий вызов
RD #71
WR R1
RD 70
WR R2

CALL ODD
RD R4
WR 82

RD 80
ADD 81
ADD 82
DIV #3
OUT
HLT

;ODD (R1: начало массива, R2: количество элементов) -> R4
ODD:RD #0 ; Инициализация подпрограммы
    WR R3
    WR R4

    ; Проверка чётности
    L:  RD @R1
        DIV #2
        MUL #2
        SUB @R1
        JNZ N
        ; Увеличение количества чётных
        RD R4
        ADD #1
        WR R4

        ; Переход на следующий элемент
        N:  RD R1
            ADD #1
            WR R1
            ; Увеличение итерации
            RD R3
            ADD #1
            WR R3

    ; Проверка итерации цикла
    RD R3
    SUB R2
    JS L
    RET