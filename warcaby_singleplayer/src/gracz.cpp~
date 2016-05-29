#include "gracz.hh"
#include <iostream>
bool gracz::RuszPionek(ruchy &r,pionek &pio , int x, int y)
{
  int pom;
  queue<int> dostepne;
  if(pio.damka==true)
    {

    }
  else
    {
      if(y==pio.poz.J+1)
	{
	  if(r.DostepPrawo(pio)==false)
	    throw niedozwolony_ruch();
	  else
	    {
	      r.RuchPrawo(pio);
	      return true;
	    }
	}
      else
	if(y==pio.poz.J-1)
	{
	  if(r.DostepLewo(pio)==false)
	    throw niedozwolony_ruch();
	  else
	    {
	      r.RuchLewo(pio);
	      return true;
	    }
	}
	else
	  {
	    throw niedozwolony_ruch();
	  }
    }
  return false;
}
pionek gracz::ZaznaczPionek(ruchy &r, int x, int y)
{
  pionek pio;
  int pom;
  queue<int> dostepne;
  pio=r.wyszukajPionek(x,y);
  cout<<pio.id<<endl;
  if(pio.brak==true)
    throw brak_pionka_na_podanej_pozycji();
  if(pio.bialy==true)
    throw pionek_przeciwnika();
  if(pio.damka==false)
    {
      dostepne=r.DostepneCzarne();
      while(dostepne.empty()==false)
	{
	  pom=dostepne.front();
	  if(pom==pio.id)
	    {
	      r.wyswietl(pio);
	      return pio;
	    }
	  dostepne.pop();
	}
    }
  else
    {
      dostepne=r.KrolowaCzarnaDostep();
      while(dostepne.empty()==false)
	{
	  pom=dostepne.front();
	  if(pom==pio.id)
	    {
	      r.wyswietl(pio);
	      return pio;
	    }
	  dostepne.pop();
	}
    }
  throw brak_ruchu();
  return pio;
}
