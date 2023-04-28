/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_world
*/

#ifndef SM_WORLD_HPP_
#define SM_WORLD_HPP_

#define Max_X 6
#define Max_Y 6
#define SCALE 64

#include <iostream>
#include <cmath>

#include "toolBox.hpp"

class sm_world {
    public:
        sm_world(int sizeX, int sizeY, int intMap[Max_Y][Max_X]);
        ~sm_world();
        void fillIntMap(int intMap[Max_Y][Max_X]);
        sf::Vector2f projectISOPoint(int x, int y, int z);
        std::vector<std::vector<sf::Vector2f>> create2DMap(int intMap[Max_Y][Max_X]);
        sf::VertexArray * createLine(sf::Vector2f p1, sf::Vector2f p2);
        void center2DMapOnScreen();
        void run();
        void createDrawMap();
        int draw2DMap(sf::RenderWindow *window, std::vector<std::vector<sf::Vector2f>> map);
        void fillVertexColor();
        void createShapesWithVertex();
        void drawShapes(sf::RenderWindow *window);
        void ShapeToStruct();
        std::vector<std::pair<int, int>> getTileAngles(int id);
        void createToolBox();
        void UpTile(int id);
        void DownTile(int id);
        void resetTile(int id);
        typedef struct tile_s {
            sf::ConvexShape shape;
            sf::Color color;
            int id;
        } tile_t;
        void rotateMap(int angle);

    protected:
    private:
        std::vector<std::vector<sf::Vector2f>> _2DMap;
        sf::RenderWindow *window;
        std::vector<sf::VertexArray> _DrawMap;
        std::vector<sf::ConvexShape> _Shapes;
        std::vector<tile_s> _Tiles;
        int Wx;
        int Wy;
        int tile_selected;
        toolBox *toolbox;
        int intMap[Max_Y][Max_X];
};

#endif /* !SM_WORLD_HPP_ */
