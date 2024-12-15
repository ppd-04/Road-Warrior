#include "iGraphics.h"
#include <iostream>
#include <time.h>
#include <unistd.h>

#define kacheashargolpo 300
using namespace std;

int x = 300, y = 300, r = 20;

int player_x = 458, player_y = 0;
float v1_x = 324, v1_y = 650;
float v2_x = 588, v2_y = 450;
float v3_x = 550, v3_y = 750;
float v4_x = 290, v4_y = 1200;

int e = 10;

// For Coin
float c1_x = 200, c1_y = 571;
float c2_x = 366, c2_y = 595;
float c3_x = 615, c3_y = 594;
float c1_speed = 0, c2_speed = 0, c3_speed = 0;

int coin_score = 0;
int score = 0;

float bullet_x = 575, bullet_y = 505;

// recheck

float police_bullet_x = 300, police_bullet_y = 900;

// drawing variables
int home_page = 1;
int start_page = 0;
int about_page = 0;
int score_page = 0;
int settings_page = 0;
int instruction_page = 0;

int simple_page = 0;
int death_page = 0;

// clicking variables
int startbutton_click = 0;
int scorebutton_click = 0;
int aboutbutton_click = 0;
int exitbutton_click = 0;
int settingsbutton_click = 0;
int backbutton_click = 0;
int musicbutton_click = 0;

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

bool active_bullet = false;
bool active_police_bullet = false;

// int max_score = readMaxScore();

int player_life = 3;

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

bool music_gameover = false;

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

void simple_button_click();
void death_button_click();
void settings_button_click();

void collision();

void coin_collision();

void bullet_collision();

void increase_score();

void image_position_init();

void rendering();

int readMaxScore();

void writeMaxScore(int max);

void game_over();

// void draw_game_over();

void bullet_trigger();

void update_bullet();

void reset();

void increase_speed();
void police_bullet_trigger();
void update_police_bullet();
void police_bullet_collision();

void updateMusic();

void draw_simple_page();

void draw_death_page();
void draw_settings_page();

void toggleMusic();

int max_score = readMaxScore();

void iDraw()
{
	// place your drawing codes here
	iClear();

	if (home_page == 1)
	{
		drawHomePage();
	}
	else if (start_page == 1)
	{
		draw_start_page();
	}
	else if (about_page == 1)
	{
		draw_about_page();
	}
	else if (instruction_page == 1)
	{
		draw_instruction_page();
	}
	else if (score_page == 1)
	{
		draw_totalscore_page();
	}
	else if (simple_page == 1)
	{
		draw_simple_page();
	}
	else if (death_page == 1)
	{
		draw_death_page();
	}
	else if (settings_page == 1)
	{
		draw_settings_page();
	}
	else if (gameover == 1)
	{
		game_over();
	}
}

