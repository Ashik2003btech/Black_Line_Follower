# Line Follower Robot

This repository contains the Arduino code for a black line follower robot. The robot uses two IR sensors to detect the black line and controls two motors to follow the line accordingly.

## Components Required

- Arduino-compatible board (e.g., NodeMCU or ESP8266)
- L298N Motor Driver Module
- Two DC motors
- Two IR sensors
- Chassis for the robot
- Jumper wires
- Battery pack

## Pin Configuration

| Component         | Pin          |
|-------------------|--------------|
| Left Motor (A)    | D2, D1       |
| Right Motor (B)   | D4, D3       |
| Left IR Sensor    | D6           |
| Right IR Sensor   | D5           |
| Optional LED      | D7           |

## Code Explanation

1. **Motor Control Functions**
   - `moveForward()`: Moves the robot forward by driving both motors.
   - `turnLeft()`: Turns the robot left by stopping the left motor and driving the right motor.
   - `turnRight()`: Turns the robot right by stopping the right motor and driving the left motor.
   - `halt()`: Stops both motors.

2. **IR Sensor Logic**
   - The sensors detect the presence of the black line. Based on their readings:
     - Both sensors off the line: Move forward.
     - Left sensor on the line: Turn right.
     - Right sensor on the line: Turn left.
     - Both sensors on the line: Stop.

3. **Command Mapping**
   - `cmd = 1`: Move forward
   - `cmd = 2`: Turn right
   - `cmd = 3`: Turn left
   - `cmd = 4`: Stop

## Installation and Usage


1. Open the code file in the Arduino IDE.

2. Connect your Arduino board to the computer and select the appropriate board and port in the Arduino IDE.

3. Upload the code to the Arduino board.

4. Assemble the hardware components as per the pin configuration.

5. Power up the robot and place it on a track with a black line.



## Troubleshooting

- Ensure proper connections as per the pin configuration.
- Verify the IR sensors are calibrated to detect the black line.
- Adjust the motor speed in the code if the robot is moving too fast or too slow.
- Test the motors and sensors individually to confirm they are working correctly.


---

Happy building your line follower robot! 🎉
