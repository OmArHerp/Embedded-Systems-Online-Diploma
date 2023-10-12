/*
 * Bit_Manipulation.h
 *
 * Created: 10/6/2023 1:20:32 AM
 *  Author: Dell
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SetBit(Reg,Bit)		(Reg |=  (1<<Bit))
#define ClrBit(Reg,Bit)		(Reg &= ~(1<<Bit))
#define TogBit(Reg,Bit)		(Reg ^=  (1<<Bit))
#define GetBit(Reg,Bit)		((Reg>>Bit)&1)




#endif /* BIT_MANIPULATION_H_ */