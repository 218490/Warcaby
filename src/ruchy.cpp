#include "ruchy.hh"

bool ruchy::CzyBicie(char kolor='n')
{
  vector<pionek> pom;
  int licz=0;
  if(kolor=='b')
    {
      pom=szachownica.BialeWGrze();
      for(unsigned int i=0; i<pom.size(); i++)
	{
	  licz=licz+CzyBicie(pom[i]);
	}
      if(licz>0)
	return true;
    }
  if(kolor=='c')
    {
      pom=szachownica.CzarneWGrze();
      for(unsigned int i=0; i<pom.size(); i++)
	{
	  licz=licz+CzyBicie(pom[i]);
	}
      if(licz>0)
	return true;
    }
  if(kolor=='n')
    {
      pom=szachownica.CzarneWGrze();
      for(unsigned int i=0; i<pom.size(); i++)
	{
	  licz=licz+CzyBicie(pom[i]);
	}
      pom=szachownica.BialeWGrze();
      for(unsigned int i=0; i<pom.size(); i++)
	{
	  licz=licz+CzyBicie(pom[i]);
	}
      if(licz>0)
	return true;
    }
  return false;
}
bool ruchy::CzyBicie(int x, int y)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(x,y);
  //if(pom.brak==true)
  // throw szachownica.brak_pionka;
  return CzyBicie(pom);
}
bool ruchy::CzyBicie(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return CzyBicie(pom);
}
bool ruchy::CzyBicie(pionek pio)
{
  //###################### DLA ZWYKLYCH PIONKOW ############################
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==true)
    {
//==========================PRAWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1, pio.poz.J+1)==false 
	&& szachownica.wyjscie_poza_tablice(pio.poz.I+2, pio.poz.J+2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J+1).bialy==false)
	  if(szachownica.wyszukajPionek(pio.poz.I+2, pio.poz.J+2).brak==true)
	    return true;
//==========================LEWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1, pio.poz.J-1)==false
	 && szachownica.wyjscie_poza_tablice(pio.poz.I+2, pio.poz.J-2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).bialy==false)
	  if(szachownica.wyszukajPionek(pio.poz.I+2, pio.poz.J-2).brak==true)
	    return true;	
//==========================PRAWY DOLNY ROG===============================	
      if(szachownica.wyjscie_poza_tablice(pio.poz.I-1, pio.poz.J+1)==false 
	 && szachownica.wyjscie_poza_tablice(pio.poz.I-2, pio.poz.J+2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).bialy==false)
	  if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J+2).brak==true)
	    return true;
//==========================LEWY DOLNY ROG===============================				
      if(szachownica.wyjscie_poza_tablice(pio.poz.I-1, pio.poz.J-1)==false
	 && szachownica.wyjscie_poza_tablice(pio.poz.I-2, pio.poz.J-2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).bialy==false)
	  if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J-2).brak==true)
	    return true;	
    }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< czarne >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==false)
    {
//==========================PRAWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1, pio.poz.J+1)==false 
	 && szachownica.wyjscie_poza_tablice(pio.poz.I+2, pio.poz.J+2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J+1).bialy==true)
	  if(szachownica.wyszukajPionek(pio.poz.I+2, pio.poz.J+2).brak==true)
	    return true;
      //==========================LEWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1, pio.poz.J-1)==false
	 && szachownica.wyjscie_poza_tablice(pio.poz.I+2, pio.poz.J-2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).bialy==true)
	  if(szachownica.wyszukajPionek(pio.poz.I+2, pio.poz.J-2).brak==true)
	    return true;	
     //==========================PRAWY DOLNY ROG===============================	
      if(szachownica.wyjscie_poza_tablice(pio.poz.I-1, pio.poz.J+1)==false 
	 && szachownica.wyjscie_poza_tablice(pio.poz.I-2, pio.poz.J+2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).bialy==true)
	  if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J+2).brak==true)
	    return true;
     //==========================LEWY DOLNY ROG===============================				
      if(szachownica.wyjscie_poza_tablice(pio.poz.I-1, pio.poz.J-1)==false
	 && szachownica.wyjscie_poza_tablice(pio.poz.I-2, pio.poz.J-2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).bialy==true)
	  if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J-2).brak==true)
	    return true;	
    } 
  //############################ DLA DAMEK ###############################
  if(pio.damka==true)
    {
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(pio.bialy==true)
	{
//==========================PRAWY GORNY ROG===============================
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J+2+i)==true; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J+1+i).bialy==false)
		if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J+2+i).brak==true)
		  return true;
//==========================LEWY GORNY ROG===============================
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J-1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J-2-i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J-1).bialy==false)
		if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J-2-i).brak==true)
		  return true;	
//==========================PRAWY DOLNY ROG===============================	
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J+2+i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1-i, pio.poz.J+1+i).bialy==false)
		if(szachownica.wyszukajPionek(pio.poz.I-2-i, pio.poz.J+2+i).brak==true)
		  return true;
//==========================LEWY DOLNY ROG===============================				
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J-1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J-2-i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).bialy==false)
		if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J-2).brak==true)
		  return true;	
	}
      if(pio.bialy==false)
	{
//==========================PRAWY GORNY ROG===============================
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J+2+i)==true; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J+1+i).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J+2+i).brak==true)
		  return true;
//==========================LEWY GORNY ROG===============================
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J-1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J-2-i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J-1).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J-2-i).brak==true)
		  return true;	
//==========================PRAWY DOLNY ROG===============================	
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J+2+i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1-i, pio.poz.J+1+i).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I-2-i, pio.poz.J+2+i).brak==true)
		  return true;
//==========================LEWY DOLNY ROG===============================				
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J-1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J-2-i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J-2).brak==true)
		  return true;	
	}
    }
  return false;
}
bool ruchy::DostepPrawo(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return DostepPrawo(pom);
}
bool ruchy::DostepPrawo(pionek pio)
{
  if(pio.poz.J==rozmiar-1)
    return false;


  if(pio.bialy==true)
  {
	if(CzyBicie('b')==true && CzyBicie(pio)==false)
		return false;
	if(CzyBicie(pio)==true)
		return true;

    if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J+1).brak==true)
      return true;
	if(pio.damka==true)
		if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).brak==true)
			return true;
  }
  if(pio.bialy==false)
  {
	if(CzyBicie('c')==true && CzyBicie(pio)==false)
		return false;
	if(CzyBicie(pio)==true)
		return true;
	  
    if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).brak==true)
      return true;
  	if(pio.damka==true)
		if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).brak==true)
			return true;
  }
  return false;
}
bool ruchy::DostepPrawo(int x, int y)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(x,y);
  //if(pom.brak==true)
  // throw szachownica.brak_pionka;
  return DostepPrawo(pom);
}
bool ruchy::DostepLewo(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return DostepLewo(pom);
}
bool ruchy::DostepLewo(pionek pio)
{
  if(pio.poz.J==0)
    return false;
  if(CzyBicie()==true && CzyBicie(pio)==false)
    return false;
  if(CzyBicie(pio)==true)
    return true;

  if(pio.bialy==true)
  {
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).brak==true)
        return true;
	if(pio.damka==true)
		if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).brak==true)
			return true;
  }
  if(pio.bialy==false)
  {
    if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).brak==true)
      return true;
  	if(pio.damka==true)
		if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).brak==true)
			return true;
  }
  return false;
}
bool ruchy::DostepLewo(int x, int y)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(x,y);
  //if(pom.brak==true)
  //throw szachownica.brak_pionka;
  return DostepLewo(pom);
}
