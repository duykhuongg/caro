#ifndef BOTFOURGIFTS
#define BOTFOURGIFTS

#include <iostream>
#include <stdlib.h>
#include "config.h"

using namespace std;

//int ngang = 0, doc = 0, cheo1 = 0, cheo2 = 0;
//int Dngang = 0, Ddoc = 0, Dcheo1 = 0, Dcheo2 = 0;
//int board_game[HEIGHT][WIDTH];

// bot 2
int SoDiemTanCong_DuyetNgang2(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempNgang = 0;
	int iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	ngang = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH; iDem++)
	{
		if (board_game[Dong][ Cot + iDem] == 1)
			iSoQuanTa++;
		if (board_game[Dong][Cot + iDem] == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong][Cot + iDem]== 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH; iDem2++)
			{
				if (board_game[Dong][Cot + iDem2] == 1)
					iSoQuanTa2++;
				if (board_game[Dong][Cot + iDem2]== -1)
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
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (board_game[Dong] [Cot - iDem] == 1)
			iSoQuanTa++;
		if (board_game[Dong][Cot - iDem]== -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong][Cot - iDem2] == 1)
					iSoQuanTa2++;
				if (board_game[Dong][Cot - iDem2] == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong][Cot - iDem2]== 0)
					break;
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0) {
		iScoreTempNgang += Attack_Score[iSoQuanTa] * 2;
		//
		ngang = iSoQuanTa;
	}
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
		//iScoreTempNgang *= 3;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];
	/*
	if (iSoQuanTa2 == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich2];
		*/
	return iScoreTempNgang;
}
int SoDiemTanCong_DuyetDoc2(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempDoc = 0;
	int iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	doc = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][Cot] == 1)
			iSoQuanTa++;
		if (board_game[Dong + iDem][Cot] == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong + iDem][Cot] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot]== 1)
					iSoQuanTa2++;
				if (board_game[Dong + iDem2][Cot] == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot]== 0)
					break;
			}
			break;
		}

	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot] == 1)
			iSoQuanTa++;
		if (board_game[Dong - iDem][ Cot] == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong - iDem][Cot] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot] == 1)
					iSoQuanTa2++;
				if (board_game[Dong - iDem2][Cot] == -1)
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
	if (iSoQuanDich == 0) {
		iScoreTempDoc += Attack_Score[iSoQuanTa] * 2;
		doc = iSoQuanTa;
	}
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
		//iScoreTempDoc *= 3;
	if (iSoQuanTa == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich];
		/*
	if (iSoQuanTa2 == 0)
		iScoreTempDoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempDoc += Defend_Score[iSoQuanDich2];
		*/
	return iScoreTempDoc;
}

int SoDiemTanCong_DuyetCheo12(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempCheoNguoc = 0;
	int iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	cheo1 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][ Cot + iDem] == 1)
			iSoQuanTa++;
		if (board_game[Dong + iDem][Cot + iDem] == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong + iDem][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot + iDem2] == 1)
					iSoQuanTa2++;
				if (board_game[Dong + iDem2][Cot + iDem2] == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot + iDem2]  == 0)
				{
					break;
				}
			}
			break;
		}
	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot - iDem]  == 1)
			iSoQuanTa++;
		if (board_game[Dong - iDem][Cot - iDem]  == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong - iDem][Cot - iDem]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot - iDem2]  == 1)
					iSoQuanTa2++;
				if (board_game[Dong - iDem2][Cot - iDem2]  == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot - iDem2]  == 0)
					break;
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0) {
		iScoreTempCheoNguoc += Attack_Score[iSoQuanTa] * 2;
		cheo1 = iSoQuanTa;
	}
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
		//iScoreTempCheoNguoc *= 3;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
		/*
	if (iSoQuanTa2 == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich2];
		*/
	return iScoreTempCheoNguoc;
}
int SoDiemTanCong_DuyetCheo22(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempCheoXuoi = 0;
	int iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	cheo2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem] [Cot - iDem]  == 1)
			iSoQuanTa++;
		if (board_game[Dong + iDem][Cot - iDem]  == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong + iDem][Cot - iDem]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot - iDem2]  == 1)
					iSoQuanTa2++;
				if (board_game[Dong + iDem2][Cot - iDem2]  == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot - iDem2]  == 0)
					break;
			}
			break;
		}
	}
	//iScoreAttack += Attack_Score[iSoQuanTa];
	//iSoQuanTa = 0;

	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot + iDem] == 1)
			iSoQuanTa++;
		if (board_game[Dong - iDem][Cot + iDem]  == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (board_game[Dong - iDem][Cot + iDem]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot + iDem2]  == 1)
					iSoQuanTa2++;
				if (board_game[Dong - iDem2][Cot + iDem2]  == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot + iDem2]  == 0)
					break;
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0) {
		iScoreTempCheoXuoi += Attack_Score[iSoQuanTa] * 2;
		cheo2 = iSoQuanTa;
	}
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
		//iScoreTempCheoXuoi *= 3;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];
		/*
	if (iSoQuanTa2 == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich2];
		*/
	return iScoreTempCheoXuoi;
}
int DiemNuocDoi (const int Attack_Score[]) {
	int NuocDoi = 0;
	if (ngang > 1) NuocDoi++;
	if (doc > 1) NuocDoi++;
	if (cheo1 > 1) NuocDoi++;
	if (cheo2 > 1) NuocDoi++;
	return Attack_Score[NuocDoi];
}

