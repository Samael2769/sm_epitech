/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_world
*/

#include "sm_world.hpp"

sm_world::sm_world(int sizeX, int sizeY, int intMap[Max_Y][Max_X])
{
    Wx = sizeX;
    Wy = sizeY;
    tile_selected = -1;
    window = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), "sm_world");
    fillIntMap(intMap);
}

sm_world::~sm_world()
{
    
}

void sm_world::fillIntMap(int intMap[Max_Y][Max_X])
{
    for (int i = 0; i < Max_Y; i++) {
        for (int j = 0; j < Max_X; j++) {
            this->intMap[i][j] = intMap[i][j];
        }
    }
}


sf::Vector2f sm_world::projectISOPoint(int x, int y, int z)
{
    sf::Vector2f point;
    point.x = (x - y) * cos(0.523599) * SCALE;
    point.y = (x + y) * sin(0.523599) * SCALE - z * SCALE/8;
    return point;
}



std::vector<std::vector<sf::Vector2f>> sm_world::create2DMap(int intMap[Max_Y][Max_X])
{
    _2DMap.clear();
    for (int i = 0; i < Max_Y; i++) {
        std::vector<sf::Vector2f> line;
        for (int j = 0; j < Max_X; j++) {
            line.push_back(projectISOPoint(j, i, intMap[i][j]));
        }
        _2DMap.push_back(line);
    }
    center2DMapOnScreen();
    return _2DMap;
}

void sm_world::run()
{
    createDrawMap();
    fillVertexColor();
    createShapesWithVertex();
    ShapeToStruct();
    createToolBox();
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed) {
                for (int i = 0; i < _Tiles.size(); i++) {
                    if (_Tiles[i].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        tile_selected = i;
                    }
                }
                if (toolbox->isClicked(window, event, 0) && tile_selected != -1) {
                        UpTile(tile_selected);
                }
                if (toolbox->isClicked(window, event, 1) && tile_selected != -1) {
                        DownTile(tile_selected);
                }
                if (toolbox->isClicked(window, event, 2) && tile_selected != -1) {
                        resetTile(tile_selected);
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Left) {
                    rotateMap(-90);
                }
                if (event.key.code == sf::Keyboard::Right) {
                    rotateMap(90);
                }
            }
        }
        window->clear();
        drawShapes(window);
        draw2DMap(window, _2DMap);
        toolbox->draw();
        window->display();
    }
}

sf::VertexArray * sm_world::createLine(sf::Vector2f p1, sf::Vector2f p2)
{
    sf::VertexArray *line = new sf::VertexArray(sf::Lines, 2);

    (*line)[0].position = p1;
    (*line)[1].position = p2;
    return line;
}

void sm_world::createDrawMap()
{
    _DrawMap.clear();
    for (int i = 0; i < _2DMap.size(); i++) {
        for (int j = 0; j < _2DMap[i].size(); j++) {
            if (i + 1 < _2DMap.size()) {
                _DrawMap.push_back(*createLine(_2DMap[i][j], _2DMap[i + 1][j]));
            }
            if (j + 1 < _2DMap[i].size()) {
                _DrawMap.push_back(*createLine(_2DMap[i][j], _2DMap[i][j + 1]));
            }
        }
    }
}

int sm_world::draw2DMap(sf::RenderWindow *window, std::vector<std::vector<sf::Vector2f>> map)
{
    if (_DrawMap.size() == 0) {
        createDrawMap();
    }
    for (int i = 0; i < _DrawMap.size(); i++) {
        window->draw(_DrawMap[i]);
    }
    return 0;
}

//Use Wx and Wy to get the size of screen and center the tab on the screen
void sm_world::center2DMapOnScreen()
{
    float minX = _2DMap[0][0].x;
    float minY = _2DMap[0][0].y;
    float maxX = _2DMap[0][0].x;
    float maxY = _2DMap[0][0].y;

    for (int i = 0; i < _2DMap.size(); i++) {
        for (int j = 0; j < _2DMap[i].size(); j++) {
            if (_2DMap[i][j].x < minX)
                minX = _2DMap[i][j].x;
            if (_2DMap[i][j].y < minY)
                minY = _2DMap[i][j].y;
            if (_2DMap[i][j].x > maxX)
                maxX = _2DMap[i][j].x;
            if (_2DMap[i][j].y > maxY)
                maxY = _2DMap[i][j].y;
        }
    }
    for (int i = 0; i < _2DMap.size(); i++) {
        for (int j = 0; j < _2DMap[i].size(); j++) {
            _2DMap[i][j].x -= minX;
            _2DMap[i][j].y -= minY;
            _2DMap[i][j].x += (Wx - (maxX - minX)) / 2;
            _2DMap[i][j].y += (Wy - (maxY - minY)) / 2;
        }
    }
}

