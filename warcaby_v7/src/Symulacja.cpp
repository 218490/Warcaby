#include "Symulacja.hh"

/*!
 *
 */
int Symuluj(ruchy& plansza, int& ID, string& strona,int& flaga,pozycja& miejsce){
  flaga=0;
  //zasada w biciu krolowa ma pierwszenstwo
  queue<int> bicia;
  queue<int> krolowe;
  krolowe=plansza.KrolowaCzarnaDostep();
  if(krolowe.size()!=0){
    while(!krolowe.empty()){
      if(plansza.CzyBicie(krolowe.front(),'C'))
	bicia.push(krolowe.front());
      krolowe.pop();
    }
  }
  if(!bicia.empty()){
    Pojemnik zyski[8];
    int i=0;
    int rozmiarbic=bicia.size();
    while(!bicia.empty()){
      ruchy planszapom=plansza;
      zyski[i].Id()=bicia.front();
      zyski[i].Zysk()=RuszKrolowaCzarna(planszapom,0,0,bicia.front(),zyski[i].Miejsce());
      i++;
      bicia.pop();
    }
    //minimum z ruchow krolowkami
    int indeks=0;
    for(int j=1;j<rozmiarbic;j++){
      if(zyski[indeks].Zysk()>zyski[j].Zysk())
	indeks=j;
    }
    flaga=1;
    miejsce=zyski[indeks].Miejsce();
    ID=zyski[indeks].Id();
    return zyski[indeks].Zysk();
  }

  //czy pionki maja bicia
  if(plansza.CzyBicie('C')){
    queue<int> pionki;
    queue<int> pbicia;
    pionki=plansza.DostepneCzarne();

    while(!pionki.empty()){
      if(plansza.CzyBicie(pionki.front(),'C'))
	pbicia.push(pionki.front());
	  pionki.pop();
    }
    int rozmiarpbic=pbicia.size();
    RuchDane delta[12];
    for(int i=0;i<rozmiarpbic;i++){
      ruchy planszapom=plansza;
      delta[i].WezId()=pbicia.front();
      delta[i].WezZysk()=RuszCzarne(planszapom,0,0,pbicia.front(),delta[i].WezStrona());
      pbicia.pop();
    }
    int indeks=0;
    for(int j=1;j<rozmiarpbic;j++){
      if(delta[indeks].WezZysk()>delta[j].WezZysk())
	indeks=j;
    }
    ID=delta[indeks].WezId();
    strona=delta[indeks].WezStrona();
    return delta[indeks].WezZysk();
  }//czy bicia dla zwyklego

  //SYMULACJA STANDARDOWA
  return SymulujStandard(plansza,ID,strona,flaga,miejsce);
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
 *\param[in] flaga 1-jak ruszamy krolowa, 0-jak pionkiem
 *\param[in] miejsce jak ruszamy sie krolowa to gdzie mamy sie ruszyc
 *
 *\retval zysk najkorzystniejszy z mozliwych dla wybranego pionka czarnego
 */
int SymulujStandard(ruchy& plansz,int& ID,string& strona,int& flaga,pozycja& miejsce){
  flaga=0;
  queue<int> pionki;
  pionki=plansz.DostepneCzarne();
  int rozmiartab=pionki.size();
  cout<<"Ile mama pionkow: "<<pionki.size()<<endl;
  queue<int> pionkitestowanie=pionki;
  for(int i=0;i<rozmiartab;i++){
    cout<<pionkitestowanie.front()<<"  ";
    pionkitestowanie.pop();
  }
  cout<<endl;
  RuchDane tab[12];

  for(int i=rozmiartab;i>0;i--){
    ruchy planszapom=plansz;
    int obecnagl=0;
    int zysk=0;
    tab[i-1].WezId()=pionki.front();
    tab[i-1].WezZysk()=RuszCzarne(planszapom,obecnagl,zysk,pionki.front(),tab[i-1].WezStrona());
    pionki.pop();
  }

  queue<int> krolowe;
  krolowe=plansz.KrolowaCzarnaDostep();
  int rozmiarkrolowe=krolowe.size();
  Pojemnik tabzyski2[8];
  int indeksk=-1;
  if(rozmiarkrolowe!=0){
    for(int i=0;i<rozmiarkrolowe;i++){
      ruchy planszapom=plansz;
      int obecnagl=0;
      int zysk=0;
      tabzyski2[i].Id()=krolowe.front();
      tabzyski2[i].Zysk()=RuszKrolowaCzarna(planszapom,obecnagl,zysk,krolowe.front(),tabzyski2[i].Miejsce());
    }
    //szukamy minimum dla krolowek
    indeksk=0;
    for(int i=1;i<rozmiarkrolowe;i++){
      if(tabzyski2[indeksk].Zysk()>tabzyski2[i].Zysk())
	indeksk=i;
    }
  }
  cout<<"Zyski:"<<endl;
  for(int i=0;i<rozmiartab;i++){
    cout<<tab[i].WezZysk()<<"  ";
  }
  cout<<endl;
  //szukamy minimum
  int indeks=0;
  for(int i=1;i<rozmiartab;i++){
    if(tab[indeks].WezZysk()>tab[i].WezZysk())
      indeks=i;
  }

  if(indeksk==-1){
    ID=tab[indeks].WezId();
    strona=tab[indeks].WezStrona();
    return tab[indeks].WezZysk();
  }
  if(tab[indeks].WezZysk()<tabzyski2[indeksk].Zysk()){
    ID=tab[indeks].WezId();
    strona=tab[indeks].WezStrona();
    return tab[indeks].WezZysk();
  }

  flaga=1;//rusz krolowka
  ID=tabzyski2[indeksk].Id();
  miejsce=tabzyski2[indeksk].Miejsce();
  return tabzyski2[indeksk].Zysk();
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
int RuszCzarne(ruchy& plansza, int obecnagl, int zysk, int id, string& strona){
  cout<<"Jestem w czarnych pionkiem: "<<id<<endl;
  ruchy plansza1=plansza;
  ruchy plansza2=plansza;
  int zysk1=zysk, zysk2=zysk; 
  int flagaprzod=1;

    if(plansza1.BicieLewoTyl(id,'C')){
      flagaprzod=0;
      zysk1=zysk-1;
      int glpom=obecnagl+1;
      int zyskpom=987;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza1.DostepneBiale();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  ruchy plansza1pom=plansza1;
	  zyski[i]=RuszBiale(plansza1pom,glpom,zysk1,pionki.front());
	  pionki.pop();
	}

	int zyski2[8]; //analizujemy krolowke przeciwnika
	queue<int> kbiale;
	kbiale=plansza1.KrolowaBialaDostep();
	int rozmiarkbiale=kbiale.size();
	if(rozmiarkbiale!=0){
	  for(int j=0;j<rozmiarkbiale;j++){
	    ruchy plansza1pom=plansza1;
	    zyski2[j]=RuszKrolowaBiala(plansza1pom,glpom,zysk1,kbiale.front());
	    kbiale.pop();
	  }
	}
	//maksimum z ruchu bialych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom<zyski[i])
	    zyskpom=zyski[i];
	}
	for(int j=0;j<rozmiarkbiale;j++){
	  if(zyskpom<zyski2[j])
	    zyskpom=zyski2[j];
	}
      }//glebokosc

      //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk1=zyskpom;
    }

    if(plansza2.BiciePrawoTyl(id,'C')){
      flagaprzod=0;
      zysk2=zysk-1;
      int glpom=obecnagl+1;
      int zyskpom=987;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza2.DostepneBiale();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  ruchy plansza2pom=plansza2;
	  zyski[i]=RuszBiale(plansza2pom,glpom,zysk2,pionki.front());
	  pionki.pop();
	}

	int zyski2[8]; //analizujemy krolowke przeciwnika
	queue<int> kbiale;
	kbiale=plansza2.KrolowaBialaDostep();
	int rozmiarkbiale=kbiale.size();
	if(rozmiarkbiale!=0){
	  for(int j=0;j<rozmiarkbiale;j++){
	  ruchy plansza2pom=plansza2;
	    zyski2[j]=RuszKrolowaBiala(plansza2pom,glpom,zysk2,kbiale.front());
	    kbiale.pop();
	  }
	}
	//maksimum z ruchu bialych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom<zyski[i])
	    zyskpom=zyski[i];
	}
	for(int j=0;j<rozmiarkbiale;j++){
	  if(zyskpom<zyski2[j])
	    zyskpom=zyski2[j];
	}
      }//gl
      //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk2=zyskpom;
    }

  if(flagaprzod==1){
    //flagi
  int prawaflaga=1;
  int lewaflaga=1;
  int biciep=5, biciel=5;
  if(plansza.CzyBicie(id,'C')){
    ruchy planszapom=plansza;
    if(planszapom.DostepPrawo(id,'C')){
      biciep=planszapom.RuchPrawo(id,'C');
    }
    planszapom=plansza;
    if(planszapom.DostepLewo(id,'C')){
      biciel=planszapom.RuchLewo(id,'C');
    }
    if(biciep>-1)
      prawaflaga=0;
    if(biciel>-1)
      lewaflaga=0;
  }
  cout<<"prawa flaga: "<<prawaflaga<<endl;
  cout<<"lewa flaga: "<<lewaflaga<<endl;

  if(plansza.DostepPrawo(id,'C') && prawaflaga==1){
    cout<<"Poszedlem w prawo czarnym"<<endl;
    zysk1=zysk+plansza1.RuchPrawo(id,'C');
    int glpom=obecnagl+1;
    int zyskpom=987;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza1.DostepneBiale();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	  ruchy plansza1pom=plansza1;
	zyski[i]=RuszBiale(plansza1pom,glpom,zysk1,pionki.front());
	pionki.pop();
      }
	int zyski2[8]; //analizujemy krolowke przeciwnika
	queue<int> kbiale;
	kbiale=plansza1.KrolowaBialaDostep();
	int rozmiarkbiale=kbiale.size();
	if(rozmiarkbiale!=0){
	  for(int j=0;j<rozmiarkbiale;j++){
	  ruchy plansza1pom=plansza1;
	    zyski2[j]=RuszKrolowaBiala(plansza1pom,glpom,zysk1,kbiale.front());
	    kbiale.pop();
	  }
	}
      //maksimum z ruchu bialych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom<zyski[i])
	  zyskpom=zyski[i];
      }
	for(int j=0;j<rozmiarkbiale;j++){
	  if(zyskpom<zyski2[j])
	    zyskpom=zyski2[j];
	}
    }//gl
    //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk1=zyskpom;
  }

  if(plansza.DostepLewo(id,'C')){cout<<"moze isc w lewo"<<endl;}
  else cout<<"Nie moze"<<endl;
  plansza.wyswietl(plansza.wyszukajPionek(id, 'C'));
  if(plansza.DostepLewo(id,'C') && lewaflaga==1){
    cout<<"Poszedlem w lewo czarnym"<<endl;
    zysk2=zysk+plansza2.RuchLewo(id,'C');
    int glpom=obecnagl+1;
    int zyskpom=987;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza2.DostepneBiale();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	  ruchy plansza2pom=plansza2;
	zyski[i]=RuszBiale(plansza2pom,glpom,zysk2,pionki.front());
	pionki.pop();
      }

	int zyski2[8]; //analizujemy krolowke przeciwnika
	queue<int> kbiale;
	kbiale=plansza2.KrolowaBialaDostep();
	int rozmiarkbiale=kbiale.size();
	if(rozmiarkbiale!=0){
	  for(int j=0;j<rozmiarkbiale;j++){
	  ruchy plansza2pom=plansza2;
	    zyski2[j]=RuszKrolowaBiala(plansza2pom,glpom,zysk2,kbiale.front());
	    kbiale.pop();
	  }
	}
      //maksimum z ruchu bialych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom<zyski[i])
	  zyskpom=zyski[i];
      }
	for(int j=0;j<rozmiarkbiale;j++){
	  if(zyskpom<zyski2[j])
	    zyskpom=zyski2[j];
	}
    }//gl
    //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk2=zyskpom;
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
int RuszBiale(ruchy& plansza, int obecnagl, int zysk, int id){
  cout<<"Jestem w bialych pionkiem: "<<id<<endl;
  ruchy plansza1=plansza;
  ruchy plansza2=plansza;
  int zysk1=zysk, zysk2=zysk;
  string stronapom;
  int flagaprzod=1;
  pozycja pozycjapom;

    if(plansza1.BicieLewoTyl(id,'B')){
      flagaprzod=0;
      zysk1=zysk+1;
      int glpom=obecnagl+1;
      int zyskpom=987;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza1.DostepneCzarne();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  ruchy plansza1pom=plansza1;
	  zyski[i]=RuszCzarne(plansza1pom,glpom,zysk1,pionki.front(),stronapom);
	  pionki.pop();
	}

	int zyski2[8]; //symulacja krolowki przeciwnika
	queue<int> kczarne;
	kczarne=plansza1.KrolowaCzarnaDostep();
	int rozmiarkczarne=kczarne.size();
	if(rozmiarkczarne!=0){
	  for(int j=0;j<rozmiarkczarne;j++){
	  ruchy plansza1pom=plansza1;
	    zyski2[j]=RuszKrolowaCzarna(plansza1pom,glpom,zysk1,kczarne.front(),pozycjapom);
	    kczarne.pop();
	  }
	}
	//minimum z ruchu czarnych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom>zyski[i])
	    zyskpom=zyski[i];
	}
	for(int j=0;j<rozmiarkczarne;j++){
	  if(zyskpom>zyski2[j])
	    zyskpom=zyski2[j];
	}
      }
      //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk1=zyskpom;
    }

    if(plansza2.BiciePrawoTyl(id,'B')){
      flagaprzod=0;
      zysk2=zysk+1;
      int glpom=obecnagl+1;
      int zyskpom=987;
      if(glpom<plansza.Glebokosc()){
	queue<int> pionki;
	pionki=plansza2.DostepneCzarne();
	int rozmiartab=pionki.size();
	int zyski[12];
	for(int i=0;i<rozmiartab;i++){
	  ruchy plansza2pom=plansza2;
	  zyski[i]=RuszCzarne(plansza2pom,glpom,zysk2,pionki.front(),stronapom);
	  pionki.pop();
	}

	int zyski2[8]; //symulacja krolowki przeciwnika
	queue<int> kczarne;
	kczarne=plansza2.KrolowaCzarnaDostep();
	int rozmiarkczarne=kczarne.size();
	if(rozmiarkczarne!=0){
	  for(int j=0;j<rozmiarkczarne;j++){
	  ruchy plansza2pom=plansza2;
	    zyski2[j]=RuszKrolowaCzarna(plansza2pom,glpom,zysk2,kczarne.front(),pozycjapom);
	    kczarne.pop();
	  }
	}
	//minimum z ruchu czarnych
	zyskpom=zyski[0];
	for(int i=1;i<rozmiartab;i++){
	  if(zyskpom>zyski[i])
	    zyskpom=zyski[i];
	}
	for(int j=0;j<rozmiarkczarne;j++){
	  if(zyskpom>zyski2[j])
	    zyskpom=zyski2[j];
	}
      }
      //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk2=zyskpom;
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
    int zyskpom=987;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza1.DostepneCzarne();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	  ruchy plansza1pom=plansza1;
	zyski[i]=RuszCzarne(plansza1pom,glpom,zysk1,pionki.front(),stronapom);
	pionki.pop();
      }

	int zyski2[8]; //symulacja krolowki przeciwnika
	queue<int> kczarne;
	kczarne=plansza1.KrolowaCzarnaDostep();
	int rozmiarkczarne=kczarne.size();
	if(rozmiarkczarne!=0){
	  for(int j=0;j<rozmiarkczarne;j++){
	  ruchy plansza1pom=plansza1;
	    zyski2[j]=RuszKrolowaCzarna(plansza1pom,glpom,zysk1,kczarne.front(),pozycjapom);
	    kczarne.pop();
	  }
	}
      //minimum z ruchu czarnych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom>zyski[i])
	  zyskpom=zyski[i];
      }
	for(int j=0;j<rozmiarkczarne;j++){
	  if(zyskpom>zyski2[j])
	    zyskpom=zyski2[j];
	}
    }
    //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk1=zyskpom;
  }

  if(plansza.DostepLewo(id,'B') && lewaflaga==1){
    zysk2=zysk+plansza2.RuchLewo(id,'B');
    int glpom=obecnagl+1;
    int zyskpom=987;
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=plansza2.DostepneCzarne();
      int rozmiartab=pionki.size();
      int zyski[12];
      for(int i=0;i<rozmiartab;i++){
	  ruchy plansza2pom=plansza2;
	zyski[i]=RuszCzarne(plansza2pom,glpom,zysk2,pionki.front(),stronapom);
	pionki.pop();
      }

	int zyski2[8]; //symulacja krolowki przeciwnika
	queue<int> kczarne;
	kczarne=plansza2.KrolowaCzarnaDostep();
	int rozmiarkczarne=kczarne.size();
	if(rozmiarkczarne!=0){
	  for(int j=0;j<rozmiarkczarne;j++){
	  ruchy plansza2pom=plansza2;
	    zyski2[j]=RuszKrolowaCzarna(plansza2pom,glpom,zysk2,kczarne.front(),pozycjapom);
	    kczarne.pop();
	  }
	}
      //minimum z ruchu czarnych
      zyskpom=zyski[0];
      for(int i=1;i<rozmiartab;i++){
	if(zyskpom>zyski[i])
	  zyskpom=zyski[i];
      }
	for(int j=0;j<rozmiarkczarne;j++){
	  if(zyskpom>zyski2[j])
	    zyskpom=zyski2[j];
	}
    }
    //uaktualniamy zysk
      if(zyskpom==987){}
      else
	zysk2=zyskpom;
  }
  }

  cout<<"Jak w prawo to zysk: "<<zysk1<<endl;
  cout<<"Jak w lewo to zysk: "<<zysk2<<endl;

  //maksimum dla ruchu bialym
  if(zysk1<zysk2)
    return zysk2;

  return zysk1;
}

