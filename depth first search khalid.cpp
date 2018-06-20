#include <deque>
#include <set>


bool depthFirstSearch(char maze[100][100],coords location, coords target, std::deque<coords>* path, std::set<coords>* closed)
{
    path->push_back(location);
    closed->insert(location);
    if (location == target)
    {
        return true;
    }
    for(int i = location.x-1; i <= location.x+1; i++)
        for (int j = location.y-1; j <= location.y+1; j++)
        {
            if(i != location.x || j 1= loaction.y)
            {
                if(maze[i][j] != '0' && maze[i][j] != 'o')
                {
                    if(!closed->count(coords(i,j)))
                    {
                        if (depthFirstSearch(maze,coords(i, j), target, path))
                        {
                            return true;
                        }
                    }
                }
            }
        }
    path->pop_back()
    return false;
}
