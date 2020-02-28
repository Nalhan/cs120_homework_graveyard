/*
Nathan Park
4/15/15
Exercise 12.1
*/

#include <iostream>
using namespace std;
int callcount1 = 0, callcount2 = 0;
//declare color class
class color {
private:
  int r;
  int g;
  int b;
public:
  color();
  color(int,int,int);
  void set(int,int,int);
  void add(const color&);
  void mix(const color&);
  int R(void) const;
  int G(void) const;
  int B(void) const;
  void printColor(void);
};
//declare color class methods

color::color() {
  r = 0;
  g = 0;
  b = 0;
  callcount1++;
}

color::color(int red, int green, int blue) {
  r = red;
  g = green;
  b = blue;
  callcount2++;
}

void color::set(int red, int green, int blue) {
  r = red;
  g = green;
  b = blue;
}

void color::add(const color& incolor) {
  if(incolor.r > r) r = incolor.r;
  if(incolor.g > g) g = incolor.g;
  if(incolor.b > b) b = incolor.b;
}

void color::mix(const color& incolor) {
  r = ((r + incolor.r) / 2);
  g = ((g + incolor.g) / 2);
  b = ((b + incolor.b) / 2);
}

int color::R(void) const {
  return r;
}

int color::G(void) const {
  return g;
}

int color::B(void) const {
  return b;
}

void color::printColor(void) {
  cout << r << ' ' << g << ' ' << b << endl;
}

int main() {
  const color Black;
  const color White(255, 255, 255);
  const color SkyBlue(135,206,235);
  const color SeaGreen(46, 139, 87);
  const color Gold(255,215,0);
  const color Chocolate(210,105,30);
  const color DarkGrey(75,75,75);
  
  color Custom(White);
  Custom.mix(DarkGrey);
  Custom.mix(SkyBlue);
  Custom.printColor();
  
  color CreamyMix(White);
  CreamyMix.mix(SkyBlue);
  CreamyMix.mix(SeaGreen);
  CreamyMix.mix(White);
  CreamyMix.mix(White);
  CreamyMix.printColor();

  color mixes[5];
  mixes[0] = SkyBlue;
  mixes[0].add(SeaGreen);
  mixes[0].mix(Black);
  mixes[0].printColor();
  
  mixes[1].set(Chocolate.B(), SeaGreen.R(), DarkGrey.G());
  mixes[1].mix(Gold);
  mixes[1].printColor();

  mixes[2] = White;
  mixes[2].add(Black);
  mixes[2].add(Gold);
  mixes[2].printColor();

  mixes[3].set(Chocolate.R(), Gold.G(), SeaGreen.B());
  mixes[3].add(SkyBlue);
  mixes[3].printColor();

  mixes[4] = mixes[3];
  mixes[4].mix(Black);
  mixes[4].mix(Black);
  mixes[4].printColor();
  
  cout << callcount1 << " " << callcount2 << endl;
  return Black.R();
}
