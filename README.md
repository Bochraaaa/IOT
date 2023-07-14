The goal of this project is to create an automatic and optimized watering solution based on WeMos D1 R2. 
Here is the description:

The system is divided into three parts : 
The first part involves humidity detection using a soil moisture sensor. This sensor is connected to and controlled by the WeMos D1 R2 board, which can receive humidity readings in analog and/or digital mode.

The second part focuses on weather retrieval. Data is transferred between the 'Openweathermap' platform and the WeMos D1 R2 board. The board sends a request to the website using the ESP8266, which facilitates the WiFi connection. Subsequently, the website responds with a request containing location-based weather data.

The last part is the informative section, where the weather data, including humidity, wind, pressure, and more, is displayed on an LCD screen.
