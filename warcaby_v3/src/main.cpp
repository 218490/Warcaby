#include <iostream>
#include <stack>
#include "Symulacja.hh"
using namespace std;

int main(){
  ruchy plansza;
  int ID,flaga;
  string strona;
  pozycja miejsce;
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'B'));
  plansza.RuchPrawo(11,'B');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'B'));
  plansza.RuchPrawo(12,'B');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchPrawo(10,'C');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));
  plansza.RuchPrawo(11,'C');
  plansza.wyswietl();
   plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchPrawo(10,'C');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));
  plansza.RuchPrawo(11,'C');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));
  plansza.RuchLewo(11,'C');
  plansza.wyswietl();
  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);

  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }

}
