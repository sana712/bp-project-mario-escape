//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include <conio.h>
#include <Windows.h>
#include <stdbool.h>



#ifndef ColorsDefine
#define Red "\x1b[38;2;255;0;0m"
#define Blue "\x1b[38;2;0;191;255m"
#define Green "\x1b[38;2;0;255;0m"
#define Yellow "\x1b[38;2;255;255;0m"
#define Purple "\x1b[38;2;128;0;128m"
#define Orange "\x1b[38;2;255;165;0m"
#define Pink "\x1b[38;2;248;160;184m"
#define Cyan "\x1b[38;2;160;184;248m"
#define BrightRed "\x1b[38;2;248;96;96m"
#define BrightBlue "\x1b[38;2;96;96;248m"
#define LavenderBlush "\x1b[38;2;49;79;79m"
#define Brown "\x1b[38;2;139;69;19m" 
#define Reset "\x1b[0m"
#endif


#ifdef _WIN32
#include <windows.h>
#define SLEEP(milliseconds) Sleep(milliseconds)
#else
#include <unistd.h>
#define SLEEP(milliseconds) usleep(milliseconds * 1000)
#endif

typedef struct profile {
	int id;
	char username[30] ;
	char email[30] ;
	char password[9] ;
	int points; 
	int coins;
	int wins;   
	int losses; 
}profile;


typedef struct users {
	struct profile data;
	struct users* next;
}users;

typedef struct history {
	int id;
	int matchID;     
	int wins;        
	int lose;        
	int coins;        
	int points;       
} history;



