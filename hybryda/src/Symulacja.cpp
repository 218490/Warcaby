#include "Symulacja.hh"

/*!
 *
 */
int Symuluj(ruchy plansza, int& ID, string& strona){
  //czy sa bicia?

  // // jak nie ma bic
  //czy jest krolowa -tak zasymuluj krolowe, zapamietaj zysk 
  //                 -nie nic nie rob

  //symuluj standardowo
  return 1;
}

/*!
 *Symuluje ruchy pionkow czrnych i bialych na zmiane. Wywoluje rekurencyjnie
 *funkcje RuszCzarne(), RuszBiale() az do momentu osiagniecia glebokosci wywolan
 *,porownuje zyski, ostatecznie wybiera ten ruch ktory wzgledem pionka bialego
 *jest najmniej oplacalny
 *
 *\param[in] plansza przechowuje wszystkie informacje o aktualnym stanie gry
 *\param[in] ID funkcja zapisuje w tej zmiennej id pionka, ktorym najkorzystniej
 *jest ruszyc
 *\param[in] strona funkcja zapisuje w tej zmiennej, w ktora strone jest
 *najkorzystniej sie ruszyc
 *
 *\retval zysk najkorzystniejszy z mozliwych dla wybranego pionka czarnego
 */
int SymulujStandard(ruchy plansz,int& ID,string& strona){
  queue<int> pionki;
  pionki=plansz.DostepneCzarne();
  int rozmiartab=pionki.size();
  RuchDane tab[12];

  for(int i=rozmiartab;i>0;i--){
    ruchy planszapom=plansz;
    int obecnagl=0;
    int zysk=0;
    tab[i-1].WezId()=pionki.front();
    tab[i-1].WezZysk()=RuszCzarne(planszapom,obecnagl,zysk,pionki.front(),tab[i-1].WezStrona());
    pionki.pop();
  }

  //szukamy minimum
  int indeks=0;
  for(int i=1;i<rozmiartab;i++){
    if(tab[indeks].WezZysk()>tab[i].WezZysk())
      indeks=i;
  }
  ID=tab[indeks].WezId();
  strona=tab[indeks].WezStrona();
  return tab[indeks].WezZysk();

}

/*!
 *Funkcja wykonuje ruch danym pionkiem czarnym i symuluje odpowiedzi na zmiane 
 *stanu planszy na zmiane bialymi pionkami i czarnymi pionkami az do momenu
 *osiagniecia maksymalnej glebokosci wywolan. Ostatecznie wybierany jest 
 *najmniejszy zysk wzgledem bialych ze  wzgledu na to, ze mamy zadecydowac o 
 *ruchu pionka czarnego
 *
 *\param[in] plansza przechowuje wszystkie informacje o aktualnym stanie gry
 *\param[in] obecnagl zmienna przechowujaca dotychczasowa glebokosc wywolan
 *\param[in] zysk ogolny zysk mierzony wzgledem oplacalnosci dla pionkow bialych
 *przechowuje historie zysku wzgledem wczesniejszych ruchow (wywolan funkcji)
 *\param[in] id identyfikator pionka, ktorego ruch rozwazamy
 *\param[in] strona ma znaczenie gdy dany pionek jest tym najbardziej oplacalnym
 *aby sie nim ruszyc. Informuje nas, w ktora strone mamy sie nim ruszyc
 *
 *\retval zysk najkorzystniejszy dla pionka czarnego po wykonaniu odpowiedniego
 *ruchu
 */
int RuszCzarne(ruchy plansza, int obecnagl, int zysk, int id, string& strona){
  ruchy plansza1=plansza;
  ruchy plansza2=plansza;
  int zysk1=500, zysk2=500; 
  int flagaprzod=1;

    if(plansza1.BicieLewoTyl(id,'C')){
      flagaprzod=0;
      zysk1=zysk-1;
      int glpom=obecnagl+1;
      int zyskpom;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza1.DostepneBiale();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  zyski[i]=RuszBiale(plansza1,glpom,zysk1,pionki.front());
	  pionki.pop();
	}
	//maksimum z ruchu bialych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom<zyski[i])
	    zyskpom=zyski[i];
	}
      }
      //uaktualniamy zysk
      zysk1=zysk1+zyskpom;
    }

    if(plansza2.BiciePrawoTyl(id,'C')){
      flagaprzod=0;
      zysk2=zysk-1;
      int glpom=obecnagl+1;
      int zyskpom;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza2.DostepneBiale();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  zyski[i]=RuszBiale(plansza2,glpom,zysk2,pionki.front());
	  pionki.pop();
	}
	//maksimum z ruchu bialych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom<zyski[i])
	    zyskpom=zyski[i];
	}
      }
      //uaktualniamy zysk
      zysk2=zysk2+zyskpom;
    }

  if(flagaprzod==1){
    //flagi
  int prawaflaga=1;
  int lewaflaga=1;
  int biciep=5, biciel=5;
  if(plansza.CzyBicie(id,'C')){
    ruchy planszapom=plansza;
    if(planszapom.DostepPrawo(id,'C'))
      biciep=planszapom.RuchPrawo(id,'C');
    planszapom=plansza;
    if(planszapom.DostepLewo(id,'C'))
      biciel=planszapom.RuchLewo(id,'C');
    if(biciep>-1)
      prawaflaga=0;
    if(biciel>-1)
      lewaflaga=0;
  }

  if(plansza.DostepPrawo(id,'C') && prawaflaga==1){
    zysk1=zysk+plansza1.RuchPrawo(id,'C');
    int glpom=obecnagl+1;
    int zyskpom;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza1.DostepneBiale();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	zyski[i]=RuszBiale(plansza1,glpom,zysk1,pionki.front());
	pionki.pop();
      }
      //maksimum z ruchu bialych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom<zyski[i])
	  zyskpom=zyski[i];
      }
    }
    //uaktualniamy zysk
    zysk1=zysk1+zyskpom;
  }

  if(plansza.DostepLewo(id,'C') && lewaflaga==1){
    zysk2=zysk+plansza2.RuchLewo(id,'C');
    int glpom=obecnagl+1;
    int zyskpom;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza2.DostepneBiale();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	zyski[i]=RuszBiale(plansza2,glpom,zysk2,pionki.front());
	pionki.pop();
      }
      //maksimum z ruchu bialych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom<zyski[i])
	  zyskpom=zyski[i];
      }
    }
    //uaktualniamy zysk
    zysk2=zysk2+zyskpom;
  }
  }//flaga przod

  //minimum dla ruchu czarnym
  if(zysk1<zysk2){
    if(flagaprzod==0)
      strona="lewatyl";
    else
      strona="prawa";
    return zysk1;
  }
  else
    if(flagaprzod==0)
      strona="prawatyl";
    else
      strona="lewa";
  return zysk2;
}

