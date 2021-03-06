#ifndef 		__DISPATCH_H__
#define 		__DISPATCH_H__

extern unsigned char ManiDispatchSteps;
extern unsigned char SubDispatchSteps;
extern unsigned char ManiDispatchStepsBak;
extern unsigned char SubDispatchStepsBak;
extern unsigned int timerCountOperation;

extern unsigned char ManualDispatchSteps;
extern unsigned int ManualTimerCount;

void ManiDispatch(void);
void SubDispatch(void);
void ManualDispatch(void);	

#endif