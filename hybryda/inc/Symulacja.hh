#ifndef SYMULACJA_HH
#define SYMULACJA_HH

#include <iostream>
#include "RuchDane.hh"
#include "ruchy.hh"
using namespace std;

/*!
 *\file
 *\brief Implementacja funkcji symulujacych ruch przeciwnika w Warcabach
 */

int Symuluj(ruchy plansza, int& ID, string& strona);
int SymulujStandard(ruchy plansza,int& ID,string& strona);
int RuszCzarne(ruchy plansza, int obecnagl, int zysk, int id, string& strona);
int RuszBiale(ruchy plansza, int obecnagl, int zysk, int id);

#endif
