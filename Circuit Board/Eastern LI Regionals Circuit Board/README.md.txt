These schematics (drawn in EAGLE 8.5.2) entail the electrical details of our 2017-2018 Mission Possible device, as it appeared at the MIT invitational. The schematics shown here were all designed, drawn, and checked by David J Cutting, a member of the Ward Melville High School Science Olympiad A Team. 

All components in the schematics came from the follwing libraries:
*Sparkfun 
*Adafruit
*Eagle Default Libraries
*Mission Possible Special Parts (included with the schematics)

Hardware for the device was designed and constructed in a joint effort between Prakash Sekar and David J Cutting. 

All microcontrollers are Attiny25s running at 8MHz on their internal clock. While not exactly precise in terms of timing, we did not want to have to take up more board space and increase the already expensive BOM to include external crystals or resonators, especially when precise timing is not important on the microcontrollers. All code for the microcontrollers was written by David J Cutting and uploaded using an Arduino Pro Mini connected to a pogo pin programmer with the ArduinoISP program installed. The Arduino IDE was used with the Attiny core installed.

It took about two weeks of concentrated effort to design and lay out the board, mainly over the course of Christmas break 2017. The board was fabricated by Seeed studio in China and the components weree procured from Digi-key.

David recieved the board almost two weeks prior to the invitational, and assembled all the components onto it using a solder paste stencil and a cheap reflow skillet. The larger board proved to be more of a challenge than previous smaller boards that I've made because the board was flat but the skillet had a slight curvature. This required me to go back in with an SMD tip on my Hakko soldering iron to fix things up. The process took five hours one evening. The total cost for the board was well over $200, so extensive testing was done on it before powerup to ensure that nothing would blow up. Nothing did, so we breathed a sigh of relief and continued with wiring, code, and mechanical actions.

At the invitational, the device had a number of issues, a majority of which stemmed from hardware and code issues. Despite these issues, the controller board so held up perfectly. The only issue we had with the board came from the lack of larger capacitors on the motor driver actions, which has since been remedied.

We are making our schematics open source so that others may benefit from them. We also expect that most competitors won't have a way of replicating our board because of the high technical level of the assembly process. If you would like to make a board, a BOM and gerber files are available, however be warned that this is a very time consuming and risky build - screw something up and you'll be out $200 with no option but to buy new parts and rebuild (that is, unless you happen to have a hot air rework station).