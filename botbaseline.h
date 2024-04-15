#ifndef BOTBASELINE
#define BOTBASELINE

#include <iostream>
#include <stdlib.h>
#include "config.h"

using namespace std;

typedef int ll;

int ngang = 0, doc = 0, cheo1 = 0, cheo2 = 0;
int Dngang = 0, Ddoc = 0, Dcheo1 = 0, Dcheo2 = 0;
//0, 8, 512, 32768, 2097152, 134217728
//0, 64, 4096, 262144, 16777216, 1073741824
const ll Defend_Score1[7] = {0, 8, 512, 32768, 2097152, 134217728};
const ll Attack_Score1[7] = {0, 8, 512, 32768, 2097152, 134217728};

int player_id = -1;
int board_game[HEIGHT][WIDTH];
//ll cnt_O = 0, cnt_X = 0;
Point check_win(int board_game[HEIGHT][WIDTH], int player_id);
Point defend(int board_game[HEIGHT][WIDTH], int player_id);
Point attack(int board_game[HEIGHT][WIDTH], int player_id);
Point check_n_tile(int board_game[HEIGHT][WIDTH], int player_id, int n);

//Point player_rand(int board_game[HEIGHT][WIDTH], int player_id){
//    int row, col;
//    //srand((int)time(0));
//    row = rand() % HEIGHT;
//    col = rand() % WIDTH;
//    return Point(row, col);
//}

Point player_baseline(int board_game[HEIGHT][WIDTH], int player_id){
    Point p = check_win(board_game, player_id);
    if(p.x != -1 && p.y != -1){
        return p;
    } else {
        p = defend(board_game, player_id);
        if(p.x != -1 && p.y != -1){
            return p;
        } else {
            return attack(board_game, player_id);
        }
    }
}

ll SoDiemTanCong_DuyetNgang(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[]) // cho X
{
	ll iScoreTempNgang = 0;
	ll iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH; iDem++)
	{
		if (board_game[Dong][ Cot + iDem] == -1)
			iSoQuanTa++;
		if (board_game[Dong][Cot + iDem] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong][Cot + iDem] == 0)
		{
			for (int iDem2 = 1; iDem2 < 6 && Cot + iDem2 < WIDTH; iDem2++)
			{
				if (board_game[Dong][Cot + iDem2] == -1)
					iSoQuanTa2++;
				if (board_game[Dong][Cot + iDem2] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong][Cot + iDem2] == 0)
					break;
			}
			break;
		}
	}
//	iScoreAttack += Attack_Score[iSoQuanTa];
//	iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (board_game[Dong] [Cot - iDem] == -1)
			iSoQuanTa++;
		if (board_game[Dong][Cot - iDem] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong][Cot - iDem2] == -1)
					iSoQuanTa2++;
				if (board_game[Dong][Cot - iDem2] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong][Cot - iDem2] == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempNgang += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempNgang += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempNgang += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempNgang += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanTa == 4)
		iScoreTempNgang *= 2;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich2];
	return iScoreTempNgang;
}
ll SoDiemTanCong_DuyetDoc(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{
	ll iScoreTempDoc = 0;
	ll iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][Cot] == -1)
			iSoQuanTa++;
		if (board_game[Dong + iDem][Cot] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong + iDem][Cot] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 <HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot] == -1)
					iSoQuanTa2++;
				if (board_game[Dong + iDem2][Cot] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot] == 0)
					break;
			}
			break;
		}

	}
//	iScoreAttack += Attack_Score[iSoQuanTa];
//	iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot] == -1)
			iSoQuanTa++;
		if (board_game[Dong - iDem][ Cot] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong - iDem][Cot] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot] == -1)
					iSoQuanTa2++;
				if (board_game[Dong - iDem2][Cot] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot] == 0)
				{
					break;
				}
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempDoc += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempDoc += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempDoc += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempDoc += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempDoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich2];
	return iScoreTempDoc;
}

ll SoDiemTanCong_DuyetCheo1(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{
	ll iScoreTempCheoNguoc = 0;
	ll iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][ Cot + iDem] == -1)
			iSoQuanTa++;
		if (board_game[Dong + iDem][Cot + iDem] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong + iDem][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot + iDem2] == -1)
					iSoQuanTa2++;
				if (board_game[Dong + iDem2][Cot + iDem2] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot + iDem2] == 0)
				{
					break;
				}
			}
			break;
		}
	}
//	iScoreAttack += Attack_Score[iSoQuanTa];
//	iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot - iDem] == -1)
			iSoQuanTa++;
		if (board_game[Dong - iDem][Cot - iDem] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong - iDem][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot - iDem2] == -1)
					iSoQuanTa2++;
				if (board_game[Dong - iDem2][Cot - iDem2] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot - iDem2] == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoNguoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2];
	return iScoreTempCheoNguoc;
}
ll SoDiemTanCong_DuyetCheo2(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{
	ll iScoreTempCheoXuoi = 0;
	ll iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem] [Cot - iDem] == -1)
			iSoQuanTa++;
		if (board_game[Dong + iDem][Cot - iDem] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong + iDem][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot - iDem2] == -1)
					iSoQuanTa2++;
				if (board_game[Dong + iDem2][Cot - iDem2] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot - iDem2] == 0)
					break;
			}
			break;
		}
	}
