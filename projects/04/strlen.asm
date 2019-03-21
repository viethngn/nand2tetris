//Project 4 Nand2Tetris CSCI140
//Students: Viet Nguyen & Minh Quach
@16
M = 0 		//Result

@100
D = A
@17
M = D 		//Store R100 address in R17

(LOOP)
@17
A = M 		//Get R100 Address
D = M 		//Get R100 value
@END
D;JLE 		//Coninue if value is > 0
@16
M = M + 1 	//Increment reuslt by 1
@17
M = M + 1 	//Increment the address
A = M 		//Store new address
@LOOP
0;JMP 		//Repeat the LOOP

(END)
@END
0;JMP 		//Infinite loop