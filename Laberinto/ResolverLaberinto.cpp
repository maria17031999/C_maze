#include <iostream>
#include <vector>

using namespace std;

struct Pared
{
    int hab1;
    int hab2;
    bool esta;
};

Pared Crear(int a, int b)
{
    if(a>b)
    {
        int aux=a;
        a=b;
        b=aux;
    }
    Pared p;
    p.hab1=a;
    p.hab2=b;
    p.esta=true;
    return p;

}

int NumHabitaciones (const vector<Pared>& p)
{
    int mayor=0;
    for(int i=0; i<p.size(); i++)
    {
        if (p[i].hab2>mayor)
            mayor=p[i].hab2;
    }
    return mayor+1;
}



bool Pasar (const vector<Pared>& p, int hab1, int hab2)
{
    bool pasar;
    if(hab1>hab2)
    {
        int aux=hab1;
        hab1=hab2;
        hab2=aux;
    }
    for (int i=0; i<p.size(); i++)
    {
        if(p[i].hab1==hab1 && p[i].hab2==hab2)
        {
            pasar=p[i].esta;
        }
    }
    return pasar;
}


vector<Pared> TodasLevantadas (vector<Pared> &p)
{
    for(int i=0; i<p.size(); i++)
        p[i].esta=true;
    return p;

}

vector<Pared> VectordeParedes (const vector<vector<int> > &v)
{
    vector<Pared> p;
    Pared par;
    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i].size(); j++)
        {
            if(i<v[i][j])
            {
                par= Crear(i,v[i][j]);
                p.push_back(par);
            }
        }
    }
    return p;
}

vector<vector<int> >TransformaraVecinos (const vector<Pared> &p)
{
    vector<vector<int> > v(NumHabitaciones(p));
    for (int i=0; i<p.size(); i++)
    {
        v[p[i].hab1].push_back(p[i].hab2);
        v[p[i].hab2].push_back(p[i].hab1);
    }
    return v;
}

vector<Pared> LeerPared()
{
    int n;
    cin >> n;
    vector<Pared> p(n);
    for(int i= 0; i< p.size(); i++)
    {
        cin >> p[i].hab1;
        cin >> p[i].hab2;
        char e;
        cin >> e;
        if (e == '|')
            p[i].esta = true;
        else if (e == '_')
            p[i].esta = false;

    }

    return p;
}

void EscribirPared (const vector<Pared>& p)
{
    cout<<p.size()<<endl;
    for(int i=0; i<p.size(); i++)
    {
        cout<<p[i].hab1<<" "<<p[i].hab2;
        if(p[i].esta)
            cout<<" | ";
        else
            cout<< " _ ";
        cout<<endl;
    }
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

vector<vector<int> > Leer ()
{
    int n;
    cin >> n;
    vector<vector<int> > v(n);
    for (int i=0; i<v.size(); i++)
    {
        int nmini;
        cin >> nmini;
        for(int j=0; j<nmini; j++)
        {
            int dato;
            cin>> dato;
            v[i].push_back(dato);
        }
    }
    return v;
}


vector<int> Resolver (const vector<Pared> &p, const vector<vector<int> > &v)
{
    vector<int> sol;
    sol.push_back(0);
    vector<bool> vis(v.size(),false);
    vis[0]=true;
    int ultimo=0;

    while(sol[sol.size()-1]!=v.size()-1)
    {
        int a=-1;
        for (int i=0; i<v[ultimo].size(); i++)
        {   bool pasar= !Pasar(p,ultimo,v[ultimo][i]);
        if(pasar==true && !vis[v[ultimo][i]])
            a=v[ultimo][i];
        }
        if(a!=-1){
            sol.push_back(a);
            vis[a]=true;
            ultimo=a;
        }
        else sol.pop_back();

        ultimo=sol[sol.size()-1];
    }
    return sol;
    }



int main()
{
    vector<Pared> p;
    p=LeerPared();
    cout<<endl<<endl;
    vector<vector<int> >v=TransformaraVecinos(p);
    cout<<endl;
    vector <int>sol;
    sol=Resolver(p,v);
    cout<<endl;
    for (int i=0; i<sol.size();i++)
        cout<< sol[i]<<"  ";



    return 0;
}
