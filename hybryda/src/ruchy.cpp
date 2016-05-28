#include "ruchy.hh"
list<int> ruchy::DostepneBiciaCzarne()
{
  list<int> wyjscie;
  vector<pionek> pom=szachownica.CzarneWGrze();
  for(unsigned int i=0; i<pom.size(); i++)
    {
      if(CzyBicie(pom[i])==true)
	wyjscie.push_back(pom[i].id);
    }
  return wyjscie;
}
list<int> ruchy::DostepneBiciaBiale()
{
  list<int> wyjscie;
  vector<pionek> pom=szachownica.BialeWGrze();
  for(unsigned int i=0; i<pom.size(); i++)
    {
      if(CzyBicie(pom[i])==true)
	wyjscie.push_back(pom[i].id);
    }
  return wyjscie;
}
queue<int> ruchy::DostepneBiale()
{
  queue<int> wyjscie;
  vector<pionek> pom=szachownica.BialeWGrze();
  for(unsigned int i=0; i<pom.size(); i++)
    {
      if(CzyBicie(pom[i])==true)
	wyjscie.push(pom[i].id);
      else
	{
	  if(DostepPrawo(pom[i])==true)
	    {
	      wyjscie.push(pom[i].id);
	    }
	  else
	    {
	      if(DostepLewo(pom[i])==true)
		{
		  wyjscie.push(pom[i].id);
		}
	    }
	}
    }
  return wyjscie;
}
queue<int> ruchy::DostepneCzarne()
{
  queue<int> wyjscie;
  vector<pionek> pom=szachownica.CzarneWGrze();
  for(unsigned int i=0; i<pom.size(); i++)
    {
      if(CzyBicie(pom[i])==true)
	wyjscie.push(pom[i].id);
      else
	{
	  if(DostepPrawo(pom[i])==true)
	    {
	      wyjscie.push(pom[i].id);
	    }
	  else
	    {
	      if(DostepLewo(pom[i])==true)
		{
		  wyjscie.push(pom[i].id);
		}
	    }
	}
    }
  return wyjscie;
}
int ruchy::RuchPrawo(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return RuchPrawo(pom);
}
int ruchy::RuchLewo(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return RuchLewo(pom);
}
int ruchy::RuchPrawo(pionek pio)
{
  if(pio.bialy==true)
    {
      if(CzyBiciePG(pio)==true)
	{
	  BiciePrawoPrz(pio);
	  return 1;
	}
      else
	{
	  szachownica.przestaw(pio,pio.poz.I+1, pio.poz.J+1);
	  return 0;
	}
    }
  else
    {
      if(CzyBiciePD(pio)==true)
	{
	  BiciePrawoPrz(pio);
	  return -1;
	}
      else
	{
	  szachownica.przestaw(pio,pio.poz.I-1, pio.poz.J+1);
	  return 0;
	}
    }
  return 0;
}
int ruchy::RuchLewo(pionek pio)
{
  if(pio.bialy==true)
    {
      if(CzyBicieLG(pio)==true)
	{
	  BicieLewoPrz(pio);
	  return 1;
	}
      else
	{
	  szachownica.przestaw(pio,pio.poz.I+1, pio.poz.J-1);
	  return 0;
	}
    }
  else
    {
      if(CzyBiciePD(pio)==true)
	{
	  BicieLewoPrz(pio);
	  return -1;
	}
      else
	{
	  szachownica.przestaw(pio,pio.poz.I-1, pio.poz.J-1);
	  return 0;
	}
    }
  return 0;
}
bool ruchy::BiciePrawoTyl(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return BiciePrawoTyl(pom);
}
bool ruchy::BiciePrawoTyl(pionek pio)
{
  if(pio.bialy==true)
    if(CzyBiciePD(pio)==true)
      {
	szachownica.usun(pio.poz.I-1,pio.poz.J+1);
	szachownica.przestaw(pio, pio.poz.I-2, pio.poz.J+2);
	return true;
      }
  if(pio.bialy==false)
    if(CzyBiciePG(pio)==true)
      {
	szachownica.usun(pio.poz.I+1,pio.poz.J+1);
	szachownica.przestaw(pio, pio.poz.I+2, pio.poz.J+2);
	return true;
      }
  return false;
}
bool ruchy::BicieLewoPrz(pionek pio)
{
  if(pio.bialy==true)
    if(CzyBicieLG(pio)==true)
      {
	szachownica.usun(pio.poz.I+1,pio.poz.J-1);
	szachownica.przestaw(pio, pio.poz.I+2, pio.poz.J-2);
	return true;
      }
  if(pio.bialy==false)
    if(CzyBicieLD(pio)==true)
      {
	szachownica.usun(pio.poz.I-1,pio.poz.J-1);
	szachownica.przestaw(pio, pio.poz.I-2, pio.poz.J-2);
	return true;
      }
  return false;
}
bool ruchy::BiciePrawoPrz(pionek pio)
{
  if(pio.bialy==true)
    if(CzyBiciePG(pio)==true)
      {
	szachownica.usun(pio.poz.I+1,pio.poz.J+1);
	szachownica.przestaw(pio, pio.poz.I+2, pio.poz.J+2);
	return true;
      }
  if(pio.bialy==false)
    if(CzyBiciePD(pio)==true)
      {
	szachownica.usun(pio.poz.I-1,pio.poz.J+1);
	szachownica.przestaw(pio, pio.poz.I-2, pio.poz.J+2);
	return true;
      }
  return false;
}
bool ruchy::BicieLewoTyl(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return BicieLewoTyl(pom);
}
bool ruchy::BicieLewoTyl(pionek pio)
{
  if(pio.bialy==true)
    if(CzyBicieLD(pio)==true)
      {
	szachownica.usun(pio.poz.I-1,pio.poz.J-1);
	szachownica.przestaw(pio, pio.poz.I-2, pio.poz.J-2);
	return true;
      }
  if(pio.bialy==false)
    if(CzyBicieLG(pio)==true)
      {
	szachownica.usun(pio.poz.I+1,pio.poz.J-1);
	szachownica.przestaw(pio, pio.poz.I+2, pio.poz.J-2);
	return true;
      }
  return false;
}
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

