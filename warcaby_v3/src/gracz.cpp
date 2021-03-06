#include "gracz.hh"
#include <iostream>
bool gracz::RuszPionek(ruchy &r,pionek &pio , int x, int y)
{
  int pom;
  queue<int> dostepne;
  if(pio.bialy==true)
    {
      if(pio.damka==true)
	{
	  
	}
      else
	{
	  if(y==pio.poz.J+1 && x==pio.poz.I+1)
	    {
	      if(r.DostepPrawo(pio)==false)
		throw niedozwolony_ruch();
	      else
		{
		  r.RuchPrawo(pio);
		  return true;
		}
	    }
	  else if(y==pio.poz.J-1 && x==pio.poz.I+1)
	    {
	      if(r.DostepLewo(pio)==false)
		throw niedozwolony_ruch();
	      else
		{
		  r.RuchLewo(pio);
		  return true;
		}
	    }
	  else if(y==pio.poz.J+2 && x==pio.poz.I+2)
	    {
	      if(r.CzyBiciePG(pio)==true)
		{
		  r.BiciePrawoPrz(pio);
		  return true;
		}
	      else throw niedozwolony_ruch();
	    }
	  else if(y==pio.poz.J-2 && x==pio.poz.I+2)
	    {
	      if(r.CzyBicieLG(pio)==true)
		{
		  r.BicieLewoPrz(pio);
		  return true;
		}
	      else throw niedozwolony_ruch();
	    }
	  else
	    if(y==pio.poz.J+2 && x==pio.poz.I-2)
	      {
		if(r.CzyBiciePD(pio)==true)
		  {
		    r.BiciePrawoTyl(pio);
		    return true;
	      }
		else throw niedozwolony_ruch();
	      }
	    else if(y==pio.poz.J-2 && x==pio.poz.I-2)
	      {
		if(r.CzyBicieLD(pio)==true)
		  {
		    r.BicieLewoTyl(pio);
		return true;
		  }
		else throw niedozwolony_ruch();
	      }
	    else
	      {
		cout<<"cos jest nie tak"<<endl;
		throw niedozwolony_ruch();
	      }
	}
    }
  else
    {
      if(pio.damka==true)
	{
	  
	}
      else
	{
	  //    cout<<"y J-1 J+1: "<<y<<" "<<pio.poz.J-1<<" "<<pio.poz.J+1<<endl;
	  //   cout<<"x I-1 I+1: "<<x<<" "<<pio.poz.I-1<<" "<<pio.poz.I+1<<endl;
	  if(y==pio.poz.J+1 && x==pio.poz.I-1)
	    {
	      if(r.DostepPrawo(pio)==false)
		throw niedozwolony_ruch();
	      else
		{
		  r.RuchPrawo(pio);
		  return true;
		}
	    }
	  else if(y==pio.poz.J-1 && x==pio.poz.I-1)
	    {
	      if(r.DostepLewo(pio)==false)
		throw niedozwolony_ruch();
	      else
		{
		  r.RuchLewo(pio);
		  return true;
		}
	    }
	  else if(y==pio.poz.J+2 && x==pio.poz.I-2)
	    {
	      if(r.CzyBiciePD(pio)==true)
		{
		  r.BiciePrawoPrz(pio);
		  return true;
		}
	      else throw niedozwolony_ruch();
	    }
	  else if(y==pio.poz.J-2 && x==pio.poz.I-2)
	    {
	      if(r.CzyBicieLD(pio)==true)
		{
		  r.BicieLewoPrz(pio);
		  return true;
		}
	      else throw niedozwolony_ruch();
	    }
	  else
	    if(y==pio.poz.J+2 && x==pio.poz.I+2)
	      {
		if(r.CzyBiciePG(pio)==true)
		  {
		    r.BiciePrawoTyl(pio);
		    return true;
	      }
		else throw niedozwolony_ruch();
	      }
	    else if(y==pio.poz.J-2 && x==pio.poz.I+2)
	      {
		if(r.CzyBicieLG(pio)==true)
		  {
		    r.BicieLewoTyl(pio);
		return true;
		  }
		else throw niedozwolony_ruch();
	      }
	    else
	      {
		cout<<"cos jest nie tak"<<endl;
		throw niedozwolony_ruch();
	      }
	}
    }
  return false;
}
pionek gracz::ZaznaczPionek(ruchy &r, int x, int y, char k='C')
{
  pionek pio;
  int pom;
  queue<int> dostepne;
  pio=r.wyszukajPionek(x,y);
  cout<<pio.id<<endl;
  if(pio.brak==true)
    throw brak_pionka_na_podanej_pozycji();
  if(k=='C')
    if(pio.bialy==true)
      throw pionek_przeciwnika();
  if(k=='B')
    if(pio.bialy==false)
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
