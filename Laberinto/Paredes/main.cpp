#include <iostream>
#include <vector>
using namespace std;

//Ejercicio 4.1
struct Pared{
    int hab;
    int hab2;

    bool crearpared;
};

Pared EstadoPared(int hab, int hab2){
    if(hab>hab2){
        int aux=hab;
        hab=hab2;
        hab2=aux;
    }

    Pared p;
    p.hab=hab;
    p.hab2=hab2;

    p.crearpared=true;
}

int CantidadCasillas(vector<Pared> p){
    int maxi=0;
    for(int i=0;i<p.size();i++){
        if(p[i].hab>maxi){
            maxi=p[i].hab;
        }
    }

return maxi+1;
}

int Paredes(vector<Pared> p, int h1, int h2){
    bool esta=false;
    int posicion=0;
    if(h1>h2){
        int aux=h1;
        h1=h2;
        h2=aux;
    }

    for(int i=0; i<p.size() && !esta; i++){
        if(p[i].hab==h1 && p[i].hab2==h2){
            posicion=i;
            esta=true;
        }
        if(esta)
            return posicion;
        else return -1;
    }
}

vector<Pared> VectordeParedes(const vector<vector>int > &v){
    vector<Pared> p;
    Pared par;

    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++)
        if(i<v[i]v[j]){
        par= EstadoPared(i,v[i]v[j]);
        p.push_back(par);}
    }

return p;
}

bool Pasar(vector<Pared> p, int h1, int h2){
    bool esta=false;
    int posicion=0;
    if(h1>h2){
        int aux=h1;
        h1=h2;
        h2=aux;
    }

    for(int i=0; i<p.size() && !esta; i++){
        if(p[i].hab==h1 && p[i].hab2==h2){
            pasar=p[i].esta;
        }
    }

return pasar;
}

vector<Pared> Levantadas(vector<Pared> p){
    for(int i=0;i<p.size();i++){
        p[i].crearpared=true;
    }


}

