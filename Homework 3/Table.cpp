#include <iostream>
#include <fstream>

using namespace std;
ifstream fin;
ofstream fout;

int CountOfLine(){
    fin.open("matrix_of_incendence10.txt");
    string line;
    int i=0;
    while(fin){
        i++;
        getline(fin, line);
    }
    fin.close();
    return i-1;
}

int LenOfLine(){
    fin.open("matrix_of_incendence10.txt");
    string line;
    int k=0;
    getline(fin, line);
    for(int i=0; i<line.size(); i++)
        if(line[i]!=' ')
            k++;
    fin.close();
    return k;
}

int main()
{
    int  lenx=LenOfLine(), leny=CountOfLine(), i, j, n;
    char Matrix[leny][lenx];
    string line;
    fin.open("matrix_of_incendence10.txt");
    for(i=0; i<leny; i++){
        getline(fin, line);
        n=0;
        for(j=0; j<line.size(); j++){
            if(line[j]!=' '){
                Matrix[i][n]=line[j];
                n++;
            }
        }
    }
    fin.close();

    int Edges[2][lenx];
    for(j=0; j<lenx; j++){
        Edges[0][j]=0;
        Edges[1][j]=0;
        n=0;
        for(i=0; i<lenx; i++)
            if(Matrix[i][j]=='1'){
                Edges[n++][j]=i+1;
            }
    }

    bool flag=true;
    fout.open("Result.txt");

    for(i=0; i<lenx; i++){
        if(Edges[1][i]==0){
            fout<<"Ребро "<<i+1<<" является петлёй\n";
            flag=false;
        }
    }

    string s;
    for(i=0; i<lenx-1; i++){
        if(Edges[0][i]!=0){
            s=to_string(i+1)+" ";
            bool flag1=false;
            for(j=i+1; j<lenx; j++)
                if(Edges[0][i]==Edges[0][j] && Edges[1][i]==Edges[1][j]){
                    Edges[0][j]=0;
                    s+=to_string(j+1)+" ";
                    flag=false;
                    flag1=true;
                }
        if(flag1)
            fout<<"Ребрa "<<s<<"соединяют одинаковые вершины\n";
        }
    }
    fout<<'\n';
    if(flag){
        if(leny>(lenx-2)*(lenx-1)/2)
            fout<<"По теореме граф связанный";
        else
            fout<<"По теореме граф несвязанный";
    }else
        fout<<"=> граф не простой => граф не связанный по теореме";
    fout.close();
    return 0;
}
