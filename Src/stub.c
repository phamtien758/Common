/*******************************************************************************
 * File  : stub.c       
 * Author: phamtien758      
 * Brief : Stub source file
 ******************************************************************************/

/*** INCLUDE ******************************************************************/

#include "stub.h"

/*** DEFINE *******************************************************************/

/*** VARIABLES ****************************************************************/

/*** PROTOTYPE ****************************************************************/

/*** STATIC FUNCTION **********************************************************/

/*** FUNCTIONS ****************************************************************/

/**
  * @brief   Function 1
  * @note    
  * @param   void
  * @retval  None
  */       
void Sys_ExIntCfg(Sys_Exti ExtiNum_e, Sys_Port PortNum_e)
{
    uint8_t RegIndex_u8;
    uint8_t ExtiIndex_u8;

    RegIndex_u8 = (uint8_t)ExtiNum_e / (uint8_t)SYSCFG_EXTICR_NUM_EXTI;
    ExtiIndex_u8 = (uint8_t)ExtiNum_e % (uint8_t)SYSCFG_EXTICR_NUM_EXTI;

    SYSCFG->EXTICR[RegIndex_u8] |= (PortNum_e << \
                                    SYSCFG_EXTICR_EXTI_POS(ExtiIndex_u8));
}