#ifndef GameObject_hpp
#define GameObject_hpp
#include <SFML/Graphics.hpp>


class Gameobject
{
public:
	virtual ~Gameobject() = default;

private:
	sf::Vector2f position;
	virtual void update() = 0;
	virtual void render() = 0;


};
#endif // !GameObject_hpp
