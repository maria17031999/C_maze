#include <iostream>
#include <vector>
using namespace std;

//Ejercicio 4.1
int NumHabitacion (int fil, int col, int f, int c)
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

void Escribir (const vector<vector<int> >&v)
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


int main()
{
    int fil, col, vec;
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
    v=HabVecinas(fil,col,vec);
    Escribir(v);

    return 0;
}
