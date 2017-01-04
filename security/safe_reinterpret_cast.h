/* VARIANT 1 */

#define STATIC_CHECK(expr) { char unnamed[(expr) ? 1 : 0]; }

template<class To, class From>
To safe_reinterpret_cast(From from)
{
	STATIC_CHECK(sizeof(From) <= sizeof(To));
	return reinterpret_cast<To>(from);
}




/* VARIANT 2 */
template<class To, class From>
To safe_reinterpret_cast(From from)
{
	assert(sizeof(From) <= sizeof(To));
	return reinterpret_cast<To>(from);
}
