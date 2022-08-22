
/*
 * Welcome to MultiWii.
 *
 * If you see this message, chances are you are using the Arduino I;DE. That is ok.
 * To get the MultiWii program configured for your copter, you must switch to the tab named 'config.h'.
 * Maybe that tab is not visible in the list at the top, then you must use the drop down list at the right
 * to access that tab. In that tab you must enable your baord or sensors and optionally various features.
 * For more info go to http://www.multiwii.com/wiki/index.php?title=Main_Page
 *
 * Have fun, and do not forget MultiWii is made possible and brought to you under the GPL License.
 *modified by archit bubber to work with nrf24,bmp280

 * 13/08/2022 by Eric Xu
 * Modified to combine FC and RX into one single Arduino Promo Mini board
 * NRF2401L+ module connects to the Arduino directly
 * WARNING: This has not been implemented to work with the failsafe function, if failsafe is enabled then 
 * it will be triggered straight away, therefore failsafe is not usable yet.
 */
