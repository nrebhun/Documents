	.nolist

;	2007 apr 19
;	2010 dec 20

;	include file for calling windows API functions

	.386
	.model	flat,stdcall
	.stack	1000h

readconsole equ	<ReadConsoleA>
writeconsole equ <WriteConsoleA>

ExitProcess proto,                  	; exit program
	exitcode:dword			; return code

GetStdHandle proto,                 	; get standard handle
	stdhandle:dword  		; type of console handle

ReadConsole proto,
	handle:dword,                  	; input handle
	buffer:ptr byte,             	; pointer to buffer
	numberofbytestoread:dword,    	; number of chars to read
	numberofbyteswritten:ptr dword,	; num bytes read
	reserved:dword               	; (not used)

WriteConsole proto,			; write a buffer to the console
	handle:dword,			; output handle
	buffer:ptr byte,		; pointer to buffer
	numberofbytestowrite:dword,	; size of buffer
	numberofbyteswritten:ptr dword,	; num bytes written
	reserved:dword			; (not used)

	.list
