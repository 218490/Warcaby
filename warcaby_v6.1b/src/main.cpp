#include <iostream>
#include "Symulacja.hh"
using namespace std;

int ProbaB(ruchy& plansza,int id){
  ruchy planszapom=plansza;
  return planszapom.RuchPrawo(id,'B');
}

int main(){
  ruchy plansza;
  int ID,flaga;
  string strona;
   pozycja miejsce;
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
  plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchPrawo(10,'C');
  plansza.wyswietl();

  //  int zysk=RuszCzarne(plansza,0,0,10,strona);
  //cout<<zysk<<endl;
  //int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);
  //ProbaB(plansza,6);
  /*
  if(flaga==0){
  cout<<"ID: "<<ID<<endl;
  cout<<"strona: "<<strona<<endl;
  cout<<"zysk: "<<zysk<<endl;
  }*//*
  queue<int> pionki=plansza.DostepneCzarne();
  int rozmiartab=pionki.size();
    for(int i=0;i<rozmiartab;i++){
    cout<<pionki.front()<<"  ";
    pionki.pop();
  }
    if(pionki.empty()){
      cout<<"kolejka pusta"<<endl;
    }*/
  plansza.RuchPrawo(6,'B');
  plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));
  if(plansza.DostepLewo(11,'C')){
    cout<<"lewo"<<endl;
    plansza.RuchLewo(11,'C');
  }  
  /*
  if(plansza.DostepPrawo(11,'C')){
    cout<<"prawo"<<endl;
    plansza.RuchPrawo(11,'C');
    }*/
  plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));

}
