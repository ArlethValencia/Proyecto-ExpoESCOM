/*
Towers.cpp
V 1.5 Junio 2023
Autores:
Equipo Las Divinas

Programa que resuelve mediante Programacion Dinamica el problema de Towers

Orden de complejidad:
Temporal: O(n*(Wn+Sn))
Espacial: O(Wn+Sn)
Compilación 
Linux: gpp Towers.cpp -o Towers.exe
Ejecución
Linux: ./Towers.exe 
Windows: Towers.exe 
*/
////************************Librerias**********************////
#include <bits/stdc++.h>

using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(0);
#define ll long long

////************************Funciones**********************////

/*
Estructura que representa un bloque con sus atributos
*/
typedef struct bloque 
{
    ll w, s, v;
} bloque;

/*
bool compara(bloque x, bloque y)
Recibe: bloque x, bloque y, bloques a comparar
Devuelve: bool, true si el primer bloque es menor que el segundo, false en otro caso
Observaciones: Funcion que compara dos bloques respecto a la suma de sus atributos w y s
utilizada para ordenar los bloques de menor a mayor respecto a la suma de sus atributos w y s
*/
bool compara(bloque x, bloque y) 
{ 
    return x.s + x.w < y.s + y.w; 
}

/*
void solve()
Recibe: void (No recibe parametros)
Devuelve: void (No retorna valor explicito)
Observaciones: Funcion que resuelve el problema de Towers mediante Programacion Dinamica
*/
void solve() 
{
    ll n, respuesta=0;
    cin >> n;
    //Crea un arreglo de bloques de tamaño n+1
    bloque a[n+1];
    //Lee los atributos de cada bloque
    for (int i = 1; i <= n; i++) {
        cin >> a[i].w >> a[i].s >> a[i].v;
    }
    //Ordena los bloques de menor a mayor respecto a la suma de sus atributos w y s
    sort(a + 1, a + n + 1, compara);
    //Calcula la suma maxima de los atributos w y s de los bloques
    ll suma_max=a[n].w+a[n].s;
    //Crea un arreglo de tamaño suma_max+1
    ll dp[suma_max+1];
    //Inicializa el arreglo dp con 0
    memset(dp, 0, sizeof(dp));
    //Calcula la respuesta mediante Programacion Dinamica
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i].w + a[i].s; j >= a[i].w; j--)
        {
            dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v);
        }
    }
    //Busca el valor mas grande en el arreglo dp que sera la respuesta
    for (ll i = suma_max ; i > 0; i--)
        respuesta = max(respuesta, dp[i]); 
    cout << respuesta<<endl;
    return;
}

////************************Funcion Principal**********************////
int main() 
{
    fastio
    solve();
    return 0;
}
