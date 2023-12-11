/*_____ I N C L U D E S ____________________________________________________*/
#include <stdio.h>
#include <string.h>
#include "NuMicro.h"

#include "fifo_buffer.h"

/*_____ D E C L A R A T I O N S ____________________________________________*/

/*_____ D E F I N I T I O N S ______________________________________________*/

/*_____ M A C R O S ________________________________________________________*/

/*_____ F U N C T I O N S __________________________________________________*/


void FifoBufferDump(unsigned char *pucBuff, int nBytes)
{
    unsigned short  i = 0;
    
    // printf("dump_buffer : %2d\r\n" , nBytes);    
    for (i = 0 ; i < nBytes ; i++)
    {
        printf("0x%2X," , pucBuff[i]);
        if ((i+1)%8 ==0)
        {
            printf("\r\n");
        }            
    }

    printf("\r\n\r\n");
    // printf("\r\n");
}


bool FifoBufferPush(fifoBuf_t *Buf, FIFO_tBuffer_T *WriteData)
{
    uint16_t u16WriteIdx = (uint16_t)(Buf->u16Tail + 1);

    if (u16WriteIdx == Buf->u16Size)
        u16WriteIdx = 0;

    if (u16WriteIdx == Buf->u16Head )     // Buffer is full.
        return FALSE;                   // Return enqueue fail.

    #if 1
    memcpy(&Buf->FifoBuffer[u16WriteIdx],WriteData,sizeof(FIFO_tBuffer_T));
    #else
    Buf->FifoBuffer[u16WriteIdx] = WriteData;
    #endif
    Buf->u16Tail = u16WriteIdx;

    return TRUE;                        // Return enqueue successful.
}

bool FifoBufferPop(fifoBuf_t *Buf, FIFO_tBuffer_T *ReadData)
{
    uint16_t u16ReadIdx = Buf->u16Head;

    if (u16ReadIdx == Buf->u16Tail)     // Buffer is empty.
        return FALSE;                   // return failed to pop.

    if (u16ReadIdx < Buf->u16Size-1)
    {
        u16ReadIdx += 1;
    }
    else
    {
        u16ReadIdx = 0;
    }

    #if 1
    memcpy(ReadData,&Buf->FifoBuffer[u16ReadIdx],sizeof(FIFO_tBuffer_T));
    Buf->u16Head = u16ReadIdx;
    #else
    *ReadData = Buf->FifoBuffer[Buf->u16Head];
    #endif

    return TRUE;                        // return successful pop.
}

bool CheckFifoBufferEmpty(fifoBuf_t *Buf)
{
    if (Buf->u16Head == Buf->u16Tail)     // Buffer is empty.
        return TRUE;
    else
        return FALSE;
}

bool CheckFifoBufferNextItem(fifoBuf_t *Buf, FIFO_tBuffer_T *ReadData)
{
    if (Buf->u16Head == Buf->u16Tail)     // Buffer is empty.
        return FALSE;                   // return failed to pop.

    *ReadData = Buf->FifoBuffer[Buf->u16Head];

    return TRUE;                        // return successful pop.
}

