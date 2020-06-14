#include "../../include/op/Op.h"

using namespace lzw;

Op::Op(PixelMtrix *pixelMtrix,OpMode opMode){
    this->pixelMtrix=pixelMtrix;
    this->opMode=opMode;
}

Op::Op::~Op()
{
}