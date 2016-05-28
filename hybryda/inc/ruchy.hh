#ifndef RUCHY
#define RUCHY
#include "plansza.hh"
#include <queue>
#include <list>
class ruchy
{
private:
  plansza szachownica;
  int glebokosc=4;
public:
  queue<int> DostepneBiale();
  queue<int> DostepneCzarne();
  bool CzyBicie(char);        //czy bicie dla danego gracza lub ogolnie na szachownicy gdy nie podano koloru
  bool CzyBicie(pionek); //czy dany pionek ma bicie
  bool CzyBicie(int, char);
  bool CzyBicie(int, int);
  bool CzyBiciePG(pionek); //czy dany pionek ma bicie prawy gorny rog
  bool CzyBicieLG(pionek); //czy dany pionek ma bicie lewy gorny rog
  bool CzyBiciePD(pionek); //czy dany pionek ma bicie prawy dolny rog
  bool CzyBicieLD(pionek); //czy dany pionek ma bicie lewy dolny rog
  bool DostepPrawo(int, char); //za pomoca odwolania dp id i koloru pionka
  bool DostepPrawo(pionek);   //za pomoca odwolania do pionka
  bool DostepPrawo(int, int);//za pomoca odwolania do konkretnego pola
  bool DostepLewo(int, char);
  bool DostepLewo(pionek);
  bool DostepLewo(int, int);
  int RuchPrawo(int, char); //zwykly ruch i bicie
  int RuchPrawo(pionek);
  int RuchLewo(int, char);
  int RuchLewo(pionek);
  //void Ruch(pionek, int, int);
  //void Ruch(int, int, int, int);
  //bool Bicie(pionek, int, int);
  //void Bicie(int, int, int, int);
  list<int> DostepneBiciaBiale(); //zwraca id pionkow ktore maja bicie
  list<int> DostepneBiciaCzarne();
  bool BiciePrawoTyl(int, char); //true- gdy mogl wykonac
  bool BicieLewoTyl (int, char);
  bool BiciePrawoTyl(pionek); //true- gdy mogl wykonac
  bool BicieLewoTyl (pionek);
  bool BiciePrawoPrz(pionek); //true- gdy mogl wykonac
  bool BicieLewoPrz (pionek);
  /**/  int Glebokosc(){return glebokosc;};
  /**/void Trudnosc(int poziom){glebokosc=poziom;};

};

#endif