vector<vector<int> > TransAVecinos(vector<Pared> p){
    vector<vector<int> > v(CantidadCasillas(vector<Pared> p);

    for(int i=0;i<v.size();i++){
        v[p[i].hab1].push_back(p[i].hab2);
        v[p[i].hab2].push_back(p[i].hab1);
    }

}

/*int NumHabitacion (int fil, int col, int f, int c)
{
    int num=(f*col)+c;
    return num;
}

bool Estar (int fil, int col, int f, int c)
{
    bool estar=true;
    if (f>=fil || c>=col || f<0 || c<0)
        estar=false;
    return estar;
}
*/

/*
vector<vector<int> >HabVecinas (int fil, int col, int vec)
{
    vector<vector<int> > v(fil*col);
    for(int i=0; i<fil; i++)
    {
        for(int j=0; j<col; j++)
        {
            int pos= NumHabitacion(fil,col,i,j);
            if (vec==4)
            {
                if (Estar(fil,col,i,j+1))
                    v[pos].push_back(NumHabitacion(fil,col,i,j+1));
                if (Estar(fil,col,i,j-1))
                    v[pos].push_back(NumHabitacion(fil,col,i,j-1));
                if (Estar(fil,col,i+1,j))
                    v[pos].push_back(NumHabitacion(fil,col,i+1,j));
                if (Estar(fil,col,i-1,j))
                    v[pos].push_back(NumHabitacion(fil,col,i-1,j));
            }
            else if (vec==6)
            {
                if(i%2==0)
                {
                    if (Estar(fil,col,i,j+1))
                        v[pos].push_back(NumHabitacion(fil,col,i,j+1));
                    if (Estar(fil,col,i,j-1))
                        v[pos].push_back(NumHabitacion(fil,col,i,j-1));
                    if (Estar(fil,col,i+1,j))
                        v[pos].push_back(NumHabitacion(fil,col,i+1,j));
                    if (Estar(fil,col,i-1,j))
                        v[pos].push_back(NumHabitacion(fil,col,i-1,j));
                    if (Estar(fil,col,i-1,j+1))
                        v[pos].push_back(NumHabitacion(fil,col,i-1,j+1));
                    if (Estar(fil,col,i+1,j+1))
                        v[pos].push_back(NumHabitacion(fil,col,i+1,j+1));
                }
                if(i%2!=0)
                {
                    if (Estar(fil,col,i,j+1))
                        v[pos].push_back(NumHabitacion(fil,col,i,j+1));
                    if (Estar(fil,col,i,j-1))
                        v[pos].push_back(NumHabitacion(fil,col,i,j-1));
                    if (Estar(fil,col,i+1,j))
                        v[pos].push_back(NumHabitacion(fil,col,i+1,j));
                    if (Estar(fil,col,i-1,j))
                        v[pos].push_back(NumHabitacion(fil,col,i-1,j));
                    if (Estar(fil,col,i-1,j-1))
                        v[pos].push_back(NumHabitacion(fil,col,i-1,j-1));
                    if (Estar(fil,col,i+1,j-1))
                        v[pos].push_back(NumHabitacion(fil,col,i+1,j-1));
                }
            }
            else if (vec==8)
            {
                if (Estar(fil,col,i,j+1))
                    v[pos].push_back(NumHabitacion(fil,col,i,j+1));
                if (Estar(fil,col,i,j-1))
                    v[pos].push_back(NumHabitacion(fil,col,i,j-1));
                if (Estar(fil,col,i+1,j))
                    v[pos].push_back(NumHabitacion(fil,col,i+1,j));
                if (Estar(fil,col,i-1,j))
                    v[pos].push_back(NumHabitacion(fil,col,i-1,j));
                if (Estar(fil,col,i+1,j+1))
                    v[pos].push_back(NumHabitacion(fil,col,i+1,j+1));
                if (Estar(fil,col,i+1,j-1))
                    v[pos].push_back(NumHabitacion(fil,col,i+1,j-1));
                if (Estar(fil,col,i-1,j+1))
                    v[pos].push_back(NumHabitacion(fil,col,i-1,j+1));
                if (Estar(fil,col,i-1,j-1))
                    v[pos].push_back(NumHabitacion(fil,col,i-1,j-1));
            }
        }


    }
    return v;
}



/*void Escribir (const vector<vector<int> >&v)
{
    cout<<v.size()<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].size()<<" ";
        for (int j=0; j<v[i].size(); j++)
            cout<< v[i][j]<< " ";
        cout<<endl;
    }
}
*/
vector<Pared> LeerPared(){
    int n, a, b;
    cin>>n;
    vector<Pared> p;

    for(int i=0;i<n;i++){
        cin>>a,b;
        if(a<b){
            p.push_back(EstadoPared(a,b))
        }
    }
    return p;
}



vector<vector<int> > Leer(){
    vector<vector<int> >v;
    int n;

    //cout<<"Tamanyo n del vector de vectores ";
    cin>>n;

    for(int i=0; i<n;i++){
        vector<int>v2;
        int nv2;
        //cout<<"Tamanyo del vector "<<i+1<<" ";
        cin>>nv2;
        for(int j=0;j<nv2;j++){
            int dato;
            //cout<<"Datos: ";
            cin>>dato;
            v[i].push_back(dato);
        }
    }

return v;
}

void EscribirPared(const vector<pared> &p){
    cout << p.size() <<endl;
    for(int i=0;i<p.size();i++){
        if(p[i].esta=true){
            cout<<" | ";
        }else cout<<"  _ ";
    }
}


int main()
{
    /*int fil, col, vec;
    vector<vector<int> > v;
    cout << "Introduzca el numero de filas totales del laberinto : " << endl;
    cin >> fil;
    while(fil<=0)
    {
        cout<< "El numero de de filas es menor que 0, introduzca otro valor: "<<endl;
        cin >> fil;
    }
    cout << "Introduzca el numero de columnas totales: "<< endl;
    cin >> col;
    while(col<=0)
    {
        cout<< "El numero de de columnas es menor que 0, introduzca otro valor: "<<endl;
        cin >> col;
    }
    cout <<"Introduzca el numero de vecinos: " << endl;
    cin >> vec;
    while((vec<=0) || ((vec!=4)&&(vec!=6)&&(vec!=8)))
    {
        cout<< "El numero de vecinos es incorrecto, introduzca otro valor: "<<endl;
        cin >> vec;
    }
    */
    v=HabVecinas(fil,col,vec);
    Escribir(v);

    vector<vector<int> >v2;
    v2=Leer();
    Escribir(v2);
    
    vector<Pared> p;
    p= Paredes(v);
	EscribirPared(p);

    return 0;
}
