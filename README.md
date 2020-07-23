# MIPS-Simulator

Created a MIPS simulator in C++

## Outline:
I implemented a simulator in C++ for the MIPS processor. The program takes in an instruction set and performs those instructions one-by-one.
Memory, Register file, and Instructions have all been stored in arrays.

**Instructions implemented:** add, sub, mult, div , srl, sll, sw, lw, j, bne, beq, bgtz, blez, jal, jr

**Implementation:** I take instructions line by line and execute them accordingly, incrementing the program counter each time.

**Testing:** I converted various instructions into MIPS format and gave them as input and tested it on simulation. My model seems to be working fine for a variety of test cases. (*to the extent that I have tested*)

Leaf procedure examples:

1) Add t1, t2, t3 <br />
   Sub t1, t2, t3 <br />
   Sll t4, t3(0x3) <br />
   Srl t5, t4(0x2) <br />
   Sw t1, 0(s1) <br />
   Lw t6, 0(s1) <br />
   End(0-vector) <br />

2) Add t1 t2 t3 <br />
   Add t4 t1 t2 <br />
   Branch, jump,jal t2 t3 0x2 <br />
   Add t5 t1 t2 <br />
   Add t6 t1 t2 <br  />
   Add t7 t1 t2 <br />
		
Note: this example has been generalized to use all the branch, jump instructions.

Non-leaf procedure examples:-

3) Add t1 t2 t3 <br />
   Add t4 t1 t2 <br />
   Jal 0x5 <br />
   Add s1 t5 t6 <br />
   sub s2 t6 t5 <br />
   add t5 t1 t4 <br />
   add t6 t2 t3 <br />
   jr ra <br />

4) addi $sp, $sp, –2 <br />
   sw $ra, 0x1($sp) <br />
   sw $a0, 0x0($sp) <br />
   slti $t0,$a0,1 <br />
   beq $t0,$zero,0x3 <br />
   addi $v0,$zero,1 <br />
   addi $sp,$sp,2 <br />
   jr $ra <br />
   addi $a0,$a0,–1 <br />
   jal fact <br />
   lw $a0, 0x0($sp) <br />
   lw $ra, 0x1($sp) <br />
   addi $sp, $sp, 2 <br />
   mul $v0,$a0,$v0 <br />
   jr $ra <br />
