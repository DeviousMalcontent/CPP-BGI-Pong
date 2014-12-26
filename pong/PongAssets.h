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

#ifndef __PONGASSETS_H__
#define __PONGASSETS_H__

void DrawTitle(int x, int y);
void DrawPlayer(int x, int y);
void MovePlayer(int cpx, int cpy, int x, int y);
void DrawBall(int x, int y);
void MoveBall(int cpx, int cpy, int x, int y);

#endif