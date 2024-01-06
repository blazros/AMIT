#ifndef	BIT_MATH_H
#define	BIT_MATH_H

#define SET_BIT(pin,nbit)	(reg |=  (1<< nbit))
#define CLEAR_BIT(pin,nbit)	(reg &= ~(1 << nbit))
#define TOGGLE_BIT(pin,nbit)(reg ^=  (1 << nbit))
#define GET_BIT(pin,nbit)	((reg >> nbit) & 1)


#endif	/* BIT_MATH_H */