//########################################################################//

bool ruchy::CzyBicie(int x, int y)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(x,y);
  //if(pom.brak==true)
  // throw szachownica.brak_pionka;
  return CzyBicie(pom);
}

//########################################################################//

bool ruchy::CzyBicie(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return CzyBicie(pom);
}

//########################################################################//

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
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CZARNE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
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

//########################################################################//

bool ruchy::DostepPrawo(int ID, char kolor)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(ID,kolor);
  return DostepPrawo(pom);
}

//########################################################################//

bool ruchy::DostepPrawo(pionek pio)
{
  if(pio.poz.J==rozmiar-1)
    return false;


  if(pio.bialy==true)
  {
    if(CzyBicie('b')==true && CzyBicie(pio)==false)
      return false;
    if(CzyBiciePG(pio)==true)
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
    if(CzyBiciePD(pio)==true)
      return true;
    if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).brak==true)
      return true;
    if(pio.damka==true)
      if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).brak==true)
	return true;
  }
  return false;
}

//########################################################################//

bool ruchy::DostepPrawo(int x, int y)
{
  pionek pom;
  pom=szachownica.wyszukajPionek(x,y);
  //if(pom.brak==true)
  // throw szachownica.brak_pionka;
  return DostepPrawo(pom);
}

//########################################################################//

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


  if(pio.bialy==true)
  {
    if(CzyBicie('b')==true && CzyBicie(pio)==false)
      return false;
    if(CzyBicieLG(pio)==true)
      return true;
    if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).brak==true)
      return true;
    if(pio.damka==true)
      if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).brak==true)
	return true;
  }
  if(pio.bialy==false)
  {
    if(CzyBicie('c')==true && CzyBicie(pio)==false)
      return false;
    if(CzyBicieLD(pio)==true)
      return true;	
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
bool ruchy::CzyBiciePG(pionek pio)
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
	}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CZARNE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(pio.bialy==false)
	{
//==========================PRAWY GORNY ROG===============================
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J+2+i)==true; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J+1+i).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J+2+i).brak==true)
		  return true;
	}
    }
  return false;
}
bool ruchy::CzyBicieLG(pionek pio)
{
//###################### DLA ZWYKLYCH PIONKOW ############################
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==true)
    {
//==========================LEWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1, pio.poz.J-1)==false
	 && szachownica.wyjscie_poza_tablice(pio.poz.I+2, pio.poz.J-2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).bialy==false)
	  if(szachownica.wyszukajPionek(pio.poz.I+2, pio.poz.J-2).brak==true)
	    return true;
    }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< czarne >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==false)
    {
//==========================LEWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1, pio.poz.J-1)==false
	 && szachownica.wyjscie_poza_tablice(pio.poz.I+2, pio.poz.J-2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I+1, pio.poz.J-1).bialy==true)
	  if(szachownica.wyszukajPionek(pio.poz.I+2, pio.poz.J-2).brak==true)
	    return true;
    }
