arduino-lightswitch
=====

Uses a pair of XBees to flip a light switch from a simple Flask served webpage.

Wiring
----------

* Pin 3 - LED with resistor
* Pin 11 - PWM signal to Servo
* TX - RX of XBee module (putting in a removable jumper allows the Arduino to be easily programmed with the XBee still 'plugged in')
* TX - TX of XBee module
* 5V & GND to servo and XBee module

Running
----------

* Open port 5000 in your firewall to allow requests from WiFi devices
* Plug an XBee into the host computer using an Explorer or FTDI breakout board. On Windows, open Device Manager and determine the COM port of the XBee. 
* Modify lines 4 and 8 of app.py to point to the COM port found in the Device Manager.
* From /Flask run "python app.py"
* Navigate to "http://hostipaddress:5000/on" on a WiFi connected device (phone, tablet)

License
-------
Licensed under the [Apache License](http://www.apache.org/licenses/LICENSE-2.0.html), Version 2.0 (the "License");