void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		printf("x = %d, y= %d\n", mx, my);

		if (home_page == 1)
		{
			if ((mx >= 6 && mx <= 189) && (my >= 11 && my <= 61))
			{
				start_button_click();
			}
			else if (((mx >= 416 && mx <= 600) && (my >= 4 && my <= 61)))
			{
				about_button_click();
			}
			else if (((mx >= 207 && mx <= 396) && (my >= 6 && my <= 61)))
			{
				instruction_button_click();
			}
			else if ((mx >= 619 && mx <= 806) && (my >= 6 && my <= 61))
			{
				totalscore_button_click();
			}
			else if ((mx >= 819 && mx <= 998) && (my >= 6 && my <= 61))
			{
				settings_button_click();
			}
		}
		// Ekhane jhamela hote pare!!!
		// Reminder Settings banano hoynai !!
		if (start_page == 1 || about_page == 1 || instruction_page == 1 || settings_page == 1 || score_page == 1 || game_over_page == 1 || death_page == 1 || simple_page == 1)
		{
			if ((mx >= 18 && mx <= 68) && (my >= 480 && my <= 529))
			{
				back_button_click();
			}
		}

		if (start_page == 1)
		{
			if ((mx >= 418 && mx <= 612) && (my >= 414 && my <= 465))
			{
				simple_button_click();
			}
			else if ((mx >= 418 && mx <= 612) && (my >= 310 && my <= 375))
			{
				death_button_click();
			}
		}

		if (settings_page == 1)
		{
			if ((mx >= 208 && mx <= 391) && (my >= 211 && my <= 397))
			{
				toggleMusic();
			}
			else if ((mx >= 509 && mx <= 780) && (my >= 240 && my <= 390))
			{
				exit(1);
			}
		}
		x += 10;
		y += 10;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		// place your codes here
		x -= 10;
		y -= 10;
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	if (key == 'q')
	{
		exit(0);
	}

	if (key == 'a' || key == 'A')
	{
		player_x = player_x - e;

		if (player_x < 180)
		{
			player_x = 180;
		}
		if (player_x > 650)
		{
			player_x = 650;
		}
	}

	if (key == 'd' || key == 'D')
	{
		player_x = player_x + e;

		if (player_x < 180)
		{
			player_x = 180;
		}
		if (player_x > 650)
		{
			player_x = 650;
		}
	}

	if (key == 'w' || key == 'W')
	{
		player_y = player_y + e;

		if (player_y > 600)
		{
			player_y = 600;
		}
	}

	if (key == 's' || key == 'S')
	{
		player_y = player_y - e;

		if (player_y < 0)
		{
			player_y = 0;
		}
	}

	if (key == 'm' || key == 'M')
	{
		if (key == 'a' || key == 'A')
		{
			player_x = player_x - e;

			if (player_x < 180)
			{
				player_x = 180;
			}
			if (player_x > 650)
			{
				player_x = 650;
			}
		}

		if (key == 'd' || key == 'D')
		{
			player_x = player_x + e;

			if (player_x < 180)
			{
				player_x = 180;
			}
			if (player_x > 650)
			{
				player_x = 650;
			}
		}

		if (key == 'w' || key == 'W')
		{
			player_y = player_y + e;

			if (player_y > 600)
			{
				player_y = 600;
			}
		}

		if (key == 's' || key == 'S')
		{
			player_y = player_y - e;

			if (player_y < 0)
			{
				player_y = 0;
			}
		}
	}
	// place your codes for other keys here
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
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (key == GLUT_KEY_RIGHT)
	{
		player_x = player_x + 10;

		if (player_x < 180)
		{
			player_x = 180;
		}
		if (player_x > 650)
		{
			player_x = 650;
		}
	}

	if (key == GLUT_KEY_LEFT)
	{
		player_x = player_x - 10;

		if (player_x < 180)
		{
			player_x = 180;
		}
		if (player_x > 650)
		{
			player_x = 650;
		}
	}

	if (key == GLUT_KEY_UP)
	{
		player_y = player_y + 10;

		if (player_y > 600)
		{
			player_y = 600;
		}
	}

	if (key == GLUT_KEY_DOWN)
	{
		player_y = player_y - 10;

		if (player_y < 0)
		{
			player_y = 0;
		}
	}

	if (key == GLUT_KEY_F1)
	{
		if (music)
		{
			music = false;
			PlaySound(0, 0, 0);
		}
		else
		{
			music = true;
			PlaySound("sounds\\Tropical.wav", NULL, SND_LOOP | SND_ASYNC);
		}
	}
}

void drawHomePage()
{

	// Reset case

	if (home_page == 1)
	{
		// reset();
		iSetColor(128, 128, 128);
		iFilledRectangle(0, 0, 1000, 600);
		iShowBMP(0, 0, "images\\NewOpen.bmp");

		// Buttons

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
		iText(630, 27, "Maximum Score", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(865, 27, "Settings", GLUT_BITMAP_TIMES_ROMAN_24);
	}
}

void draw_start_page()
{

	iShowBMP2(0, 0, "images\\catcar.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
	iShowBMP2(410, 400, "images\\Button\\button1.bmp", 0);
	iShowBMP2(410, 300, "images\\Button\\button2.bmp", 0);
	iText(480, 435, "Simple", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(480, 335, "Death", GLUT_BITMAP_TIMES_ROMAN_24);
}

void draw_about_page()
{

	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\AboutMe.bmp", 255);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
}

void draw_instruction_page()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\Instruction.bmp", 255);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
}

void draw_totalscore_page()
{
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 00, "images\\scoreBG\\score.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
	// iText(452, 430, "Maximum Score %d", max_score, "GLUT_BITMAP_TIMES");
	char max[50];
	sprintf(max, "Maximum Score is : %d", max_score);
	iSetColor(0, 0, 0);
	iText(452, 430, max, GLUT_BITMAP_HELVETICA_18);
	// iText(480, 335, "Maximum Score %d", GLUT_BITMAP_TIMES_ROMAN_24);
}

void start_button_click()
{
	home_page = 0;
	start_page = 1;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 0;
	death_page = 0;
}

void about_button_click()
{

	home_page = 0;
	start_page = 0;
	about_page = 1;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 0;
	death_page = 0;
}

void instruction_button_click()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 1;
	game_over_page = 0;
	simple_page = 0;
	death_page = 0;
}

void totalscore_button_click()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 1;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 0;
	death_page = 0;
}

