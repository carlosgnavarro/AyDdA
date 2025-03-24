#include <iostream>

int sudoku[9][9] = {0};

bool can(int num, int fila, int columna)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudoku[fila][i] == num || sudoku[i][columna] == num)
        {
            return false;
        }
    }
    int filo = (fila/3)*3;
    int colo = (columna/3)*3;
    for(int i = filo; i < filo+3; i++)
    {
        for(int j = colo; j < colo+3; j++)
        {
            if(sudoku[i][j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

void resuelveme_esta(int fila, int columna)
{
    bool flag = false;
    int filo, colo;
    for(filo = fila; filo < 9 && !flag; filo++)
    {
        for(colo = 0; colo < 9 && !flag; colo++)
        {
            if(sudoku[filo][colo] == 0)
            {
                flag = true;
            }
        }
    }
    if(!flag)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                std::cout << sudoku[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    filo--;
    colo--;
    for(int i = 1; i <= 9; i++)
    {
        if (can(i,filo,colo))
        {
            sudoku[filo][colo] = i;
            resuelveme_esta(filo,colo);
            sudoku[filo][colo] = 0;
        }   
    }
}

int main()
{
    char temp;
    int num_casos;
    std::cin >> num_casos;
    for(int i = 0; i < num_casos; i++)
    {
        for(int fila = 0; fila < 9; fila++)
        {
            for(int columna = 0; columna < 9; columna++)
            {
                std::cin >> temp;
                sudoku[fila][columna] = temp - '0';

            }
            std::cin.ignore();
        }
        resuelveme_esta(0,0);
    }
    return 0;
}