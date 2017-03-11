/*
 * the call ret.sorted() will call the non rvalue reference member function of
 * the new created Foo, sorted, and the member function sorted will create new Foo, all do it again
 * Fall into a dead loop
 */
