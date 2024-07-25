#ifndef GESTOR_H
#define GESTOR_H

#include "../paint/image.h"
#include <map>
#include <string>
#include <fstream>

const std::string ASSETS_PATH = "./assets/";

class GestorImagenes{
  std::map<std::string, Image*> imagens;
public:
  Image* load_bmp(const std::string &s);
  Image* operator[](const std::string &s){
    return load_bmp(s);
  }
};

Image* GestorImagenes::load_bmp(const std::string &asset_name){
  std::string s = ASSETS_PATH + asset_name;
  if(imagens.count(s))
    return imagens[s];
  std::ifstream f(s);
  if(f.good()){
    f.close();
    Image * i = new Image();
    i->load_bmp(s.c_str());
    std::cout << "Loaded asset: " << s << std::endl;
    return imagens[s]=i;
  } else {
    std::cout << "Asset not found! :" << s << std::endl << "Exiting." << std::endl;
    exit(1);
  }
  return nullptr;
}

#endif