//############################ DLA DAMEK ###############################
  if(pio.damka==true)
    {
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(pio.bialy==true)
	{
//==========================LEWY GORNY ROG===============================
      if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J-1)==false)
	for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J-2-i)==false; i++)
	  if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J-1).bialy==false)
	    if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J-2-i).brak==true)
	      return true;
	}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CZARNE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(pio.bialy==false)
	{
//==========================LEWY GORNY ROG===============================
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I+1,pio.poz.J-1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I+2+i,pio.poz.J-2-i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I+1+i, pio.poz.J-1).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I+2+i, pio.poz.J-2-i).brak==true)
		  return true;
	}
    }
  return false;
}
bool ruchy::CzyBiciePD(pionek pio)
{
  //###################### DLA ZWYKLYCH PIONKOW ############################
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==true)
    {
//==========================PRAWY DOLNY ROG===============================	
      if(szachownica.wyjscie_poza_tablice(pio.poz.I-1, pio.poz.J+1)==false 
	 && szachownica.wyjscie_poza_tablice(pio.poz.I-2, pio.poz.J+2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).bialy==false)
	  if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J+2).brak==true)
	    return true;
    }
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< czarne >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==false)
    {
//==========================PRAWY DOLNY ROG===============================	
      if(szachownica.wyjscie_poza_tablice(pio.poz.I-1, pio.poz.J+1)==false 
	 && szachownica.wyjscie_poza_tablice(pio.poz.I-2, pio.poz.J+2)==false)
	
	if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J+1).bialy==true)
	  if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J+2).brak==true)
	    return true;
    }
//############################ DLA DAMEK ###############################
  if(pio.damka==true)
    {
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(pio.bialy==true)
	{
//==========================PRAWY DOLNY ROG===============================	
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J+2+i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1-i, pio.poz.J+1+i).bialy==false)
		if(szachownica.wyszukajPionek(pio.poz.I-2-i, pio.poz.J+2+i).brak==true)
		  return true;
	}
//==========================PRAWY DOLNY ROG===============================	
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J+1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J+2+i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1-i, pio.poz.J+1+i).bialy==true)
		if(szachownica.wyszukajPionek(pio.poz.I-2-i, pio.poz.J+2+i).brak==true)
		  return true;
    }
  return false;
}
bool ruchy::CzyBicieLD(pionek pio)
{
 //###################### DLA ZWYKLYCH PIONKOW ############################
  //<<<<<<<<<<<<<<<<<<<<<<<<<<<<< BIALE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
  if(pio.bialy==true)
    {
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
//==========================LEWY DOLNY ROG===============================				
	  if(szachownica.wyjscie_poza_tablice(pio.poz.I-1,pio.poz.J-1)==false)
	    for(int i=0; szachownica.wyjscie_poza_tablice(pio.poz.I-2-i,pio.poz.J-2-i)==false; i++)
	      if(szachownica.wyszukajPionek(pio.poz.I-1, pio.poz.J-1).bialy==false)
		if(szachownica.wyszukajPionek(pio.poz.I-2, pio.poz.J-2).brak==true)
		  return true;	
	}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< CZARNE >>>>>>>>>>>>>>>>>>>>>>>>>>>>
      if(pio.bialy==false)
	{  
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
