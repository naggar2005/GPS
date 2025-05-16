#ifndef _COMMON_FUNCTIONS_H_
#define _COMMON_FUNCTIONS_H_

            // Set a specific bit 
#define SET_BIT(REG, BIT)      ((REG) |=  (1U << (BIT)))

            //Set a specific port
#define SET_PORT(REG)    ((REG) = 0xFF)

            // Clear a specific bit 
#define CLEAR_BIT(REG, BIT)      ((REG) &= ~(1U << (BIT)))

            //clear a specific port
#define CLEAR_PORT(REG)  ((REG) = 0x00)

            // Toggle a specific bit 
#define TOGGLE_BIT(REG, BIT)   ((REG) ^=  (1U << (BIT)))

            // Get the value of a specific bit 
#define GET_BIT(REG, BIT)      (((REG) >> (BIT)) & 1U)

            // check if bit is set or clear
#define BIT_IS_SET(REG, BIT)   (((REG) & (1U << (BIT))) != 0U)
#define BIT_IS_CLEAR(REG, BIT) (((REG) & (1U << (BIT))) == 0U)

            //rotate right / left 
#define ROR (REF, NUM)         (((REG) >> (NUM)) | ((REG) << (sizeof(REG) * 8 - (NUM))))
#define ROL(REG, NUM)          (((REG) << (NUM)) | ((REG) >> (sizeof(REG) * 8 - (NUM))))

#endif