void back_button_click()
{
	reset();
	home_page = 1;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	gameover = 0;
	simple_page = 0;
	death_page = 0;
}

void collision()
{

	if ((player_x + 50 >= v1_x && player_x <= v1_x + 50) && (player_y + 105 >= v1_y && player_y <= v1_y + 105))
	{

		if (--player_life >= 0)
		{
			v1_y = 630;
		}
		else
		{
			game_over();
		}
	}
	else if ((player_x + 50 >= v2_x && player_x <= v2_x + 50) && (player_y + 105 >= v2_y && player_y <= v2_y + 105))
	{
		if (--player_life >= 0)
		{
			v2_y = 700;
		}
		else
		{
			game_over();
		}
	}
	else if ((player_x + 70 >= v3_x && player_x <= v3_x + 70) && (player_y + 130 >= v3_y && player_y <= v3_y + 130))
	{
		if (--player_life != 0)
		{
			v3_y = 830;
		}
		else
		{
			game_over();
		}
	}
	else if ((player_x + 50 >= v4_x && player_x <= v4_x + 50) && (player_y + 117 >= v4_y && player_y <= v4_y + 117))
	{
		if (--player_life != 0)
		{
			v4_y = 1000;
		}
		else
		{
			game_over();
		}
	}
}

void coin_collision()
{
	if (flag_gameover)
		return;
	// Check collision with coin 1
	if ((player_x < c1_x + 50 && player_x + 50 > c1_x) &&
		(player_y < c1_y + 50 && player_y + 50 > c1_y))
	{

		coin_score += 5;
		score += 100;
		c1_speed += 10;

		c1_x += c1_speed;
		if (c1_x >= 680)
		{
			c1_x = 200;
		}
		if (c1_y == 0)
		{
			c1_y = 530;
		}
	}

	// Check collision with coin 2
	if ((player_x < c2_x + 50 && player_x + 50 > c2_x) &&
		(player_y < c2_y + 50 && player_y + 50 > c2_y))
	{

		coin_score += 5;
		score += 100;
		c2_speed += 10;
		c2_x += c2_speed;

		if (c2_x >= 680)
		{
			c2_x = 200;
		}
		if (c2_y == 0)
		{
			c2_y = 530;
		}
	}

	// Check collision with coin 3
	if ((player_x < c3_x + 50 && player_x + 50 > c3_x) &&
		(player_y < c3_y + 50 && player_y + 50 > c3_y))
	{
		coin_score += 5;
		score += 100;
		c3_speed += 10;
		c3_x += c3_speed;
		if (c3_x >= 680)
		{
			c3_x = 300;
		}
		if (c3_y == 0)
		{

			c3_y = 530;
		}
	}
}

void bullet_collision()
{
	if ((player_x + 30 >= bullet_x && player_x <= bullet_x + 30) && (player_y + 30 >= bullet_y && player_y <= bullet_y + 30))
	{

		if (--player_life != 0)
		{
			active_bullet = false;
		}
		else
		{
			game_over();
		}
	}
}

void police_bullet_collision()
{
	if ((player_x + 30 >= police_bullet_x && player_x <= police_bullet_x + 30) && (player_y + 30 >= police_bullet_y && player_y <= police_bullet_y + 30))
	{

		if (--player_life != 0)
		{
			active_police_bullet = false;
		}
		else
		{
			game_over();
		}
	}
}