int SoDiemPhongThu_DuyetDoc2(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempDoc = 0;
	int iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][ Cot]  == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong + iDem][Cot]  == -1)
			iSoQuanDich++;
		if (board_game[Dong + iDem][Cot]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot]  == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot]  == -1)
					iSoQuanDich2++;
				if (board_game[Dong + iDem2][Cot]  == 0)
					break;
			}
			break;
		}
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;
	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem][Cot]  == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong - iDem][Cot]  == -1)
			iSoQuanDich++;
		if (board_game[Dong - iDem][Cot]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot]  == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot]  == -1)
					iSoQuanDich2++;
				if (board_game[Dong - iDem2][Cot]  == 0)
					break;
			}
			break;
		}
	}
	Ddoc = iSoQuanDich;

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
	if (iSoQuanDich == 4 )
		iScoreTempDoc *= 2;
	return iScoreTempDoc;
}

int SoDiemPhongThu_DuyetNgang2(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempNgang = 0;
	int iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
// check right
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH; iDem++)
	{
		if (board_game[Dong][ Cot + iDem]  == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong][Cot + iDem] == -1)
			iSoQuanDich++;
		if (board_game[Dong][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH; iDem2++)
			{
				if (board_game[Dong][Cot + iDem2] == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong][Cot + iDem2] == -1)
					iSoQuanDich2++;
				if (board_game[Dong][Cot + iDem2] == 0)
					break;
			}
			break;
		}
	}
// check left
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (board_game[Dong][ Cot - iDem] == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong][Cot - iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong][Cot - iDem2] == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong][Cot - iDem2] == 0)
					break;
				if (board_game[Dong][Cot - iDem2] == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong][Cot - iDem] == -1)
			iSoQuanDich++;
	}
	Dngang = iSoQuanDich;
	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempNgang += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempNgang += Defend_Score[iSoQuanDich];

	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanDich == 4 )
		iScoreTempNgang *= 3;
	return iScoreTempNgang;
}

int SoDiemPhongThu_DuyetCheo12(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{

	int iScoreTempCheoNguoc = 0;
	int iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem][ Cot + iDem] == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong + iDem][Cot + iDem] == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < WIDTH && Dong + iDem2< HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot + iDem2] == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot + iDem2]  == 0)
					break;
				if (board_game[Dong + iDem2][Cot + iDem2]  == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong + iDem][Cot + iDem]  == -1)
			iSoQuanDich++;
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem] [Cot - iDem]  == 1)
		{
			iSoQuanTa++;
			break;
		}

		if (board_game[Dong - iDem][Cot - iDem]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot - iDem2]  == 1)
				{
					iSoQuanTa2++;
					break;
				}

				if (board_game[Dong - iDem2][Cot - iDem2]  == 0)
					break;
				if (board_game[Dong - iDem2][Cot - iDem2]  == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong - iDem][Cot - iDem]  == -1)
			iSoQuanDich++;
	}
	Dcheo1 = iSoQuanDich;
	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += Defend_Score[iSoQuanDich];
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanDich == 4 )
		iScoreTempCheoNguoc *= 3;
	return iScoreTempCheoNguoc;
}

int SoDiemPhongThu_DuyetCheo22(int Dong, int Cot, const int Defend_Score[], const int Attack_Score[])
{
	int iScoreTempCheoXuoi = 0;
	int iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < HEIGHT; iDem++)
	{
		if (board_game[Dong + iDem] [Cot - iDem]  == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong + iDem][Cot - iDem]  == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < HEIGHT; iDem2++)
			{
				if (board_game[Dong + iDem2][Cot - iDem2]  == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong + iDem2][Cot - iDem2]  == 0)
					break;
				if (board_game[Dong + iDem2][Cot - iDem2]  == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong + iDem][Cot - iDem]  == -1)
			iSoQuanDich++;
	}
	//iScoreDefend += Defend_Score[iSoQuanDich];
	//iSoQuanDich = 0;

	for (int iDem = 1; iDem < 6 && Cot + iDem < WIDTH && Dong - iDem >= 0; iDem++)
	{
		if (board_game[Dong - iDem][ Cot + iDem]  == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (board_game[Dong - iDem][Cot + iDem]  == 0)
		{
			for (int iDem2 = 2; iDem < 7 && Cot + iDem2 < WIDTH && Dong - iDem2 >= 0; iDem2++)
			{
				if (board_game[Dong - iDem2][Cot + iDem2]  == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (board_game[Dong - iDem2][Cot + iDem2]  == 0)
					break;
				if (board_game[Dong - iDem2][Cot + iDem2]  == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (board_game[Dong - iDem][Cot + iDem]  == -1)
			iSoQuanDich++;
	}
	Dcheo2 = iSoQuanDich;

	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += Defend_Score[iSoQuanDich];

	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanDich == 4 )
		iScoreTempCheoXuoi *= 3;
	return iScoreTempCheoXuoi;
}

Point player_fourgifts(int board_game[][WIDTH], int player_id){
    Point p;
	int Diem = 0, moved = 0;
	if (moved == 0 && player_id == 1) {
		p.x = HEIGHT / 2;
		p.y = WIDTH / 2;
		moved++;
		return p;
	}
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			int DiemTanCong = 0;
			int DiemPhongThu = 0;
			if (board_game[i][j] == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc2(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang2(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo12(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo22(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += DiemNuocDoi(Attack_Score1);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc2(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang2(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo12(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo22(i, j, Defend_Score1, Attack_Score1);
				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						p.x = i;
						p.y = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						p.x = i;
						p.y = j;
					}
				}
			}
		}
	}
	return p;

}



#endif // BOTFOURGIFTS
