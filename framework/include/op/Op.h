#ifndef __FRAMEWORK_OP_H__
#define __FRAMEWORK_OP_H__

#include "../../include/image/PixelMtrix.h"

namespace lzw{

    typedef enum OpMode{
        Canny_Op,
    }OpMode;

    class Op
    {
    private:
        /* data */
        OpMode opMode;
        PixelMtrix *pixelMtrix;

    public:
        Op(PixelMtrix *pixelMtrix,OpMode fliterMode);
        ~Op();

        virtual PixelMtrix *doOp()=0;

        PixelMtrix *getPixelMtrix(){return this->pixelMtrix;};
    };
    
    
}

#endif //! __FRAMEWORK_OP_H__