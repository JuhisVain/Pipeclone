#ifndef TILE_H
#define TILE_H

enum PIPE {
	   N =        0x1,
	   E =        0x2,
	   S =        0x4,
	   W =        0x8,
	   POOL =     0x10,
	   NARROW =   0x20,
	   START =    0x40,
	   END =      0x80
};

class Tile
{
public:
  Tile(); //create random tile for queue
  explicit Tile(int pipe); //predetermined pipe. 0 is the empty tile
  int Get_pipe();
  void Set_pipe(int pipe);

private:
  int pipe;

};

#endif
