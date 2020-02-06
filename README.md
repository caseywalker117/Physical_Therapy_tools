# Physical_Therapy_tools
This is the Physical Therapy Tools code. Used with the 3D printed smart scraping tools. 
Developed in BYU's Human Computer Interaction Research Lab.


The schematic for the arduino will be uploaded once i find the darn thing. Or redraw it. It is fairly simply.

All models also need to be uploaded. There are 5 Tools in the set but the Smart feature was only implemented in the 
Medium sized tool. There are other tools that are ready to be equiped with sensors, but the smaller tools will require
more engineering to get them to that stage.

The Tools have no internal battery so they need to be hard jacked into a usb port. They can Run off a computer or
a battery pack as the code runs on the ardiono in the tool. Either way the tool will have an embilical cord coming out.
You will need a male to male as it has a small dongle fastened into the housing.

Arduino 1.8.8 is needed to make it work, it may work with later versions but I cannot promise it will work.
Some libraries will be needed like Fastled.h, and perhaps one other. All of the libraries can be downloaded through 
the Arduino libraries download tool.

To send code to the arduino just make sure that the correct board is selected, Arduino Micro board. And make sure it sees
the arduino on the port. 


Tool will glow with a red LED once plugged in, It takes a few moments to initialze and all the LEDs flash white once it has 
finished. After this the tool is good to go and will indicate how hard you are pressing with the tool with the imbedded RGBs.
Green is the lower threshold, Yellow the Middle and Red is the upper Threshold. The lights should always turn off if it does
not detect any force being applied. You need to press harder than you think when scraping to get it to green.

The dummy arm should give a little when scraped much like skin would. You can press on it pretty firmly but once it tears
there is no other way to fix the arm other than remelting the ballistic gel and re forming it. The skin is there to provide
protection for the Gel and provides a smooth surface for it to glide on.


I hope to continue the project and make a more streamlined tool.

Future goals include a more reliable way to make the tools. The 3D printed tools are great but a better manufacturung
method is needed. Enductive charging or small contact pads with an internal battery that will last a resonable amoun of time.
More functionality of the tools, such as connecting to host and send the data wirelessly. 
