#include "config.hpp"

void Write(const std::string& text){
  if(text.empty()){
    std::cout << "empty" << std::endl;
    return;
  }
  bool count = false;
  for(int i=0;i<text.size();i++){
    std::cout << text[i] << std::endl;
    serialPrintf(srid,&text[i]);
    if(count){
      delay(1);
      //std::cout << " delay1 " << std::endl;
    }
    count = !count;
  }
}
