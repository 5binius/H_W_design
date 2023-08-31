.text
.global _start

_start:
	movia	r8, RESULT # r8 points to the result location
	ldw 	r4, 4(r8) # r4 holds number of elements in the list
	addi	r5, r8, 8 # r5 points to the start of the list
	call	LARGE
	stw 	r2, (r8) # r2 holds the subroutine return value

STOP: 	br	STOP
LARGE: subi r4, r4, 1 # decrement the counter
		beq r4, r0, DONE # finished if r4 is equal to 0
		addi r5, r5, 4 # increment the list pointer
		ldw r6, (r5) # get the next number
		bge r2, r6, LARGE # check if larger number found
		mov r2, r6 # update the largest number found
		br LARGE
DONE:	ret


RESULT: .skip	4 # space for the largest number found
N: 	.word 	7 # number of entries in the list
NUMBERS:.word 	4, 5, 3, 6 # the data . . .
	.word 	1, 8, 2 
	.end
