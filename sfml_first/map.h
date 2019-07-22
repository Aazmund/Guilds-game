#include <SFML/Graphics.hpp>
#include "gen_cell.h"

using namespace sf;

const int h_map = 11;
const int w_map = 11;

Image i_map;
Texture t_map;
Sprite s_map;

sf::String TileMap[h_map] = {
    "01111C11110",
    "1****C****1",
    "1*********1",
    "1*********1",
    "1*********1",
    "CC*******CC",
    "1*********1",
    "1*********1",
    "1*********1",
    "1****C****1",
    "01111C11110",
};

void map_generator(){
    
    int counter = 0;
    for (int i = 0; i < h_map; i++) {
        for (int j = 0; j < w_map; j++) {
            
            if(TileMap[i][j] == '0'){
                switch (int(arr[counter])) {
                    case 1:
                        counter++;
                        TileMap[i][j] = 'P';
                        break;
                        
                    case 2:
                        counter++;
                        TileMap[i][j] = 'S';
                        break;
                        
                    case 3:
                        counter++;
                        TileMap[i][j] = 'H';
                        break;
                        
                    case 4:
                        counter++;
                        TileMap[i][j] = 'M';
                        break;
                        
                    default:
                        break;
                }
            }
        }
    }
    
    int i_index = 0;
    int j_index = 0;
    
    for(i_index; i_index < 11; i_index++){
        if(TileMap[i_index][j_index] == '1'){
            
        }
    }
    
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            std::cout << TileMap[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    
}

