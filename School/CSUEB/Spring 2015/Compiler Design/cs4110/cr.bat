@ if not exist p8.exe cl/nologo p8.c > nul
@ if not exist p80.obj ml /nologo /c -coff p80.asm > nul
@ p8 %1.p8
@ ml /nologo /c -coff %1.asm > nul
@ link32 /nologo /subsystem:console %1.obj p80.obj kernel32.lib
@ if exist p8.obj del p8.obj
@ del p80.obj
@ del p8.exe
@ del %1.asm
@ del %1.obj
@ %1
