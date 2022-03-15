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
    fout.open("Edges.dot");
    fout<<"graph graphname {\n";
    for(j=0; j<leny; j++)
        fout<<j+1<<";\n";
    int Edge[2];
    for(j=0; j<lenx; j++){
        Edge[0]='0';
        Edge[1]='0';
        n=0;
        for(i=0; i<leny; i++)
            if(Matrix[i][j]=='1'){
                Edge[n++]=i+1;
            }
        if(Edge[0]!='0' && Edge[1]!='0')
            fout<<Edge[0]<<" -- "<<Edge[1]<<";\n";
        else
            fout<<Edge[0]<<" -- "<<Edge[0]<<";\n";
    }
    fout<<"}";
    fout.close();
    return 0;
}
