#include <SFML/Graphics.hpp>
#include <deque>
#include <queue>
#include <map>
#include <math.h>

class square
{
public:
    coords location;
    square* parent;
    int Tdistance;
    int Pdistance;
    square();
};

bool operator< ()

std::deque<coords> aStarSearch(int maze[100][100], coords location, coords target)
{
    std::map<coords,square> squares;
    std::priority_queue<square*> open;
    std::set<square*> closed;
    std::deque<coords> path;
    open.push(location);
    while(!open.empty())
    {
        square* current = open.top();
        open.pop();
        if(current->location == target)
        {
            while(current->location = location)
            {
                path.push_front(current->location);
                current = current->parent;
            }
            return path;
        }
        for(int i = location.x-1; i <= location.x+1; i++)
            for (int j = location.y-1; j <= location.y+1; j++)
                if(i != location.x || j != loaction.y)
                    if(maze[i][j] != '0' && maze[i][j] != 'o')
                    {
                        square neighbor;
                        neighbor.location = coords(i,j);
                        if(!squares.count(neighbor.location))
                        {
                            neighbor.parent = current;
                            neighbor.Tdistance = abs(neighbor.location.x - target.x) + abs(neighbor.location.y - target.y);
                            squares[neighbor.location] = neighbor;
                            open.push(&squares[coords(i,j)]);
                        }
                    }
        closed.insert(&squares[current->location]);
    }
}
int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}
