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
   
  queue<int> krolowki;
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
  //plansza.wyswietl(plansza.wyszukajPionek(4, 'B'));
  plansza.RuchLewo(3,'C');
  plansza.RuchLewo(8,'B');
  plansza.RuchPrawo(6,'C');
  plansza.RuchLewo(4,'B');
  plansza.RuchPrawo(4,'B');
  
  krolowki=plansza.KrolowaBialaDostep();
  cout<<"krolowki: "<<krolowki.front()<<endl;

  plansza.wyswietl(plansza.wyszukajPionek(4, 'B'));

  plansza.RuchLewo(4,'B');
  plansza.wyswietl();

  krolowki=plansza.KrolowaBialaDostep();
  cout<<"krolowki: "<<krolowki.front()<<endl;

  queue<pozycja> ruchy=plansza.KrolowaRuchy(4,'B');
  while(!ruchy.empty()){
    cout<<ruchy.front().I<<"  "<<ruchy.front().J<<endl;
    ruchy.pop();
  }
  if(plansza.CzyBicie('B')){cout<<"jest bicie"<<endl;}
  if(plansza.CzyBicie(4,'B')){cout<<"Ma bicie"<<endl;}
  ruchy=plansza.KrolowaRuchy(4,'B');
  plansza.RuchKrolowa(4,'B',ruchy.front());
  cout<<"Po ruchu"<<endl;
  plansza.wyswietl();

  /*
  int zysk=Symuluj(plansza,ID,strona,flaga,miejsce);
  cout<<"Zysk:"<<zysk<<endl;
  cout<<"Strona:"<<strona<<endl;
*/
  /*
  int zysk=RuszCzarne(plansza,0,0,3,strona);
  cout<<"Zysk:"<<zysk<<endl;
  cout<<"Strona:"<<strona<<endl;
*/
  /*
  plansza.RuchPrawo(11,'B');
  plansza.RuchLewo(12,'C');
  plansza.wyswietl();
  plansza.RuchPrawo(12,'C');
  plansza.wyswietl();*/
  /*
  queue<int> krolowki;
  krolowki=plansza.KrolowaCzarnaDostep();
  //krolowki.push(9870);
  cout<<"krolowki: "<<krolowki.front()<<endl;
  */
  //queue<pozycja> ruchy=plansza.KrolowaRuchy(12,'C');
  /* while(!ruchy.empty()){
    cout<<ruchy.front().I<<"  "<<ruchy.front().J<<endl;
    ruchy.pop();
  }*/
  // pozycja pom;
  //pom.I=6; pom.J=2;
  /*while(!ruchy.empty()){
  plansza.RuchKrolowa(12,'C',ruchy.front());
  ruchy.pop();
  plansza.wyswietl();
 }*/

  /*
  plansza.wyswietl(plansza.wyszukajPionek(8, 'B'));
  plansza.RuchPrawo(11,'C');
  plansza.RuchLewo(3,'C');
  plansza.RuchLewo(8,'B');
  plansza.RuchPrawo(8,'B');
  plansza.RuchLewo(8,'B');
  plansza.wyswietl();

  queue<int> krolowki;
  krolowki=plansza.KrolowaBialaDostep();
  cout<<"krolowki: "<<krolowki.front()<<endl;
  
  queue<int> krolowki2;
  krolowki2=plansza.KrolowaCzarnaDostep();
  cout<<"krolowki: "<<krolowki2.front()<<endl;
*/
  //plansza.wyswietl(plansza.wyszukajPionek(12, 'C'));
  //plansza.DostepLewo(12,'C');

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
