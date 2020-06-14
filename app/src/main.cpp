#include <iostream>

#include "../../framework/include/io/JPGImageLoader.h"
#include "../../framework/include/fliter/GrayFliter.h"
#include "../../framework/include/fliter/BinaryValFliter.h"
#include "../../framework/include/window/Window.h"
#include "../../framework/include/window/WindowManager.h"
#include "../../framework/include/fliter/DenoiseFliter.h"
#include "../../framework/include/scale/Scale.h"
#include "../../framework/include/op/CannyOp.h"
#include <vector>


int main(int argc,char *argv[]){
    int x1[] = {2,3,5,6,5,7,9,10,19,32,36,42,38,13,10,0,0,12,18,29,28,26,25,25,23,22,24,24,24,37,37,31,25,21,20,23,24,25,28,27,13,13,12,11,8,2,4,6,7,7,7,17,18,21,23,27,23,17,17,21,20,20,24,24,21,23,26,26,25,28,27,23,25,26,26,28,25,15,15,18,20,25,24,24,28,23,22,15,5,4};
    int x2[] = {2,2,2,4,7,18,27,27,18,3,0,3,6,8,4,5,9,10,6,6,11,17,30,26,25,16,18,20,22,16,17,13,16,19,18,19,16,6,7,7,6,6,5,4,0,3,3,3,3,3,3,3,6,15,16,10,9,10,10,4,4,9,12,16,15,22,21,17,17,16,16,18,18,19,13,16,19,19,16,14,11,9,9,10,14,20,23,13,0,0};
    int x3[] = {0,2,3,5,7,7,7,7,10,16,20,25,25,21,16,8,11,16,21,22,27,21,20,21,25,22,19,17,18,23,38,40,37,28,24,22,24,22,16,13,10,5,5,4,0,0,3,3,5,5,5,4,4,6,8,9,11,10,10,17,22,23,20,24,24,18,21,26,26,27,28,29,27,23,25,25,26,25,25,20,20,17,17,18,19,23,19,14,11,8};
    int x4[] = {0,1,6,10,11,11,13,14,16,17,18,18,17,29,29,31,34,37,39,39,35,34,33,33,33,33,32,30,32,32,30,30,30,26,23,21,18,13,10,9,7,7,6,0,0,0,4,6,7,7,8,9,9,8,3,17,28,30,41,41,42,21,27,30,30,30,30,29,20,23,24,27,30,33,37,25,21,26,28,23,23,20,16,20,21,18,20,20,10,5};
    lzw::ImageLoader *jpgLoader = new lzw::JPGImageLoader();
    lzw::PixelMtrix *pixels3 = jpgLoader->loadImage("/home/lzw/lzw/1/characters/06100004/00000050(81,871,146,928).jpg");



    // lzw::Window *GrayWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"灰度化");
    // //lzw::Fliter *grayFliter = new lzw::GrayFliter(pixels);
    lzw::Fliter *GrayFliter = new lzw::GrayFliter(pixels3);
    // GrayWindow->SetPixelMtrix(GrayFliter->doFliter());

    lzw::Window *BinaryWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"二值化");
    lzw::Fliter *binaryValFliter = new lzw::BinaryValFliter(GrayFliter->doFliter());
    BinaryWindow->SetPixelMtrix(binaryValFliter->doFliter());


    // lzw::Window *CannyWindow=new lzw::Window(pixels3->getWidth(),pixels3->getHeight(),"canny");
    // lzw::Op *CannyOp = new lzw::CannyOp(binaryValFliter->doFliter());
    // CannyWindow->SetPixelMtrix(CannyOp->doOp());

    lzw::Window *scaleWindow=new lzw::Window(45,45,"scale");
    lzw::Scale *scale = new lzw::Scale(45,45,binaryValFliter->doFliter());
    lzw::PixelMtrix *pixels5 = scale->doScale(); 
    scaleWindow->SetPixelMtrix(pixels5);

    int nnn = 0;
    for(int col=0; col<pixels5->getWidth();col++){
        int sum =0;
        for(int row=0;row<pixels5->getHeight(); row++){
            if(pixels5->getPixel()[row][col].getColor()->getR()!=0){
            }
            else{
                sum++;
            }
            
        }
        nnn=nnn+abs(sum-x1[col]);
    }

    for(int row=0;row<pixels5->getHeight(); row++){
        int sum =0;
        for(int col=0; col<pixels5->getWidth();col++){
            if(pixels5->getPixel()[row][col].getColor()->getR()!=0){
            }
            else{
                sum++;
            }
            
        }
        nnn=nnn+abs(sum-x1[45+row]);
    }

    std::cout<<sqrt(nnn)<<std::endl;


    lzw::WindowManager *manager=lzw::WindowManager::GetWindowManagerInstance();


    // manager->createWindow(locateWindow);
    //manager->createWindow(GrayWindow);
    //manager->createWindow(BinaryWindow);
    manager->createWindow(scaleWindow);
    //  manager->createWindow(denoiseWindow);
    // for(int i = 0;i<cut->getArray().size();i++){ 
    //     manager->createWindow(windows.at(i));
    // }

    manager->renderWindow();
    
    return 0;

}