void sm_world::fillVertexColor()
{
    for (int i = 0; i < _DrawMap.size(); i++) {
        _DrawMap[i][0].color = sf::Color::Red;
        _DrawMap[i][1].color = sf::Color::Red;
    }
}

//create shapes with vertex vector
void sm_world::createShapesWithVertex()
{
    if (_Shapes.size() != 0)
        _Shapes.clear();
    for (int i = 0; i < _2DMap.size() - 1; i++) {
        for (int j = 0; j < _2DMap[i].size() - 1; j++) {
            sf::ConvexShape shape;
            shape.setPointCount(4);
            shape.setPoint(0, _2DMap[i][j]);
            shape.setPoint(1, _2DMap[i][j + 1]);
            shape.setPoint(2, _2DMap[i + 1][j + 1]);
            shape.setPoint(3, _2DMap[i + 1][j]);
            shape.setFillColor(sf::Color::Green);
            _Shapes.push_back(shape);
        }
    }
}

//draw shapes
void sm_world::drawShapes(sf::RenderWindow *window)
{
    for (int i = 0; i < _Tiles.size(); i++) {
        if (i != tile_selected) {
            _Tiles[i].shape.setFillColor(sf::Color::Green);
            window->draw(_Tiles[i].shape);
        } else {
            _Tiles[i].shape.setFillColor(sf::Color::Red);
            window->draw(_Tiles[i].shape);
        }
    }
}

void sm_world::ShapeToStruct()
{
    if (_Tiles.size() != 0)
        _Tiles.clear();
    for (int i = 0; i < _Shapes.size(); i++) {
        tile_t tile;
        tile.shape = _Shapes[i];
        tile.color = _Shapes[i].getFillColor();
        tile.id = i;
        _Tiles.push_back(tile);
    }
}

std::vector<std::pair<int, int>> sm_world::getTileAngles(int id)
{
    std::vector<std::pair<int, int>> angles;
    angles.push_back(std::make_pair(id / (Max_Y - 1), id % (Max_X - 1)));
    angles.push_back(std::make_pair(id / (Max_Y - 1), id % (Max_X - 1) + 1));
    angles.push_back(std::make_pair(id / (Max_Y - 1) + 1, id % (Max_X - 1)));
    angles.push_back(std::make_pair(id / (Max_Y - 1) + 1, id % (Max_X - 1) + 1));
    return angles;
}

void sm_world::UpTile(int id){
    std::vector<std::pair<int, int>> angles = getTileAngles(id);
    for (int i = 0; i < angles.size(); i++) {
        intMap[angles[i].first][angles[i].second] += 1;
    }
    create2DMap(intMap);
    createDrawMap();
    fillVertexColor();
    createShapesWithVertex();
    ShapeToStruct();
}

void sm_world::DownTile(int id){
    std::vector<std::pair<int, int>> angles = getTileAngles(id);
    for (int i = 0; i < angles.size(); i++) {
        intMap[angles[i].first][angles[i].second] -= 1;
    }
    create2DMap(intMap);
    createDrawMap();
    fillVertexColor();
    createShapesWithVertex();
    ShapeToStruct();
}

void sm_world::resetTile(int id){
    std::vector<std::pair<int, int>> angles = getTileAngles(id);
    for (int i = 0; i < angles.size(); i++) {
        intMap[angles[i].first][angles[i].second] = 0;
    }
    create2DMap(intMap);
    createDrawMap();
    fillVertexColor();
    createShapesWithVertex();
    ShapeToStruct();
}

void sm_world::createToolBox() {
    toolbox = new toolBox(sf::Color::Blue, sf::Vector2f(0, 0), sf::Vector2f(300, 100), window);
    toolbox->addButton("test", sf::Color::Red, sf::Vector2f(10, 10), sf::Vector2f(50, 50));
    toolbox->addButton("test2", sf::Color::Green, sf::Vector2f(70, 10), sf::Vector2f(50, 50));
    toolbox->addButton("test3", sf::Color::Magenta, sf::Vector2f(130, 10), sf::Vector2f(50, 50));
}

void sm_world::rotateMap(int angle)
{
    int newMap[Max_X][Max_Y] = { 0 };
    for (int i = 0; i < Max_X; i++) {
        for (int j = 0; j < Max_Y; j++) {
            if (angle == 90) {
                newMap[i][j] = intMap[Max_Y - j - 1][i];
            } else if (angle == -90)
                newMap[i][j] = intMap[j][Max_X - i - 1];
        }
    }
    tile_selected = -1;
    fillIntMap(newMap);
    create2DMap(intMap);
    createDrawMap();
    fillVertexColor();
    createShapesWithVertex();
    ShapeToStruct();
}