/*!
 *
 */
int RuszKrolowaCzarna(ruchy& plansza, int obecnagl, int zysk, int id, pozycja& miejsce){

  queue<pozycja> kolejka;
  kolejka=plansza.KrolowaRuchy(id,'C');
  int rozmiartab=kolejka.size();
  ruchy tabplansz[20];
  for(int i=0;i<rozmiartab;i++){
    tabplansz[i]=plansza;
  }
  Pojemnik tabpojem[20];

  //sprawdzanie czy krolowka ma bicia
  queue<pozycja> kolejkapom=kolejka;
  queue<pozycja> bicia;
  if(plansza.CzyBicie(id,'C')){
    while(!kolejkapom.empty()){
      int zpom;
      ruchy planszapom=plansza;
      zpom=planszapom.RuchKrolowa(id,'C',kolejkapom.front());
      kolejkapom.pop();
      if(zpom==-1)
	bicia.push(kolejkapom.front());
      kolejkapom.pop();
    }
  }
  else
    bicia=kolejka; //nie ma bic to przechodzimy przez wszystkie miejsca

  for(int i=0;i<rozmiartab;i++){
    if(kolejka.front()!=bicia.front()){ //sprawdzanie bic
      kolejka.pop(); //nie bierzemy tego ruchu pod uwage
      tabpojem[i].Zysk()=500; //musi byc on nieoplacalny w wyborze minimum
    }
    else{
    bicia.pop();
    tabpojem[i].Miejsce()=kolejka.front();
    tabpojem[i].Zysk()=zysk+tabplansz[i].RuchKrolowa(id,'C',kolejka.front());
    int glpom=obecnagl+1;
    kolejka.pop();

    int zyskpom=987;
    //symulacja nastepnego poziomu
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=tabplansz[i].DostepneBiale();
      int rozmiarpionki=pionki.size();
      int zyski[12];
      for(int j=0;j<rozmiarpionki;j++){
	ruchy planszapom=tabplansz[i];
	zyski[j]=RuszBiale(planszapom,glpom,tabpojem[i].Zysk(),pionki.front());
	pionki.pop();
      }

      int zyski2[8];
      queue<int> kbiale;
      kbiale=tabplansz[i].KrolowaBialaDostep();
      int rozmiarkbiale=kbiale.size();
      if(rozmiarkbiale!=0){
	for(int j=0;j<rozmiarkbiale;j++){
	ruchy planszapom=tabplansz[i];
	  zyski2[j]=RuszKrolowaBiala(planszapom,glpom,tabpojem[i].Zysk(),kbiale.front());
	  kbiale.pop();
	}
      }
      //maksimum dla bialych
      zyskpom=zyski[0];
      for(int j=1;j<rozmiarpionki;j++){
	if(zyskpom<zyski[j])
	  zyskpom=zyski[j];
      }
      for(int j=0;j<rozmiarkbiale;j++){
	if(zyskpom<zyski2[j])
	  zyskpom=zyski2[j];
      }
    }//if glebokosc

   //uaktualniamy zysk
    if(zyskpom==987){}
    else
      tabpojem[i].Zysk()=zyskpom;

    }//else od warunku czy mial bicia
  }//duzy for
  

  //minimum dla ruchu czarna krolowka
  int indeks=0;
  for(int i=1;i<rozmiartab;i++){
    if(tabpojem[indeks].Zysk()>tabpojem[i].Zysk())
      indeks=i;
  }

  miejsce=tabpojem[indeks].Miejsce();
  return tabpojem[indeks].Zysk();
}