//	iScoreAttack += Attack_Score[iSoQuanTa];
//	iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot + iDem]== -1)
			iSoQuanTa++;
		if (board_game[Dong - iDem][Cot + iDem] == 1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong - iDem][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot + iDem2] == -1)
					iSoQuanTa2++;
				if (board_game[Dong - iDem2][Cot + iDem2] == 1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot + iDem2] == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa] * 2;
	else
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2] * 2;
	else
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoXuoi *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2];
	return iScoreTempCheoXuoi;
}

ll SoDiemPhongThu_DuyetDoc(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{
	ll iScoreTempDoc = 0;
	ll iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][ Cot] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong + iDem][Cot] == 1)
			iSoQuanDich++;
		if (board_game[Dong + iDem][Cot] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot] == 1)
					iSoQuanDich2++;
				if (board_game[Dong + iDem2][Cot] == 0)
					break;
			}
			break;
		}
	}
//	iScoreDefend += Defend_Score[iSoQuanDich];
//	iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem][Cot] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong - iDem][Cot] == 1)
			iSoQuanDich++;
		if (board_game[Dong - iDem][Cot] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot] == 1)
					iSoQuanDich2++;
				if (board_game[Dong - iDem2][Cot] == 0)
					break;
			}
			break;
		}
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];

	if (iSoQuanTa == 0)
	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
	iScoreTempDoc += Defend_Score[iSoQuanDich2];


	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempDoc *= 2;
	return iScoreTempDoc;
}

ll SoDiemPhongThu_DuyetNgang(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{
	ll iScoreTempNgang = 0;
	ll iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH; iDem++)
	{
		if (board_game[Dong][ Cot + iDem] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong][Cot + iDem] == 1)
			iSoQuanDich++;
		if (board_game[Dong][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 <WIDTH; iDem2++)
			{
				if (board_game[Dong][Cot + iDem2] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong][Cot + iDem2] == 1)
					iSoQuanDich2++;
				if (board_game[Dong][Cot + iDem2] == 0)
					break;
			}
			break;
		}
	}
//	iScoreDefend += Defend_Score[iSoQuanDich];
//	iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (board_game[Dong][ Cot - iDem] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong][Cot - iDem2] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong][Cot - iDem2] == 0)
					break;
				if (board_game[Dong][Cot - iDem2] == 1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong][Cot - iDem] == 1)
			iSoQuanDich++;
	}

	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];


//	if (iSoQuanTa == 0)
//	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
//	else
//	iScoreTempDoc += Defend_Score[iSoQuanDich2];


	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanDich == 4)
		iScoreTempNgang *= 2;
	return iScoreTempNgang;
}

ll SoDiemPhongThu_DuyetCheo1(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{

	ll iScoreTempCheoNguoc = 0;
	ll iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][ Cot + iDem] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong + iDem][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH && Dong + iDem2< HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot + iDem2] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot + iDem2] == 0)
					break;
				if (board_game[Dong + iDem2][Cot + iDem2] == 1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong + iDem][Cot + iDem] == 1)
			iSoQuanDich++;
	}

//	iScoreDefend += Defend_Score[iSoQuanDich];
//	iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot - iDem] == -1)
		{
			iSoQuanTa++;
			break;
		}

		if (board_game[Dong - iDem][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot - iDem2] == -1)
				{
					iSoQuanTa2++;
					break;
				}

				if (board_game[Dong - iDem2][Cot - iDem2] == 0)
					break;
				if (board_game[Dong - iDem2][Cot - iDem2] == 1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong - iDem][Cot - iDem] == 1)
			iSoQuanDich++;
	}
	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];


//	if (iSoQuanTa == 0)
//	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
//	else
//	iScoreTempDoc += Defend_Score[iSoQuanDich2];


	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoNguoc *= 2;
	return iScoreTempCheoNguoc;
}

ll SoDiemPhongThu_DuyetCheo2(ll Dong, ll Cot, const ll Defend_Score[], const ll Attack_Score[])
{
	ll iScoreTempCheoXuoi = 0;
	ll iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem] [Cot - iDem] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong + iDem][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot - iDem2] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot - iDem2] == 0)
					break;
				if (board_game[Dong + iDem2][Cot - iDem2] == 1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong + iDem][Cot - iDem] == 1)
			iSoQuanDich++;
	}
//	iScoreDefend += Defend_Score[iSoQuanDich];
//	iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem][ Cot + iDem] == -1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong - iDem][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem < 7 && Cot + iDem2 < WIDTH && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot + iDem2] == -1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot + iDem2] == 0)
					break;
				if (board_game[Dong - iDem2][Cot + iDem2] == 1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong - iDem][Cot + iDem] == 1)
			iSoQuanDich++;
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];


//	if (iSoQuanTa == 0)
//	iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
//	else
//	iScoreTempDoc += Defend_Score[iSoQuanDich2];


	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoXuoi *= 2;
	return iScoreTempCheoXuoi;
}

Point Tim_Kiem_NuocDi_1()
{
	Point Oco ;
	ll dong = 0, cot = 0;
	ll Diem = 0;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			ll DiemTanCong = 0;
			ll DiemPhongThu = 0;
			if (board_game[i][j] == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1,Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem <= DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
//	Oco.x = cot*4+2;
//	Oco.y = dong*2+1;
	Oco.x = dong;
	Oco.y = cot;
	return Oco;
}

#endif // BOTBASELINE
