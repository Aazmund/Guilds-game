#include <SFML/Graphics.hpp>

using namespace sf;

class GameDrawable {
protected:
	Vector2f spriteSize;
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

	Vector2f getSpriteSize()
	{
		return spriteSize;
	}

	Sprite get_sprite() {
		return this->sprite;
	}

	void setSprite(std::string imagePath, IntRect textureRect) {
		Image image;
		image.loadFromFile(imagePath);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(textureRect);
		sprite.setPosition(x, y);
	}

	bool isPointOverSprite(Vector2f point)
	{
		Vector2f offset(point - sprite.getPosition());
		return (offset.x < spriteSize.x && offset.y < spriteSize.y);
	}

	bool isPointOverSprite(Vector2i point)
	{
		Vector2i offset = Vector2i(point.x - sprite.getPosition().x, point.y - sprite.getPosition().y);
		return (offset.x >= 0 && offset.y >= 0 && offset.x < spriteSize.x && offset.y < spriteSize.y);
	}

	virtual void action()
	{

	}

	GameDrawable()
	{
	}
};

class Cell : public GameDrawable {
protected:
	IntRect activeRect;
	IntRect hoveredRect;
	IntRect pressedRect;
public:
	virtual void action()
	{
		printf("cells action\n");
	}

	void setSpriteActive()
	{
		sprite.setTextureRect(activeRect);
	}

	void setSpriteHovered()
	{
		sprite.setTextureRect(hoveredRect);
	}

	void setSpritePressed()
	{
		sprite.setTextureRect(pressedRect);
	}

	Cell()
	{
	}
};

class Port : public Cell {
public:
	Port(Vector2f position)
	{
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(160, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(160, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(160, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
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
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(192, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(192, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(192, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
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
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(224, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(224, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(224, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
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
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(256, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(256, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(256, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
	}

	void action()
	{
		printf("mine action\n");
	}
};

class emptyCell : public Cell {
public:
	emptyCell(Vector2f position)
	{
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(96, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(96, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(96, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
	}

	void action()
	{
		printf("empty action\n");
	}
};

class zeroCell : public Cell {
public:
	zeroCell(Vector2f position)
	{
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(32, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(32, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(32, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
	}

	void action()
	{
		printf("zero circle action\n");
	}
};

class oneCell : public Cell {
public:
	oneCell(Vector2f position)
	{
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(64, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(64, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(64, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
	}

	void action()
	{
		printf("outer circle action\n");
	}
};

class transitCell : public Cell {
public:
	transitCell(Vector2f position)
	{
		spriteSize = Vector2f(32, 32);
		activeRect = IntRect(128, 0, spriteSize.x, spriteSize.y);
		hoveredRect = IntRect(128, 32, spriteSize.x, spriteSize.y);
		pressedRect = IntRect(128, 64, spriteSize.x, spriteSize.y);
		x = position.x;
		y = position.y;
		setSprite("./images/mpImage.png", activeRect);
	}

	void action()
	{
		printf("C action\n");
	}
};

class Player : public GameDrawable {
private:
	Cell* curretnCell;

public:
	Player(Cell* currCell) : curretnCell(currCell)
	{
		spriteSize = Vector2f(32, 32);
		x = currCell->get_x();
		y = currCell->get_y();
		setSprite("./images/playerImg.png", IntRect(0, 0, spriteSize.x, spriteSize.y));
	}

	Cell* getCurrentCell()
	{
		return curretnCell;
	}

	void moveToCell(Cell* cl)
	{
		x = cl->get_x();
		y = cl->get_y();
		sprite.setPosition(x, y);
	}

	void action()
	{
		printf("player action\n");
	}
};