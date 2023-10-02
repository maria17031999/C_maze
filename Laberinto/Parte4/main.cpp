#include <iostream>
#include <vector>

using namespace std;

vector<bool> VectorVistiadasInicial(vector<Pared> p, vector<vector<int> >v){

	vector<bool> visitadas(v.size());
	for(int i=0; i<visitadas.size(); i++){
		visitadas[i]=false;
	}
}

vector<bool> VectorVisitadas(int h,vector<bool> b){
    b[h]=true;

return b;
}

vector<int> Solucion(vector<vector<int> >v, vector<bool> b, vector<int> Sol, int s){
    vector<int> VecinosNoVisitados();

    while(h!=s){
    for(int i=0; i<v[h].size();i++){
        b=VectorVisitadas(h,b);
        vecinillo=v[i];
        if(b[vecinillo]=false&&Pasar(vp,h,vecinillo)=true){
            VecinosNoVisitados.push_back(vecinillo);
        }
    }

        if(VecinosNoVisitados.size()==0){
        Sol.pop_back(h);
        s=Sol[Sol.size()];
        }else{
            Sol.push_back(vecinillo);
            h=vecinillo
        }

    }

return Sol;
}

int GenerarAleatorio (int mini, int maxi)
{
    double aleatorio=rand()/(RAND_MAX+1.0);
    int num=(maxi-mini+1)*aleatorio+mini;
    return num;
}

int main()
{
    vector<int> vectorSolucion();
    vectorSolucion.push_back(0);


    int h=0;
    vector<int> VecinosNovisitados=VecinosNoVisitados(v,b,vectorSolucion,h);
    int aleatorio=GenerarAleatorio(0,VecinosNoVisitados.size());

}