void image_position_init()
{
	int i, j;

	for (i = 0, j = 0; i < count_image; i++)
	{
		image_position[i] = j;
		j = j + increment;
	}
}

void BackgroundMoving()
{
	int i;
	for (i = 0; i < count_image; i++)
	{
		image_position[i] = image_position[i] - increment;
	}

	for (i = 0; i < count_image; i++)
	{
		if (image_position[i] < 0)
		{
			image_position[i] = 600 - increment;
		}
	}
}

void rendering()
{
	for (int i = 0; i < count_image; i++)
	{
		iShowBMP2(0, image_position[i], image_path[i], 0);
	}
}

void increase_score()
{
	if (flag_gameover)
		return;
	if (start_page == 1 && !gameover)
	{
		score += 5;
	}
}

int readMaxScore()
{
	FILE *file = fopen("maxscore.txt", "r");
	if (!file)
	{
		return 0;
	}
	int maxScore;
	fscanf(file, "%d", &maxScore);
	fclose(file);
	return maxScore;
}

void writeMaxScore(int maxScore)
{
	FILE *file = fopen("maxscore.txt", "w");
	if (file)
	{
		fprintf(file, "%d", maxScore);
		fclose(file);
	}
}

void game_over()
{
	// For first car

	// New Part
	if (score > max_score)
	{
		max_score = score;
		writeMaxScore(max_score);
	}

	music = false;
	music_gameover = true;
	updateMusic();
	game_over_page = 1;
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	flag_gameover = 1;
	simple_page = 0;
	death_page = 0;

	gameover = 1;
	game_over_page = 1;
	iShowBMP2(0, 0, "images\\GameOver\\GameOver.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
	iSetColor(255, 255, 255);
	char scoreText[50];
	char max_score_Text[50];
	sprintf(scoreText, "Your Score is: %d", score);
	iText(450, 250, scoreText, GLUT_BITMAP_HELVETICA_18);

	iSetColor(255, 255, 255);
	sprintf(max_score_Text, "Maximum Score is : %d", max_score);
	iText(450, 200, max_score_Text, GLUT_BITMAP_HELVETICA_18);
	start_page = 0;
	home_page = 0;
}

void bullet_trigger()
{
	if (!active_bullet && player_x >= v3_x - 50 && player_x <= v3_x + 50)
	{
		active_bullet = true;
		bullet_x = v3_x + 25;
		bullet_y = v3_y;
	}
}

void police_bullet_trigger()
{
	if (!active_police_bullet && player_x >= v4_x - 50 && player_x <= v4_x + 50)
	{
		active_police_bullet = true;
		police_bullet_x = v4_x + 5;
		police_bullet_y = v4_y;
	}
}

void update_bullet()
{
	if (active_bullet)
	{
		bullet_y -= 10;

		if (bullet_y <= 0)
		{
			active_bullet = false;
		}
	}
}

void update_police_bullet()
{
	if (active_police_bullet)
	{
		police_bullet_y -= 12;

		if (police_bullet_y <= 0)
		{
			active_police_bullet = false;
		}
	}
}

void reset()
{
	x = 300, y = 300, r = 20;

	player_x = 458, player_y = 0;
	v1_x = 324, v1_y = 650;
	v2_x = 588, v2_y = 450;
	v3_x = 550, v3_y = 750;
	v4_x = 290, v4_y = 900;

	player_life = 3;

	e = 10;

	// For Coin
	c1_x = 200, c1_y = 571;
	c2_x = 366, c2_y = 595;
	c3_x = 615, c3_y = 594;
	c1_speed = 0, c2_speed = 0, c3_speed = 0;

	coin_score = 0;
	score = 0;

	bullet_x = 575, bullet_y = 455;

	// drawing variables
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	simple_page = 0;
	death_page = 0;

	// clicking variables
	startbutton_click = 0;
	scorebutton_click = 0;
	aboutbutton_click = 0;
	exitbutton_click = 0;

	backbutton_click = 0;

	// physics variables
	acceleration = 0;
	gameover = 0;
	flag_gameover = 0;

	count_image = 40;
	increment = 30;
	image_position[100];
	background_Y = 0;
	background_image_path = 0;
	game_over_page = 0;

	active_bullet = false;
	active_police_bullet = false;

	police_bullet_x = 300;
	police_bullet_y = 530;
	music_gameover = false;
	music = true;
	updateMusic();
}

void increase_speed()
{
	e++;
	if (e >= 25)
	{
		e = 25;
	}
}

void updateMusic()
{
	static bool isPlayingGameMusic = false;
	static bool isPlayingGameOverMusic = false;

	if (music && !isPlayingGameMusic)
	{
		PlaySound("sounds\\Tropical.wav", NULL, SND_LOOP | SND_ASYNC);
		isPlayingGameMusic = true;
		isPlayingGameOverMusic = false;
	}
	else if (music_gameover && !isPlayingGameOverMusic)
	{
		// PlaySound("sounds\\joybangla.wav", NULL, SND_LOOP | SND_ASYNC);
		PlaySound("sounds\\gameOver.wav", NULL, SND_LOOP | SND_ASYNC);
		isPlayingGameOverMusic = true;
		isPlayingGameMusic = false;
	}
}

void toggleMusic()
{
	if (music)
	{
		PlaySound(NULL, NULL, 0); // Stop any playing sounds
		music = false;
	}
	else
	{

		PlaySound("sounds\\Tropical.wav", NULL, SND_LOOP | SND_ASYNC); // Start playing music
		music = true;
	}
}

void draw_simple_page()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 1;
	iFilledRectangle(0, 0, 1000, 600);

	iShowBMP2(0, 0, "images\\BackgroundRoad\\resizedbgroad.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);
	// printf("Start page is active");

	rendering();

	iShowBMP2(player_x, player_y, "images\\VillainCars\\Car_1.bmp", 0);
	iShowBMP2(v1_x, v1_y, "images\\VillainCars\\Car_2.bmp", 0);
	iShowBMP2(v2_x, v2_y, "images\\VillainCars\\Car_3.bmp", 0);
	iShowBMP2(v3_x, v3_y, "images\\VillainCars\\Car_4.bmp", 0);
	iShowBMP2(v4_x, v4_y, "images\\VillainCars\\Car_5.bmp", 0);

	// Coin add
	iShowBMP2(c1_x, c1_y, "images\\coins\\CoinFinal1.bmp", 0);
	iShowBMP2(c2_x, c2_y, "images\\coins\\CoinFinal2.bmp", 0);
	iShowBMP2(c3_x, c3_y, "images\\coins\\CoinFinal3.bmp", 0);

	// Display Score

	iSetColor(255, 255, 255);

	v1_y = v1_y - 1.5;

	// Reset villain car if it moves out of the screen
	if (v1_y <= 0)
	{
		v1_y = 630;
		v1_x = 195 + rand() % 271;
	}

	collision();

	v2_y -= 5;

	// Reset the second villain car when it goes out of the screen
	if (v2_y <= 0)
	{
		v2_y = 700;
		v2_x = 427 + rand() % 225;
	}

	collision();

	if (abs(v1_x - v2_x) <= 60 && abs(v1_y - v2_y) <= 60)
	{
		if (v1_x < v2_x)
		{
			v2_x += 10;
		}
		else
		{
			v2_x -= 10;
		}
	}

	collision();

	// For Tank

	v3_y = v3_y - 1;

	// Reset villain car if it moves out of the screen
	if (v3_y <= 0)
	{
		v3_y = 530;
		v3_x = 195 + rand() % 271;
	}

	collision();

	if (abs(v3_x - v2_x) <= 80 && abs(v2_y - v3_y) <= 80)
	{
		if (v3_x < v2_x)
		{
			v2_x += 10;
		}
		else
		{
			v2_x -= 10;
		}
	}

	collision();

	if (abs(v3_x - v1_x) <= 80 && abs(v1_y - v3_y) <= 80)
	{
		if (v3_x < v1_x)
		{
			v1_x += 10;
		}
		else
		{
			v1_x -= 10;
		}
	}

	collision();

	v4_y = v4_y - 2;
	collision();
	if (v4_y <= 0)
	{
		v4_y = 830;
		v4_x = 195 + rand() % 271;
	}
	collision();
	// police_bullet_collision();

	if (abs(v1_x - v4_x) <= 100 && abs(v4_y - v1_y) <= 100)
	{
		if (v1_x < v4_x)
		{
			v4_x += 10;
		}
		else
		{
			v4_x -= 10;
		}
	}

	if (abs(v2_x - v4_x) <= 100 && abs(v4_y - v2_y) <= 100)
	{
		if (v2_x < v4_x)
		{
			v4_x += 10;
		}
		else
		{
			v4_x -= 10;
		}
	}

	if (abs(v3_x - v4_x) <= 100 && abs(v4_y - v3_y) <= 100)
	{
		if (v3_x < v4_x)
		{
			v4_x += 10;
		}
		else
		{
			v4_x -= 10;
		}
	}

	// For coin

	// C1

	c1_y = c1_y - 15;

	if (c1_y <= 0)
	{
		c1_y = 530;
		c1_x = 177 + rand() % 110;
	}
	coin_collision();

	// C2

	c2_y = c2_y - 12;

	if (c2_y <= 0)
	{
		c2_y = 530;
		c2_x = 302 + rand() % 182;
	}
	coin_collision();

	c3_y = c3_y - 13;

	if (c3_y <= 0)
	{
		c3_y = 530;
		c3_x = 525 + rand() % 131;
	}
	coin_collision();
}

void draw_death_page()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	death_page = 1;
	iFilledRectangle(0, 0, 1000, 600);

	iShowBMP2(0, 0, "images\\BackgroundRoad\\resizedbgroad.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 0);

	rendering();

	iShowBMP2(player_x, player_y, "images\\VillainCars\\Car_1.bmp", 0);
	iShowBMP2(v1_x, v1_y, "images\\VillainCars\\Car_2.bmp", 0);
	iShowBMP2(v2_x, v2_y, "images\\VillainCars\\Car_3.bmp", 0);
	iShowBMP2(v3_x, v3_y, "images\\VillainCars\\Hull_02.bmp", 0);
	iShowBMP2(v4_x, v4_y, "images\\VillainCars\\police_bike.bmp", 0);

	// Coin add
	iShowBMP2(c1_x, c1_y, "images\\coins\\CoinFinal1.bmp", 0);
	iShowBMP2(c2_x, c2_y, "images\\coins\\CoinFinal2.bmp", 0);
	iShowBMP2(c3_x, c3_y, "images\\coins\\CoinFinal3.bmp", 0);

	// Display Score

	iSetColor(255, 255, 255);

	v1_y = v1_y - 1.5;

	// Check if the villain car is close to the player's car
	if (abs(player_x - v1_x) <= kacheashargolpo && abs(player_y - v1_y) <= kacheashargolpo)
	{

		if (player_x > v1_x)
		{
			v1_x += 2;
		}
		else
		{
			v1_x -= 2;
		}
	}

	if (v1_y <= 0)
	{
		v1_y = 630;
		v1_x = 195 + rand() % 271;
	}

	collision();

	if (v3_y <= 530 && active_bullet)
	{
		iShowBMP2(bullet_x, bullet_y, "images\\Bullets\\police_bullet.bmp", 0);
	}

	bullet_trigger();
	update_bullet();
	bullet_collision();
	bullet_collision();

	// For v2

	v2_y -= 5;

	if (abs(player_x - v2_x) <= kacheashargolpo && abs(player_y - v2_y) <= kacheashargolpo)
	{

		if (player_x > v2_x)
		{
			v2_x += 2; // Move right
		}
		else
		{
			v2_x -= 2; // Move left
		}
	}

	if (v2_y <= 0)
	{
		v2_y = 700;
		v2_x = 427 + rand() % 225;
	}

	// Check for collision
	collision();

	if (abs(v1_x - v2_x) <= 60 && abs(v1_y - v2_y) <= 60)
	{
		if (v1_x < v2_x)
		{
			v2_x += 10;
		}
		else
		{
			v2_x -= 10;
		}
	}

	collision();

	// For Tank

	v3_y = v3_y - 1;

	if (abs(player_x - v3_x) <= kacheashargolpo && abs(player_y - v3_y) <= kacheashargolpo)
	{
		if (player_x > v3_x)
		{
			v3_x += 2; // Move right
		}
		else
		{
			v3_x -= 2; // Move left
		}
	}
	collision();

	// Reset villain car if it moves out of the screen
	if (v3_y <= 0)
	{
		v3_y = 530;
		v3_x = 195 + rand() % 271;
	}

	collision();

	// For avoiding collision with Tank and villain cars

	if (abs(v3_x - v2_x) <= 80 && abs(v2_y - v3_y) <= 80)
	{
		if (v3_x < v2_x)
		{
			v2_x += 10;
		}
		else
		{
			v2_x -= 10;
		}
	}

	// Check for collision with the player
	collision();

	if (abs(v3_x - v1_x) <= 80 && abs(v1_y - v3_y) <= 80)
	{
		if (v3_x < v1_x)
		{
			v1_x += 10;
		}
		else
		{
			v1_x -= 10;
		}
	}

	collision();

	// For Police Bike

	v4_y = v4_y - 5;
	if (v4_y <= 0)
	{
		v4_y = 830;
		v4_x = 195 + rand() % 271;
	}
	collision();
	police_bullet_collision();

	if (abs(v1_x - v4_x) <= 60 && abs(v4_y - v1_y) <= 60)
	{
		if (v1_x < v4_x)
		{
			v4_x += 10;
		}
		else
		{
			v4_x -= 10;
		}
	}

	if (abs(v2_x - v4_x) <= 60 && abs(v4_y - v2_y) <= 60)
	{
		if (v2_x < v4_x)
		{
			v4_x += 10;
		}
		else
		{
			v4_x -= 10;
		}
	}

	if (abs(v3_x - v4_x) <= 60 && abs(v4_y - v3_y) <= 60)
	{
		if (v3_x < v4_x)
		{
			v4_x += 10;
		}
		else
		{
			v4_x -= 10;
		}
	}
	// collision();

	if (v4_y <= 530 && active_police_bullet)
	{
		iShowBMP2(police_bullet_x, police_bullet_y, "images\\Bullets\\bullet.bmp", 0);
	}

	police_bullet_trigger();
	update_police_bullet();
	police_bullet_collision();

	// For coin

	// C1

	c1_y = c1_y - 15;

	if (c1_y <= 0)
	{
		c1_y = 530;
		c1_x = 177 + rand() % 110;
	}
	coin_collision();

	// C2

	c2_y = c2_y - 12;

	if (c2_y <= 0)
	{
		c2_y = 530;
		c2_x = 302 + rand() % 182;
	}
	coin_collision();

	c3_y = c3_y - 13;

	if (c3_y <= 0)
	{
		c3_y = 530;
		c3_x = 525 + rand() % 131;
	}
	coin_collision();
}

void simple_button_click()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 1;
	death_page = 0;
}

void death_button_click()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 0;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 0;
	death_page = 1;
}

void settings_button_click()
{
	home_page = 0;
	start_page = 0;
	about_page = 0;
	score_page = 0;
	settings_page = 1;
	instruction_page = 0;
	game_over_page = 0;
	simple_page = 0;
	death_page = 0;
}

void draw_settings_page()
{
	// printf("Drawing Settings Page");
	iFilledRectangle(0, 0, 1000, 600);
	iShowBMP2(0, 0, "images\\settingsBG.bmp", 255);
	iShowBMP2(200, 200, "images\\MusicButton.bmp", 0);
	iShowBMP2(20, 475, "images\\Buttons\\Resizeback.bmp", 255);
	iSetColor(0, 0, 0);
	iText(270, 420, "Music ", GLUT_BITMAP_HELVETICA_18);
	iShowBMP2(495, 210, "images\\exitb.bmp", 0);
}

int main()
{

	srand(time(0));
	updateMusic();
	image_position_init();

	iSetTimer(10, BackgroundMoving);
	iSetTimer(1000, increase_score);
	iSetTimer(2000, increase_speed);
	iInitialize(1000, 600, "Road Warrior");
	return 0;
}
