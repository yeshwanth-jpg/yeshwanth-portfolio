YESHWANTH S — ENGINEERING PORTFOLIO SOURCE PACKAGE

This package contains newly authored demonstrations and reconstructed documentation to support a truthful portfolio. These are not recovered original project files.

PROJECTS INCLUDED
1. Autonomous Pick-and-Place Robot Rover
   - source_code/rover_arduino/rover_control_starter.ino
   - Manual serial control example for Arduino + motor driver + servo gripper.
   - Verify hardware assumptions and pins before powering the robot.

2. Vehicle Speed Detection
   - source_code/vehicle_speed_detection/vehicle_speed_two_sensor_demo.ino
   - Two-ultrasonic-sensor timing concept. Sensor geometry, sensor update behavior, and calibration must be tested.

3. GPS Tracker using ESP32
   - source_code/esp32_gps_tracker/esp32_gps_tracker_demo.ino
   - Requires a UART GPS module and TinyGPSPlus library.

4. Differential Drive Robot Navigation
   - source_code/differential_drive_demo/differential_drive_demo.py
   - Plotted illustrative path, not a physics-based or ROS 2 simulation.

5. ROS 2 Laneless Navigation
   - source_code/laneless_navigation_demo/laneless_opencv_demo.py
   - Synthetic OpenCV image demonstration only; not CARLA, not ROS 2, and not a validated road detector.

ASSETS
- assets/rover_system_diagram.png: conceptual reconstructed system block diagram.
- assets/differential_drive_demo.gif: illustrative path animation.
- assets/laneless_pipeline.svg: conceptual architecture pipeline.

HOW TO RUN PYTHON DEMOS
- Install Python 3.
- Differential-drive plot: pip install matplotlib numpy
  python source_code/differential_drive_demo/differential_drive_demo.py
- Synthetic OpenCV: pip install opencv-python numpy
  python source_code/laneless_navigation_demo/laneless_opencv_demo.py

IMPORTANT HONESTY NOTES
- The user reports that the rover was physically built using Arduino, wheels, and a gripper, but original photos and code are unavailable.
- All code in this package is newly written example code, not original project code.
- Diagrams and animations are conceptual/illustrative; they are not proof of actual tests.
- Do not describe these new demos as completed original project results. If you run and test them, record your own observations and label them as new demonstrations.
- No hardware code should be used without checking exact pinout, voltage, motor driver, current limits, and actuator type.
