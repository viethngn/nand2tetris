// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.
(LOOP)
@SCREEN
D = A
@0
M = D 		//Store screen start pixel address in R0

@KBD
D = M
@BLACK
D;JGT		//jump to BLACK if key is pressed
@WHITE
D;JMP 		//else jump to WHITE

(BLACK)
@0
A = M 		//Access screen address
M = -1 		//Fill black
@0
D = M + 1 	//increment the pixel address
@KBD
D = A - D 	//counter to see if reach the end of screen
@0
M = M + 1 	//increment the epixel address
A = M 		//store new address
@BLACK
D;JGT 		//Repeat if not reach the end of the screen
@LOOP
0;JMP 		//reset to the first pixel

(WHITE)
@0
A = M 		//Access screen address
M = 0 		//Fill white
@0
D = M + 1 	//increment the pixel address
@KBD
D = A - D 	//counter to see if reach the end of screen
@0
M = M + 1 	//increment the pixel address
A = M 		//store new address
@WHITE
D;JGT 		//Repeat if not reach the end of the screen
@LOOP
0;JMP 		//reset to the first pixel