/*!
 *Funkcja wykonuje ruch danym pionkiem bialym i symuluje odpowiedzi na zmiane 
 *stanu planszy na zmiane czarnymi pionkami i bialymi pionkami az do momenu
 *osiagniecia maksymalnej glebokosci wywolan. Ostatecznie wybierany jest 
 *najwiekszy zysk wzgledem bialych ze  wzgledu na to, ze mamy zadecydowac o 
 *ruchu pionka bialego
 *
 *\param[in] plansza przechowuje wszystkie informacje o aktualnym stanie gry
 *\param[in] obecnagl zmienna przechowujaca dotychczasowa glebokosc wywolan
 *\param[in] zysk ogolny zysk mierzony wzgledem oplacalnosci dla pionkow bialych
 *przechowuje historie zysku wzgledem wczesniejszych ruchow (wywolan funkcji)
 *\param[in] id identyfikator pionka, ktorego ruch rozwazamy
 *
 *\retval zysk najkorzystniejszy dla pionka bialego po wykonaniu odpowiedniego
 *ruchu
 */
int RuszBiale(ruchy plansza, int obecnagl, int zysk, int id){
  ruchy plansza1=plansza;
  ruchy plansza2=plansza;
  int zysk1=-200, zysk2=-200;
  string stronapom;
  int flagaprzod=1;

    if(plansza1.BicieLewoTyl(id,'B')){
      flagaprzod=0;
      zysk1=zysk+1;
      int glpom=obecnagl+1;
      int zyskpom;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza1.DostepneCzarne();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  zyski[i]=RuszCzarne(plansza1,glpom,zysk1,pionki.front(),stronapom);
	  pionki.pop();
	}
	//minimum z ruchu czarnych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom>zyski[i])
	    zyskpom=zyski[i];
	}
      }
      //uaktualniamy zysk
      zysk1=zysk1+zyskpom;
    }

    if(plansza2.BiciePrawoTyl(id,'B')){
      flagaprzod=0;
      zysk2=zysk+1;
      int glpom=obecnagl+1;
      int zyskpom;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza2.DostepneCzarne();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  zyski[i]=RuszCzarne(plansza2,glpom,zysk2,pionki.front(),stronapom);
	  pionki.pop();
	}
	//minimum z ruchu czarnych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom>zyski[i])
	    zyskpom=zyski[i];
	}
      }
      //uaktualniamy zysk
      zysk2=zysk2+zyskpom;
    }


  if(flagaprzod==1){
    //flagi
  int prawaflaga=1;
  int lewaflaga=1;
  int biciep=-5, biciel=-5;
  if(plansza.CzyBicie(id,'B')){
    ruchy planszapom=plansza;
    if(planszapom.DostepPrawo(id,'B'))
      biciep=planszapom.RuchPrawo(id,'B');
    planszapom=plansza;
    if(planszapom.DostepLewo(id,'B'))
      biciel=planszapom.RuchLewo(id,'B');
    if(biciep<1)
      prawaflaga=0;
    if(biciel<1)
      lewaflaga=0;
  }

  if(plansza.DostepPrawo(id,'B') && prawaflaga==1){
    zysk1=zysk+plansza1.RuchPrawo(id,'B');
    int glpom=obecnagl+1;
    int zyskpom;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza1.DostepneCzarne();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	zyski[i]=RuszCzarne(plansza1,glpom,zysk1,pionki.front(),stronapom);
	pionki.pop();
      }
      //minimum z ruchu czarnych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom>zyski[i])
	  zyskpom=zyski[i];
      }
    }
    //uaktualniamy zysk
    zysk1=zysk1+zyskpom;
  }

  if(plansza.DostepLewo(id,'B') && lewaflaga==1){
    zysk2=zysk+plansza2.RuchLewo(id,'B');
    int glpom=obecnagl+1;
    int zyskpom;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza2.DostepneCzarne();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	zyski[i]=RuszCzarne(plansza2,glpom,zysk2,pionki.front(),stronapom);
	pionki.pop();
      }
      //minimum z ruchu czarnych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom>zyski[i])
	  zyskpom=zyski[i];
      }
    }
    //uaktualniamy zysk
    zysk2=zysk2+zyskpom;
  }
  }

  //maksimum dla ruchu bialym
  if(zysk1<zysk2)
    return zysk2;

  return zysk1;
}
