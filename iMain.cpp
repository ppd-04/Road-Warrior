# include "iGraphics.h"
#include<iostream>
#include<time.h>
#include<unistd.h>


#define kacheashargolpo 300
using namespace std;

int x = 300, y = 300, r = 20;

int player_x = 458, player_y = 0;
float v1_x = 324, v1_y = 450;
float v2_x = 588, v2_y = 450;
float v3_x = 550, v3_y = 450;


// For Coin
float c1_x = 200, c1_y = 571;
float c2_x = 366, c2_y = 595;
float c3_x = 615, c3_y = 594; 
float c1_speed = 0, c2_speed = 0, c3_speed = 0;

int coin_score = 0;
int score = 0;

float bullet_x = 324, bullet_y = 455;



// drawing variables
int home_page = 1;
int start_page = 0;
int about_page = 0;
int score_page = 0;
int settings_page = 0;
int instruction_page = 0;

// clicking variables
int startbutton_click = 0;
int scorebutton_click = 0;
int aboutbutton_click = 0;
int exitbutton_click = 0;

int backbutton_click = 0;

// physics variables
int acceleration = 0;
int gameover = 0;
int flag_gameover = 0;

int count_image = 40;
int increment = 30;
int image_position[100];
int background_Y = 0;
int background_image_path = 0;
int game_over_page = 0;

char image_path[200][250] = {
	"images\\IgraphicsPicSlices\\Slice_1.bmp",
	"images\\IgraphicsPicSlices\\Slice_2.bmp",
	"images\\IgraphicsPicSlices\\Slice_3.bmp",
	"images\\IgraphicsPicSlices\\Slice_4.bmp",
	"images\\IgraphicsPicSlices\\Slice_5.bmp",
	"images\\IgraphicsPicSlices\\Slice_6.bmp",
	"images\\IgraphicsPicSlices\\Slice_7.bmp",
	"images\\IgraphicsPicSlices\\Slice_8.bmp",
	"images\\IgraphicsPicSlices\\Slice_9.bmp",
	"images\\IgraphicsPicSlices\\Slice_10.bmp",
	"images\\IgraphicsPicSlices\\Slice_11.bmp",
	"images\\IgraphicsPicSlices\\Slice_12.bmp",
	"images\\IgraphicsPicSlices\\Slice_13.bmp",
	"images\\IgraphicsPicSlices\\Slice_14.bmp",
	"images\\IgraphicsPicSlices\\Slice_15.bmp",
	"images\\IgraphicsPicSlices\\Slice_16.bmp",
	"images\\IgraphicsPicSlices\\Slice_17.bmp",
	"images\\IgraphicsPicSlices\\Slice_18.bmp",
	"images\\IgraphicsPicSlices\\Slice_19.bmp",
	"images\\IgraphicsPicSlices\\Slice_20.bmp",
	"images\\IgraphicsPicSlices\\Slice_21.bmp",
	"images\\IgraphicsPicSlices\\Slice_22.bmp",
	"images\\IgraphicsPicSlices\\Slice_23.bmp",
	"images\\IgraphicsPicSlices\\Slice_24.bmp",
	"images\\IgraphicsPicSlices\\Slice_25.bmp",
	"images\\IgraphicsPicSlices\\Slice_26.bmp",
	"images\\IgraphicsPicSlices\\Slice_27.bmp",
	"images\\IgraphicsPicSlices\\Slice_28.bmp",
	"images\\IgraphicsPicSlices\\Slice_29.bmp",
	"images\\IgraphicsPicSlices\\Slice_30.bmp",
	"images\\IgraphicsPicSlices\\Slice_31.bmp",
	"images\\IgraphicsPicSlices\\Slice_32.bmp",
	"images\\IgraphicsPicSlices\\Slice_33.bmp",
	"images\\IgraphicsPicSlices\\Slice_34.bmp",
	"images\\IgraphicsPicSlices\\Slice_35.bmp",
	"images\\IgraphicsPicSlices\\Slice_36.bmp",
	"images\\IgraphicsPicSlices\\Slice_37.bmp",
	"images\\IgraphicsPicSlices\\Slice_38.bmp",
	"images\\IgraphicsPicSlices\\Slice_39.bmp",
	"images\\IgraphicsPicSlices\\Slice_40.bmp"

};


