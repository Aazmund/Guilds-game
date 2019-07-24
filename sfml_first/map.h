#include <SFML/Graphics.hpp>
#include "gen_cell.h"

using namespace sf;

const int h_map = 11;
const int w_map = 11;

Image i_map;
Texture t_map;
Sprite s_map;

sf::String TileMap[h_map] = {
    "09999C99990",
    "9****C****9",
    "9*********9",
    "9*********9",
    "9*********9",
    "CC*******CC",
    "9*********9",
    "9*********9",
    "9*********9",
    "9****C****9",
    "09999C99990",
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
    int rl = 0;

    
    for(i_index = 0; i_index < 11; i_index++){
        if(TileMap[i_index][j_index] == '9'){
            random_line();
            for(int i = i_index; i < i_index + 4; i++){
                TileMap[i][j_index] = line_arr[rl];
                rl++;
            }
        }
        rl = 0;
    }
    
    j_index = 10;
    
    for(i_index = 0; i_index < 11; i_index++){
        if(TileMap[i_index][j_index] == '9'){
            random_line();
            for(int i = i_index; i < i_index + 4; i++){
                TileMap[i][j_index] = line_arr[rl];
                rl++;
            }
        }
        rl = 0;
    }

	i_index = 0;
	j_index = 0;

	for (j_index = 0; j_index < 11; j_index++) {
		if (TileMap[i_index][j_index] == '9') {
			random_line();
			for (int j = j_index; j < j_index + 4; j++) {
				TileMap[i_index][j] = line_arr[rl];
				rl++;
			}
		}
		rl = 0;
	}

	i_index = 10;

	for (j_index = 0; j_index < 11; j_index++) {
		if (TileMap[i_index][j_index] == '9') {
			random_line();
			for (int j = j_index; j < j_index + 4; j++) {
				TileMap[i_index][j] = line_arr[rl];
				rl++;
			}
		}
		rl = 0;
	}
	
	/* //вывод pos
	for (int i = 0; i < 20; i++) {
		std::cout << pos << std::endl;
	}
	*/
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            std::cout << TileMap[i][j] << " ";
        }
        std::cout<<std::endl;
    }
    
}
