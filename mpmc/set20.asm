.8086
.MODEL SMALL
.STACK 512
.DATA
        CRLF    DB 13,10,'$'
        STRING  DB 64 DUP(?)
.CODE
START:

        MOV AX,@DATA
        MOV DS,AX



READCHAR MACRO
        MOV AX,0100H
        INT 21H
ENDM



WRITECHAR MACRO 
        ;CHAR TO BE MOVED TO DL
        MOV AX,0200H
        INT 21H
ENDM



READSTR MACRO
        MOV SI,0
RST:
        READCHAR
        MOV STRING[SI],AL
        INC SI
        CMP AL,13
        JNZ RST
        MOV STRING[SI],'$'
ENDM



WRITESTR MACRO
        MOV SI,0
WST:
        MOV DL,STRING[SI]
        WRITECHAR
        INC SI
        CMP DL,13
        JNZ WST
ENDM

;        READCHAR
;        MOV DL,AL
;        WRITECHAR
;
;        LEA DX,CRLF
;        MOV AH,09H
;        INT 21H

        READSTR

        LEA DX,CRLF
        MOV AH,09H
        INT 21H
        
        WRITESTR

        MOV AH,4CH
        INT 21H
END START


