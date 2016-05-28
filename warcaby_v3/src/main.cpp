#include <iostream>
#include <stack>
#include "Symulacja.hh"
using namespace std;

int main(){
  ruchy plansza;
  int ID,flaga;
  string strona;
  pozycja miejsce;

  plansza.RuchPrawo(2,'B');

  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);

  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }

}