bool music = true;

void drawHomePage();
/*
	function iDraw() is called again and again by the system.

	*/


void draw_start_page();
void draw_about_page();
void draw_instruction_page();
void draw_totalscore_page();

void start_button_click();
void about_button_click();
void instruction_button_click();
void totalscore_button_click();

void back_button_click();


void collision();

void coin_collision();

void increase_score();

void image_position_init();

void rendering();


int readMaxScore();

void writeMaxScore(int max);

void game_over();

void draw_game_over();



void iDraw() {
	//place your drawing codes here
	iClear();

	if(home_page == 1){
		drawHomePage();
	}else if(start_page == 1){
		draw_start_page();
	}
	else if(about_page == 1){
		draw_about_page();
	}else if(instruction_page == 1){
		draw_instruction_page();
	}else if(score_page == 1){
		draw_totalscore_page();
	}
	else if(gameover == 1){
		draw_game_over();
	}


	// iSetColor(20, 200, 200);
	// iFilledCircle(x, y, r);
	// //iFilledRectangle(10, 30, 20, 20);
	// iSetColor(20, 200, 0);
	// iText(40, 40, "Hi, I am iGraphics");
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my){
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}


/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		printf("x = %d, y= %d\n",mx,my);

		if(home_page == 1){
			if((mx >= 6 && mx <= 189) && (my >= 11 && my <= 61)){
				start_button_click();
			}
			else if(((mx >= 416 && mx <= 600) && (my >= 4 && my <= 61))){
				about_button_click();
			}else if(((mx >= 207 && mx <= 396) && (my >= 6 && my <= 61))){
				instruction_button_click();
			}else if((mx >= 619 && mx <= 806) && (my >= 6 && my <= 61)){
				totalscore_button_click();
			}
		}
		// Ekhane jhamela hote pare!!!
		// Reminder Settings banano hoynai !!
		if(start_page == 1 || about_page == 1 || instruction_page == 1 || settings_page == 1 || score_page == 1 || game_over_page == 1){
			if((mx >= 18 && mx <= 68) && (my >= 480 && my <= 529)){
				back_button_click();
			}
		}
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {
	if (key == 'q') {
		exit(0);
	}

	if(key == 'a' || key == 'A'){
		player_x = player_x - 10;

		if(player_x < 180){
			player_x = 180;
		}
		if(player_x > 650){
			player_x = 650;
		}
	}

	if(key == 'd' || key == 'D'){
		player_x = player_x + 10;

		if(player_x < 180){
			player_x = 180;
		}
		if(player_x > 650){
			player_x = 650;
		}
	}

	if(key == 'w' || key == 'W'){
		player_y = player_y + 10;

		if(player_y > 600){
			player_y = 600;
		}
	}

	if(key == 's' || key == 'S'){
		player_y = player_y - 10;

		if(player_y < 0){
			player_y = 0;
		}
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}


	if(key == GLUT_KEY_RIGHT){
		player_x = player_x + 10;

		if(player_x < 180){
			player_x = 180;
		}
		if(player_x > 650){
			player_x = 650;
		}
	}

	if(key == GLUT_KEY_LEFT){
		player_x = player_x - 10;

		if(player_x < 180){
			player_x = 180;
		}
		if(player_x > 650){
			player_x = 650;
		}
	}

	if(key == GLUT_KEY_UP){
		player_y = player_y + 10;

		if(player_y > 600){
			player_y = 600;
		}
	}

	if(key == GLUT_KEY_DOWN){
		player_y = player_y - 10;

		if(player_y < 0){
			player_y = 0;
		}
	}



	if(key == GLUT_KEY_F1){
		if(music){
			music = false;
			PlaySound(0,0,0);
		}else{
			music = true;
			PlaySound("sounds\\Tropical.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
	//place your codes for other keys here
}


void drawHomePage(){
	if(home_page == 1){
		iSetColor(128, 128, 128);
		iFilledRectangle(0, 0, 1000, 600);
		iShowBMP(0, 0, "images\\car.bmp");

		//Buttons

		iShowBMP2(7, 5, "images\\Table_1_cropped.bmp", 0);
		iShowBMP2(212, 5, "images\\Table_1_cropped.bmp", 0);
		iShowBMP2(417, 5, "images\\Table_1_cropped.bmp", 0);
		iShowBMP2(622, 5, "images\\Table_1_cropped.bmp", 0);
		iShowBMP2(817, 5, "images\\Table_1_cropped.bmp", 0);

		iSetColor(251, 252, 247);
		iText(68, 27, "Start", GLUT_BITMAP_TIMES_ROMAN_24);
		// iText(68, 27, "Start", GLUT_BITMAP_HELVETICA_18);

		iText(253, 27, "Instruction", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(478, 27, "About", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(653, 27, "Total Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(878, 27, "Settings", GLUT_BITMAP_TIMES_ROMAN_24);



	}
}


void draw_start_page(){



	iFilledRectangle(0, 0, 1000, 600);
	// iShowBMP2(0, 0, "images\\Roadcopy.bmp", 0);
	// ki je hoy
	// sleep(2);

	
	iShowBMP2(0, 0, "images\\BackgroundRoad\\resizedbgroad.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
	// printf("Start page is active");

	rendering();

	iShowBMP2(player_x, player_y, "images\\VillainCars\\Car_1.bmp", 0);
	iShowBMP2(v1_x, v1_y, "images\\VillainCars\\Car_2.bmp", 0);
	iShowBMP2(v2_x, v2_y, "images\\VillainCars\\Car_3.bmp", 0);

	// Bullet Add
	iShowBMP2(bullet_x, bullet_y, "images\\Bullets\\bullet.bmp", 0);

	// Coin add
	iShowBMP2(c1_x, c1_y, "images\\coins\\CoinFinal1.bmp", 0);
	iShowBMP2(c2_x, c2_y, "images\\coins\\CoinFinal2.bmp", 0);
	iShowBMP2(c3_x, c3_y, "images\\coins\\CoinFinal3.bmp", 0);
	

	// Display Score

	iSetColor(255, 255, 255);

	// char score_text[40];
	// sprintf(score_text, "Score: %d", score);
	// iText(20, 570, score_text, GLUT_BITMAP_TIMES_ROMAN_24);



	// For v1

	// v1_y = v1_y - 1.5;
	// if (abs(player_x - v1_x) <= kacheashargolpo && abs(player_y - v1_y) <= kacheashargolpo) {

	// 	if (player_x > v1_x) {
	// 		v1_x += 2; 
	// 	}
	// 	else { 
	// 		v1_x -= 2;
	// 	} 
	// }
	// if(v1_y == 0){
	// 	v1_y = 530;
	// 	v1_x = 195 + rand() % 271;
	// }
	// collision();

	v1_y = v1_y - 1.5;

	// Check if the villain car is close to the player's car
	if (abs(player_x - v1_x) <= kacheashargolpo && abs(player_y - v1_y) <= kacheashargolpo) {
		// Move villain car horizontally toward the player
		if (player_x > v1_x) {
			v1_x += 2; // Move right
		} else {
			v1_x -= 2; // Move left
		}
	}

	// Reset villain car if it moves out of the screen
	if (v1_y <= 0) {  // Fixed to use <= instead of ==
		v1_y = 530;   // Reset vertical position
		v1_x = 195 + rand() % 271; // Randomize horizontal position
	}

	// Check for collision (ensure it accounts for updated positions)
	collision();


	// For Bullet

	bullet_y = bullet_y - 10;

	
	if(bullet_y == 0){
		bullet_y = 530;
		// bullet_x = 195 + rand() % 455;
	}
	collision();

	// For v2

	// v2_y = v2_y - 5;
	// // v2_x = v2_x - 2;
	// if(v2_y == 0){
	// 	v2_y = 530;
	// 	v2_x = 427 + rand() % 225;
	// }
	// collision();

	v2_y -= 5;  // Move the second villain car downward

	// Debugging: Print player and villain positions
	// printf("Player: (%d, %d), Villain 2: (%d, %d)\n", player_x, player_y, v2_x, v2_y);

	// Check if the second villain car is close to the player's car
	if (abs(player_x - v2_x) <= kacheashargolpo && abs(player_y - v2_y) <= kacheashargolpo) {
		// printf("Proximity detected for Villain 2!\n");  // Debugging: Print proximity detection
		// Move the second villain car horizontally toward the player
		if (player_x > v2_x) {
			v2_x += 2; // Move right
			// printf("Villain 2 moving right to %d\n", v2_x);
		} else {
			v2_x -= 2; // Move left
			// printf("Villain 2 moving left to %d\n", v2_x);
		}
	}

	// Reset the second villain car when it goes out of the screen
	if (v2_y <= 0) {
		// printf("Resetting Villain 2\n");  // Debugging: Print reset action
		v2_y = 530;                      // Reset vertical position
		v2_x = 427 + rand() % 225;       // Randomize horizontal position
	}

	// Check for collision
	collision();  // Ensure this function accounts for the updated positions


		if (abs(v1_x - v2_x) <= 50 && abs(v1_y - v2_y) <= 50) {  // Threshold for avoiding collision
		if (v1_x < v2_x) {
			v2_x += 10;  // Move `v2` further right if too close to `v1`
		} else {
			v2_x -= 10;  // Move `v2` further left if too close to `v1`
		}
	}

	// Check for collision with the player
	collision(); 

	// For coin

	// C1
	
	c1_y = c1_y - 15;

	if(c1_y == 0){
		c1_y = 530;
		c1_x = 177 + rand() % 110;
		
	}coin_collision();

	// C2

	c2_y = c2_y - 12;

	if(c2_y == 0){
		c2_y = 530;
		c2_x = 302 + rand() % 182;
	}coin_collision();

	c3_y = c3_y - 13;

	if(c3_y == 0){
		c3_y = 530;
		c3_x = 525 + rand() % 131;
	}coin_collision();


	// int maximum_score = readMaxScore();
	// printf("Maximum Score : %d", maximum_score);
	

}

void draw_about_page(){

	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(300, 0, "images\\Myimage.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
}


void draw_instruction_page(){
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\1random.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
}

void draw_totalscore_page(){
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(100, 00, "images\\TotalScoreTemplate.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
}



void start_button_click(){
	home_page = 0;
	start_page = 1;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
}

void about_button_click(){
	
	home_page = 0;
	start_page = 0;
	about_page = 1;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
}

void instruction_button_click(){
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 1;
	game_over_page = 0;
}

void totalscore_button_click(){
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 1;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
}


void back_button_click(){
	home_page = 1;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	// drawHomePage();
}


void collision(){

	game_over();

	// For first car
	// if((player_x + 50 >= v1_x && player_x <= v1_x + 50) && (player_y + 105 >= v1_y &&  player_y <= v1_y + 105)){
	// 	iShowBMP2(0, 0, "images\\GameOver\\GameOver.bmp", 0);
	// 	iSetColor(255, 255, 255);
	// 	// int maxScore = readMaxScore();
	// 	flag_gameover = 1;
		
	// 	// iText(450, 300, "Your Score: %d", GLUT_BITMAP_HELVETICA_18);
	// 	char scoreText[50];
	// 	sprintf(scoreText, "Your Score is: %d", score);
	// 	iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
		
	// 	gameover = 1;
	// 	flag_gameover = 1;

	// 	drawHomePage();

	// 	// int maxScore = readMaxScore();
	// 	// // Update max score if the current score is higher
    //     // if (score > maxScore) {
    //     //     maxScore = score;
    //     //     writeMaxScore(maxScore);
    //     // }

	// 	    // Display current and maximum scores
    //     // char maxScoreText[50];
    //     // // sprintf(scoreText, "Your Score is: %d", score);
    //     // sprintf(maxScoreText, "Max Score: %d", maxScore);

    //     iSetColor(255, 255, 255); // Set text color to white
    //     // iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
    //     // iText(450, 200, maxScoreText, GLUT_BITMAP_HELVETICA_18);

    //     // Log scores to console (optional)
    //     // printf("Game Over! Your Score: %d, Maximum Score: %d\n", score, maxScore);
    // }


	// 	// Read the current max score
		

	// 	// Update max score if the current score is higher
	// 	// if (score > maxScore) {
	// 	// 	maxScore = score;
	// 	// 	writeMaxScore(maxScore);
	// 	// }

	// 	// Display the scores
	// 	// printf("Game Over! Your Score: %d, Maximum Score: %d\n", score, maxScore);
	// 	// You can also display these in the game using iText or other UI elements


	// 	// char max_score_text[40];
		
	// 	// sprintf(max_score_text, "Max Score: %d", maxScore);
	// 	// iText(20, 540, max_score_text, GLUT_BITMAP_TIMES_ROMAN_24);

	// 	 // Render the score text }
	// 	// sleep(2);
	// 	// start_page = 0;
	// 	// exit(0);
	

	// // For second car
	// else if((player_x + 50 >= v2_x && player_x <= v2_x + 50) && (player_y + 105 >= v2_y &&  player_y <= v2_y + 105)){
	// 	iShowBMP2(0, 0, "images\\GameOver\\GameOver.bmp", 0);
	// 	iSetColor(255, 255, 255);

	// 	flag_gameover = 1;
	// 	// iText(450, 300, "Your score %d", GLUT_BITMAP_HELVETICA_18);
	// 	char scoreText[50];
	// 	sprintf(scoreText, "Your Score is: %d", score);
	// 	iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);

	// 	// int maxScore = readMaxScore();
	// 	// // Update max score if the current score is higher
    //     // if (score > maxScore) {
    //     //     maxScore = score;
    //     //     writeMaxScore(maxScore);
    //     // }

	// 	//     // Display current and maximum scores
    //     // char maxScoreText[50];
    //     // // sprintf(scoreText, "Your Score is: %d", score);
    //     // sprintf(maxScoreText, "Max Score: %d", maxScore);
	// 	drawHomePage();
    //     iSetColor(255, 255, 255); // Set text color to white
    //     // iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
    //     // iText(450, 200, maxScoreText, GLUT_BITMAP_HELVETICA_18);

    //     // Log scores to console (optional)
    //     // printf("Game Over! Your Score: %d, Maximum Score: %d\n", score, maxScore);
    // }

		
		// sleep(2);
		// start_page = 0;
		// exit(0);
	}



// void coin_collision(){
// 	if(((player_x + 50 >= c1_x) && (player_x <= c1_x - 50)) && (player_y + 50 >= c1_y) && (player_y <= c1_y - 50)){
// 		coin_score = coin_score + 5;
// 		c1_speed = c1_speed + 10;
// 		c1_x = c1_x + c1_speed;
// 		c1_y = 530;
// 	} 
// 	if(((player_x + 50 >= c2_x) && (player_x <= c2_x - 50)) && (player_y + 50 >= c2_y) && (player_y <= c2_y - 50)){
// 		coin_score = coin_score + 5;
// 		c2_speed = c2_speed + 10;
// 		c2_x = c2_x + c2_speed;
// 		c2_y = 530;
// 	} 
// 	if(((player_x + 50 >= c3_x) && (player_x <= c3_x - 50)) && (player_y + 50 >= c3_y) && (player_y <= c3_y - 50)){
// 		coin_score = coin_score + 5;
// 		c3_speed = c3_speed + 10;
// 		c3_x = c3_x + c3_speed;
// 		c3_y = 530;
// 	}
// }

void coin_collision(){
	if(flag_gameover) return;
    // Check collision with coin 1
    if ((player_x < c1_x + 50 && player_x + 50 > c1_x) && 
        (player_y < c1_y + 50 && player_y + 50 > c1_y)) {
    	
			coin_score += 5;
			score += 100;
			c1_speed += 10;
		

	
        c1_x += c1_speed;
		if(c1_x >= 680){
			c1_x = 200;
		}
		if(c1_y == 0){ // Move coin to a new position
        	c1_y = 530;
		}       // Reset coin's vertical position
    } 

    // Check collision with coin 2
    if ((player_x < c2_x + 50 && player_x + 50 > c2_x) && 
        (player_y < c2_y + 50 && player_y + 50 > c2_y)) {
		
			coin_score += 5;
			score += 100;
			c2_speed += 10;
			c2_x += c2_speed;
		
		if(c2_x >= 680){
			c2_x = 200;
		}
		if(c2_y == 0){  // Move coin to a new position
        	c2_y = 530; 
		}      // Reset coin's vertical position
    }

    // Check collision with coin 3
    if ((player_x < c3_x + 50 && player_x + 50 > c3_x) && 
        (player_y < c3_y + 50 && player_y + 50 > c3_y)) {
        coin_score += 5;
		score += 100;
        c3_speed += 10;
        c3_x += c3_speed; // Move coin to a new position
		if(c3_x >= 680){
			c3_x = 300;
		}
		if(c3_y == 0){

        	c3_y = 530;
		}       // Reset coin's vertical position
    }
}


void image_position_init(){
	int i, j;

	for(i = 0, j = 0; i < count_image; i++){
		// image_position[i] = image_position[i] - increment;
		image_position[i] = j;
		j = j + increment;
	}
}

void BackgroundMoving(){
	int i;
	for(i = 0; i < count_image; i++){
		image_position[i] = image_position[i] - increment;
	}

	for(i = 0; i < count_image; i++){
		if(image_position[i] < 0){
			image_position[i] = 600 - increment;
		}
	}
}

void rendering(){
	for(int i = 0; i < count_image; i++){
		iShowBMP2(0, image_position[i], image_path[i], 0);
	}
}

// void update_coins() {
//     // For coin 1
//     if (c1_y < 0) { // Coin goes below the screen
//         c1_y = 530; // Reset to the top
//         c1_x = rand() % 950; // Randomize horizontal position
//     } else {
//         c1_y -= c1_speed; // Move the coin down
//     }

//     // Repeat for coin 2
//     if (c2_y < 0) {
//         c2_y = 530;
//         c2_x = rand() % 950;
//     } else {
//         c2_y -= c2_speed;
//     }

//     // Repeat for coin 3
//     if (c3_y < 0) {
//         c3_y = 530;
//         c3_x = rand() % 950;
//     } else {
//         c3_y -= c3_speed;
//     }
// }

// void update_cars() {
//     // For car 1
//     if (v1_y < 0) { // Car goes below the screen
//         v1_y = 530; // Reset to the top
//         v1_x = rand() % 950; // Randomize horizontal position
//     } else {
//         v1_y -= c1_speed; // Move the car down
//     }

//     // Repeat for other cars similarly
// }

// void update_bullets() {
//     // For bullet 1
//     if (bullet1_y > 600) { // Bullet goes above the screen
//         bullet1_y = player_y + 50; // Reset to player's position
//         bullet1_x = player_x + 25; // Centered on the player
//     } else {
//         bullet1_y += bullet_speed; // Move the bullet up
//     }

//     // Repeat for other bullets
// }

void increase_score(){
	if(flag_gameover) return;
	if(start_page == 1 && !gameover){
		score += 5;
	}
}


// Function for Maximum Score

int readMaxScore() {
    FILE *file = fopen("maxscore.txt", "r");
    if (!file) {
        // If the file doesn't exist, assume max score is 0
        return 0;
    }
    int maxScore;
    fscanf(file, "%d", &maxScore);
    fclose(file);
    return maxScore;
}

void writeMaxScore(int maxScore) {
    FILE *file = fopen("maxscore.txt", "w");
    if (file) {
        fprintf(file, "%d", maxScore);
        fclose(file);
    }
}

void game_over(){
	// For first car
	if((player_x + 50 >= v1_x && player_x <= v1_x + 50) && (player_y + 105 >= v1_y &&  player_y <= v1_y + 105)){
		// iShowBMP2(0, 0, "images\\GameOver\\GameOver.bmp", 0);
		// iSetColor(255, 255, 255);
		// iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
		// back_button_click();
		// int maxScore = readMaxScore();
		flag_gameover = 1;
		gameover = 1;
		// draw_game_over();
		
		// iText(450, 300, "Your Score: %d", GLUT_BITMAP_HELVETICA_18);
		// char scoreText[50];
		// sprintf(scoreText, "Your Score is: %d", score);
		// iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
		
		// gameover = 1;
		// flag_gameover = 1;

		drawHomePage();

		// int maxScore = readMaxScore();
		// // Update max score if the current score is higher
        // if (score > maxScore) {
        //     maxScore = score;
        //     writeMaxScore(maxScore);
        // }

		    // Display current and maximum scores
        // char maxScoreText[50];
        // // sprintf(scoreText, "Your Score is: %d", score);
        // sprintf(maxScoreText, "Max Score: %d", maxScore);

        // iSetColor(255, 255, 255); // Set text color to white
        // iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
        // iText(450, 200, maxScoreText, GLUT_BITMAP_HELVETICA_18);

        // Log scores to console (optional)
        // printf("Game Over! Your Score: %d, Maximum Score: %d\n", score, maxScore);
    }


		// Read the current max score
		

		// Update max score if the current score is higher
		// if (score > maxScore) {
		// 	maxScore = score;
		// 	writeMaxScore(maxScore);
		// }

		// Display the scores
		// printf("Game Over! Your Score: %d, Maximum Score: %d\n", score, maxScore);
		// You can also display these in the game using iText or other UI elements


		// char max_score_text[40];
		
		// sprintf(max_score_text, "Max Score: %d", maxScore);
		// iText(20, 540, max_score_text, GLUT_BITMAP_TIMES_ROMAN_24);

		 // Render the score text }
		// sleep(2);
		// start_page = 0;
		// exit(0);
	

	// For second car
	else if((player_x + 50 >= v2_x && player_x <= v2_x + 50) && (player_y + 105 >= v2_y &&  player_y <= v2_y + 105)){
		// iShowBMP2(0, 0, "images\\GameOver\\GameOver.bmp", 0);
		// iSetColor(255, 255, 255);
		// iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
		// back_button_click();

		flag_gameover = 1;
		gameover = 1;
		// draw_game_over();
		// iText(450, 300, "Your score %d", GLUT_BITMAP_HELVETICA_18);
		// char scoreText[50];
		// sprintf(scoreText, "Your Score is: %d", score);
		// iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
		
		// int maxScore = readMaxScore();
		// // Update max score if the current score is higher
        // if (score > maxScore) {
        //     maxScore = score;
        //     writeMaxScore(maxScore);
        // }

		//     // Display current and maximum scores
        // char maxScoreText[50];
        // // sprintf(scoreText, "Your Score is: %d", score);
        // sprintf(maxScoreText, "Max Score: %d", maxScore);
		drawHomePage();
        // iSetColor(255, 255, 255); // Set text color to white
        // iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);
        // iText(450, 200, maxScoreText, GLUT_BITMAP_HELVETICA_18);

        // Log scores to console (optional)
        // printf("Game Over! Your Score: %d, Maximum Score: %d\n", score, maxScore);
    }

		
		// sleep(2);
		// start_page = 0;
		// exit(0);
	}

void draw_game_over(){
	game_over_page = 1;
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;

	iShowBMP2(0, 0, "images\\GameOver\\GameOver.bmp", 0);
	iSetColor(255, 255, 255); 
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
	back_button_click(); 
	char scoreText[50]; 
	sprintf(scoreText, "Your Score is: %d", score); 
	iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);

}



int main() {


	if(music){
		PlaySound("sounds\\Tropical.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	image_position_init();

	iSetTimer(10, BackgroundMoving);
	iSetTimer(1000, increase_score);
	//place your own initialization codes here.
	iInitialize(1000, 600, "Road Warrior");
	return 0;
}

