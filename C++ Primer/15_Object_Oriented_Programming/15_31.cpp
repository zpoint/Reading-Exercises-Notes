/*							
 * 								word(s1)
 *							and
 *								word(s2)
 * s1 | s2 & ~s3  ===>  or
 * 							not(s3)
 *
 *
 *
 * 							word(s1)
 * s1 | (s2 & ~s3)  ===> or
 * 								word(s2)
 * 							and
 * 								not(s3)
 *
 *
 *										word(s1)
 *									and
 *										word(s2)
 * (s1 & s2) | (s3 & s4)  ===>  and 
 * 										word(s3)
 * 									and
 * 										word(s4)
 */
