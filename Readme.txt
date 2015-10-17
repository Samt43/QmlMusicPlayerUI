Install the Qt SDK and remember to check MinGW under install.
(This can be done in the IDE to by Opening Help > Start Updater > Package Manager > Next [IMG]http://i46.tinypic.com/30hro81.png[/IMG]

After this in your C:\QtSDK\mingw folder (or what path is correct for you).
Then just go ahead and copy and paste the /lib , /bin , /include folders form your downloaded libcurl library. Found Here. http://curl.haxx.se/download.html
File:
Win32 - Generic
Win32 2000/XP 	7.28.1 	libcurl 	SSL 	  	Günter Knauf 	3.24 MB

When this is done its only one thing left and that is adding the includepath and .lib (*.a) files to your project.

Open a new project and in the file Project_Name.PRO in the Qt Creator IDE.
Go ahead and add the following lines of code.

LIBS += C:/QtSDK/mingw/lib/libcurl.a

LIBS += C:/QtSDK/mingw/lib/libcurldll.a

INCLUDEPATH += C:/QtSDK/mingw/lib


Now #include <curl/curl.h> in one of your headers.h and you are ready to go.
Hope this is helpful to some as I found it frustrating and confusing by what I found on Google.

Cheers
WetCode
