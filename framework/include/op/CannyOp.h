#ifndef __FRAMEWORK_CANNYOP_H__
#define __FRAMEWORK_CANNYOP_H__

#include "../../include/op/Op.h"

namespace lzw{

    class CannyOp:public Op
    {
    private:
        /* data */
    public:
        CannyOp(PixelMtrix *pixelMtrix);
        ~CannyOp();

        PixelMtrix *doOp();
        int F(int p,int q,int w);
    };

    
    
    
}

#endif //! __FRAMEWORK_CANNYOP_H__