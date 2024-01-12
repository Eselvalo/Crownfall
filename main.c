#include <stdio.h>
#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#define TILE_NUM 9
#define TILE_SIZE 32
#define MAT_SIZE 10

enum types{

	water,
	ice
};

	struct toChange {
		int id; // 0
		int possibilities[];
	};
	struct Ghiaccio {
		int id; // 1
	};

union GridBlock {
	struct Ghiaccio a;
	struct toChange b;
};

typedef struct tile{
	Texture2D tex;
	enum types sides[4];
	int entropy;
} tile;


void DrawTiles(tile (*matrix)[MAT_SIZE], tile *tilevector );
void InitMap(tile (*matrix)[MAT_SIZE], tile *tilevector );
void RunWFC( tile *tilevector, tile (*matrix)[MAT_SIZE]);

int main()

{
	
	InitWindow(320,320, "WFC");
	ToggleFullscreen();
 	SetTargetFPS(60);
	


	int FirstTile = GetRandomValue(2,60);
	int count = 0;
	int FirstTileX = 0;
	int FirstTileY = 0;
	Texture2D texarray[9]={0};
	tile TileArray[9] = {0};
	tile mat[10][10] = {0};
	FilePathList TileFiles = LoadDirectoryFiles("./tileset"); 



	for (int i = 0; i<9; ++i)  //loads textures from image files
	{
	
	Image Tile =LoadImage(TileFiles.paths[i]);
	ImageResize(&Tile, TILE_SIZE,TILE_SIZE);
	texarray[i] = LoadTextureFromImage(Tile);
	UnloadImage(Tile);

	 	}

	for (int i = 0; i<9; ++i)  //puts textures in tiles structures
	{
		TileArray[i].tex = texarray[i];		
	
	}




	for(int i=0; i<10; ++i)
	{
		for(int j=0; j<10;++j) { 
			mat[i][j].entropy=TileFiles.count;
			
			printf("%d",mat[i][j].entropy);
			count++;
			if (count == FirstTile){
				FirstTileX = i;
				FirstTileY = j;
			}
		}
	printf("\n");

	}

	printf("%d\n", FirstTileX);
	printf("%d\n", FirstTileY);



	while(!WindowShouldClose())
	{

		BeginDrawing();

				
			ClearBackground(WHITE);
			DrawTiles(mat,TileArray);
		EndDrawing();
	}

	CloseWindow();
	return 0; 
}

void DrawTiles(tile (*matrix)[MAT_SIZE], tile *tilevector ){

	for(int i=0; i<10; ++i)
	{
		for(int j=0; j<MAT_SIZE;++j) { 
				
				matrix[i][j].tex = tilevector[i].tex;
				DrawTexture(matrix[i][j].tex,(TILE_SIZE)*i ,(TILE_SIZE)*j, WHITE);

		}

	}
}

/* void InitMap(tile (*matrix)[MAT_SIZE], tile *tilevector ){



}

void InitTiles(tile *tilevector) {
    // Tile 0,0 (Top-left)
    tilevector[0].sides[0] = water; // North
    tilevector[0].sides[1] = ice;   // East
    tilevector[0].sides[2] = ice;   // South
    tilevector[0].sides[3] = water; // West

    // Tile 0,1 (Top-middle)
    tilevector[1].sides[0] = water; // North
    tilevector[1].sides[1] = ice;   // East
    tilevector[1].sides[2] = ice;   // South
    tilevector[1].sides[3] = ice;   // West

    // Tile 0,2 (Top-right)
    tilevector[2].sides[0] = water; // North
    tilevector[2].sides[1] = water; // East
    tilevector[2].sides[2] = ice;   // South
    tilevector[2].sides[3] = ice;   // West

    // Tile 1,0 (Middle-left)
    tilevector[3].sides[0] = ice;   // North
    tilevector[3].sides[1] = ice;   // East
    tilevector[3].sides[2] = ice;   // South
    tilevector[3].sides[3] = water; // West

    // Tile 1,1 (Center)
    tilevector[4].sides[0] = ice;   // North
    tilevector[4].sides[1] = ice;   // East
    tilevector[4].sides[2] = ice;   // South
    tilevector[4].sides[3] = ice;   // West

    // Tile 1,2 (Middle-right)
    tilevector[5].sides[0] = ice;   // North
    tilevector[5].sides[1] = water; // East
    tilevector[5].sides[2] = ice;   // South
    tilevector[5].sides[3] = ice;   // West

    // Tile 2,0 (Bottom-left)
    tilevector[6].sides[0] = ice;   // North
    tilevector[6].sides[1] = ice;   // East
    tilevector[6].sides[2] = water; // South
    tilevector[6].sides[3] = water; // West

    // Tile 2,1 (Bottom-middle)
    tilevector[7].sides[0] = ice;   // North
    tilevector[7].sides[1] = ice;   // East
    tilevector[7].sides[2] = water; // South
    tilevector[7].sides[3] = ice;   // West

    // Tile 2,2 (Bottom-right)
    tilevector[8].sides[0] = ice;   // North
    tilevector[8].sides[1] = water; // East
    tilevector[8].sides[2] = water; // South
    tilevector[8].sides[3] = ice;   // West

    // Initialize entropy for each tile
    for (int i = 0; i < 9; ++i) {
        tilevector[i].entropy = 9; // Initial entropy (maximum possible)
    }
}*/

/*void RunWFC( int X, int Y,tile *tilevector, tile (*matrix)[MAT_SIZE]){

	bool changes = false;

	while (!changes){
		for (int x; x< MAT_SIZE; ++x)
		{	for (int y; y< MAT_SIZE; ++y)
			{
				if (matrix[x][y].entropy > 1)
				{
					CollapseTile();
					Propagate();
					changes = true;

				}
			}
		}



	}

}


void CollapseTile(???){
	

}


void Propagate(???){
	//AAAAAAAAAA
}

*/
