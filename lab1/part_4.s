.text
.global _start

_start:
	movia r4, N
	addi r8, r4, 4 # r8 points to the decimal digits storage location
	ldw r4, (r4) # r4 holds N
	call DIVIDE # parameter for DIVIDE is in r4
	/* Tens digit is now in r3, ones digit is in r2 */
	stb r5, 3(r8)
	stb r4, 2(r8)
	stb r3, 1(r8)
	stb r2, (r8)
END: br END
	/* Subroutine to perform the integer division r4 / 10.
	* Returns: quotient in r3, and remainder in r2
	*/
DIVIDE: mov r2, r4 # r2 will be the remainder
	movi r12, 1000
	movi r13, 100
	movi r14, 10 # divisor
	movi r3, 0 # r3 will be the quotient
	movi r4, 0 # r4
	movi r5, 0 #
CONT1000: blt r2, r12, CONT100

	sub r2, r2, r12 # subtract the divisor, and ...
	addi r5, r5, 1 # increment the quotient
	br CONT1000
CONT100:blt r2, r13, CONT10

	sub r2, r2, r13 # subtract the divisor, and ...
	addi r4, r4, 1 # increment the quotient
	br CONT100

CONT10:blt r2, r14, DIV_END

	sub r2, r2, r14 # subtract the divisor, and ...
	addi r3, r3, 1 # increment the quotient
	br CONT10

DIV_END:ret # quotient is in r3, remainder in r2

N: 	.word 9876  #the decimal number to be converted  storage space for the decimal digits
	.space 4

	.end
