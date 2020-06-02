#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//link para exercício https://www.codingame.com/ide/puzzle/there-is-no-spoon-episode-1

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    char** grid = new char*[height]; //y - axis
    for (int i = 0; i < height; i++)
    {
        grid[i] = new char[width]; //x - axis
    }
    cerr<< "Tamanhos: " <<width<<" "<<height<<endl;
    
    string line;
    for (int i = 0; i < height; i++) 
    {
        getline(cin, line); 
        cerr<<line<<endl;
        line.copy(grid[i], width, 0);
    }

    //CERR para diferentes tamanhos
    /*
    for (int j = 0; j < height; j++)
    {  
        for (int i = 0; i < width; i++)
        {
            cerr<<"grid["<< j <<"]["<< i <<"] = "<<grid[j][i]<<" | ";
        }
        cerr<<endl;
    }
    */

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            if(grid[y][x] != '.')
            {
                //Nó
                int output[6] = {x, y, -1, -1, -1, -1};
                //Eixo X - Para Direita
                for(int dir = x + 1; dir < width; dir++)
                {
                    if(grid[y][dir] != '.') //Pular celula vazia
                    {
                        output[2] = dir;
                        output[3] = y;
                        dir = width;
                    }
                }
                //Eixo Y - Para Baixo
                for(int bai = y + 1; bai < height; bai++)
                {
                    if(grid[bai][x] != '.') //Pular celula vazia
                    {
                        output[4] = x;
                        output[5] = bai;
                        bai = height;
                    }
                }
                //Saida
                cout<<output[0]<<" "<<output[1]<<" "<<output[2]<<" "<<output[3]<<" "<<output[4]<<" "<<output[5]<<endl;
            }
        }
    }
}
