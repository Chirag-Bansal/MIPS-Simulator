# MIPS-Simulator

Created a MIPS simulator in C++

## Outline:
I implemented a simulator in C++ for the MIPS processor. The program takes in an instruction set and performs those instructions one-by-one.
Memory, Register file, and Instructions have all been stored in arrays.

Instructions implemented: add, sub, mult, div , srl, sll, sw, lw, j, bne, beq, bgtz, blez, jal, jr

Implementation:
I take instructions line by line and execute them accordingly, incrementing the program counter each time.

Testing:
I converted various instructions into MIPS format and gave them as input and tested it on simulation. My model seems to be working fine for a variety of test cases. (*to the extent that I have tested*)

Leaf procedure examples:

1) Add t1, t2, t3
   Sub t1, t2, t3
   Sll t4, t3(0x3)
   Srl t5, t4(0x2)
   Sw t1, 0(s1)
   Lw t6, 0(s1)
   End(0-vector)

2) Add t1 t2 t3
   Add t4 t1 t2
   Branch, jump,jal t2 t3 0x2
   Add t5 t1 t2
   Add t6 t1 t2
   Add t7 t1 t2
		
Note: this example has been generalized to use all the branch, jump instructions.

Non-leaf procedure examples:-

3) Add t1 t2 t3
   Add t4 t1 t2
   Jal 0x5
   Add s1 t5 t6
   sub s2 t6 t5
   add t5 t1 t4
   add t6 t2 t3
   jr ra

4) addi $sp, $sp, –2
   sw $ra, 0x1($sp) 
   sw $a0, 0x0($sp)
   slti $t0,$a0,1
   beq $t0,$zero,0x3
   addi $v0,$zero,1 
   addi $sp,$sp,2 
   jr $ra
   addi $a0,$a0,–1
   jal fact
   lw $a0, 0x0($sp)
   lw $ra, 0x1($sp)
   addi $sp, $sp, 2
   mul $v0,$a0,$v0
   jr $ra
