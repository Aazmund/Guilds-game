#include <SFML/Graphics.hpp>

using namespace sf;

class Port{
private:
    float x;
    float y;
    Image image;
    Texture texture;
    Sprite sprite;
public:
    
    void set_x(float x){
        this -> x = x;
        sprite.setPosition(this -> x, y);
    }
    void set_y(float y){
        this -> y = y;
        sprite.setPosition(x, this -> y);
    }
    float get_x(){
        return this -> x;
    }
    float get_y(){
        return this -> y;
    }
    
    Port(){
        image.loadFromFile("images/image.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(0,0,32,32));
    }
    
    Sprite get_sprite(){
        return this->sprite;
    }
    
    Texture get_texture(){
        return this->texture;
    }
    
    Image get_image(){
        return this->image;
    }
    
};

class Sowmill{
private:
    float x;
    float y;
    Image image;
    Texture texture;
    Sprite sprite;
public:
    
    void set_x(float x){
        this -> x = x;
        sprite.setPosition(this -> x, y);
    }
    void set_y(float y){
        this -> y = y;
        sprite.setPosition(x, this -> y);
    }
    float get_x(){
        return this -> x;
    }
    float get_y(){
        return this -> y;
    }
    
    Sowmill(){
        image.loadFromFile("images/image.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(96,0,32,32));
    }
    
    Sprite get_sprite(){
        return this->sprite;
    }
    
    Texture get_texture(){
        return this->texture;
    }
    
    Image get_image(){
        return this->image;
    }
    
};

class Horse{
private:
    float x;
    float y;
    Image image;
    Texture texture;
    Sprite sprite;
public:
    
    void set_x(float x){
        this -> x = x;
        sprite.setPosition(this -> x, y);
    }
    void set_y(float y){
        this -> y = y;
        sprite.setPosition(x, this -> y);
    }
    float get_x(){
        return this -> x;
    }
    float get_y(){
        return this -> y;
    }
    
    Horse(){
        image.loadFromFile("images/image.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(64,0,32,32));
    }
    
    Sprite get_sprite(){
        return this->sprite;
    }
    
    Texture get_texture(){
        return this->texture;
    }
    
    Image get_image(){
        return this->image;
    }
    
};

class Mine{
private:
    float x;
    float y;
    Image image;
    Texture texture;
    Sprite sprite;
public:
    
    void set_x(float x){
        this -> x = x;
        sprite.setPosition(this -> x, y);
    }
    void set_y(float y){
        this -> y = y;
        sprite.setPosition(x, this -> y);
    }
    float get_x(){
        return this -> x;
    }
    float get_y(){
        return this -> y;
    }
    
    Mine(){
        image.loadFromFile("images/map.png");
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setTextureRect(IntRect(96,0,32,32));
    }
    
    Sprite get_sprite(){
        return this->sprite;
    }
    
    Texture get_texture(){
        return this->texture;
    }
    
    Image get_image(){
        return this->image;
    }
    
};
