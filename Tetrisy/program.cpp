#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

#define FIELD_WIDTH 12
#define FIELD_HEIGHT 22
#define MINO_WIDTH 4
#define MINO_HEIGHT 4

char field[FIELD_HEIGHT][FIELD_WIDTH];
char displayBuffer[FIELD_HEIGHT][FIELD_WIDTH];


enum {
	MINO_TYPE_I,
	MINO_TYPE_O,
	MINO_TYPE_S,
	MINO_TYPE_Z,
	MINO_TYPE_J,
	MINO_TYPE_L,
	MINO_TYPE_T,
	MINO_TYPE_MAX
};

enum {
	MINO_ANGLE_0,
	MINO_ANGLE_90,
	MINO_ANGLE_180,
	MINO_ANGLE_270,
	MINO_ANGLE_MAX
};

char minoShapes[MINO_TYPE_MAX][MINO_ANGLE_MAX][MINO_HEIGHT][MINO_WIDTH] = {
	//MINO_TYPE_I
	{
		//MINO_ANGLE_0,
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 0, 0, 0,
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0
		},
		//MINO_ANGLE_180,
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 0, 0,
			1, 1, 1, 1,
			0, 0, 0, 0,
			0, 0, 0, 0
		}
	},
	//MINO_TYPE_O
	{
		//MINO_ANGLE_0,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_180,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		}
		
	},
	//MINO_TYPE_S
	{
		//MINO_ANGLE_0,
		{
				0, 0, 0, 0,
				0, 1, 1, 0,
				1, 1, 0, 0,
				0, 0, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_180,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			1, 1, 0, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0
		}
	},
	//MINO_TYPE_Z
	{
		//MINO_ANGLE_0,
		{
			0, 0, 0, 0,
			1, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		},
		//MINO_ANGLE_180,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 1,
			0, 0, 0, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 1, 0, 0,
			0, 0, 0, 0
		}
	},
	//MINO_TYPE_J
	{
		//MINO_ANGLE_0,
		{
			0, 0, 1, 0,
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 0, 0, 0,
			1, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		},
	//MINO_ANGLE_180,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 1, 0, 0,
			0, 1, 0, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 1,
			0, 0, 0, 0
		}
	},
	//MINO_TYPE_L
	{
		//MINO_ANGLE_0,
		{
			0, 1, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			1, 1, 1, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_180,
		{
			0, 0, 0, 0,
			0, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 1, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 0, 0,
			0, 1, 1, 1,
			0, 1, 0, 0,
			0, 0, 0, 0
		}
	},
	//MINO_TYPE_T
	{
		//MINO_ANGLE_0,
		{
			0, 0, 0, 0,
			1, 1, 1, 0,
			0, 1, 0, 0,
			0, 0, 0, 0
		},
		//MINO_ANGLE_90,
		{
			0, 0, 0, 0,
			0, 1, 0, 0,
			0, 1, 1, 0,
			0, 1, 0, 0
		},
		//MINO_ANGLE_180,
		{
			0, 0, 0, 0,
			0, 0, 1, 0,
			0, 1, 1, 1,
			0, 0, 0, 0
		},
		//MINO_ANGLE_270
		{
			0, 0, 1, 0,
			0, 1, 1, 0,
			0, 0, 1, 0,
			0, 0, 0, 0
		}
	}
};

//init startposition and Angle of mino
int minoType = 0, minoAngle = 0;
int minoX = 5, minoY = 0;

void display()
{
	//write mino

	memcpy(displayBuffer, field, sizeof(field));

	for (int i = 0; i < MINO_HEIGHT; i++) {
		for (int j = 0; j < MINO_WIDTH; j++) {
			displayBuffer[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
		}
	}
	//output tetris display
	system("cls");
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {
			printf(displayBuffer[i][j] ? "��" : "  ");
		}
		printf("\n");
	}
}

bool isHit(int _minoX, int _minoY, int _minoType, int _minoAngle)
{
	for (int i = 0; i < MINO_HEIGHT; i++) {
		for (int j = 0; j < MINO_WIDTH; j++) {
			if (minoShapes[_minoType][_minoAngle][i][j]
				&& field[_minoY + i][_minoX + j])
				return true;
		}
	}
	return false;
}

void resetMino()
{
	minoX = 5;
	minoY = 0;
	minoType = rand() % MINO_TYPE_MAX;
	minoAngle = rand() % MINO_ANGLE_MAX;
}

void main()
{

	//init field buffer
	memset(field, 0, sizeof(field));
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		field[i][0] = field[i][FIELD_WIDTH - 1] = 1;
	}
	for (int i = 0; i < FIELD_WIDTH; i++) {
		field[FIELD_HEIGHT - 1][i] = 1;
	}

	resetMino();

	time_t t = time(NULL);
	while (1) {
		if (_kbhit()) {
			switch (_getch()) {
				//case 'w':
			case 's':
				if (!isHit(minoX,//int _minoX, 
					minoY + 1,			//int _minoY,
					minoType,		//int _minoType, 
					minoAngle))		//int _minoAngle)
					minoY++;
				break;
			case 'a':
				if (!isHit(minoX - 1,//int _minoX, 
					minoY,			//int _minoY,
					minoType,		//int _minoType, 
					minoAngle))		//int _minoAngle)
					minoX--;
				break;
			case 'd':
				if (!isHit(minoX + 1,//int _minoX, 
					minoY,			//int _minoY,
					minoType,		//int _minoType, 
					minoAngle))		//int _minoAngle)
					minoX++;
				break;
				//space key
			case 0x20:
				if (!isHit(minoX,						//int _minoX, 
					minoY,								//int _minoY,
					minoType,							//int _minoType, 
					(minoAngle + 1) % MINO_ANGLE_MAX))	//int _minoAngjle)
					minoAngle = (minoAngle + 1) % MINO_ANGLE_MAX;
				break;
			}
			display();
		}
		if (t != time(NULL)) {
			t = time(NULL);

			if (isHit(minoX,	//int _minoX, 
				minoY + 1,		//int _minoY,
				minoType,		//int _minoType, 
				minoAngle))		//int _minoAngle)
			{
				//stack mino
				for (int i = 0; i < MINO_HEIGHT; i++) {
					for (int j = 0; j < MINO_WIDTH; j++) {
						field[minoY + i][minoX + j] |= minoShapes[minoType][minoAngle][i][j];
					}
				}

				//delete if line is filled
				for (int i = 0; i < FIELD_HEIGHT - 1; i++) {						
					bool lineFill = true;
					for (int j = 1; j < FIELD_WIDTH - 1; j++) {
						if (!field[i][j])
								lineFill = false;						}
					//if line is filled
					if (lineFill) {
						for (int j = i; j > 0; j--) {
							memcpy(field[j], field[j - 1], FIELD_WIDTH);
						}
					}
				}

				resetMino();
			}
			else
				minoY++;

			display();

		}
	}

	_getch();
}