void gotoxy(int x, int y) {
	COORD coord;
	coord.X = y;
	coord.Y = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void inputEROR() {
	system("cls||clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\ \033[1;31m% WRONG INPUTE!!!!TRY AGAIN\033[0m");
	Sleep(1500);
	system("cls||clear");
}


void firstwellcome() {
	SetConsoleOutputCP(CP_UTF8);
	system("cls||clear");
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t");
	char wellcome[30] = " WELLCOME TO  MARIO ESCAPE🍄";
	printf(Blue);
	for (int i = 0; i < 30; i++) {
		printf("%c", wellcome[i]);
		SLEEP(85);
	}
	printf(Reset);
	printf("\n\n\t\t\t\t\t\t\t\t");
	char creator[35] = "DEVELOPED BY Sana";
	for (int i = 0; i < 19; i++) {
		printf("\033[1;34m%c\033[0m", creator[i]);
		SLEEP(200);
	}
	SLEEP(4000);
	system("cls||clear");
}

void printwelcome() {

	printf(Red);
	printf("                           oooo  oooo                                                  \n");
	printf("                           `888  `888                                                  \n");
	printf("oooo oooo    ooo  .ooooo.   888   888   .ooooo.    .ooooo.  ooo. .oo.  .oo.    .ooooo.  \n");
	printf(" `88. `88.  .8'  d88' `88b  888   888  d88' ` `Y  d88' `88b `888P`Y88bP`Y88b  d88' `88b \n");
	printf("  `88..]88..8'   888ooo888  888   888  888        888   888  888   888   888  888ooo888 \n");
	printf("   `888'`888'    888     .  888   888  888   .o8  888   888  888   888   888  888     . \n");
	printf("    `8'  `8'     `Y8bod8P' o888o o888o `Y8bod8P'  `Y8bod8P' o888o o888o o888o `Y8bod8P' \n");
	printf("                                                                                       \n");
	printf(Reset);
}

users* readfile() {
	FILE* ppp;
	fopen_s(&ppp, "D:\\BP project\\FILE\\users.bin", "r+b");
	if (ppp == NULL) {
		fopen_s(&ppp, "D:\\BP project\\FILE\\users.bin", "w+b");
	}
	if (ppp == NULL) {
		printf("opening file failed");
		return 0;
	}
	users temp;
	users* head = NULL;
	for (; fread(&temp.data, sizeof(profile), 1, ppp) > 0;) {
		users* newnode = (users*)malloc(sizeof(users));
		newnode->data = temp.data;
		newnode->next = NULL;
		newnode->data.points = temp.data.points;

		if (head == NULL)
		{
			head = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}
	fclose(ppp);
	if (head == NULL)
	{
		head = (struct users*)malloc(sizeof(struct users));
		head->next = NULL;
		head->data.id = 0;
		head->data.points = 0;
	}
	return head;
}
void savedata(users* head) {

	FILE* ppp;
	fopen_s(&ppp, "D:\\BP project\\FILE\\users.bin", "wb");
	while (head != NULL)
	{
		fwrite(&head->data, sizeof(struct profile), 1, ppp);
		head = head->next;
	}
	fclose(ppp);
}


void signup(users** head) {
	system("cls||clear");
	printf(Green);
	printf("enter 1 to exit\n");
	printf("please enter your user name:");
	printf(Reset);
	/*int id = 0;*/
	char inputusername[30] = { '\0' };
	char emailaddress[30] = { '\0' };
	char inputpassword[30] = { '\0' };
	char confirmpassword[30] = { '\0' };

	users* temp;
	temp = *head;
	scanf("%s", inputusername);
	getchar();
	if (strcmp(inputusername, "1") == 0) {
		system("cls||clear");
		return;
	}
	for (;;) {
		int t = strcmp(temp->data.username, inputusername);
		if (t == 0) {
			system("cls||clear");
			printf(Red);
			printf("This user name is already exist");
			printf(Reset);
			Sleep(2000);
			signup(head);
			return;
		}
		if (temp->next == NULL) {
			break;
		}
		temp = temp->next;
	}
	system("cls||clear");
	printf(Yellow);
	printf("Hiiiiii %s", inputusername);
	printf(Reset);
	Sleep(2000);
	for (;;) {
		system("cls||clear");
		printf(Green);
		printf("please enter your password:\n");
		printf(Reset);
		for (int i = 0; i < 30; ++i) {
			inputpassword[i] = '\0';
		}
		for (int i = 0; i < 30; ++i) {
			confirmpassword[i] = '\0';
		}
		for (int i = 0;;) {
			char t = _getch();
			if (t == '\r') {
				inputpassword[i] = '\0';
				break;
			}
			else if (t == '\b' && i > 0) {
				printf("\b \b");
				i--;
				continue;
			}
			if (t == '\b' && i == 0)continue;
			printf("*");
			inputpassword[i] = t;
			i++;
		}
		if (strlen(inputpassword) < 8) {
			system("cls||clear");
			printf(Red);
			printf("your password is too short!\nit must be more than 8 characters");
			printf(Reset);
			Sleep(2000);
			system("cls||clear");
			continue;
		}
		printf("\n");
		printf(Green);
		printf("please confirm your password\n");
		printf(Reset);
		for (int i = 0;; ) {
			char t = _getch();
			if (t == '\r') {
				confirmpassword[i] = '\0';
				break;
			}
			else if (t == '\b' && i > 0) {
				printf("\b \b");
				i--;
				continue;
			}
			if (t == '\b' && i == 0)continue;
			printf("*");
			confirmpassword[i] = t;
			i++;
		}

		if (strcmp(inputpassword, confirmpassword) != 0) {
			system("cls||clear");
			printf(Red);
			printf("password confirmation failed");
			printf(Reset);
			Sleep(2000);
			continue;
		}
		system("cls||clear");
		printf(Green);
		printf("please enter your email\n");
		printf(Reset);
		gets_s(emailaddress, sizeof(emailaddress));
		system("cls||clear");
		printf(Pink);
		printf("your account successfully created");
		printf(Reset);
		Sleep(2000);
		system("cls||clear");
		break;
	}
	if (temp->data.id != 0) {
		users* newnode = (users*)malloc(sizeof(users));
		int maxID = 0;
		users* maxfinder = *head;
		for (; maxfinder != NULL;) {
			if (maxfinder->data.id > maxID)maxID = maxfinder->data.id;
			maxfinder = maxfinder->next;
		}
		strcpy_s(temp->data.username, sizeof(temp->data.username), inputusername);
		strcpy_s(temp->data.password, sizeof(temp->data.password), inputpassword);
		strcpy_s(temp->data.email, sizeof(temp->data.email), emailaddress);
		newnode->data.id = (maxID + 1);
		temp->next = newnode;
		newnode->next = NULL;
		newnode->data.points = 0;
		return;
	}
	/*id++;*/
	strcpy_s(temp->data.username, sizeof(temp->data.username), inputusername);
	strcpy_s(temp->data.password, sizeof(temp->data.password), inputpassword);
	strcpy_s(temp->data.email, sizeof(temp->data.email), emailaddress);
	temp->data.id = 1;
	temp->data.points = 0;
	*head = temp;
}

profile signin(users** head) {
	for (;;) {
		system("cls||clear");
		printf(Blue);
		printf("please enter your user name: ");
		printf(Reset);
		char inputusername[20];
		gets_s(inputusername, sizeof(inputusername));
		users* temp;
		temp = *head;
		int userfound = 0;
		for (; temp != NULL;) {
			if (strcmp(temp->data.username, inputusername) != 0) {
				temp = temp->next;
				continue;
			}
			userfound = 1;
			break;
		}
		if (userfound == 0) {
			system("cls||clear");
			printf(Red);
			printf("user not found!");
			printf(Reset);
			Sleep(2000);
			continue;
		}
		system("cls||clear");
		printf(Yellow);
		printf("Hiiii %s", inputusername);
		printf(Reset);
		Sleep(2000);
		for (;;) {
			system("cls||clear");
			printf(Blue);
			printf("1 - Enter password\n\n2 - Forgot PASSWORD\n\n");
			printf(Reset);
			char choice[50];
			gets_s(choice, sizeof(choice));
			if (strlen(choice) > 1) {
				inputEROR();
				continue;
			}
			if (choice[0] == '1')
			{
				for (;;) {
					char inputepassword[30] = { '\0' };
					system("cls||clear");
					printf(Blue);
					printf("Please enter your password:\n ");
					printf(Reset);
					for (int i = 0;; ) {
						char t = _getch();

						if (t == '\r') {
							inputepassword[i] = '\0';
							break;
						}
						else if (t == '\b' && i > 0) {
							printf("\b \b");
							i--;
							continue;
						}
						if (t == '\b' && i == 0)continue;
						printf("*");
						inputepassword[i] = t;
						i++;
					}
					system("cls||clear");
					if (strcmp(inputepassword, temp->data.password) != 0) {
						printf(Red);
						printf("Password is WRONG!\ntry again\n");
						printf(Reset);
						Sleep(2000);
						continue;
					}
					printwelcome();
					Sleep(2000);
					system("cls||clear");
					return temp->data;
				}
			}
			if (choice[0] == '2')
			{
				for (;;) {
					system("cls||clear");
					printf(Blue);
					printf("please enter your email address: ");
					printf(Reset);
					char inputemail[30] = { '\0' };
					gets_s(inputemail , sizeof(inputemail));
					if (strcmp(inputemail, temp->data.email) != 0) {
						system("cls||clear");
						printf(Red);
						printf("email address is wrong!\ntry again\n");
						printf(Reset);
						Sleep(2000);
						continue;
					}
					break;
				}
				for (;;) {
					system("cls||clear");
					printf(Green);
					printf("Reset Password\n\n");
					printf(Blue);
					printf("please enter your new password:\n");
					printf(Reset);
					char inputepassword[30] = { '\0' };
					for (int i = 0;; i++) {
						char t = _getch();
						if (t == '\r') {
							inputepassword[i] = '\0';
							break;
						}
						else if (t == '\b' && i > 0) {
							printf("\b \b");
							i--;
							continue;
						}
						if (t == '\b' && i == 0)continue;
						printf("*");
						inputepassword[i] = t;
					}
					if (strlen(inputepassword) < 8) {
						system("cls||clear");
						printf(Red);
						printf("your password is too short!\nit must be more than 8 characters");
						printf(Reset);
						Sleep(2000);
						system("cls||clear");
						continue;
					}
					printf("\n");
					printf(Blue);
					printf("please confirm your password:\n");
					printf(Reset);
					char confirmpassword[30] = { '\0' };
					for (int i = 0;; i++) {
						char t = _getch();
						if (t == '\r') {
							confirmpassword[i] = '\0';
							break;
						}
						else if (t == '\b' && i > 0) {
							printf("\b \b");
							i--;
							continue;
						}
						if (t == '\b' && i == 0)continue;
						printf("*");
						confirmpassword[i] = t;
					}
					int t = strcmp(inputepassword, confirmpassword);
					if (t != 0) {
						system("cls||clear");
						printf(Red);
						printf("password confirmation failed");
						printf(Reset);
						SLEEP(2000);
						system("cls||clear");
						continue;
					}
					system("cls||clear");
					printf(Green);
					printf("password changed");
					printf(Reset);
					SLEEP(2000);
					system("cls||clear");
					strcpy_s(temp->data.password,sizeof(temp->data.password), inputepassword);
					return temp->data;
				}




			}
			else {
				inputEROR();
				continue;
			}



		}
	}
}

void Changeuserinformation(users** head, users* temp) {
	FILE* hhh;
	fopen_s(&hhh, "D:\\BP project\\history.bin", "r+b");
	for (;;) {

		system("cls||clear");
		printf("1-Change username\n\n2-Change password\n\n3-Change email address\n\n4-back\n");
		char choice[50];
		gets_s(choice, sizeof(choice));
		if (strlen(choice) > 1) {
			inputEROR();
			continue;
		}
		if (choice[0] == '1') {
			for (;;) {
				system("cls||clear");
				printf("please enter your new username:");
				char inputeusername[30] = { '\0' };
				gets_s(inputeusername, sizeof(inputeusername));
				users* check = *head;
				int change = 0;
				for (;;) {
					if (strcmp(inputeusername, temp->data.username) == 0) {
						system("cls||clear");
						printf("This is your username!\nchange it :) ");
						Sleep(2000);
						break;
					}

					if (strcmp(check->data.username, inputeusername) == 0) {
						system("cls||clear");
						printf("This user name is already exist");
						Sleep(2000);
						break;
					}

					if (check->next == NULL) {
						change = 1;
						break;
					}
					check = check->next;
				}
				if (change == 0) {
					continue;
				}

				strcpy(temp->data.username, inputeusername);
				system("cls||clear");
				printf("User name changed");
				Sleep(2000);
				break;
			}

		}


		else if (choice[0] == '2') {

			for (;;) {
				system("cls||clear");
				printf("please enter your new password:\n");
				char inputepassword[30] = { '\0' };
				for (int i = 0;; i++) {
					char t = _getch();
					if (t == '\r') {
						break;
					}
					printf("*");
					inputepassword[i] = t;
				}
				if (strlen(inputepassword) < 8) {
					system("cls||clear");
					printf("your password is too short!\nit must be more than 8 characters");
					Sleep(2000);
					system("cls||clear");
					continue;
				}
				printf("\n");
				printf("please confirm your password:\n");
				char confirmpassword[30] = { '\0' };
				for (int i = 0;; i++) {
					char t = _getch();
					if (t == '\r') {
						break;
					}
					printf("*");
					confirmpassword[i] = t;
				}
				if (strcmp(inputepassword, confirmpassword) != 0) {
					system("cls||clear");
					printf("password confirmation failed");
					Sleep(2000);
					system("cls||clear");
					continue;
				}
				system("cls||clear");
				strcpy_s(temp->data.password,sizeof(temp->data.password), inputepassword);
				printf("password changed");

				Sleep(2000);
				system("cls||clear");
				break;
			}

		}



		else if (choice[0] == '3') {
			char newemail[30] = { '\0' };
			system("cls||clear");
			printf("please enter your new email address:");
			gets_s(newemail , sizeof(newemail));
			strcpy(temp->data.email, newemail);
			system("cls||clear");
			printf("your email updated");
			Sleep(2000);
		}
		else if (choice[0] == '4') {
			return;
		}
		else {
			inputEROR();
			continue;
		}
	}




}

void readhistory(users user, users* head) {
	system("cls||clear");
	FILE* hhh;
	fopen_s(&hhh, "D:\\BP project\\FILE\\history.bin", "rb");
	if (hhh == NULL) {
		system("cls||clear");
		printf(Red);
		printf("History is empty!!!");
		printf(Reset);
		_getch();
		return;
	}

	history temp;
	int playedanygame = 0;
	printf("\tMatch ID\tWins\tLosses\tCoins\tPoints\n");
	printf(Cyan);
	printf(" ----------------------------------------------------------\n");

	int matchID = 1;
	int totalWins = 0, totalLosses = 0, totalCoins = 0, totalPoints = 0;  // متغیرهای جمع‌آوری اطلاعات
	while (fread(&temp, sizeof(history), 1, hhh) > 0) {
		// فقط تاریخچه بازی‌هایی که کاربر در آن‌ها حضور داشته باشد را نمایش می‌دهیم
		if (temp.id == user.data.id ) {
			printf(Cyan);
			printf("| ");
			printf(Yellow);
			printf("%d", matchID);
			printf(Cyan);
			printf("\t");
			printf(Green);
			printf("%d", temp.wins);
			printf(Cyan);
			printf("\t");
			printf(Red);
			printf("%d", temp.lose);
			printf(Cyan);
			printf("\t");
			printf(Yellow);
			printf("%d", temp.coins);
			printf(Cyan);
			printf("\t");
			printf(Purple);
			printf("%d", temp.points);
			printf(Cyan);
			printf("\n");
			printf(" ----------------------------------------------------------\n");

			// جمع‌آوری امتیازات و سکه‌ها
			totalWins += temp.wins;
			totalLosses += temp.lose;
			totalCoins += temp.coins;
			totalPoints += temp.points;

			playedanygame = 1;
			matchID++;
		}
	}
	fclose(hhh);

	// اگر بازی انجام نشده باشد
	if (playedanygame == 0) {
		system("cls||clear");
		printf(Red);
		printf("You have not played any games !!!");
		printf(Reset);
	}

	// نمایش امتیاز کل و سکه‌ها
	printf(Purple);
	printf("\nTotal Score: ");
	if (user.data.points >= 0) printf(Yellow);
	else printf(Red);
	printf("%d", totalPoints);  // امتیاز کل بازی‌ها
	printf(Cyan);
	printf("\nTotal Coins: ");
	if (user.data.coins >= 0) printf(Yellow);
	else printf(Red);
	printf("%d", totalCoins);  // سکه‌های کل بازی‌ها
	printf(Reset);

	_getch();
	system("cls||clear");
}

void savehistory(history histo) {
	FILE* hhh;
	fopen_s(&hhh, "D:\\BP project\\FILE\\history.bin", "ab"); // باز کردن فایل به صورت append (برای افزودن اطلاعات جدید)
	if (hhh == NULL) {
		printf("Error opening file\n");
		return;
	}
	fwrite(&histo, sizeof(history), 1, hhh); // نوشتن اطلاعات تاریخچه در فایل
	fclose(hhh);
}


int gamemenu(users** head, char username[30]) {
	users* temp = *head;
	while (temp != NULL && strcmp(temp->data.username, username) != 0) {
		temp = temp->next;
	}

	if (temp == NULL) {
		printf("User not found!\n");
		return 0;
	}

	for (;;) {
		system("cls||clear");
		printf("GAME MENU\n\n1- Start game\n2- Change user information\n3- History\n4- Return to login page\n");

		char choice[50];
		gets_s(choice , sizeof(choice));

		if (strlen(choice) > 1) {
			inputEROR();
			continue;
		}

		switch (choice[0]) {
		case '1':
			return 1;

		case '2':
			Changeuserinformation(head, temp);
			savedata(*head);
			break;

		case '3':
			readhistory(*temp, *head);
			break;

		case '4':
			return 0;

		default:
			inputEROR();
			break;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int map1[15][65];
int flagmap1 = 1;
int flowerX1 = 4, flowerY1 = 47;  
int flowerX2 = 8, flowerY2 = 39; 
int flowerState1 = 0, flowerState2 = 0; 
time_t lastTime = 0;

// موقعیت‌ها و جهت‌های حرکت هشت‌پاها
int octopusX[3] = { 12, 12, 12 };  // X برای همه هشت‌پاها
int octopusY[3] = { 55, 57, 20 };
int octopusDir[3] = { 1, -1, 1 };  // جهت حرکت (1 برای راست، -1 برای چپ)

extern int map1[15][65];
int marioX = 10, marioY = 10;  // موقعیت ماریو
bool isMarioJumping = false;  // وضعیت پرش
int jumpHeight = 4, jumpStep = 0;
HANDLE lock;
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// تابع حرکت تمام هشت‌پاها

// تبدیل مقدار نقشه به کاراکتر
void converttochar1(int i, int j) {
	SetConsoleOutputCP(CP_UTF8);
	if (map1[i][j] == 2) {
		
		printf("🧱");
		
	}
	else if (map1[i][j] == 1) {
		printf("🦸");
	}
	else if (map1[i][j] == 8) {
		printf("\033[0;32m██\033[0m"); // سبز
	}
	else if (map1[i][j] == 0) {
		printf("  ");
	}
	else if (map1[i][j] == 3) {
		printf("🟧");
	}
	else if (map1[i][j] == 4) {
		printf("🟨");
	}
	else if (map1[i][j] == 5) {
		printf("🪙");
	}
	else if (map1[i][j] == 6) {
		printf("🦖");
	}
	else if (map1[i][j] == 7) {
		printf("🌱");
	}
	else if (map1[i][j] == 9) {
		printf("██");
	}
	else if (map1[i][j] == 10) {
		printf("🚩");
	}
	else if (map1[i][j] == 11) {
		printf("\033[0;32m██\033[0m"); // سبز
	}
	else if (map1[i][j] == 12) {
		printf("🐙");
	}
}


// مقداردهی نقشه

	void creatmap1() {

		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 65; j++) {
				map1[i][j] = 0; 
			}
		}


		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 64; j++) {
				if (i == 0 || i == 13) {
					map1[i][j] = 2;
				}
				if (j == 0 || j == 63) {
					map1[i][j] = 2;
				}
				if (i == 1) {
					if (j == 24) {
						map1[i][j] = 8;
					}
				}
				if (i == 2) {
					if (j == 24) {
						map1[i][j] = 8;
					}
				}
				if (i == 3) {
					if (j == 23 || j == 24 || j == 25) {
						map1[i][j] = 11;
					}
				}
				if (i == 4) {
					
					 if (j == 18)
					{
						map1[i][j] = 10;
					}
					else if (j == 28 || j == 29) {
						map1[i][j] = 5;
					}
					else if (j == 47) {
						map1[i][j] = 7;
					}
				}
				if (i == 5) {
					if (j == 18 || j == 19 || j == 20 || j == 28 || j == 29 || j == 30) {
						map1[i][j] = 2;
					}
					else if (j == 46 || j == 47 || j == 48) {
						map1[i][j] = 9;
					}
				}
				if (i == 6) {
					
					 if (j == 47) {
						map1[i][j] = 9;
					}
				}
				if (i == 7) {
					if (j == 42 || j == 43 || j == 44 || j == 47) {
						map1[i][j] = 9;
					}
					else if (j == 23 || j == 24 || j == 25||j == 26|| j == 22) {
						map1[i][j] = 2;
					}
				}
				if (i == 8)
				{
					if (j == 3 || j == 4 || j == 5) {
						map1[i][j] = 2;
					}
					else if (j == 7 || j == 8) {
						map1[i][j] = 5;
					}
					else if (j == 47 || j == 43) {
						map1[i][j] = 9;
					}
					if (j == 39) {     //موقعیت گل
						map1[i][j] = 7;
					}

				}
				if (i == 9)
				{
					if (j == 7 || j == 8 || j == 10 || j == 51 || j == 54) {
						map1[i][j] = 2;
					}
					else if (j == 52 || j == 53) {
						map1[i][j] = 3;
					}
					
					else if (j == 38 || j == 39 || j == 40 || j == 43 || j == 47) {
						map1[i][j] = 9;
					}
					else if (j == 9) {
						map1[i][j] = 4;
					}

				}
				if (i == 10) {
					if (j == 12 || j == 13 || j == 14 || j == 51 || j == 54) {
						map1[i][j] = 2;
					}
					else if (j == 59 || j == 60 || j == 61) {
						map1[i][j] = 11;
					}
					else if (j == 39 || j == 43 || j == 47) {
						map1[i][j] = 9;
					}
				}
				if (i == 11) {
					if (j == 51 || j == 54) {
						map1[i][j] = 2;
					}
					else if (j == 60) {
						map1[i][j] = 8;
					}
					else if (j == 39 || j == 43 || j == 47 || j == 34 || j == 35 || j == 36) {
						map1[i][j] = 9;
					}

				}
				if (i == 12) {

					if (j == 19 || j == 18) {
						map1[i][j] = 5;
					}
					else if (j == 20 || j == 55 || j == 57) {
						map1[i][j] = 12;
					}
					else if (j == 51) {
						map1[i][j] = 2;
					}
					else if (j == 60) {
						map1[i][j] = 8;
					}
					else if (j == 39 || j == 43 || j == 47 || j == 35) {
						map1[i][j] = 9;
					}
					else if (j == 37 || j == 41 || j == 45 || j == 49) {
						map1[i][j] = 6;
					}
					/*else if (j == 2) {
						map1[i][j] = 1;
					}*/
				}


			}
		}
	}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void printMap1() {
		for (int i = 0; i < 14; i++) {
			for (int j = 0; j < 64; j++) {
				converttochar1(i, j);  // چاپ خانه‌های نقشه
			}
			printf("\n");
		}
	}

	// تابعی برای تغییر وضعیت گل‌ها
	void toggleFlowers() {
		if (flowerState1 == 0) {
			map1[flowerX1][flowerY1] = 7;
			flowerState1 = 1;
		}
		else {
			map1[flowerX1][flowerY1] = 0;
			flowerState1 = 0;
		}

		if (flowerState2 == 0) {
			map1[flowerX2][flowerY2] = 7;
			flowerState2 = 1;
		}
		else {
			map1[flowerX2][flowerY2] = 0;
			flowerState2 = 0; 
		}
	}

	// تابعی برای به‌روزرسانی گل‌ها هر دو ثانیه
	DWORD WINAPI updateFlowersPeriodically(LPVOID lpParam) {
		while (1) {
			WaitForSingleObject(lock, INFINITE);
			toggleFlowers();  // تغییر وضعیت گل‌ها
			ReleaseMutex(lock);
			Sleep(2000);  // هر 2 ثانیه بروزرسانی گل‌ها
		}
		return 0;
	}

	// حرکت اختاپوس‌ها با زمان‌بندی مستقل
	DWORD WINAPI moveOctopus(LPVOID lpParam) {
		while (1) {
			WaitForSingleObject(lock, INFINITE);
			for (int i = 0; i < 3; i++) {
				map1[octopusX[i]][octopusY[i]] = 0;
				octopusY[i] += octopusDir[i];
				if (map1[octopusX[i]][octopusY[i]] != 0) {  // اگر برخورد کرد
					octopusDir[i] *= -1;  // جهت را برعکس کن
					octopusY[i] += octopusDir[i];
				}
				map1[octopusX[i]][octopusY[i]] = 12;  // جایگذاری اختاپوس
			}
			ReleaseMutex(lock);
			Sleep(300);  // هر 300 میلی‌ثانیه حرکت اختاپوس‌ها
		}
		return 0;
	}

	// حرکت چپ و راست
// پرش ماریو
	DWORD WINAPI jumpMario(LPVOID lpParam) {
		while (1) {
			if ((GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8000) && !isMarioJumping) {
				isMarioJumping = true;
				jumpStep = 0;  // شروع پرش
			}

			if (isMarioJumping) {
				WaitForSingleObject(lock, INFINITE);
				if (jumpStep < jumpHeight) {  // حرکت به بالا
					if (map1[marioX - 1][marioY] == 0) {
						map1[marioX][marioY] = 0;
						marioX--;
						if (marioX == 9 && marioY == 61) {
							marioX = 4;
							marioY = 24;
						}



						if (GetAsyncKeyState('A') & 0x8000 && marioY > 0 && map1[marioX][marioY - 1] == 0) {
							marioY--;  // چپ
							if (marioX == 9 && marioY == 61) {
								marioX = 4;
								marioY = 24;
							}

						}
						if (GetAsyncKeyState('D') & 0x8000 && marioY < 64 && map1[marioX][marioY + 1] == 0) {
							marioY++;  // راست
							if (marioX == 9 && marioY == 61) {
								marioX = 4;
								marioY = 24;
							}

						}

						map1[marioX][marioY] = 1;
						jumpStep++;
						if (marioX == 9 && marioY == 61) {
							marioX = 4;
							marioY = 24;
						}

					}
					else {
						jumpStep = jumpHeight;  // برخورد با مانع
					}
				}
				else if (jumpStep >= jumpHeight) {  // بازگشت به پایین
					if (map1[marioX + 1][marioY] == 0) {
						map1[marioX][marioY] = 0;
						marioX++;

						if (marioX == 9 && marioY == 61) {
							marioX = 4;
							marioY = 24;
						}



						if (GetAsyncKeyState('A') & 0x8000 && marioY > 0 && map1[marioX][marioY - 1] == 0) {
							marioY--;  // چپ
							if (marioX == 9 && marioY == 61) {
								marioX = 4;
								marioY = 24;
							}

						}
						if (GetAsyncKeyState('D') & 0x8000 && marioY < 64 && map1[marioX][marioY + 1] == 0) {
							marioY++;  // راست
							if (marioX == 9 && marioY == 61) {
								marioX = 4;
								marioY = 24;
							}

						}

						map1[marioX][marioY] = 1;
					}
					else {
						isMarioJumping = false;  // پایان پرش
					}
				}


			}
			if (!isMarioJumping && map1[marioX + 1][marioY] == 0) {
				WaitForSingleObject(lock, INFINITE);
				if (marioX < 64) {  // جلوگیری از رفتن به خارج از نقشه
					map1[marioX][marioY] = 0;  // خالی کردن موقعیت قبلی
					marioX++; // حرکت ماریو به پایین
					if (marioX == 9 && marioY == 61) {
						marioX = 4;
						marioY = 24;
					}


					map1[marioX][marioY] = 1;  // قرار دادن ماریو در موقعیت جدید
					Sleep(100);  // تأخیر برای حرکت نرم‌تر
				}
				ReleaseMutex(lock);
			}
			Sleep(100); // خواب بیشتر برای سرعت حرکت طبیعی‌تر
		}
		return 0;
	}

// حرکت چپ و راست
DWORD WINAPI moveMarioHorizontally(LPVOID lpParam) {
    while (1) {
        WaitForSingleObject(lock, INFINITE);
        if (GetAsyncKeyState('A') & 0x8000) {  // چپ
            if (marioY > 0 && map1[marioX][marioY - 1] == 0) {
                map1[marioX][marioY] = 0;
                marioY--;
				if (marioX == 9 && marioY == 61) {
					marioX = 4;
					marioY = 24;
				}

                map1[marioX][marioY] = 1;
                Sleep(100);  // تأخیر برای حرکت تدریجی
            }
        }
        if (GetAsyncKeyState('D') & 0x8000) {  // راست
            if (marioY < 64 && map1[marioX][marioY + 1] == 0) {
                map1[marioX][marioY] = 0;
                marioY++;
				if (marioX == 9 && marioY == 61) {
					marioX = 4;
					marioY = 24;
				}

                map1[marioX][marioY] = 1;
                Sleep(100);  // تأخیر برای حرکت تدریجی
            }
        }
        ReleaseMutex(lock);
        Sleep(50);  // جلوگیری از بار اضافی CPU
    }
    return 0;
}


// ///////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode = 0;
	GetConsoleMode(hConsole, &dwMode);
	SetConsoleMode(hConsole, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	/*firstwellcome();
	users* head = readfile(); // خواندن کاربران از فایل
	int choice;
	char currentUser[30]; // ذخیره نام کاربری که وارد شده است

	while (1) {
		system("cls||clear");
		printf(Green "Welcome to Mario Escape!\n" Reset);
		printf("1. Sign Up\n");
		printf("2. Log In\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		getchar(); // برای پاک کردن \n از بافر

		switch (choice) {
		case 1:
			signup(&head); // فراخوانی ساین آپ
			savedata(head); // ذخیره داده‌ها
			break;
		case 2:
			signin(&head);
			savedata(head); // فراخوانی لاگین
			// بعد از موفقیت در لاگین، منوی بازی باید نشان داده شود
			strcpy(currentUser, head->data.username); // ذخیره نام کاربری وارد شده
			if (gamemenu(&head, currentUser)) { // اگر بازی شروع شد
				// اینجا می‌توانید کدهای شروع بازی را اضافه کنید
				printf("Game starting...\n");
				// به عنوان مثال، بازی به طور خلاصه اجرا می‌شود
				// شما باید کدهای مربوط به بازی را اینجا پیاده‌سازی کنید
			}
			break;
		case 3:
			savedata(head); // ذخیره داده‌ها قبل از خروج
			system("cls||clear");
			printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\033[1;32m%HOPE YOU ENJOYED:)\033[0m");
			printf("\n\n\t\t\t\t\t\t\t\t \033[1;34m%[GOODBYE]\033[0m");
			Sleep(4000);
			return 0;
		default:
			printf(Red "Invalid choice! Try again.\n" Reset);
			Sleep(2000);
			break;
		}
	}*/

	

	HANDLE lock = CreateMutex(NULL, FALSE, NULL);  // ایجاد قفل برای هماهنگی

	// ایجاد نقشه و چاپ اولیه آن
	creatmap1();
	system("cls");
	printMap1();

	// تعریف تردها
	HANDLE moveThread = CreateThread(NULL, 0, moveMarioHorizontally, NULL, 0, NULL);
	HANDLE jumpThread = CreateThread(NULL, 0, jumpMario, NULL, 0, NULL);

	// تردی برای بروزرسانی گل‌ها
	HANDLE flowerThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)updateFlowersPeriodically, NULL, 0, NULL);

	// تردی برای حرکت هشت‌پاها
	HANDLE octopusThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)moveOctopus, NULL, 0, NULL);

	while (1) {
		WaitForSingleObject(lock, INFINITE);
		printf("\033[%d;%dH", 0, 0);  // بازگشت به موقعیت بالای صفحه
		printMap1();  // چاپ نقشه به‌روزرسانی شده
		ReleaseMutex(lock);
		Sleep(200);  // تأخیر برای به‌روزرسانی
	}

	// بستن تردها و منابع (هرچند در عمل اینجا نمی‌رسیم)
	CloseHandle(moveThread);
	CloseHandle(jumpThread);
	CloseHandle(flowerThread);
	CloseHandle(octopusThread);
	CloseHandle(lock);
	system("pause");
	return 0;
}

