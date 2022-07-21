#include <SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include <iostream>
#include<vector>


using namespace std;
using namespace sf;

//Globale Daten
RenderWindow window(VideoMode(1500, 775), "Snake-ai", Style::Titlebar | Style::Close);
vector<RectangleShape>Background;//Hintergrund Elemente
RectangleShape border;//Begrenzung des Spielfeldes

//Verlinkung
void map_draw();
void map_create();


int main()
{
    map_create();
    window.setFramerateLimit(30);

    while (window.isOpen())//Fenster öffnet sich
    {
        Event event;//Abfrage von Events
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        map_draw();
        window.display();
    }
}

void map_create() {
    
    Vector2f background_block_size(25, 25);//Größe der Elemente
    Vector2f border_loc(700, window.getSize().y);//Größe der Begrenzung
    Color back_dark(171, 96, 0);
    Color back_light(247, 151, 27);

    
    //Eigenschaften der Border
    border.setFillColor(Color::White);
    border.setSize(border_loc);
    border.setPosition(800, 0);

    /// <summary>
    /// Erstellen der Spielfeldern und deren Farben
    /// </summary>
    for (int i = 0; i < 32; i++)
    {
        RectangleShape background_block;
        background_block.setSize(background_block_size);
        
        
        for (int n = 0; n < 31; n++) {
            
            //Schachbrettmuster
            //
            
            if (Background.size() % 2 == 0) {//gerade Zahl dunkel
                background_block.setFillColor(back_dark);
            }
            else {//ungerade Zahl hell
                background_block.setFillColor(back_light);
            }
            
            //Position der einzelene Elemente
            //
            background_block.setPosition(i * 25, n * 25);
            Background.push_back(background_block);
        }
    }
    
};
void map_draw() {
    
    window.draw(border);
    for (int i = 0; i < Background.size(); i++)
    {
        window.draw(Background[i]);
        
    }
    
};
