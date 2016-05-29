#include <iostream>
#include <stack>
#include "Symulacja.hh"
using namespace std;

int main(){
  ruchy plansza;
  int ID,flaga;
  string strona;
  pozycja miejsce;
  pionek p;
  p.id=2; p.brak=false; p.bialy==true;
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'B'));
  //plansza.wyswietl(1,1);
  plansza.RuchPrawo(11,'B');
  cout<<"wykonano ruch"<<endl;
  plansza.wyswietl();
  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);

  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }

}
