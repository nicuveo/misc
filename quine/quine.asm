BITS 64
        org     0x00400000

ehdr:                                     ; Elf64_Ehdr
        db      0x7F, "ELF", 2, 1, 1, 0   ;     e_ident
        db      " quine ",0
        dw      2                         ;     e_type
        dw      0x3e                      ;     e_machine
        dd      1                         ;     e_version
        dq      _start                    ;     e_entry
        dq      phdr - $$                 ;     e_phoff
        dq      0                         ;     e_shoff
        dd      0                         ;     e_flags
        dw      64                        ;     e_ehsize
        dw      56                        ;     e_phentsize
        dw      1                         ;     e_phnum
        dw      0                         ;     e_shentsize
        dw      0                         ;     e_shnum
        dw      0                         ;     e_shstrndx

phdr:                                     ; [Elf64_Phdr]
        dd      1                         ;     p_type (LOAD)
        dd      5                         ;     p_flags
        dq      0                         ;     p_offset
        dq      $$                        ;     p_vaddr
        dq      $$                        ;     p_paddr
        dq      psize                     ;     p_filesz
        dq      psize                     ;     p_memsz
        dq      0x10                      ;     p_align

_start:
        mov     rdx, psize                ; arg3: segment size
        mov     rcx, $$                   ; arg2: beginning of segment
        mov     rbx, 1                    ; arg1: stdout
        mov     rax, 4                    ; arg0: print
        int     0x80                      ; syscall

        mov     rbx, 0                    ; arg1: return value
        mov     rax, 1                    ; arg0: exit
        int     0x80                      ; syscall

psize   equ     $ - $$
