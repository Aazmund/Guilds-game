#include <SFML/Graphics.hpp>

using namespace sf;

class Cell {
protected:
	float x;
	float y;
	Texture texture;
	Sprite sprite;
public:

	void set_x(float x) {
		this->x = x;
		sprite.setPosition(this->x, y);
	}

	void set_y(float y) {
		this->y = y;
		sprite.setPosition(x, this->y);
	}

	float get_x() {
		return this->x;
	}

	float get_y() {
		return this->y;
	}

	Sprite get_sprite() {
		return this->sprite;
	}

	void setSprite(std::string imagePath, IntRect spriteRect) {
		Image image;
		image.loadFromFile(imagePath);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(spriteRect);
		sprite.setPosition(x, y);
	}

	virtual void action()
	{
		printf("cells action\n");
	}

	Cell() {
		//printf("cell const");
	}
};

class Port : public Cell {
public:
	Port(Vector2f position)
	{
		x = position.x;
		y = position.y;
		setSprite("./images/image.png", IntRect(0, 0, 32, 32));
	}

	void action()
	{
		printf("ports action\n");
	}
};

class Sowmill : public Cell {
public:
	Sowmill(Vector2f position)
	{
		x = position.x;
		y = position.y;
		setSprite("./images/image.png", IntRect(96, 0, 32, 32));
	}

	void action()
	{
		printf("sowmill action\n");
	}
};

class Horse : public Cell {
public:
	Horse(Vector2f position)
	{
		x = position.x;
		y = position.y;
		setSprite("./images/image.png", IntRect(64, 0, 32, 32));
	}

	void action()
	{
		printf("horse action\n");
	}
};

class Mine : public Cell {
public:
	Mine(Vector2f position)
	{
		x = position.x;
		y = position.y;
		setSprite("./images/image.png", IntRect(96, 0, 32, 32));
	}

	void action()
	{
		printf("mine action\n");
	}
};