/*!
 *
 */
int RuszKrolowaBiala(ruchy& plansza, int obecnagl, int zysk, int id){
  pozycja pozycjapom;
  string stronapom;
  queue<pozycja> kolejka;
  kolejka=plansza.KrolowaRuchy(id,'B');
  int rozmiartab=kolejka.size();
  ruchy tabplansz[20];
  for(int i=0;i<rozmiartab;i++){
    tabplansz[i]=plansza;
  }
  Pojemnik tabpojem[20];

  //sprawdzanie czy krolowka ma bicia
  queue<pozycja> kolejkapom=kolejka;
  queue<pozycja> bicia;
  if(plansza.CzyBicie(id,'B')){
    while(!kolejkapom.empty()){
      int zpom;
      ruchy planszapom=plansza;
      zpom=planszapom.RuchKrolowa(id,'B',kolejkapom.front());
      kolejkapom.pop();
      if(zpom==-1)
	bicia.push(kolejkapom.front());
      kolejkapom.pop();
    }
  }
  else
    bicia=kolejka; //nie ma bic to przechodzimy przez wszystkie miejsca

  for(int i=0;i<rozmiartab;i++){
    if(kolejka.front()!=bicia.front()){ //sprawdzanie bic
      kolejka.pop(); //nie bierzemy tego ruchu pod uwage
      tabpojem[i].Zysk()=-100; //musi byc on nieoplacalny w wyborze maksimum
    }
    else{
    bicia.pop();
    tabpojem[i].Miejsce()=kolejka.front();
    tabpojem[i].Zysk()=zysk+tabplansz[i].RuchKrolowa(id,'B',kolejka.front());
    int glpom=obecnagl+1;
    kolejka.pop();

    int zyskpom=987;
    //symulacja nastepnego poziomu
    if(glpom<plansza.Glebokosc()){
      queue<int> pionki;
      pionki=tabplansz[i].DostepneCzarne();
      int rozmiarpionki=pionki.size();
      int zyski[12];
      for(int j=0;j<rozmiarpionki;j++){
	ruchy planszapom=tabplansz[i];
	zyski[j]=RuszCzarne(planszapom,glpom,tabpojem[i].Zysk(),pionki.front(),stronapom);
	pionki.pop();
      }

      int zyski2[8];
      queue<int> kczarne;
      kczarne=tabplansz[i].KrolowaCzarnaDostep();
      int rozmiarkczarne=kczarne.size();
      if(rozmiarkczarne!=0){
	for(int j=0;j<rozmiarkczarne;j++){
	ruchy planszapom=tabplansz[i];
	  zyski2[j]=RuszKrolowaCzarna(planszapom,glpom,tabpojem[i].Zysk(),kczarne.front(),pozycjapom);
	  kczarne.pop();
	}
      }
      //minimum dla czarnych
      zyskpom=zyski[0];
      for(int j=1;j<rozmiarpionki;j++){
	if(zyskpom>zyski[j])
	  zyskpom=zyski[j];
      }
      for(int j=0;j<rozmiarkczarne;j++){
	if(zyskpom>zyski2[j])
	  zyskpom=zyski2[j];
      }
    }//if glebokosc

   //uaktualniamy zysk
    if(zyskpom==987){}
    else
      tabpojem[i].Zysk()=zyskpom;

    }//else od warunku czy mial bicia
  }//duzy for
  

  //maksimum dla ruchu biala krolowka
  int indeks=0;
  for(int i=1;i<rozmiartab;i++){
    if(tabpojem[indeks].Zysk()<tabpojem[i].Zysk())
      indeks=i;
  }

  return tabpojem[indeks].Zysk();
}
