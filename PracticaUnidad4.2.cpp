//MAVI - Unidad 4 - Ejercicio 2
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture;
Sprite sprite1;
Sprite sprite2;
Sprite sprite3;
Sprite sprite4;

int main() {
	sf::RenderWindow App(sf::VideoMode(800, 600, 32), "Sniper^4 Drag");

	texture.loadFromFile("Unidad4_Assets/rcircle.png");
	sprite1.setTexture(texture);
	sprite2.setTexture(texture);
	sprite3.setTexture(texture);
	sprite4.setTexture(texture);

	float size_x = (float)texture.getSize().x;
	float size_y = (float)texture.getSize().y;

	//Setear posiciones en 4 extremos de la pantalla
	sprite1.setPosition(0, 0);
	sprite2.setPosition(800 - size_x, 0);
	sprite3.setPosition(0, 600 - size_y);
	sprite4.setPosition(800 - size_x, 600 - size_y);
	
	bool arrastreSprite1 = false;
	bool arrastreSprite2 = false;
	bool arrastreSprite3 = false;
	bool arrastreSprite4 = false;
	while (App.isOpen())
	{
		sf::Event event;
		while (App.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				App.close();
				break;
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i posicionMouse = sf::Mouse::getPosition(App);
				sf::Vector2f posicionVentana = App.mapPixelToCoords(posicionMouse);

				// Comprobar si mouse está sobre el sprite
				if (sprite1.getGlobalBounds().contains(posicionVentana)) {
					arrastreSprite1 = true; // Permite arrastre
				}
				if (sprite2.getGlobalBounds().contains(posicionVentana)) {
					arrastreSprite2 = true; 
				}
				if (sprite3.getGlobalBounds().contains(posicionVentana)) {
					arrastreSprite3 = true; 
				}
				if (sprite4.getGlobalBounds().contains(posicionVentana)) {
					arrastreSprite4 = true; 
				}
			}
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
				arrastreSprite1 = false; // Detener arrastre al dejar de presionar left Mouse
				arrastreSprite2 = false;
				arrastreSprite3 = false;
				arrastreSprite4 = false;
			}
		}
		if (arrastreSprite1) {
			sf::Vector2i posicionMouse = sf::Mouse::getPosition(App);
			sf::Vector2f posicionVentana = App.mapPixelToCoords(posicionMouse);
			sprite1.setPosition(posicionVentana.x - 50, posicionVentana.y - 50); // Ajuste de posición para centrar el sprite
		}
		if (arrastreSprite2) {
			sf::Vector2i posicionMouse = sf::Mouse::getPosition(App);
			sf::Vector2f posicionVentana = App.mapPixelToCoords(posicionMouse);
			sprite2.setPosition(posicionVentana.x - 50, posicionVentana.y - 50); 
		}
		if (arrastreSprite3) {
			sf::Vector2i posicionMouse = sf::Mouse::getPosition(App);
			sf::Vector2f posicionVentana = App.mapPixelToCoords(posicionMouse);
			sprite3.setPosition(posicionVentana.x - 50, posicionVentana.y - 50); 
		}
		if (arrastreSprite4) {
			sf::Vector2i posicionMouse = sf::Mouse::getPosition(App);
			sf::Vector2f posicionVentana = App.mapPixelToCoords(posicionMouse);
			sprite4.setPosition(posicionVentana.x - 50, posicionVentana.y - 50); 
		}

		App.clear();

		App.draw(sprite1);
		App.draw(sprite2);
		App.draw(sprite3);
		App.draw(sprite4);

		App.display();
	}
	return 0;
}
