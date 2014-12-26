/*
* Program: CPP-BGI Pong
* Purpose: Pong Game Clone
* Author: Mark Albanese
* Date: 2 March 2014
* Version: 1.0
* Release: 1
* Language: C\C++
* Compiler: Visual Studios 2010
* Notes: This program uses an open source implementation of the old DOS library that was included with Borland C (called BGI, which stands for Borland Graphics Interface) 
*		 This library is called OpenBGI and can be found here: http://openbgi.sourceforge.net/
*		 Documentation for this library can be found here: http://www.codecutter.net/tools/winbgim/V6_0/doc/index.html
*		 (Although it is not up-to-date)
*/

#ifdef _WIN32
	#if       _WIN32_WINNT < 0x0500
	  #undef  _WIN32_WINNT
	  #define _WIN32_WINNT   0x0500
	#endif
#endif

#include <stdlib.h>
#include <stdio.h>

#ifdef _WIN32

	#include <conio.h>
    #include <windows.h>	
#elif __DOS__
	#include <conio.h>
#endif

#include <graphics.h>
#include "PongAssets.h"

int midx, midy, Player1cpx, Player1cpy, Player2cpx, Player2cpy, c;

int main(void)
{
  int gdriver = DETECT, gmode, errorcode;
  initgraph(&gdriver, &gmode, "");
  
  #ifdef _WIN32
	  ShowWindow( GetConsoleWindow(), SW_HIDE );
	  SetConsoleTitle("Debug");
  #endif
  
  midx = getmaxx() / 2 - 216;
  midy = getmaxy() / 2 - 82;

  DrawTitle(midx, midy);
  outtextxy(midx, midy+164, "Version 1.0");
  outtextxy(midx, midy+174, "By Mark Albanese");
  outtextxy(midx, midy+184, "http://goo.gl/90229");
  #ifdef __DOS__
	 getch();
  #elif _WIN32
	 readkey();
  #endif
  cleardevice();

  Player1cpy = midy;
  Player1cpx = midx;
  Player2cpx = midx+432;
  Player2cpy = midy;
 
  DrawPlayer(Player1cpx, Player1cpy);
  DrawPlayer(Player2cpx, Player2cpy);
  DrawBall(midx+204, midy+35);

  #ifdef _WIN32
  do 
    {
        c = readkey();
		if(c == 'a') 
        {
			if(Player1cpy > 5)
			{
				MovePlayer(Player1cpx, Player1cpy,Player1cpx,Player1cpy-8);
				Player1cpy = Player1cpy-8;
			}
		}
		if(c == 'z') 
        {
			if(Player1cpy < 397)
			{
				MovePlayer(Player1cpx, Player1cpy,Player1cpx,Player1cpy+8);
				Player1cpy = Player1cpy+8;
			}
        }
		if(c == 'k') 
        {
			if(Player2cpy > 5)
			{
				MovePlayer(Player2cpx, Player2cpy,Player2cpx,Player2cpy-8);
				Player2cpy = Player2cpy-8;
			}
        }
		if(c == 'm') 
        {
		    if(Player2cpy < 397)
			{
				MovePlayer(Player2cpx, Player2cpy,Player2cpx,Player2cpy+8);
				Player2cpy = Player2cpy+8;
			}
        }
		/*
		if(c == 'mz' || c == 'zm') 
        {
			MovePlayer(Player2cpx, Player2cpy,Player2cpx,Player2cpy+8);
			MovePlayer(Player1cpx, Player1cpy,Player1cpx,Player1cpy+8);
			Player2cpy = Player2cpy+8;
			Player1cpy = Player1cpy+8;
        }*/
    } while(c != KEY_ESCAPE);
  #elif __DOS__
    do 
    {
        c = getch();
		if(c == 97) 
        {
			if(Player1cpy > 5)
			{
				MovePlayer(Player1cpx, Player1cpy,Player1cpx,Player1cpy-8);
				Player1cpy = Player1cpy-8;
			}
		}
		if(c == 122) 
        {
			if(Player1cpy < 397)
			{
				MovePlayer(Player1cpx, Player1cpy,Player1cpx,Player1cpy+8);
				Player1cpy = Player1cpy+8;
			}
        }
		if(c == 107) 
        {
			if(Player2cpy > 5)
			{
				MovePlayer(Player2cpx, Player2cpy,Player2cpx,Player2cpy-8);
				Player2cpy = Player2cpy-8;
			}
        }
		if(c == 109) 
        {
		    if(Player2cpy < 397)
			{
				MovePlayer(Player2cpx, Player2cpy,Player2cpx,Player2cpy+8);
				Player2cpy = Player2cpy+8;
			}
        }

    } while(c != 27);
  #endif

  readkey();

  closegraph();
  return 0;
}
