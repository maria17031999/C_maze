#include<iostream>
#include<vector>

using namespace std;

int main(){

cout<<"Introduzca las coordenadas del vector:"<<"\n";

vector<int>v;
int dato;

do{
cin>>dato;
    if(dato>=0){
    v.push_back(dato);
    }
}while(dato>=0)

int i=0;
while(i<v.size()){
    bool encontrado=false;

    for(int j=1; j<i&&!encontrado; j++)
        if(v[j]==v[i])
            encontrado=true;
    if(encontrado){
        int aux=v[i];
        v[i]=v[v.size - 1];
        v[v.size - 1]=aux;
        v.pop_back()
    }else i++;
}
system(PAUSE);
return 0;
}
