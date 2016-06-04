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
   pionek pio;
  plansza.RuchPrawo(9,'B');
  //  plansza.wyswietl();
  //plansza.wyswietl(plansza.wyszukajPionek(12, 'B'));
  plansza.RuchPrawo(12,'B');
  //plansza.wyswietl();
  //plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchLewo(12,'C');
  //  plansza.wyswietl();
  //plansza.wyswietl(plansza.wyszukajPionek(11, 'C'));
  plansza.RuchLewo(10,'C');

  //plansza.wyswietl();
  //plansza.wyswietl(plansza.wyszukajPionek(10, 'C'));
  plansza.RuchPrawo(9,'B');
  //plansza.wyswietl();
  plansza.RuchPrawo(6,'C');
  //plansza.wyswietl();

  plansza.RuchLewo(8,'B');
  plansza.RuchPrawo(4,'B');
  plansza.RuchLewo(7,'C');
  plansza.wyswietl(plansza.wyszukajPionek(12, 'C'));
  /*
  int zysk=RuszCzarne(plansza,0,0,1,strona);
    cout<<"Zysk:"<<zysk<<endl;
  cout<<"Strona:"<<strona<<endl;
  */
  plansza.RuchPrawo(11,'B');
  plansza.RuchLewo(12,'C');
  plansza.wyswietl();
  plansza.RuchPrawo(12,'C');
  plansza.wyswietl();
  plansza.CzyBicie(12,'C');

  //queue<int> krolowki=plansza.KrolowaCzarnaDostep();
  //cout<<"krolowki: "<<krolowki.front()<<endl;
  queue<pozycja> ruchy=plansza.KrolowaRuchy(12,'C');
   while(!ruchy.empty()){
    cout<<ruchy.front().I<<"  "<<ruchy.front().J<<endl;
    ruchy.pop();
  }
   ruchy=plansza.KrolowaRuchy(12,'C');
   pio=plansza.wyszukajPionek(12,'C');
   cout<<pio.poz.I<<" "<<pio.poz.J<<endl;
  // pozycja pom;
  //pom.I=6; pom.J=2;
  //cout<<ruchy.front().I<<" "<<ruchy.front().J<<endl;
  plansza.RuchKrolowa(12,'C',ruchy.front());
  plansza.wyswietl();




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
      }*//*
  plansza.wyswietl(plansza.wyszukajPionek(1, 'C'));
  if(plansza.DostepPrawo(1,'C')){
    cout<<"moze isc w prawo pionkiem 1"<<endl;
  }
  else cout<<"NIE moze isc w lewo pionkiem 1"<<endl;
     

  plansza.RuchPrawo(1,'C');
  plansza.wyswietl(plansza.wyszukajPionek(1, 'C'));*/
  /*  if(plansza.DostepLewo(11,'C')){
    cout<<"lewo"<<endl;
    plansza.RuchLewo(11,'C');
  }  */
  //plansza.wyswietl(plansza.wyszukajPionek(7, 'C'));

}
