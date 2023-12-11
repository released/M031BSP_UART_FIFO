/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include "NuMicro.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

#ifndef bool
typedef unsigned char bool;
#endif

#ifndef BOOL
typedef unsigned char BOOL;
#endif

#define  FIFO_QUQUE_SIZE                     (1024)

// typedef uint32_t FIFO_tBuffer_T;
typedef uint8_t FIFO_tBuffer_T;

typedef struct
{
    //FIFO_tBuffer_T *FifoBuffer;
    FIFO_tBuffer_T FifoBuffer[FIFO_QUQUE_SIZE];
    uint16_t u16Head;
    uint16_t u16Tail;
    uint16_t u16Size;
} fifoBuf_t;


#define DEF_FIFO_BUF(x,y)                       \
    FIFO_tBuffer_T x##_dataArray[y];            \
    fifoBuf_t x = {x##_dataArray, 0, 0, y}

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/

void FifoBufferDump(unsigned char *pucBuff, int nBytes);

bool FifoBufferPush(fifoBuf_t *Buf, FIFO_tBuffer_T *WriteData);
bool FifoBufferPop(fifoBuf_t *Buf, FIFO_tBuffer_T *ReadData);
bool CheckFifoBufferEmpty(fifoBuf_t *Buf);
bool CheckFifoBufferNextItem(fifoBuf_t *Buf, FIFO_tBuffer_T *ReadData);
