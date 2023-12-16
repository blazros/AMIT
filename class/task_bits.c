#ifndef __BIT_HEADER__
#define __BIT_HEADER__

#define SET_BIT(pin,nbit)	(pin |=  (1<< nbit))
#define CLEAR_BIT(pin,nbit)	(pin &= ~(1 << nbit))
#define TOGGLE_BIT(pin,nbit)	(pin ^=  (1 << nbit))
#define GET_BIT(pin,nbit)	(pin & (1 << nbit))


#endif
