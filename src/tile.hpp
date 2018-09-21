#ifndef TILE_H
#define TILE_H

enum PIPE {
	   NONE =     0x0,
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
  void Put_goo();
  bool Has_goo();
  int Get_tile_duration();

private:
  int pipe;
  bool has_goo; //could be set in pipe

};

#endif
