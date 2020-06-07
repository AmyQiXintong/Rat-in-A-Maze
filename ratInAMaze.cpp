// this program aims to confirm whether there is way out of a maze
 
 
 
#include <iostream>
 
 
 
using namespace std;
 
 
 
bool path(int r, int c, int maze[][10], int record[][10], int size, int exitr, int exitc) {
 
    //check whether it reaches the destination
 
    if ((r == exitr) && (c == exitc))
 
    {
 
        record[r][c] = 1;
 
        return true;
 
    }
 
 
 
    //check whether it can take the step
 
    if (r >= 0 && c >= 0 && r < size && c < size && record[r][c] == 0 && maze[r][c] == 1)
 
    {
 
        record[r][c] = 1;
 
        //check four directions:down,up,right,left
 
        if (path(r + 1, c, maze, record, size, exitr, exitc))
 
        {
 
            return true;
 
        }
 
        if (path(r - 1, c, maze, record, size, exitr, exitc))
 
        {
 
            return true;
 
        }
 
        if (path(r, c + 1, maze, record, size, exitr, exitc))
 
        {
 
            return true;
 
        }
 
        if (path(r, c - 1, maze, record, size, exitr, exitc))
 
        {
 
            return true;
 
        }
 
        //backtracking, mark it as hasn't been to
 
        record[r][c] = 0;
 
        return false;
 
    }
 
    return false;
 
}
 
 
 
 
 
int main()
 
{
 
    //get user input
 
    int size, exitr, exitc, r = 0, c = 0;
 
    int maze[10][10], record[10][10];
 
    cout << "Input the size of the maze:" << endl;
 
    cin >> size;
 
    cout << "Input the coordinate of the exit:" << endl;
 
    cin >> exitr >> exitc;
 
    cout << "Input the structure of the maze:" << endl;
 
    for (int i = 0; i < size; i++)
 
    {
 
        for (int j = 0; j < size; j++)
 
        {
 
            cin >> maze[i][j];
 
        }
 
    }
 
    //another array to record the path
 
    //and determine whether the position has been to or not
 
    for (int i = 0; i < size; i++)
 
    {
 
        for (int j = 0; j < size; j++)
 
        {
 
            record[i][j] = 0;
 
        }
 
    }
 
 
 
    //call the function and get the result
 
    bool havePath = path(r, c, maze, record, size, exitr, exitc);
 
 
 
    //give the output
 
    if (havePath == true)
 
    {
 
        cout << "Congratulation! You can get to the exit!" << endl;
 
    }
 
    else
 
    {
 
        cout << "There is no way to get to the exit!" << endl;
 
    }
 
 
 
    return 0;
 
}
