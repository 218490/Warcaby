
#include <iostream>
#include "Symulacja.hh"
using namespace std;

int main(){
  ruchy plansza;
  int ID,flaga;
  string strona;
  pozycja miejsce;
  queue<int> pionki;
  int rozmiartab;
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'B'));
  plansza.RuchLewo(11,'B');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(12, 'B'));
  plansza.RuchPrawo(12,'B');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchLewo(10,'C');
  plansza.wyswietl();
  plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));
  plansza.RuchPrawo(11,'C');
  plansza.wyswietl();
  pionki=plansza.DostepneCzarne();
  rozmiartab=pionki.size();
  for(int i=0;i<rozmiartab;i++){
    cout<<pionki.front()<<"  ";
    pionki.pop();
  }
    if(pionki.empty()){
      cout<<"kolejka pusta"<<endl;
    }
  plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchPrawo(10,'C');
  plansza.wyswietl();

  //  int zysk=RuszCzarne(plansza,0,0,10,strona);
  //cout<<zysk<<endl;
  //int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);
  /*
  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }*/
  pionki=plansza.DostepneCzarne();
  rozmiartab=pionki.size();
    for(int i=0;i<rozmiartab;i++){
    cout<<pionki.front()<<"  ";
    pionki.pop();
  }
    if(pionki.empty()){
      cout<<"kolejka pusta"<<endl;
    }
  //plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));  

}
